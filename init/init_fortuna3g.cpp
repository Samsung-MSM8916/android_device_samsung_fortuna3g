/*
   Copyright (c) 2013, The Linux Foundation. All rights reserved.
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.
   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>
#include <unistd.h>

#include <cutils/properties.h>
#include "vendor_init.h"
#include "log.h"
#include "util.h"

void vendor_load_properties()
{
    char platform[PROP_VALUE_MAX];
    char bootloader[PROP_VALUE_MAX];
    char device[PROP_VALUE_MAX];
    char devicename[PROP_VALUE_MAX];
    int rc;

    rc = property_get("ro.board.platform", platform, NULL);
    if (!rc || strncmp(platform, ANDROID_TARGET, PROP_VALUE_MAX))
        return;

    property_get("ro.bootloader", bootloader, NULL);

    if (strstr(bootloader, "G530HXXU2BPH1")) {
        property_set("ro.product.model", "SM-G530H");
        property_set("ro.product.device", "fortuna3g");
        property_set("persist.radio.multisim.config", "none");
        //property_set("telephony.lteOnGsmDevice","0");
    } else if (strstr(bootloader, "G530HXXS2BPH1")) {
        property_set("ro.product.model", "SM-G530H");
        property_set("ro.product.device", "fortuna3g");
        property_set("persist.radio.multisim.config", "none");
        //property_set("telephony.lteOnGsmDevice","0");
    } else if (strstr(bootloader, "G530MUBU1BPG1")) {
        property_set("ro.product.model", "SM-G530M");
        property_set("ro.product.device", "fortuna3g");
        property_set("persist.radio.multisim.config", "none");
        //property_set("telephony.lteOnGsmDevice","0");
    } else if (strstr(bootloader, "G530MUBU1BPH2")) {
        property_set("ro.product.model", "SM-G530M");
        property_set("ro.product.device", "fortuna3g");
        property_set("persist.radio.multisim.config", "none");
        //property_set("telephony.lteOnGsmDevice","0");
    } else if (strstr(bootloader, "G530HXXU2BPC2")) {
        property_set("ro.product.model", "SM-G530H");
        property_set("ro.product.device", "fortuna3g");
        property_set("persist.radio.multisim.config", "none");
        //property_set("telephony.lteOnGsmDevice","0");
    } else {
        property_set("ro.product.model", "SM-G530H");
        property_set("ro.product.device", "fortuna3g");
        property_set("persist.radio.multisim.config", "dsds");
        property_set("ro.multisim.simslotcount", "2");
        //property_set("telephony.lteOnGsmDevice","0");
    }

    property_get("ro.product.device", device, NULL);
    strlcpy(devicename, device, sizeof(devicename));
    ERROR("Found bootloader id %s setting build properties for %s device\n", bootloader, devicename);
}
