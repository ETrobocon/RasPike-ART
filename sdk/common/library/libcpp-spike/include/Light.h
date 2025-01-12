//
// Light.h
//
// Copyright (c) 2025 Embedded Technology Software Design Robot Contest
//

#ifndef SPIKE_CPP_API_LIGHT_H_
#define SPIKE_CPP_API_LIGHT_H_

extern "C" {
#include <spike/hub/light.h>
#include <pbio/color.h>
}
  
namespace spikeapi {
/**
 * SPIKE ハブ内蔵ステータスライトクラス
 */
class Light
{
public:

  /**
   * ライト用カラー
   */
  enum class EColor {
    NONE = PBIO_COLOR_NONE, 
    BLACK = PBIO_COLOR_BLACK, 
    GRAY = PBIO_COLOR_GRAY, 
    WHITE = PBIO_COLOR_WHITE, 
    RED = PBIO_COLOR_RED, 
    BROWN = PBIO_COLOR_BROWN, 
    ORANGE = PBIO_COLOR_ORANGE, 
    YELLOW = PBIO_COLOR_YELLOW, 
    GREEN = PBIO_COLOR_GREEN, 
    SPRING_GREEN = PBIO_COLOR_SPRING_GREEN, 
    CYAN = PBIO_COLOR_CYAN, 
    BLUE = PBIO_COLOR_BLUE, 
    VIOLET = PBIO_COLOR_VIOLET, 
    MAGENTA = PBIO_COLOR_MAGENTA
  };

  struct HSV {
    uint16_t h;
    uint8_t  s;
    uint8_t  v;
  };
  
  
  /**
   * コンストラクタ
   * @param -
   * @return -
   */
  Light(void) = default;
    
  /** 
   * 指定されたHSVでライトを点灯させる 
   * @param colorHSV HSV 
   */ 
  void turnOnHSV(Light::HSV &colorHSV);

  /** 
   * 指定された色でライトを点灯させる 
   * @param color 色 
   */ 
  void turnOnColor(Light::EColor color);

  /** 
   * ライトを消灯させる 
   */ 
  void turnOff() const { 
    hub_light_off(); 
  }

  /**
   * インスタンス生成が正常にできたかどうかを確認するための共通メソッド
   * Lightでは複数生成が問題ないので、常にfalseを返す
   */
  bool hasError() { return false; }

  
}; // class Light
}  // namespace spikeapi

#endif // !SPIKE_CPP_API_LIGHT_H_
