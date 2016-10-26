include resin-image.inc

# eMMC boot needs different BL1 and BL@ binaries
BL1 = "${BL1_EMMC}"
BL2 = "${BL2_EMMC}"

# custom uboot binary env data for eMMC boot
UBOOT_ENV_BIN = "params_emmc.bin"
