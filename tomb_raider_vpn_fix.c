/*
 * Simple LD_PRELOAD library to fix assumptions made by Tomb Raiders about the output of getifaddrs()
 *
 * Compiling:
 * gcc -m32 -fPIC -shared tomb_raider_vpn_fix.c -o tomb_raider_vpn_fix.so -ldl -Wall
 *
 * Installing:
 * Either run the install script, or copy tomb_raider_vpn_fix.so to Tomb Raider dir
 * (.../SteamApps/common/Tomb Raider/bin) then  change steam launch options for Tomb
 * Raider to:
 *
 * env LD_PRELOAD=$LD_PRELOAD:./tomb_raider_vpn_fix.so %command%
 *
 */

#include <stdio.h>
#include <errno.h>
#include <ifaddrs.h>

int getifaddrs(struct ifaddrs **ifap) {
    fprintf(stderr, "\n\n\n---------------- dummied out getifaddrs()!\n\n\n");
    *ifap = NULL;
    return 0;
}

void freeifaddrs(struct ifaddrs *ifap) {
    /* do nothing */
}
