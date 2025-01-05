//
// Port.h
//
// Copyright (c) 2025 Embedded Technology Software Design Robot Contest
//

#ifndef SPIKE_CPP_API_PORT_H_
#define SPIKE_CPP_API_PORT_H_

extern "C" {
#include "pbio/port.h"
}

/**
 * モータ/センサポート関連定義
 */

/**
 * モータ/センサポート番号
 */
enum class EPort
{
    PORT_A = PBIO_PORT_ID_A,    /**< SPIKE ポートA */
    PORT_B = PBIO_PORT_ID_B,    /**< SPIKE ポートB */
    PORT_C = PBIO_PORT_ID_C,    /**< SPIKE ポートC */
    PORT_D = PBIO_PORT_ID_D,    /**< SPIKE ポートD */
    PORT_E = PBIO_PORT_ID_E,    /**< SPIKE ポートE */
    PORT_F = PBIO_PORT_ID_F     /**< SPIKE ポートF */
};

/** センサポート数 */
#define NUM_PORT_S (6) // number of sensor ports

/** モータポート数 */
#define NUM_PORT_M (6) // number of motor ports

#endif // ! SPIKE_CPP_API_PORT_H_
