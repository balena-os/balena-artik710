IMAGE_FSTYPES_append = " resin-sdcard"

# Customize resin-sdcard
RESIN_BOOT_PARTITION_FILES_append = " uImage-${MACHINE}.bin:/uImage"

#
# Samsung Artik 710
#

# Customize resin-sdcard
RESIN_IMAGE_BOOTLOADER_artik710 = "u-boot-artik710"
RESIN_BOOT_PARTITION_FILES_append_artik710 = " \
    uImage-s5p6818-artik710-raptor-rev00.dtb:/s5p6818-artik710-raptor-rev00.dtb \
    uImage-s5p6818-artik710-raptor-rev01.dtb:/s5p6818-artik710-raptor-rev01.dtb \
    uImage-s5p6818-artik710-raptor-rev03.dtb:/s5p6818-artik710-raptor-rev03.dtb \
"

IMAGE_CMD_resin-sdcard_append_artik710 () {
    dd conv=notrunc if=${DEPLOY_DIR_IMAGE}/${BL1} of=${RESIN_SDIMG} bs=512 seek=${BL1_OFFSET}
    dd conv=notrunc if=${DEPLOY_DIR_IMAGE}/${SINGLEIMAGE} of=${RESIN_SDIMG} bs=512 seek=${BL2_OFFSET}
    dd conv=notrunc if=${DEPLOY_DIR_IMAGE}/${UBOOT_ENV_BIN} of=${RESIN_SDIMG} conv=notrunc bs=512 seek=${ENV_OFFSET}
}
