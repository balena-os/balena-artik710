inherit kernel-resin

FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"
SRC_URI_append = " \
    file://0001-s5p6818-artik710-raptor-common.dtsi-Add-gpio-leds-on.patch \
    file://don-t-save-power.patch \
    "
RESIN_CONFIGS_append = " kitra"
RESIN_CONFIGS[kitra] = " \
    CONFIG_SND_SOC_SGTL5000=m \
    CONFIG_MICREL_PHY=m \
"
