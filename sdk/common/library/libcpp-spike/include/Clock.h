//
// Clock.h
//
// Copyright (c) 2025 Embedded Technology Software Design Robot Contest
//

#ifndef SPIKE_CPP_API_CLOCK_H_
#define SPIKE_CPP_API_CLOCK_H_

#include <cstdint>

extern "C" {
#include <kernel.h>
}

namespace spikeapi {
/**
 * SPIKE クロッククラス
 */
class Clock
{
public:
  /**
   * コンストラクタ
   * 開始時間をシステム時刻で初期化する
   * @param -
   * @return -
   */
  Clock(void);

  /**
   * リセット
   * 開始時間を現在のシステム時刻でリセットする
   * @param -
   * @return -
   */
  void reset(void);

  /**
   * 経過時間取得
   * 開始時間からの経過時間を取得する
   * @param -
   * @return 経過時間[usec]
   */
  uint64_t now(void) const;
  
  /**
   * 自タスク遅延
   * @param duration 遅延時間[usec]
   * @return -
   */
  void wait(uint64_t duration)
  {
    dly_tsk(duration);
  }
  
  /**
   * 自タスクスリープ
   * @param duration スリープ時間[usec]
   * @return -
   */
  void sleep(uint64_t duration)
  {
    tslp_tsk(duration);
  }

  /**
   * インスタンス生成が正常にできたかどうかを確認するための共通メソッド
   * Clockでは複数生成が問題ないので、常にfalseを返す
   */
  bool hasError() { return false; }
  

  
protected:
  /**
   * システム時刻取得
   * @param -
   * @return 現在のシステム時刻[usec]
   */
  static uint64_t getTim();

private:
    uint64_t mStartClock;
}; // class Clock
}  // namespace spikeapi

#endif // !SPIKE_CPP_API_CLOCK_H_
