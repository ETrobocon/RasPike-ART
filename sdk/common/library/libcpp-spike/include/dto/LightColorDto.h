//
// LightColorDto.h
//
// Copyright (c) 2025 Embedded Technology Software Design Robot Contest
//

#ifndef SPIKE_CPP_API_LIGHT_COLOR_DTO_H_
#define SPIKE_CPP_API_LIGHT_COLOR_DTO_H_

#include <pbio/color.h>

/**
 * ライトカラーDtoクラス
 */
class LightColorDto {
public:
    enum class Name { 
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

    /** 
     * コンストラクタ 
     */ 
    LightColorDto(Name color) : mColor(color) {}

    /** 
     * 色の名前を取得する 
     * @return 色の名前 
     */ 
    Name getColor() const { 
        return mColor; 
    }

    /** 
     * 色の名前を設定する 
     * @param color 色の名前 
     */ 
    void setColor(Name color) { 
        mColor = color; 
    }

private:
    /** 色 */
    Name mColor;
};

#endif  // SPIKE_CPP_API_LIGHT_COLOR_DTO_H_
