include resin-image.inc

# SD boot needs different BL1 and BL2 binaries
BL1 = "${BL1_SD}"
BL2 = "${BL2_SD}"

# custom uboot binary env data for SD card boot
UBOOT_ENV_BIN = "params_sd.bin"
