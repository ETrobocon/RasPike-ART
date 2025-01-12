/*
 * spikemain.cpp
 *
 *  Created on: Jan 12 2025
 *      Author: liyixiao
 */

#include "kernel.h"
#include "platform.h"
#include "platform_interface_layer.h"
#include <string.h>

#include <kernel.h>
#include <t_stdlib.h>
#include "syssvc/syslog.h"
#include "syssvc/serial.h"
#include "target_syssvc.h"
#include "kernel_cfg.h"

#define TMAX_DRI_NUM (16)
static ev3_driver_t drivers[TMAX_DRI_NUM];
static uint32_t tnum_drivers = 0;

static bool_t is_initialized = false;

void spike_main_task(intptr_t exinf) {

    platform_pause_application(false);

    is_initialized = false;

//    syslog(LOG_NOTICE, "Sample program starts (exinf = %d).", (int_t) exinf);

    uint32_t i;
    /**
     * Initialize all drivers
     */
	for(i = 0; i < tnum_drivers; ++i)
		if (drivers[i].init_func != NULL) drivers[i].init_func(0);

	platform_soft_reset();

	// Banner
    static char version_banner[] = "===========================<=";
    char *ptr_version = version_banner + sizeof(version_banner) - strlen(CSL_VERSION_STRING) - 4;
    ptr_version[0] = '>';
    memcpy(ptr_version + 1, CSL_VERSION_STRING, strlen(CSL_VERSION_STRING));
    //	syslog(LOG_NOTICE, "   _____   ______ ___  ______");
    //	syslog(LOG_NOTICE, "  / __/ | / /_  // _ \\/_  __/");
    //	syslog(LOG_NOTICE, " / _/ | |/ //_ </ , _/ / /");
    //	syslog(LOG_NOTICE, "/___/ |___/____/_/|_| /_/");
    //	syslog(LOG_NOTICE, " ");
	syslog(LOG_NOTICE, "%s", version_banner);
	//	syslog(LOG_NOTICE, " ");
	syslog(LOG_NOTICE, "Powered by TOPPERS/ASP3 RTOS of Hakoniwa");
	//	syslog(LOG_NOTICE, "Initialization is completed..");

    // Pause the application when using standalone mode
#if !defined(BUILD_LOADER)
	platform_pause_application(true);
#endif

	is_initialized = true;

	brick_misc_command(MISCCMD_SET_LED, TA_LED_GREEN);

}

ER platform_register_driver(const ev3_driver_t *p_driver) {
	if (tnum_drivers < TMAX_DRI_NUM) {
		drivers[tnum_drivers++] = *p_driver;
		return E_OK;
	} else {
		syslog(LOG_ERROR, "%s(): Too many device drivers", __FUNCTION__);
		return E_NOID;
	}
}

/**
 * Note: This function can only be called when the application is stopped.
 */
ER platform_soft_reset() {
	/**
	 * Soft reset
	 */
	uint32_t i;
	for(i = 0; i < tnum_drivers; ++i)
		if (drivers[i].softreset_func != NULL) drivers[i].softreset_func(0);

	return E_OK;
}

bool_t platform_is_ready() {
	return is_initialized;
}

void platform_pause_application(bool_t pause) {
#if 0
	if (pause)
		rsm_tsk(PLATFORM_BUSY_TASK);
	else
		sus_tsk(PLATFORM_BUSY_TASK);
#endif
}

/**
 * This task should be activated when the platform is busy,
 * which can pause all user tasks.
 */
void
platform_busy_task(intptr_t exinf) {
//	SVC_PERROR(syslog_msk_log(LOG_UPTO(LOG_DEBUG), LOG_UPTO(LOG_EMERG)));
	while(1);
}

void
svc_perror(const char *file, int_t line, const char *expr, ER ercd) {
    if (ercd < 0) {
        t_perror(LOG_ERROR, file, line, expr, ercd);
    }
}

void ev3rt_logtask(intptr_t unused) {
    //logtask_main(SIO_PORT_DEFAULT);
}

