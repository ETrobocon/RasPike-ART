//
// ColorSensor.h
//
// Copyright (c) 2025 Embedded Technology Software Design Robot Contest
//

#ifndef SPIKE_CPP_API_COLOR_SENSOR_H_ 
#define SPIKE_CPP_API_COLOR_SENSOR_H_

#include <cstdint>
#include <pup/colorsensor.h>

#include "Port.h"

namespace spikeapi {
/**
 * SPIKE カラーセンサクラス
 */
class ColorSensor
{
public:

    /** 
     * コンストラクタ 
     * @param port PUPポートID 
     */ 
    ColorSensor(ePort port) { 
        mDevice = pup_color_sensor_get_device(static_cast<pbio_port_id_t>(port));
    }
    
    /** 
     * カラーセンサのRGB値を取得する 
     * @return RGB値、各色10ビット 
     */ 
    inline pup_color_rgb_t getRGB() const { 
        return pup_color_sensor_rgb(mDevice); 
    } 
    
    /** 
     * カラーセンサで色を測定する 
     * @param surface trueならば表面の色から、falseならば他の光源の色を検出する 
     * @return 色（hsvによる表現） 
     */ 
    inline pup_color_hsv_t getColor(bool surface) const { 
        return pup_color_sensor_color(mDevice, surface); 
    } 
    
    /** 
     * カラーセンサで色を測定する（近似なし） 
     * @param surface trueならば表面の色から、falseならば他の光源の色を検出する 
     * @return 色（hsvによる表現） 
     */ 
    inline pup_color_hsv_t getHSV(bool surface) const { 
        return pup_color_sensor_hsv(mDevice, surface); 
    } 
    
    /** 
     * センサーの発する光を表面がどの程度反射するかを測定する 
     * @return どの程度反射しているか（％） 
     */ 
    inline int32_t getReflection() const { 
        return pup_color_sensor_reflection(mDevice); 
    } 
    
    /** 
     * 周囲の光の強度を測定する 
     * @return 周囲の光の強度（％） 
     */ 
    inline int32_t getAmbient() const { 
        return pup_color_sensor_ambient(mDevice); 
    } 
    
    /** 
     * カラーセンサのライトを設定する 
     * @param bv1 輝度1 
     * @param bv2 輝度2 
     * @param bv3 輝度3 
     * @return - 
     */ 
    inline void setLight(int32_t bv1, int32_t bv2, int32_t bv3) const { 
        pup_color_sensor_light_set(mDevice, bv1, bv2, bv3); 
    } 
    
    /** 
     * カラーセンサのライトを点灯する 
     * @param -
     * @return - 
     */ 
    inline void lightOn() const { 
        pup_color_sensor_light_on(mDevice); 
    } 
    
    /** 
     * カラーセンサのライトを消灯する 
     * @param -
     * @return - 
     */ 
    inline void lightOff() const { 
        pup_color_sensor_light_off(mDevice); 
    } 
    
    /** 
     * カラーセンサが検知する色を設定する 
     * @param size カラーの配列のサイズ 
     * @param colors カラーの配列 
     * @return - 
     */ 
    inline void setDetectableColors(int32_t size, pup_color_hsv_t *colors) const { 
        pup_color_sensor_detectable_colors(size, colors);
    }

private: 
    pup_device_t *mDevice;
}; // class ColorSensor
}  // namespace spikeapi

#endif // !SPIKE_CPP_API_COLOR_SENSOR_H_
