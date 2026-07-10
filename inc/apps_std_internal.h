// Copyright (c) 2024, Qualcomm Innovation Center, Inc. All rights reserved.
// SPDX-License-Identifier: BSD-3-Clause

#ifndef __APPS_STD_INTERNAL_H__
#define __APPS_STD_INTERNAL_H__

#include "apps_std.h"
#include <stddef.h>

/**
  * @brief Macros used in apps_std
  * defines the search paths where fastRPC library should
  * look for skel libraries, .debugconfig, .farf files.
  * Could be overloaded from build system.
  **/

#define RETRY_WRITE (3) // number of times to retry write operation

// Environment variable name, that can be used to override the search paths
#define ADSP_LIBRARY_PATH "ADSP_LIBRARY_PATH"
#define DSP_LIBRARY_PATH "DSP_LIBRARY_PATH"
#define MAX_NON_PRELOAD_LIBS_LEN 2048
#define FILE_EXT ".so"

#ifndef VENDOR_DSP_LOCATION
#define VENDOR_DSP_LOCATION "/vendor/dsp/"
#endif
#ifndef VENDOR_DOM_LOCATION
#define VENDOR_DOM_LOCATION "/vendor/dsp/xdsp/"
#endif

/*
 * Pre-parsed list of directory search paths built once from an environment
 * variable string.  Callers iterate paths[] directly without re-parsing the
 * original semicolon-delimited string on every file open.
 */
#define FASTRPC_MAX_SEARCH_PATHS 64

struct fastrpc_path_list {
  char *buf;                               /* backing buffer holding all path strings */
  char *paths[FASTRPC_MAX_SEARCH_PATHS];  /* pointers into buf */
  int count;                               /* number of valid entries in paths[] */
};

void fastrpc_path_list_free(struct fastrpc_path_list *pl);

int fopen_from_dirlist(const struct fastrpc_path_list *pl,
    const char *mode, const char *name, apps_std_FILE *psout);

#endif /*__APPS_STD_INTERNAL_H__*/
