# Inherit some common LineageOS stuff.
$(call inherit-product, vendor/lineage/config/common_full_phone.mk)

# Inherit device configuration
$(call inherit-product, device/samsung/fortuna3g/full_fortuna3g.mk)

# Setup device configuration
PRODUCT_DEVICE := fortuna3g
PRODUCT_NAME := lineage_fortuna3g