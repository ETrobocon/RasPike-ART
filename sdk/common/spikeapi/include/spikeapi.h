#pragma once

/**
 * TOPPERS API
 */
#include <kernel.h>
#include <t_syslog.h>
#include <t_stdlib.h>

/**
 * Newlib
 */
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Kernel object ID
 */
#if !defined(TOPPERS_CFG1_OUT)
#if defined(BUILD_MODULE)
#include "module_cfg.h"
#else
#include "kernel_cfg.h"
#endif
#endif

/**
 * Application initialize task
 */
extern void _app_init_task(intptr_t unused);

#ifdef __cplusplus
}
#endif

