IMAGE_FSTYPES_append = " resinos-img"

# Customize resinos-img
RESIN_BOOT_PARTITION_FILES_append = " Image-${MACHINE}.bin:/Image"

#
# Samsung Artik 710
#

# Customize resinos-img
RESIN_IMAGE_BOOTLOADER_artik710 = "u-boot-artik710"
RESIN_BOOT_PARTITION_FILES_append_artik710 = " \
    Image-s5p6818-artik710-raptor-rev00.dtb:/s5p6818-artik710-raptor-rev00.dtb \
    Image-s5p6818-artik710-raptor-rev01.dtb:/s5p6818-artik710-raptor-rev01.dtb \
    Image-s5p6818-artik710-raptor-rev03.dtb:/s5p6818-artik710-raptor-rev03.dtb \
"

IMAGE_CMD_resinos-img_append_artik710 () {
    # Artik710 needs the following:
    # bl1 (a.k.a. AP Boot ROM: AP_BL1, in our case bl1-sdboot.img for SD boot and bl1-emmcboot.img for eMMC boot),
    # bl2 (a.k.a. AP RAM Firmware: AP_BL2, in our case fip-loader-sd.img for SD boot and fip-loader-emmc.img for eMMC boot),
    # bl31 + bl32 (a.k.a. EL3 Runtime Firmware or SoC AP firmware or EL3 monitor firmware: AP_BL31 + Secure-EL1 Payload (SP): AP_BL32, in our case the bundled image fip-secure.img consisting of the ATF + secure OS OPTEE)
    # bl33 (a.k.a. AP Normal World Firmware: AP_BL33, in our case the uboot binary modified as a FIP - Firmware Image Package - and then into a nexell image using SECURE_BINGEN),
    # u-boot environment data
    # written at specific locations for both SD card and eMMC boot.
    dd conv=notrunc if=${DEPLOY_DIR_IMAGE}/${BL1} of=${RESIN_RAW_IMG} bs=512 seek=${BL1_OFFSET}
    dd conv=notrunc if=${DEPLOY_DIR_IMAGE}/${BL2} of=${RESIN_RAW_IMG} bs=512 seek=${BL2_OFFSET}
    dd conv=notrunc if=${DEPLOY_DIR_IMAGE}/${BL31} of=${RESIN_RAW_IMG} bs=512 seek=${TZSW_OFFSET}
    dd conv=notrunc if=${DEPLOY_DIR_IMAGE}/${BL33} of=${RESIN_RAW_IMG} bs=512 seek=${UBOOT_OFFSET}
}
