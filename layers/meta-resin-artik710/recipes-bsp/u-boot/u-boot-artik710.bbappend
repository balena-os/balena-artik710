UBOOT_KCONFIG_SUPPORT = "1"
inherit resin-u-boot

FILESEXTRAPATHS_append := ":${THISDIR}/patches"
SRC_URI_append = " file://artik710-integrate-with-resin-configuration.patch"
