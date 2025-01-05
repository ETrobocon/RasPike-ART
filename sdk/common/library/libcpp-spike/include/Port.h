//
// Port.h
//
// Copyright (c) 2025 Embedded Technology Software Design Robot Contest
//

#ifndef SPIKE_CPP_API_PORT_H_
#define SPIKE_CPP_API_PORT_H_

#include "pbio/port.h"

/**
 * モータ/センサポート関連定義
 */

/**
 * モータ/センサポート番号
 */
enum class ePort
{
    PORT_A = 'A',    /**< SPIKE ポートA */
    PORT_B = 'B',    /**< SPIKE ポートB */
    PORT_C = 'C',    /**< SPIKE ポートC */
    PORT_D = 'D',    /**< SPIKE ポートD */
    PORT_E = 'E',    /**< SPIKE ポートE */
    PORT_F = 'F'     /**< SPIKE ポートF */
};

/** センサポート数 */
#define NUM_PORT_S (6) // number of sensor ports

/** モータポート数 */
#define NUM_PORT_M (6) // number of motor ports

#endif // ! SPIKE_CPP_API_PORT_H_
