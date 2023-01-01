/*
 * Copyright (C) 2016 The CyanogenMod Project
 * Copyright (C) 2020 The LineageOS Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef SAMSUNG_POWER_H
#define SAMSUNG_POWER_H

/*
 * Board specific nodes
 *
 * If your kernel exposes these controls in another place, you can either
 * symlink to the locations given here, or override this header in your
 * device tree.
 */

static const std::vector<std::string> cpuSysfsPaths = {
    "/sys/devices/system/cpu/cpu0",
    "/sys/devices/system/cpu/cpu4"
};

static const std::vector<std::string> cpuInteractivePaths = {
    "/sys/devices/system/cpu/cpu0/cpufreq/interactive",
    "/sys/devices/system/cpu/cpu4/cpufreq/interactive"
};

/* double tap to wake node */
//#define TAP_TO_WAKE_NODE "/sys/class/sec/tsp/dt2w_enable"

/* custom CPU power saving freq - trelte */
#define PSAVE_LITTLE "1000000"
#define PSAVE_BIG "1400000"
#define LITTLE "1300000"
#define BIG "1700000"
#define HIGH_LITTLE "1300000"
#define HIGH_BIG "1900000"

/* interactive default profile - trelte */
#define INTERACTIVE_DEF_L_TIMER_RATE "20000"
#define INTERACTIVE_DEF_L_TIMER_SLACK "20000"
#define INTERACTIVE_DEF_L_MIN_SAMPLE_TIME "40000"
#define INTERACTIVE_DEF_L_BOOSTPULSE_DURATION "40000"
#define INTERACTIVE_DEF_L_MULTI_ENTER_LOAD "800"
#define INTERACTIVE_DEF_L_SINGLE_ENTER_LOAD "200"
#define INTERACTIVE_DEF_L_HISPEED_FREQ "900000"
#define INTERACTIVE_DEF_L_GO_HISPEED_LOAD "85"
#define INTERACTIVE_DEF_L_TARGET_LOADS "75"
#define INTERACTIVE_DEF_L_ABOVE_HISPEED_DELAY "19000"
#define INTERACTIVE_DEF_B_SINGLE_CLUSTER0_MIN_FREQ "800000"
#define INTERACTIVE_DEF_B_MULTI_CLUSTER0_MIN_FREQ "1200000"
#define INTERACTIVE_DEF_B_TIMER_RATE "20000"
#define INTERACTIVE_DEF_B_TIMER_SLACK "20000"
#define INTERACTIVE_DEF_B_MIN_SAMPLE_TIME "40000"
#define INTERACTIVE_DEF_B_BOOSTPULSE_DURATION "40000"
#define INTERACTIVE_DEF_B_MULTI_ENTER_LOAD "360"
#define INTERACTIVE_DEF_B_MULTI_ENTER_TIME "79000"
#define INTERACTIVE_DEF_B_MULTI_EXIT_LOAD "240"
#define INTERACTIVE_DEF_B_MULTI_EXIT_TIME "299000"
#define INTERACTIVE_DEF_B_SINGLE_ENTER_LOAD "95"
#define INTERACTIVE_DEF_B_SINGLE_ENTER_TIME "199000"
#define INTERACTIVE_DEF_B_SINGLE_EXIT_LOAD "60"
#define INTERACTIVE_DEF_B_SINGLE_EXIT_TIME "99000"
#define INTERACTIVE_DEF_B_HISPEED_FREQ "1000000"
#define INTERACTIVE_DEF_B_GO_HISPEED_LOAD "89"
#define INTERACTIVE_DEF_B_TARGET_LOADS "65 1500000:75"
#define INTERACTIVE_DEF_B_ABOVE_HISPEED_DELAY "59000 1300000:39000 1700000:19000"

/* interactive low profile - trelte */
#define INTERACTIVE_LOW_L_HISPEED_FREQ "900000"
#define INTERACTIVE_LOW_L_GO_HISPEED_LOAD "85"
#define INTERACTIVE_LOW_L_TARGET_LOADS "75"
#define INTERACTIVE_LOW_L_ABOVE_HISPEED_DELAY "19000"
#define INTERACTIVE_LOW_L_MIN_SAMPLE_TIME "15000"
#define INTERACTIVE_LOW_B_MIN_SAMPLE_TIME "15000"
#define INTERACTIVE_LOW_B_HISPEED_FREQ "1200000"
#define INTERACTIVE_LOW_B_GO_HISPEED_LOAD "95"
#define INTERACTIVE_LOW_B_TARGET_LOADS "80 1500000:90"
#define INTERACTIVE_LOW_B_ABOVE_HISPEED_DELAY "59000 1300000:39000 1700000:19000"

/* interactive high profile - trelte */
#define INTERACTIVE_HIGH_L_HISPEED_FREQ "1300000"
#define INTERACTIVE_HIGH_L_GO_HISPEED_LOAD "80"
#define INTERACTIVE_HIGH_L_ABOVE_HISPEED_DELAY "19000"
#define INTERACTIVE_HIGH_L_TARGET_LOADS "70"
#define INTERACTIVE_HIGH_L_MIN_SAMPLE_TIME "35000"
#define INTERACTIVE_HIGH_B_MIN_SAMPLE_TIME "35000"
#define INTERACTIVE_HIGH_B_HISPEED_FREQ "1600000"
#define INTERACTIVE_HIGH_B_GO_HISPEED_LOAD "83"
#define INTERACTIVE_HIGH_B_TARGET_LOADS "60 1500000:70"
#define INTERACTIVE_HIGH_B_ABOVE_HISPEED_DELAY "25000 1300000:20000 1700000:20000"

#endif // SAMSUNG_POWER_H
