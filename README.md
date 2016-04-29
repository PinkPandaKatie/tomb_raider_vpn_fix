# Tomb Raider VPN Fix

This is an LD_PRELOAD script that forces getifaddrs to return no addresses.

Tomb Raider for Linux won't start if there are any VPNs active that use TUN
devices. This is because it makes incorrect assumptions about the return value
of getifaddrs(). The only reason it calls getifaddrs() is to get the MAC address
for a Version 1 UUID, and falls back to a different algorithm if getifaddrs()
returns no interfaces at all.

To install, just run the install script. It will install the library in
~/.local/lib, and show instructions on how to set up Steam to launch Tomb Raider
with the fix in place.
