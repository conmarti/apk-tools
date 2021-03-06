/* app_vertest.c - Alpine Package Keeper (APK)
 *
 * Copyright (C) 2005-2008 Natanael Copa <n@tanael.org>
 * Copyright (C) 2008-2011 Timo Teräs <timo.teras@iki.fi>
 * All rights reserved.
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

#include <stdio.h>
#include "apk_defines.h"
#include "apk_applet.h"
#include "apk_database.h"
#include "apk_version.h"
#include "apk_print.h"

static int vertest_main(void *pctx, struct apk_ctx *ac, struct apk_string_array *args)
{
	struct apk_out *out = &ac->out;
	apk_blob_t arg, ver, op, space = APK_BLOB_STRLIT(" ");
	char **parg;
	int errors = 0;

	foreach_array_item(parg, args) {
		int ok = 0;

		// arguments are either:
		//   "version"		-> check validty
		//   "ver1 op ver2"	-> check if that the comparison is true
		arg = APK_BLOB_STR(*parg);
		if (apk_blob_split(arg, space, &ver, &arg) &&
		    apk_blob_split(arg, space, &op,  &arg)) {
			if (apk_version_compare_blob(ver, arg) & apk_version_result_mask_blob(op))
				ok = 1;
		} else {
			ok = apk_version_validate(arg);
		}
		if (!ok) {
			apk_msg(out, "%s", *parg);
			errors++;
		}
	}

	return errors ? 1 : 0;
}

static struct apk_applet apk_vertest = {
	.name = "vertest",
	.main = vertest_main,
};

APK_DEFINE_APPLET(apk_vertest);
