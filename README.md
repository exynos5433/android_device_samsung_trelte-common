Device configuration for the Samsung Galaxy Note 4 family

## Copyright
* Copyright (C) 2015-2017 Christopher N. Hesse <raymanfx@gmail.com>
* Copyright (C) 2021 ananjaser1211 (AnanJaser)

## License
Apache License 2.0 (Apache-2.0) (Located at LICENSE, read more at [tldrlegal.com/license/apache-license-2.0](https://tldrlegal.com/license/apache-license-2.0-%28apache-2.0%29))

------------------------------------------------------------------

# Universal5433 - BUG Reports Guide

**Bug reporting repo for [LineageOS-17.1](https://forum.xda-developers.com/t/exynos-unofficial-lineageos-17-1-06-30-2021.3937956/) | [RessurectionRemix](https://forum.xda-developers.com/t/exynos-unofficial-resurrection-remix-q-v8-7-0-06-30-2021.3981537/unread)**

![alt text](https://cdn.arstechnica.net/wp-content/uploads/2021/04/Lineage-OS.jpg)

### How to write issues

* Select the right template for your issue request `([BUG] for bug, [Request] for requests)`
* Please explain your issue correctly
* Give as much details as possible.
* Low effort issues most likely will be closed.
* Gather logs!

### How to gather logs with **LoggingKit**
* Clone/Fork the repo or download the kit via [Releases](https://github.com/universal5433/android_device_samsung_trelte-common/releases)

### [With booted System] - **Intended for Crashes, FCs and other SYSTEM Logs**

1) 1. For Windows users: Install **Universal ADB drivers** or **Brand specific ADB drivers** if you don't have them
    2. For Linux and macOS users: To make the files executable, type in Terminal `chmod +x` and drag the files
2) On your phone **enable USB debugging** under `Developer options`
3) Launch your required log type (to find out which logs you should gather, check [Legend](#Legend))
4) Grant `ADB Keys`
5) Close your log type
6) Launch the needed log, again
7) After recording log, attach the created file to your GitHub issue post.

### **Legend**

| Log type | Description |
| :------: | :------: |
| log-ball | Full buffer logcat. Don't use unless requested|
| log-all | Verbose logcat, messy but records everything|
| log-e | Log for Error filter, only shows crashes|
| log-ril | Log for Modem/SIM and other RIL issues|
| log-kmsg | Log for Kernel msg when the kernel panics|
| log-dmsg | Log for Kernel on an active system|
| log-ActiveDmesg 	| Looping Log for Kernel on active system|

* Being stuck at **`"Waiting For Device"`** means you either **did not auth the adb key** or your **device does not even have debugging enabled**
* **Extra**: You can skip step 3/4 by running **`ADB_Keys.bat`** if you previously allowed your computer ADB

