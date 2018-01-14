include resin-image.inc

# eMMC boot needs different BL1 and BL@ binaries
BL1 = "${BL1_EMMC}"
BL2 = "${BL2_EMMC}"

# deploy the bootloader binaries in resin-boot (will be needed by hostapps for updating the bootloader)
RESIN_BOOT_PARTITION_FILES_append_artik710 = " \
    ${BL1_EMMC}: \
    ${BL2_EMMC}: \
    ${BL31}: \
    ${BL33}: \
"
