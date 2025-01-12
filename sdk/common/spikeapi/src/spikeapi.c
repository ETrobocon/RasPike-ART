/*
 * ev3api.c
 *
 *  Created on: Oct 20, 2014
 *      Author: liyixiao
 */

#include "platform_interface_layer.h"

typedef void (*func_ptr)(void);

void _app_init_task(intptr_t unused) {
#if defined(DEBUG)
	syslog(LOG_ERROR, "_app_init_task starts.");
#endif

}

/**
 * TODO:
 * C++ destructors are not supported currently.
 * This workaround can suppress compiler errors.
 */
void *__dso_handle __attribute__((weak))=0;

/**
 * TODO:
 * This is a dummy function to workaround a potential bug in 'gcc-arm-none-eabi-6-2017-q1-update',
 * since the global destructors are not supported currently.
 * See 'http://wiki.osdev.org/Calling_Global_Constructors' for details of '.fini_array' and '_fini' in ARM.
 */
void __attribute__((weak)) _fini() {}
