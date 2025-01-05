//
// IMU.h
//
// Copyright (c) 2025 Embedded Technology Software Design Robot Contest
//

#ifndef SPIKE_CPP_API_IMU_H_
#define SPIKE_CPP_API_IMU_H_

extern "C" {
#include <spike/hub/imu.h>
}

namespace spikeapi {
/**
 * SPIKE ハブ内蔵IMUクラス
 */
class IMU
{
public:

  /* 加速度 mm/s^2*/
  struct Acceleration {
    float x;
    float y;
    float z;
  };

  /* 角速度 degree/s */
  struct AngularVelocity {
    float x;
    float y;
    float z;
  };
    

  /**
   * コンストラクタ
   * @param -
   * @return -
   */
  IMU(void) {
    // このinitは2回目以降エラーとなるが、値を取る上では問題ないためそのままとする
    hub_imu_init();
  }
    
  /** 
   * IMUから加速度を取得する
   * @param x/y/z軸の加速度を格納するためのAcceleration構造体[mm/s^2] 
   * @return -
   */ 
  void getAcceleration(Acceleration &accel);
    
  /** 
   * IMUから角速度を取得する
   * @param x/y/z軸の角速度を格納するためのAngularVelocity構造体配列[°/s] 
   * @return -
   */ 
  void getAngularVelocity(AngularVelocity &ang);
    
  /** 
   * IMUから温度を取得する
   * @param -
   * @return 温度[℃] 
   */
  float getTemperature() const { 
    return hub_imu_get_temperature(); 
  }

  /**
   * インスタンス生成が正常にできたかどうかを確認するための共通メソッド
   * IMUでは複数生成が問題ないので、常にfalseを返す
   */
  bool hasError() { return false; }
  
  
}; // class IMU
}  // namespace spikeapi

#endif // !SPIKE_CPP_API_IMU_H_
