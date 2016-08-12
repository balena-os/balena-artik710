inherit kernel-resin

FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"
SRC_URI_append = " file://0001-s5p6818-artik710-raptor-common.dtsi-Add-gpio-leds-on.patch"
