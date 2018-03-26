/*
 *  Copyright (C) 2012 Igalia S.L
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <cstdio>
#include "GStreamerUtilities.h"
#include <gst/gst.h>


bool initializeGStreamer()
{
#if GST_CHECK_VERSION(0, 10, 31)
    if (gst_is_initialized())
        return true;
#endif

    GError *error;
    bool gstInitialized = gst_init_check(0, 0, &error);
    if (!gstInitialized) {
        fprintf(stderr, "GStreamer initialization failed: %s", error ? error->message : "unknown error occurred");
    }
    return gstInitialized;
}

