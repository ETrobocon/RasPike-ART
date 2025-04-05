//
// UltrasonicSensor.h
//
// Copyright (c) 2025 Embedded Technology Software Design Robot Contest
//

#ifndef SPIKE_CPP_API_ULTRASONIC_SENSOR_H_ 
#define SPIKE_CPP_API_ULTRASONIC_SENSOR_H_

#include <cstdint>
extern "C" {
#include <pup/ultrasonicsensor.h>
}

#include "Port.h"

namespace spikeapi {
/**
 * SPIKE 超音波センサクラス
 */
class UltrasonicSensor
{
public:

  /** 
   * コンストラクタ 
   * @param port PUPポートID 
   */ 
  UltrasonicSensor(EPort port) { 
    mDevice = pup_ultrasonic_sensor_get_device(static_cast<pbio_port_id_t>(port));
  }
    
  /** 
   * 超音波センサで距離を測定する 
   * @return 距離（単位：cm） 
   */ 
  int32_t getDistance() const { 
    return pup_ultrasonic_sensor_distance(mDevice); 
  } 
    
  /** 
   * 超音波信号を検出する 
   * @return true 超音波を検出した 
   * @return false 超音波を検出しなかった 
   */ 
  bool isPresence() const { 
    return pup_ultrasonic_sensor_presence(mDevice); 
  } 
    
  /** 
   * 超音波センサのライトの輝度を設定する 
   * @param bv1 輝度1 
   * @param bv2 輝度2 
   * @param bv3 輝度3 
   * @param bv4 輝度4 
   * @return - 
   */ 
  void setLight(int32_t bv1, int32_t bv2, int32_t bv3, int32_t bv4) const { 
    pup_ultrasonic_sensor_light_set(mDevice, bv1, bv2, bv3, bv4); 
  } 
    
  /** 
   * 超音波センサのライトを点灯する 
   * @return - 
   */ 
  void lightOn() const { 
    pup_ultrasonic_sensor_light_on(mDevice); 
  } 
    
  /** 
   * 超音波センサのライトを消灯する [
   * @return - 
   */ 
  void lightOff() const { 
    pup_ultrasonic_sensor_light_off(mDevice); 
  }

  /**
   * インスタンス生成が正常にできたかどうかを確認するための共通メソッド
   * mDeviceがNULLの場合にtrueとなる
   */
  bool hasError() { return mDevice == 0; }
  
  
private: 
  pup_device_t *mDevice;
}; // class UltrasonicSensor
}  // namespace spikeapi

#endif // !SPIKE_CPP_API_ULTRASONIC_SENSOR_H_
