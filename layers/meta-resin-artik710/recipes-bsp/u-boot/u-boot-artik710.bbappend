UBOOT_KCONFIG_SUPPORT = "1"
inherit resin-u-boot

FILESEXTRAPATHS_append := ":${THISDIR}/patches"
SRC_URI_append = " file://0007-artik710_raptor.h-Board-specific-integration-with-re.patch"
