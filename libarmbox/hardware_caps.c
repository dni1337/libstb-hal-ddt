/*
 * determine the capabilities of the hardware.
 * part of libstb-hal
 *
 * (C) 2010-2012 Stefan Seyfried
 *
 * License: GPL v2 or later
 */

#include <config.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>

#include <hardware_caps.h>

#define FP_DEV "/dev/dbox/oled0"
static int initialized = 0;
static hw_caps_t caps;

hw_caps_t *get_hwcaps(void)
{
	if (initialized)
		return &caps;

	memset(&caps, 0, sizeof(hw_caps_t));

#if BOXMODEL_VUSOLO4K
	initialized = 1;
	caps.has_CI = 1;
	caps.can_cec = 1;
	caps.can_shutdown = 1;
	caps.display_xres = 480;
	caps.display_yres = 320;
	caps.display_type = HW_DISPLAY_GFX;
	caps.display_can_deepstandby = 1;
	caps.display_can_set_brightness = 1;
	caps.display_has_statusline = 1;
	caps.has_button_timer = 1;
	caps.has_HDMI = 1;
	strcpy(caps.boxvendor, "VU");
	strcpy(caps.boxname, "SOLO4K");
	strcpy(caps.boxarch, "BCM7376");
#else
	initialized = 1;
	caps.has_CI = 1;
	caps.can_cec = 1;
	caps.can_shutdown = 1;
	caps.display_xres = 16;
	caps.display_type = HW_DISPLAY_LINE_TEXT;
	caps.display_can_deepstandby = 0;
	caps.display_can_set_brightness = 1;
	caps.display_has_statusline = 0;
	caps.has_button_timer = 1;
	caps.has_HDMI = 1;
	strcpy(caps.boxvendor, "AX-Technologies");
	strcpy(caps.boxname, "HD51");
	strcpy(caps.boxarch, "BCM7251S");
#endif
	return &caps;
}
