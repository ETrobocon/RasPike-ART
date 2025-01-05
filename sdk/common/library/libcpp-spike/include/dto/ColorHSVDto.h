//
// LightColorHSVDto.h
//
// Copyright (c) 2025 Embedded Technology Software Design Robot Contest
//

#ifndef SPIKE_CPP_API_LIGHT_COLOR_HSV_DTO_H_
#define SPIKE_CPP_API_LIGHT_COLOR_HSV_DTO_H_

#include <cstdint>

/**
 * HSVカラーDtoクラス
 */
class LightColorHSVDto {
public:
    /**
     * コンストラクタ
     * @param h 色相 (0から359度)
     * @param s 彩度 (0から100パーセント)
     * @param v 明度 (0から100パーセント)
     */
    LightColorHSVDto(uint16_t h, uint8_t s, uint8_t v)
        : mH(h), mS(s), mV(v) {}

    /**
     * 色相を取得する
     * @return 色相 (0から359度)
     */
    inline uint16_t getHue() const {
        return mH;
    }

    /**
     * 彩度を取得する
     * @return 彩度 (0から100パーセント)
     */
    inline uint8_t getSaturation() const {
        return mS;
    }

    /**
     * 明度を取得する
     * @return 明度 (0から100パーセント)
     */
    inline uint8_t getValue() const {
        return mV;
    }

    /**
     * 色相を設定する
     * @param h 色相 (0から359度)
     */
    void setHue(uint16_t h) {
        mH = h;
    }

    /**
     * 彩度を設定する
     * @param s 彩度 (0から100パーセント)
     */
    void setSaturation(uint8_t s) {
        mS = s;
    }

    /**
     * 明度を設定する
     * @param v 明度 (0から100パーセント)
     */
    void setValue(uint8_t v) {
        mV = v;
    }

private:
    /** 色相 */
    uint16_t mH;

    /** 彩度 */
    uint8_t mS;
    
    /** 明度 */
    uint8_t mV;
};

#endif  // SPIKE_CPP_API_LIGHT_COLOR_HSV_DTO_H_
