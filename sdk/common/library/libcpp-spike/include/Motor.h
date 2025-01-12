//
// Motor.h
//
// Copyright (c) 2025 Embedded Technology Software Design Robot Contest
//

#ifndef SPIKE_CPP_API_MOTOR_H_ 
#define SPIKE_CPP_API_MOTOR_H_

#include <cstdint>
extern "C" {
#include <pup/motor.h>
}

#include "Port.h"

namespace spikeapi {
/**
 * SPIKE モータクラス
 */
class Motor
{
public:

  enum class EDirection {
    CLOCKWISE = PUP_DIRECTION_CLOCKWISE,
    COUNTERCLOCKWISE = PUP_DIRECTION_COUNTERCLOCKWISE,
  };
  
  /** 
   * コンストラクタ 
   * @param port PUPポートID 
   * @param direction モータの回転方向
   * @param reset_count カウントをリセットするか
   * pup_motor_setup()を複数回呼ぶとハングするため、コンストラクタで一回だけ呼ぶことでエラーを回避する
   */ 
  Motor(EPort port,EDirection direction = EDirection::CLOCKWISE, bool reset_count = true) : mHasError(false) { 
    mMotor = pup_motor_get_device(static_cast<pbio_port_id_t>(port));
    if ( !mMotor ) {
      mHasError = true;
      return;
    }
    pbio_error_t ret = pup_motor_setup(mMotor, static_cast<pup_direction_t>(direction), reset_count);
    if ( ret != PBIO_SUCCESS ) {
      mHasError = true;
    }
  }
    
  /** 
   * エンコーダをリセットする 
   * @return - 
   */ 
  void resetCount() const { 
    pup_motor_reset_count(mMotor); 
  } 
    
  /** 
   * エンコーダの値を取得する 
   * @return エンコーダの値 [°] 
   */ 
  int32_t getCount() const { 
    return pup_motor_get_count(mMotor); 
  } 
    
  /** 
   * モータの回転速度を取得する 
   * @return 回転速度 [°/秒] 
   */ 
  int32_t getSpeed() const { 
    return pup_motor_get_speed(mMotor);
  } 
    
  /** 
   * モータの回転速度を設定する 
   * @param speed モータの回転速度 [°/秒] 
   * @return - 
   */ 
  void setSpeed(int speed) const { 
    pup_motor_set_speed(mMotor, speed); 
  } 
    
  /** 
   * モータのパワー値を取得する 
   * @return パワー値（-100 ～ +100） 
   */ 
  int32_t getPower() const { 
    return pup_motor_get_power(mMotor); 
  } 
    
  /** 
   * モータのパワー値を設定する 
   * @param power モータのパワー値（-100 ～ +100） 
   * @return - 
   */ 
  void setPower(int power) const { 
    pup_motor_set_power(mMotor, power); 
  } 
    
  /** 
   * モータを止める 
   * @return - 
   */ 
  void stop() const { 
    pup_motor_stop(mMotor); 
  } 
    
  /** 
   * ブレーキをかけてモータを止める 
   * @return - 
   */ 
  void brake() const { 
    pup_motor_brake(mMotor); 
  } 
    
  /** 
   * モータを止めて角度を維持する 
   * @return - 
   */ 
  void hold() const { 
    pup_motor_hold(mMotor); 
  } 
    
  /** 
   * モータがストールしているか調べる 
   * @return true ストールしている
   * @return false ストールしていない 
   */ 
  bool isStalled() const { 
    return pup_motor_is_stalled(mMotor); 
  } 
    
  /** 
   * モータのデューティ値を下げる 
   * @param duty_limit 新しいデューティ値（0-100） 
   * @return 元の状態に戻すための最大電圧 
   */ 
  int32_t setDutyLimit(int duty_limit) const { 
    return pup_motor_set_duty_limit(mMotor, duty_limit); 
  } 
    
  /** 
   * モータのデューティ値を元に戻す 
   * @param old_value pup_motor_set_duty_limitの戻り値 
   */ 
  void restoreDutyLimit(int old_value) const { 
    pup_motor_restore_duty_limit(mMotor, old_value); 
  }

  /**
   * インスタンス生成が正常にできたかどうかを確認するための共通メソッド
   */
  bool hasError() { return mHasError; }
  
  
private: 
  pup_motor_t *mMotor;
  bool mHasError;
  
}; // class Motor
}  // namespace spikeapi

#endif // !SPIKE_CPP_API_MOTOR_H_
