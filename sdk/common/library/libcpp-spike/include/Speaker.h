//
// Speaker.h
//
// Copyright (c) 2025 Embedded Technology Software Design Robot Contest
//

#ifndef SPIKE_CPP_API_SPEAKER_H_
#define SPIKE_CPP_API_SPEAKER_H_

#include <cstdint>
extern "C" {
#include <spike/hub/speaker.h>
}

namespace spikeapi {
/**
 * スピーカークラス
 */
class Speaker
{
public:

  /**
   * コンストラクタ
   * @param -
   * @return -
   */
  Speaker(void) = default;
    
  /** 
   * 音量を調整する 
   * @param volume ボリュームの値（0..100） 
   */ 
  void setVolume(uint8_t volume) const { 
    hub_speaker_set_volume(volume); 
  }
  
  /** 
   * 指定した周波数でトーンを再生する 
   * @param frequency トーンの周波数（Hz） 
   * @param duration 出力持続時間（ミリ秒）SOUND_MANUAL_STOPを指定した場合は手動で停止する必要がある 
   */ 
  void playTone(uint16_t frequency, int32_t duration) const { 
    hub_speaker_play_tone(frequency, duration); 
  }

  /** 
   * 再生中のサウンドを停止する 
   */ 
  void stop() const { 
    hub_speaker_stop(); 
  }

  /**
   * インスタンス生成が正常にできたかどうかを確認するための共通メソッド
   * Speakerでは複数生成が問題ないので、常にfalseを返す
   */
  bool hasError() { return false; }
  

  
}; // class Speaker
}  // namespace spikeapi

#endif // !SPIKE_CPP_API_SPEAKER_H_
