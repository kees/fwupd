/*
 * Copyright (C) 2020 Richard Hughes <richard@hughsie.com>
 *
 * SPDX-License-Identifier: LGPL-2.1+
 */

#include "config.h"
#include "fu-firmware.h"
#include "fu-fuzzer.h"

int
LLVMFuzzerTestOneInput (const guint8 *data, gsize size)
{
	g_autoptr(FuFirmware) firmware = GOBJECTTYPE ();
	g_autoptr(GBytes) fw = g_bytes_new (data, size);
	G_GNUC_UNUSED gboolean ret;
	ret = fu_firmware_parse (firmware, fw,
				 FWUPD_INSTALL_FLAG_NO_SEARCH |
				 FWUPD_INSTALL_FLAG_IGNORE_VID_PID |
				 FWUPD_INSTALL_FLAG_IGNORE_CHECKSUM,
				 NULL);
#if 0
	if (ret) {
		g_autofree gchar *str = fu_firmware_to_string (firmware);
		g_print ("%s", str);
	}
#endif
	return 0;
}
