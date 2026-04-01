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
 * このクラスはSPIKEハブの内蔵IMUセンサーを操作するためのインターフェースを提供します。
 */
class IMU
{
public:

  /** 加速度 mm/s^2 */
  struct Acceleration {
    float x;
    float y;
    float z;
  };

  /** 角速度 degree/s */
  struct AngularVelocity {
    float x;
    float y;
    float z;
  };
    

  /**
   * コンストラクタ
   */
  IMU(void) {
    // このinitは2回目以降エラーとなるが、値を取る上では問題ないためそのままとする
    hub_imu_init();
  }
    
  /** 
   * IMUから加速度を取得する
   * @param accel [out] x/y/z軸の加速度を格納するためのAcceleration構造体[mm/s^2] 
   */ 
  void getAcceleration(Acceleration &accel);
    
  /** 
   * IMUから角速度を取得する
   * @param ang [out] x/y/z軸の角速度を格納するためのAngularVelocity構造体[°/s] 
   */ 
  void getAngularVelocity(AngularVelocity &ang);
    
  /** 
   * IMUから温度を取得する
   * @return 温度[℃] 
   */
  float getTemperature() const { 
    return hub_imu_get_temperature(); 
  }

  /**
   * IMUモジュールが使用可能かチェックする
   * @return true: 準備が整っている, false: まだ準備が整っていない
   */
  bool isReady() const {
    return hub_imu_is_ready();
  }

  /**
   * IMUモジュールが静止状態かチェックする
   * @return true: 静止している, false: 動いている
   */
  bool isStationary() const {
    return hub_imu_is_stationary();
  }

  /**
   * IMUモジュールの傾斜角度をセットする
   * @param angle [in] モジュールの（Y軸に対する）傾斜角度（度）
   */
  void setTilt(float angle) {
    hub_imu_set_tilt(angle);
  }

  /**
   * IMUの方位角を取得する
   * @return 方位角 [°]
   */
  float getHeading() const {
    return hub_imu_get_heading();
  }

  /**
   * IMUの方位角をリセットする
   */
  void resetHeading() {
    hub_imu_reset_heading();
  }

  /**
   * インスタンス生成が正常にできたかどうかを確認するための共通メソッド
   * IMUでは複数生成が問題ないので、常にfalseを返す
   */
  bool hasError() { return false; }
  
  
}; // class IMU
}  // namespace spikeapi

#endif // !SPIKE_CPP_API_IMU_H_
