/*
   Copyright (c) 2020, The LineageOS Project. All rights reserved.
   Copyright (c) 2021, universal5433. All rights reserved.
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.
   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>
#include <sys/stat.h>
#include <sys/types.h>

#include <android-base/file.h>
#include <android-base/logging.h>
#include <android-base/properties.h>
#include <android-base/strings.h>

#include "vendor_init.h"

using android::base::GetProperty;
using android::base::ReadFileToString;
using android::base::Trim;
using std::string;

// copied from build/tools/releasetools/ota_from_target_files.py
// but with "." at the end and empty entry
std::vector<std::string> ro_props_default_source_order = {
    "",
    "product.",
    "product_services.",
    "odm.",
    "vendor.",
    "system.",
    "system_ext.",
};

/* From Magisk@jni/magiskhide/hide_utils.c */
static const char *snet_prop_key[] = {
  "ro.boot.vbmeta.device_state",
  "ro.boot.verifiedbootstate",
  "ro.boot.flash.locked",
  "ro.boot.selinux",
  "ro.boot.veritymode",
  "ro.boot.warranty_bit",
  "ro.warranty_bit",
  "ro.debuggable",
  "ro.secure",
  "ro.build.type",
  "ro.build.tags",
  "ro.build.selinux",
  NULL
};

static const char *snet_prop_value[] = {
  "locked",
  "green",
  "1",
  "enforcing",
  "enforcing",
  "0",
  "0",
  "0",
  "1",
  "user",
  "release-keys",
  "1",
  NULL
};

void property_override(string prop, string value) {
    auto pi = (prop_info*) __system_property_find(prop.c_str());

    if (pi != nullptr)
        __system_property_update(pi, value.c_str(), value.size());
    else
        __system_property_add(prop.c_str(), prop.size(), value.c_str(), value.size());
}

void set_ro_build_prop(const string &prop, const string &value, bool product = true) {
    string prop_name;

    for (const auto &source : ro_props_default_source_order) {
        if (product)
            prop_name = "ro.product." + source + prop;
        else
            prop_name = "ro." + source + "build." + prop;

        property_override(prop_name.c_str(), value.c_str());
    }
}

void lte_properties()
{
    property_override("telephony.lteOnGsmDevice", "1");
    property_override("ro.telephony.default_network", "9");
}

void nonlte_properties()
{
    property_override("telephony.lteOnGsmDevice", "0");
    property_override("ro.telephony.default_network", "3");
}

static void workaround_snet_properties() {

  // Hide all sensitive props
  for (int i = 0; snet_prop_key[i]; ++i) {
    property_override(snet_prop_key[i], snet_prop_value[i]);
  }

  chmod("/sys/fs/selinux/enforce", 0640);
  chmod("/sys/fs/selinux/policy", 0440);
}

void set_build_fingerprint(string name, string device, string build) {
    string build_fingerprint;
    string build_desc;

    std::string bl = GetProperty("ro.bootloader","");
    if(bl.empty()){
        bl = GetProperty("ro.boot.bootloader", "");
    }
    
    LOG(ERROR) << "Found bootloader id " << bl << " setting build properties for " << device << " device" << std::endl;

    build_fingerprint = "samsung/" + name + "/" + device + ":6.0.1/MMB29K/" + build + ":user/release-keys";
    build_desc = name + "-user 6.0.1 MMB29K " + build + " release-keys";

    set_ro_build_prop("fingerprint", build_fingerprint, false);
    set_ro_build_prop("description", build_desc, false);
    property_override("ro.bootimage.build.fingerprint", build_fingerprint);
    
    set_ro_build_prop("name", name);
    set_ro_build_prop("name", name, false);
    set_ro_build_prop("device", device);
    set_ro_build_prop("device", device, false);
}

void vendor_load_properties() {
    string model;

    std::string bootloader = GetProperty("ro.bootloader","");
    if(bootloader.empty()){
        bootloader = GetProperty("ro.boot.bootloader", "");
    }

    /* name , device , build */
    /* samsung/treltexx/trelte:6.0.1/MMB29K/N910CXXU2DSA2:user/release-keys */
    /* treltexx-user 6.0.1 MMB29K N910CXXU2DSA2 release-keys*/
    
    if (bootloader.find("N910C") == 0) {
        set_build_fingerprint("treltexx", "trelte", "N910CXXU2DSA2");
        model = "N910C";
    } else if (bootloader.find("N910H") == 0) {
        set_build_fingerprint("tre3gxx", "tre3g", "N910HXXS2DSB2");
        model = "N910H";
    } else if (bootloader.find("N910U") == 0) {
        set_build_fingerprint("trhpltexx", "trhplte", "N910UXXU2DSA1");
        model = "N910U";
    } else if (bootloader.find("N910S") == 0) {
        set_build_fingerprint("trelteskt", "trelteskt", "N910SKSU2DSA1");
        model = "N910S";
    } else if (bootloader.find("N910L") == 0) {
        set_build_fingerprint("treltelgt", "treltelgt", "N910LKLU2DSA1");
        model = "N910L";
    } else if (bootloader.find("N910K") == 0) {
        set_build_fingerprint("treltektt", "treltektt", "N910KKTU2DSA1");
        model = "N910K";
    } else if (bootloader.find("N915S") == 0) {
        set_build_fingerprint("tbelteskt", "tbelteskt", "N915SKSU2DSA1");
        model = "N915S";
    } else if (bootloader.find("N915L") == 0) {
        set_build_fingerprint("tbeltelgt", "tbeltelgt", "N915LKLU2DSA1");
        model = "N915L";
    } else if (bootloader.find("N915K") == 0) {
        set_build_fingerprint("tbeltektt", "tbeltektt", "N915KKTU2DSA1");
        model = "N915K";
    } else if (bootloader.find("N916S") == 0) {
        set_build_fingerprint("tre3calteskt", "tre3calteskt", "N916SKSU2DSA1");
        model = "N916S";
    } else if (bootloader.find("N916L") == 0) {
        set_build_fingerprint("tre3caltelgt", "tre3caltelgt", "N916LKLU2DSA1");
        model = "N916L";
    } else if (bootloader.find("N916K") == 0) {
        set_build_fingerprint("tre3caltektt", "tre3caltektt", "N916KKTU2DSA1");
        model = "N916K";
    } else {
        LOG(ERROR) << __func__ << ": Coudn't indentify model! Setting Default Model";
        set_build_fingerprint("treltexx", "trelte", "N910CXXU2DSA2");
        lte_properties();
        model = "N910C";
    }
    
    /* Only set 3G For N910H */
    if (bootloader.find("N910H") == 0) {
        nonlte_properties();
        LOG(ERROR) << "Setting 3G Only as " << bootloader << " is detected." << std::endl;
    } else {
        lte_properties();
        LOG(ERROR) << "Enabling 4G Support as " << bootloader << " is detected." << std::endl;
    }
    
    set_ro_build_prop("model", model);
    set_ro_build_prop("product", model, false);
    
    // Workaround SafetyNet
    //workaround_snet_properties();

}

