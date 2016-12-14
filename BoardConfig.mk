#
# Copyright (C) 2016 The CyanogenMod Project
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

# Inherit from common samsung fortuna
-include device/samsung/fortunaxx-common/BoardConfigCommon.mk

LOCAL_PATH := device/samsung/fortuna3g

# Assert
TARGET_OTA_ASSERT_DEVICE := SM-G530H,fortuna3g,samsung_sm_g530h

# Kernel
TARGET_KERNEL_CONFIG := msm8916_fortuna3g_eur_defconfig

# Vendor Init
TARGET_UNIFIED_DEVICE                := true
TARGET_INIT_VENDOR_LIB               := libinit_fortuna3g
TARGET_RECOVERY_DEVICE_MODULES       := libinit_fortuna3g

# inherit from the proprietary version
-include vendor/samsung/fortuna3g/BoardConfigVendor.mk

