//
// Light.h
//
// Copyright (c) 2025 Embedded Technology Software Design Robot Contest
//

#ifndef SPIKE_CPP_API_LIGHT_H_
#define SPIKE_CPP_API_LIGHT_H_

#include <spike/hub/light.h>

#include "dto/ColorHSVDto.h"
#include "dto/ColorDto.h"

namespace spikeapi {
/**
 * SPIKE ハブ内蔵ステータスライトクラス
 */
class Light
{
public:
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
    void turnOnHSV(ColorHSVDto &colorHSV);

    /** 
     * 指定された色でライトを点灯させる 
     * @param color 色 
     */ 
    void turnOnColor(LightColorDto color);

    /** 
     * ライトを消灯させる 
     */ 
    inline void turnOff() const { 
        hub_light_off(); 
    }
    
}; // class Light
}  // namespace spikeapi

#endif // !SPIKE_CPP_API_LIGHT_H_
