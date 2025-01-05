//
// ForceSensor.h
//
// Copyright (c) 2025 Embedded Technology Software Design Robot Contest
//

#ifndef SPIKE_CPP_API_FORCE_SENSOR_H_ 
#define SPIKE_CPP_API_FORCE_SENSOR_H_

#include <cstdint>
#include <pup/forcesensor.h>

#include "Port.h"

namespace spikeapi {
/**
 * SPIKE フォースセンサクラス
 */
class ForceSensor
{
public:

    /** 
     * コンストラクタ 
     * @param port PUPポートID 
     */ 
    ForceSensor(ePort port) { 
        mDevice = pup_force_sensor_get_device(static_cast<pbio_port_id_t>(port));
    }
    
    /** 
     * フォースセンサで力を測定する 
     * @return 力（単位：N） 
     */ 
    inline float getForce() const { 
        return pup_force_sensor_force(mDevice); 
    }
    
    /** 
     * フォースセンサのボタンの移動距離を取得する 
     * @return 距離（単位：mm） 
     */ 
    inline float getDistance() const { 
        return pup_force_sensor_distance(mDevice);
    } 
    
    /** 
     * フォースセンサのボタンが押されているかを検出する 
     * @param force 押されていると判定する最低限の力（単位：N） 
     * @return true 押されている 
     * @return false 押されていない 
     */ 
    inline bool isPressed(float force) const { 
        return pup_force_sensor_pressed(mDevice, force); 
    } 
    
    /** 
     * フォースセンサのボタンが触れられているかを検出する 
     * @return true 触れられている 
     * @return false 触れられていない 
     */ 
    bool isTouched() const { 
        return pup_force_sensor_touched(mDevice); 
    }

private: 
    pup_device_t *mDevice;
}; // class ForceSensor
}  // namespace spikeapi

#endif // !SPIKE_CPP_API_FORCE_SENSOR_H_
