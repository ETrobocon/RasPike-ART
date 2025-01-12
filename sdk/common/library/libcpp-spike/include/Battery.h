//
// Battery.h
//
// Copyright (c) 2025 Embedded Technology Software Design Robot Contest
//

#ifndef SPIKE_CPP_API_BATTERY_H_
#define SPIKE_CPP_API_BATTERY_H_

#include <cstdint>

extern "C" {
#include <spike/hub/battery.h>
}

namespace spikeapi {
/**
 * SPIKE バッテリークラス
 */
class Battery
{
public:
  /**
   * コンストラクタ
   * @param -
   * @return -
   */
  Battery(void) = default;

  /**
   * 電流取得
   * バッテリーの電流を取得する
   * @param -
   * @return 電流[mA]
   */
  uint16_t getCurrent(void) const {
    return hub_battery_get_current();
  }

  /**
   * 電圧取得
   * バッテリーの電圧を取得する
   * @param -
   * @return 電圧[mV]
   */
  uint16_t getVoltage(void) const {
    return hub_battery_get_voltage();
  }

  /**
   * インスタンス生成が正常にできたかどうかを確認するための共通メソッド
   * Batteryでは複数生成が問題ないので、常にfalseを返す
   */
  bool hasError() { return false; }
  
  
}; // class Battery
}  // namespace spikeapi

#endif // !SPIKE_CPP_API_BATTERY_H_
