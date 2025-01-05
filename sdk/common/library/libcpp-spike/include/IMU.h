//
// IMU.h
//
// Copyright (c) 2025 Embedded Technology Software Design Robot Contest
//

#ifndef SPIKE_CPP_API_IMU_H_
#define SPIKE_CPP_API_IMU_H_

#include <spike/hub/imu.h>

#include "AccelerationDto.h"
#include "AngularVelocityDto.h"

namespace spikeapi {
/**
 * SPIKE ハブ内蔵IMUクラス
 */
class IMU
{
public:
    /**
     * コンストラクタ
     * @param -
     * @return -
     */
    IMU(void) = default;
    
    /** 
     * IMUドライバを初期化する
     * @param -
     * @return -
     */ 
    inline void init() const { 
        hub_imu_init(); 
    }
    
    /** 
     * IMUから加速度を取得する
     * @param -
     * @return x/y/z軸の加速度を格納するためのfloat配列[mm/s^2] 
     */ 
    AccelerationDto getAcceleration();
    
    /** 
     * IMUから角速度を取得する
     * @param -
     * @return x/y/z軸の角速度を格納するためのfloat配列[°/s] 
     */ 
    AngularVelocityDto getAngularVelocity();
    
    /** 
     * IMUから温度を取得する
     * @param -
     * @return 温度[℃] 
     */
    inline float getTemperature() const { 
        return hub_imu_get_temperature(); 
    }
}; // class IMU
}  // namespace spikeapi

#endif // !SPIKE_CPP_API_IMU_H_
