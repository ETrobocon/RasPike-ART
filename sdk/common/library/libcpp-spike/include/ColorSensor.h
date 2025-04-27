//
// ColorSensor.h
//
// Copyright (c) 2025 Embedded Technology Software Design Robot Contest
//

#ifndef SPIKE_CPP_API_COLOR_SENSOR_H_ 
#define SPIKE_CPP_API_COLOR_SENSOR_H_

#include <cstdint>
extern "C" {
#include <pup/colorsensor.h>
}

#include "Port.h"

namespace spikeapi {
/**
 * SPIKE カラーセンサクラス
 */
class ColorSensor
{
public:

  struct RGB {
    uint16_t r;
    uint16_t g;
    uint16_t b;
  };

  struct HSV {
    uint16_t h;
    uint8_t  s;
    uint8_t  v;
  };
  
  /** 
   * コンストラクタ 
   * @param port PUPポートID 
   */ 
  ColorSensor(EPort port) { 
    mDevice = pup_color_sensor_get_device(static_cast<pbio_port_id_t>(port));
  }
  
  /** 
   * カラーセンサのRGB値を取得する 
   * @param  値を設定するRGB構造体、各色8ビット
   * @return -
   */ 
  void getRGB(RGB& rgb) const { 
    pup_color_rgb_t pup_rgb = pup_color_sensor_rgb(mDevice);
    rgb.r = pup_rgb.r;
    rgb.g = pup_rgb.g;
    rgb.b = pup_rgb.b;    
  } 
    
  /** 
   * カラーセンサで色を測定する 
   * @param surface trueならば表面の色から、falseならば他の光源の色を検出する 
   * @return 色（hsvによる表現） 
   */ 
  void getColor(HSV& hsv, bool surface = true) const { 
    pup_color_hsv_t pup_hsv = pup_color_sensor_color(mDevice, surface);
    hsv.h = pup_hsv.h;
    hsv.s = pup_hsv.s;
    hsv.v = pup_hsv.v;
  } 
    
  /** 
   * カラーセンサで色を測定する（近似なし） 
   * @param surface trueならば表面の色から、falseならば他の光源の色を検出する 
   * @return 色（hsvによる表現） 
   */ 
  void getHSV(HSV& hsv, bool surface = true ) const { 
    pup_color_hsv_t pup_hsv = pup_color_sensor_hsv(mDevice, surface);
    hsv.h = pup_hsv.h;
    hsv.s = pup_hsv.s;
    hsv.v = pup_hsv.v;
  } 
    
  /** 
   * センサーの発する光を表面がどの程度反射するかを測定する 
   * @return どの程度反射しているか（％） 
   */ 
  int32_t getReflection() const { 
    return pup_color_sensor_reflection(mDevice); 
  } 
    
  /** 
   * 周囲の光の強度を測定する 
   * @return 周囲の光の強度（％） 
   */ 
  int32_t getAmbient() const { 
    return pup_color_sensor_ambient(mDevice); 
  } 
    
  /** 
   * カラーセンサのライトを設定する 
   * @param bv1 輝度1 
   * @param bv2 輝度2 
   * @param bv3 輝度3 
   * @return - 
   */ 
  void setLight(int32_t bv1, int32_t bv2, int32_t bv3) const { 
    pup_color_sensor_light_set(mDevice, bv1, bv2, bv3); 
  } 
    
  /** 
   * カラーセンサのライトを点灯する 
   * @param -
   * @return - 
   */ 
  void lightOn() const { 
    pup_color_sensor_light_on(mDevice); 
  } 
    
  /** 
   * カラーセンサのライトを消灯する 
   * @param -
   * @return - 
   */ 
  void lightOff() const { 
    pup_color_sensor_light_off(mDevice); 
  } 
    
  /** 
   * カラーセンサが検知する色を設定する 
   * @param size カラーの配列のサイズ 
   * @param colors カラーの配列 
   * @return - 
   */ 
  void setDetectableColors(int32_t size, pup_color_hsv_t *colors) const { 
    pup_color_sensor_detectable_colors(size, colors);
  }

  /**
   * インスタンス生成が正常にできたかどうかを確認するための共通メソッド
   * mDeviceがNULLの場合にtrueとなる
   */
  bool hasError() { return mDevice == 0; }

  
private: 
  pup_device_t *mDevice;
}; // class ColorSensor
}  // namespace spikeapi

#endif // !SPIKE_CPP_API_COLOR_SENSOR_H_
