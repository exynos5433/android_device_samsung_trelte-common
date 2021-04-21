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

#include <android-base/file.h>
#include <android-base/logging.h>
#include <android-base/properties.h>
#include <android-base/strings.h>

#include "property_service.h"
#include "vendor_init.h"

using android::base::GetProperty;
using android::base::ReadFileToString;
using android::base::Trim;
using android::init::property_set;

// copied from build/tools/releasetools/ota_from_target_files.py
// but with "." at the end and empty entry
std::vector<std::string> ro_product_props_default_source_order = {
    "",
    "product.",
    "product_services.",
    "odm.",
    "vendor.",
    "system.",
};

void property_override(char const prop[], char const value[], bool add = true)
{
    auto pi = (prop_info *) __system_property_find(prop);

    if (pi != nullptr) {
        __system_property_update(pi, value, strlen(value));
    } else if (add) {
        __system_property_add(prop, strlen(prop), value, strlen(value));
    }
}

void lte_properties()
{
    property_set("telephony.lteOnGsmDevice", "1");
    property_set("ro.telephony.default_network", "9");
}

void nonlte_properties()
{
    property_set("telephony.lteOnGsmDevice", "0");
    property_set("ro.telephony.default_network", "0");
}

void vendor_load_properties()
{
    std::string bootloader = GetProperty("ro.bootloader", "");

    const auto set_ro_product_prop = [](const std::string &source,
            const std::string &prop, const std::string &value) {
        auto prop_name = "ro.product." + source + prop;
        property_override(prop_name.c_str(), value.c_str(), false);
    };

    if (bootloader.find("N910C") == 0) {
        /* treltexx */
        for (const auto &source : ro_product_props_default_source_order) {
            set_ro_product_prop(source, "fingerprint", "samsung/treltexx/trelte:6.0.1/MMB29K/N910CXXU2DSA2:user/release-keys");
            set_ro_product_prop(source, "model", "SM-N910C");
            set_ro_product_prop(source, "device", "trelte");
            set_ro_product_prop(source, "name", "treltexx");
        }
        property_override("ro.build.description", "treltexx-user 6.0.1 MMB29K N910CXXU2DSA2 release-keys");
        lte_properties();
    } else if (bootloader.find("N910H") == 0) {
        /* tre3gxx */
        for (const auto &source : ro_product_props_default_source_order) {
            set_ro_product_prop(source, "fingerprint", "samsung/tre3gxx/tre3g:6.0.1/MMB29K/N910HXXS2DSB2:user/release-keys");
            set_ro_product_prop(source, "model", "SM-N910H");
            set_ro_product_prop(source, "device", "tre3g");
            set_ro_product_prop(source, "name", "tre3gxx");
        }
        property_override("ro.build.description", "tre3gxx-user 6.0.1 MMB29K N910HXXS2DSB2 release-keys");
        nonlte_properties();
    } else if (bootloader.find("N910U") == 0) {
        /* trhpltexx */
        for (const auto &source : ro_product_props_default_source_order) {
            set_ro_product_prop(source, "fingerprint", "samsung/trhpltexx/trhplte:6.0.1/MMB29K/N910UXXU2DSA1:user/release-keys");
            set_ro_product_prop(source, "model", "SM-N910U");
            set_ro_product_prop(source, "device", "trhplte");
            set_ro_product_prop(source, "name", "trhpltexx");
        }
        property_override("ro.build.description", "trhpltexx-user 6.0.1 MMB29K N910UXXU2DSA1 release-keys");
        lte_properties();
    } else if (bootloader.find("N910S") == 0) {
        /* trelteskt */
        for (const auto &source : ro_product_props_default_source_order) {
            set_ro_product_prop(source, "fingerprint", "samsung/trelteskt/trelteskt:6.0.1/MMB29K/N910SKSU2DSA1:user/release-keys");
            set_ro_product_prop(source, "model", "SM-N910S");
            set_ro_product_prop(source, "device", "trelteskt");
            set_ro_product_prop(source, "name", "trelteskt");
        }
        property_override("ro.build.description", "trelteskt-user 6.0.1 MMB29K N910SKSU2DSA1 release-keys");
        lte_properties();
    } else if (bootloader.find("N910L") == 0) {
        /* treltelgt */
        for (const auto &source : ro_product_props_default_source_order) {
            set_ro_product_prop(source, "fingerprint", "samsung/treltelgt/treltelgt:6.0.1/MMB29K/N910LKLU2DSA1:user/release-keys");
            set_ro_product_prop(source, "model", "SM-N910L");
            set_ro_product_prop(source, "device", "treltelgt");
            set_ro_product_prop(source, "name", "treltelgt");
        }
        property_override("ro.build.description", "treltelgt-user 6.0.1 MMB29K N910LKLU2DSA1 release-keys");
        lte_properties();
    } else if (bootloader.find("N910K") == 0) {
        /* treltektt */
        for (const auto &source : ro_product_props_default_source_order) {
            set_ro_product_prop(source, "fingerprint", "samsung/treltektt/treltektt:6.0.1/MMB29K/N910KKTU2DSA1:user/release-keys");
            set_ro_product_prop(source, "model", "SM-N910K");
            set_ro_product_prop(source, "device", "treltektt");
            set_ro_product_prop(source, "name", "treltektt");
        }
        property_override("ro.build.description", "treltektt-user 6.0.1 MMB29K N910KKTU2DSA1 release-keys");
        lte_properties();
    } else if (bootloader.find("N915S") == 0) {
        /* tbelteskt */
        for (const auto &source : ro_product_props_default_source_order) {
            set_ro_product_prop(source, "fingerprint", "samsung/tbelteskt/tbelteskt:6.0.1/MMB29K/N915SKSU2DSA1:user/release-keys");
            set_ro_product_prop(source, "model", "SM-N915S");
            set_ro_product_prop(source, "device", "tbelteskt");
            set_ro_product_prop(source, "name", "tbelteskt");
        }
        property_override("ro.build.description", "tbelteskt-user 6.0.1 MMB29K N915SKSU2DSA1 release-keys");
        lte_properties();
    } else if (bootloader.find("N915L") == 0) {
        /* tbeltelgt */
        for (const auto &source : ro_product_props_default_source_order) {
            set_ro_product_prop(source, "fingerprint", "samsung/tbeltelgt/tbeltelgt:6.0.1/MMB29K/N915LKLU2DSA1:user/release-keys");
            set_ro_product_prop(source, "model", "SM-N915L");
            set_ro_product_prop(source, "device", "tbeltelgt");
            set_ro_product_prop(source, "name", "tbeltelgt");
        }
        property_override("ro.build.description", "tbeltelgt-user 6.0.1 MMB29K N915LKLU2DSA1 release-keys");
        lte_properties();
    } else if (bootloader.find("N915K") == 0) {
        /* tbeltektt */
        for (const auto &source : ro_product_props_default_source_order) {
            set_ro_product_prop(source, "fingerprint", "samsung/tbeltektt/tbeltektt:6.0.1/MMB29K/N915KKTU2DSA1:user/release-keys");
            set_ro_product_prop(source, "model", "SM-N915K");
            set_ro_product_prop(source, "device", "tbeltektt");
            set_ro_product_prop(source, "name", "tbeltektt");
        }
        property_override("ro.build.description", "tbeltektt-user 6.0.1 MMB29K N915KKTU2DSA1 release-keys");
        lte_properties();
    } else {
        lte_properties();
    }

    std::string device = GetProperty("ro.product.device", "");
    LOG(ERROR) << "Found bootloader id " << bootloader << " setting build properties for " << device << " device" << std::endl;
}