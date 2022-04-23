LOCAL_PATH := device/samsung/trelte-common

### PLATFORM

TARGET_ARCH := arm
TARGET_NO_BOOTLOADER := true
TARGET_NO_RADIOIMAGE := true

BOARD_VENDOR := samsung

# CPU
TARGET_CPU_ABI := armeabi-v7a
TARGET_CPU_ABI2 := armeabi
TARGET_ARCH_VARIANT := armv8-a
TARGET_CPU_VARIANT := cortex-a53

# Platform
TARGET_BOARD_PLATFORM := exynos5
TARGET_SLSI_VARIANT := bsp
TARGET_SOC := exynos5433

TARGET_BOOTLOADER_BOARD_NAME := universal5433

# Security Patch Level
VENDOR_SECURITY_PATCH := 2017-08-01

# Audio
USE_XML_AUDIO_POLICY_CONF := 1

# Binder
TARGET_USES_64_BIT_BINDER := true

# Inherit board specific defines
-include $(LOCAL_PATH)/board/*.mk

# Allow Invalid PThreads
TARGET_ALLOWS_INVALID_PTHREAD := true

# Init
TARGET_INIT_VENDOR_LIB := //$(LOCAL_PATH):libinit_trelte
TARGET_RECOVERY_DEVICE_MODULES := //$(LOCAL_PATH):libinit_trelte

### FILESYSTEM

BOARD_BOOTIMAGE_PARTITION_SIZE := 14680064
BOARD_CACHEIMAGE_PARTITION_SIZE := 209715200
BOARD_RECOVERYIMAGE_PARTITION_SIZE := 16777216
BOARD_SYSTEMIMAGE_PARTITION_SIZE := 3774873600
BOARD_USERDATAIMAGE_PARTITION_SIZE := 26965164032 # Account for length=-16384
BOARD_FLASH_BLOCK_SIZE := 4096

BOARD_HAS_LARGE_FILESYSTEM := true
TARGET_USERIMAGES_USE_EXT4 := true

BOARD_CACHEIMAGE_FILE_SYSTEM_TYPE := ext4

TARGET_KERNEL_HAVE_EXFAT := true
TARGET_KERNEL_HAVE_NTFS := true

# Extended FileSystem Support
TARGET_EXFAT_DRIVER := sdfat

LZMA_RAMDISK_TARGETS := boot,recovery

BOARD_ROOT_EXTRA_FOLDERS += efs
TARGET_FS_CONFIG_GEN := $(LOCAL_PATH)/config.fs

BUILD_BROKEN_DUP_RULES := true

### KERNEL

BOARD_KERNEL_BASE := 0x10000000
BOARD_KERNEL_PAGESIZE := 2048
BOARD_KERNEL_SEPARATED_DT := true
BOARD_MKBOOTIMG_ARGS := --ramdisk_offset 0x01000000 --tags_offset 0x00000100
TARGET_CUSTOM_DTBTOOL := dtbhtoolExynos
BOARD_CUSTOM_BOOTIMG := true
BOARD_CUSTOM_BOOTIMG_MK := hardware/samsung/mkbootimg.mk
TARGET_KERNEL_SOURCE := kernel/samsung/universal5433
KERNEL_TOOLCHAIN_PREFIX := arm-linux-androideabi-
BOARD_KERNEL_IMAGE_NAME := zImage
TARGET_LINUX_KERNEL_VERSION := 3.10

# Ant+
BOARD_ANT_WIRELESS_DEVICE := "vfs-prerelease"

# Audio HAL variant
TARGET_AUDIOHAL_VARIANT := universal5433

# Bootanimation
TARGET_SCREEN_HEIGHT := 2560
TARGET_SCREEN_WIDTH := 1440

# Bluetooth
BOARD_BLUETOOTH_BDROID_BUILDCFG_INCLUDE_DIR := $(LOCAL_PATH)/bluetooth
BOARD_CUSTOM_BT_CONFIG := $(LOCAL_PATH)/bluetooth/libbt_vndcfg.txt
BOARD_HAVE_BLUETOOTH := true
BOARD_HAVE_BLUETOOTH_BCM := true
#BOARD_HAVE_SAMSUNG_BLUETOOTH := true

# Camera
BOARD_USE_SAMSUNG_CAMERAFORMAT_NV21 := true
TARGET_HAS_LEGACY_CAMERA_HAL1 := true
TARGET_ADDITIONAL_GRALLOC_10_USAGE_BITS := 0x2000U

# Charger/Healthd
BOARD_CHARGING_MODE_BOOTING_LPM := /sys/class/power_supply/battery/batt_lp_charging
CHARGING_ENABLED_PATH := /sys/class/power_supply/battery/batt_lp_charging

# LED
RED_LED_PATH := "/sys/class/leds/led_r/brightness"
GREEN_LED_PATH := "/sys/class/leds/led_g/brightness"
BLUE_LED_PATH := "/sys/class/leds/led_b/brightness"
BACKLIGHT_PATH := "/sys/class/backlight/panel/brightness"
TARGET_PROVIDES_LIBLIGHT := false

# Dexpreopt
ifeq ($(HOST_OS),linux)
  ifneq ($(TARGET_BUILD_VARIANT),eng)
    WITH_DEXPREOPT_BOOT_IMG_AND_SYSTEM_SERVER_ONLY ?= false
    WITH_DEXPREOPT := true
  endif
endif

# Display
TARGET_SCREEN_DENSITY := 560

# FIMG2D
BOARD_USES_SKIA_FIMGAPI := true
BOARD_USES_NEON_BLITANTIH := true
BOARD_USES_FIMGAPI_V4L2 := false

# Fingerprint
# TARGET_SEC_FP_HAL_VARIANT := bauth

# ValidityService
BOARD_USES_VALIDITY := true

# KEYSTORE
BOARD_USES_TRUST_KEYMASTER := true

# Fonts
EXTENDED_FONT_FOOTPRINT := true

# (G)SCALER
BOARD_USES_SCALER := true
BOARD_USES_DT := true

# Mixer
BOARD_USE_BGRA_8888 := true

# Graphics
USE_OPENGL_RENDERER := true

# Low memory devices
MALLOC_SVELTE := true

BOARD_USES_EXYNOS5_COMMON_GRALLOC := false
BOARD_USES_EXYNOS5433_GRALLOC := true

# Gralloc
TARGET_USES_GRALLOC1_ADAPTER := true

# Lineage hardware
ifneq ($(findstring lineage, $(TARGET_PRODUCT)),)
JAVA_SOURCE_OVERLAYS := \
    org.lineageos.hardware|$(LOCAL_PATH)/lineagehw|**/*.java
endif

# HDMI
BOARD_HDMI_INCAPABLE := true

# Hidl
DEVICE_MANIFEST_FILE := device/samsung/trelte-common/manifest.xml

# HWCServices
#BOARD_USES_HWC_SERVICES := true
SKIP_DISPLAY_BLANK_CTRL := true

# Include path
TARGET_SPECIFIC_HEADER_PATH += $(LOCAL_PATH)/include

# ION
TARGET_USES_ION := true

# ConsumerIR from hardware/samsung
IR_HAL_SUFFIX := exynos5

# Lights
TARGET_PROVIDES_LIBLIGHT := false

# Samsung OpenMAX Video
BOARD_USE_STOREMETADATA := true
BOARD_USE_METADATABUFFERTYPE := true
BOARD_USE_DMA_BUF := true
BOARD_USE_ANB_OUTBUF_SHARE := true
BOARD_USE_IMPROVED_BUFFER := true
BOARD_USE_NON_CACHED_GRAPHICBUFFER := true
BOARD_USE_GSC_RGB_ENCODER := true
BOARD_USE_CSC_HW := false
BOARD_USE_QOS_CTRL := false
BOARD_USE_S3D_SUPPORT := true
BOARD_USE_TIMESTAMP_REORDER_SUPPORT := false
BOARD_USE_DEINTERLACING_SUPPORT := false
BOARD_USE_VP8ENC_SUPPORT := true
BOARD_USE_HEVCDEC_SUPPORT := true
BOARD_USE_HEVCENC_SUPPORT := false
BOARD_USE_HEVC_HWIP := true
BOARD_USE_VP9DEC_SUPPORT := false
BOARD_USE_VP9ENC_SUPPORT := false
BOARD_USE_CUSTOM_COMPONENT_SUPPORT := true
BOARD_USE_VIDEO_EXT_FOR_WFD_HDCP := false
BOARD_USE_SINGLE_PLANE_IN_DRM := false

# Power
TARGET_POWERHAL_VARIANT := samsung

# Recovery
TARGET_RECOVERY_DENSITY := xxhdpi
BOARD_HAS_DOWNLOAD_MODE := true
BOARD_HAS_NO_SELECT_BUTTON := true
BOARD_RECOVERY_SWIPE := true
BOARD_USE_CUSTOM_RECOVERY_FONT := \"roboto_23x41.h\"
RECOVERY_GRAPHICS_USE_LINELENGTH := true
RECOVERY_SDCARD_ON_DATA := true
TARGET_RECOVERY_PIXEL_FORMAT := "RGBX_8888"
TARGET_USE_CUSTOM_LUN_FILE_PATH := "/sys/devices/15400000.usb/15400000.dwc3/gadget/lun%d/file"

ifeq ($(RECOVERY_VARIANT),twrp)
TARGET_RECOVERY_FSTAB := $(LOCAL_PATH)/rootdir/etc/recovery.fstab
TW_BRIGHTNESS_PATH := "/sys/devices/13800000.decon_fb/backlight/panel/brightness"
TW_THEME := portrait_hdpi
TW_MAX_BRIGHTNESS := 255
TW_DEFAULT_BRIGHTNESS := 150
TW_NO_REBOOT_BOOTLOADER := true
TW_HAS_DOWNLOAD_MODE := true
TW_INCLUDE_NTFS_3G := true
TW_NO_EXFAT_FUSE := true
TW_EXCLUDE_TWRPAPP := true
TW_USE_NEW_MINADBD := true
TW_EXCLUDE_DEFAULT_USB_INIT := true
TW_INCLUDE_FBE := true
TW_INCLUDE_CRYPTO := true
BOARD_HAS_NO_REAL_SDCARD := true
RECOVERY_GRAPHICS_USE_LINELENGTH := true
TW_INCLUDE_CRYPTO := true
TW_EXCLUDE_SUPERSU := true
else
TARGET_RECOVERY_FSTAB := $(LOCAL_PATH)/rootdir/etc/fstab.universal5433
endif

# Samsung Seiren audio
BOARD_USE_ALP_AUDIO := true
BOARD_USE_SEIREN_AUDIO := true

# SELinux
#BOARD_SEPOLICY_DIRS += device/samsung/trelte-common/sepolicy
SELINUX_IGNORE_NEVERALLOWS := true

# Sensors
TARGET_NO_SENSOR_PERMISSION_CHECK := true

# Shims
TARGET_LD_SHIM_LIBS := \
    /system/vendor/lib/libexynoscamera.so|libexynoscamera_shim.so \
    /system/vendor/bin/gpsd|libshim_gpsd.so \
     /system/bin/mediaserver|/vendor/lib/libstagefright_shim.so

# Legacy BLOB Support
TARGET_PROCESS_SDK_VERSION_OVERRIDE += \
    /system/vendor/bin/hw/rild=27 \
		/system/bin/mediaserver=22


# Network Routing
TARGET_NEEDS_NETD_DIRECT_CONNECT_RULE := true

# WFD
BOARD_USES_WFD := true

# WiFi
BOARD_HAVE_SAMSUNG_WIFI          := true
BOARD_WLAN_DEVICE                := bcmdhd
WPA_SUPPLICANT_VERSION           := VER_0_8_X
WPA_SUPPLICANT_USE_HIDL          := true
BOARD_WPA_SUPPLICANT_DRIVER      := NL80211
BOARD_WPA_SUPPLICANT_PRIVATE_LIB := lib_driver_cmd_bcmdhd
BOARD_HOSTAPD_DRIVER             := NL80211
BOARD_HOSTAPD_PRIVATE_LIB        := lib_driver_cmd_bcmdhd
WIFI_DRIVER_FW_PATH_PARAM        := "/sys/module/dhd/parameters/firmware_path"
WIFI_DRIVER_FW_PATH_STA          := "/vendor/etc/wifi/bcmdhd_sta.bin"
WIFI_DRIVER_FW_PATH_AP           := "/vendor/etc/wifi/bcmdhd_apsta.bin"
#WIFI_BAND                        := 802_11_ABG
WPA_SUPPLICANT_USE_HIDL          := true

# WiFi Configs
PRODUCT_COPY_FILES += \
	$(LOCAL_PATH)/configs/wifi/wpa_supplicant_overlay.conf:system/vendor/etc/wifi/wpa_supplicant_overlay.conf \
	$(LOCAL_PATH)/configs/wifi/p2p_supplicant_overlay.conf:system/vendor/etc/wifi/p2p_supplicant_overlay.conf

# Soong namespaces
PRODUCT_SOONG_NAMESPACES += $(LOCAL_PATH)


