do_install_append() {
    # don't enable random mac address for scanning on artik710
    cat >> ${D}${sysconfdir}/NetworkManager/NetworkManager.conf <<EOF

[device]
wifi.scan-rand-mac-address=no
EOF
}
