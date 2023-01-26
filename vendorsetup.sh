#
# Copyright (C) 2022 The LineageOS Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

DEVICE=trelte-common

echo "Patches : Fetching Patches Repo"
git clone https://github.com/universal5433/universal5433_patches -b lineage-18.1 device/samsung/$DEVICE/patches

if [ -e device/samsung/$DEVICE/patches ]; then
	echo "Patches: Fetched Repo"
else
	echo "Patches: Failed to Fetch Repo"
	exit 0;
fi

echo " "
echo "Patches: Applying NetworkStack: TcpSocketTracker: Opt-out for TCP info parsing on legacy kernels"
patch -d packages/modules/NetworkStack -p1 -N --no-backup-if-mismatch --reject-file=/tmp/rej < device/samsung/$DEVICE/patches/packages/modules/NetworkStack/0001-TcpSocketTracker-Opt-out-for-TCP-info-parsing-on-leg.patch
echo " "
echo "Patches: Applying system: core: utils: Threads: Handle empty thread names"
patch -d system/core -p1 -N --no-backup-if-mismatch --reject-file=/tmp/rej < device/samsung/$DEVICE/patches/system/core/0001-utils-Threads-Handle-empty-thread-names.patch
echo " "
echo "Patches: Applying inputflinger: disable touch input while using a stylus"
patch -d frameworks/native -p1 -N --no-backup-if-mismatch --reject-file=/tmp/rej < device/samsung/$DEVICE/patches/frameworks/native/0001-inputflinger-disable-touch-input-while-using-a-stylus.patch
echo " "
if [ $BUILD_SPOOFING = "1" ]; then
	echo "Patches: Applying frameworks: base: Add support for app signature spoofing"
	patch -d frameworks/base -p1 -N --no-backup-if-mismatch --reject-file=/tmp/rej < device/samsung/$DEVICE/patches/frameworks/base/0001-Add-support-for-app-signature-spoofing.patch
    echo " "
else
	echo "Patches: Skipping frameworks: base: Add support for app signature spoofing"
	echo "Patches: To compile with Spoofing patch type export BUILD_SPOOFING=1 and re-run envsetup"
    echo " "
fi

echo "Patches: Cleaning up"
rm -rf device/samsung/$DEVICE/patches
