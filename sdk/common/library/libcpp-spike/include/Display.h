//
// Display.h
//
// Copyright (c) 2025 Embedded Technology Software Design Robot Contest
//

#ifndef SPIKE_CPP_API_DISPLAY_H_ 
#define SPIKE_CPP_API_DISPLAY_H_

#include <cstdint>
extern "C" {
#include <hub/display.h>
}

namespace spikeapi {
  /**
   * SPIKE Display クラス
   */

  class Display
  {
  public:
    enum class EOrientation {
        TOP = PBIO_SIDE_TOP,
	LEFT = PBIO_SIDE_LEFT,
	RIGHT = PBIO_SIDE_RIGHT,
	BOTTOM = PBIO_SIDE_BOTTOM
   };

    /**
     * コンストラクタ
     */
    Display(void) = default;

    /**
     * ハブ内蔵ディスプレイの表示方向を設定する
     * param up 表示方向の上側
     * return -
     */
    void setOrientation(EOrientation up) {
      hub_display_orientation(static_cast<uint8_t>(up));
    }

    /**
     * ハブ内蔵ディスプレイを消灯する
     * param  -
     * return -
     */
    void off() {
      hub_display_off();
    }

    /**
     * 指定した輝度で指定したピクセルを点灯する
     * param row(int) 一番上側を0とした行番号
     * param column(int) 一番左側を0とした列番号
     * param brightness(%) ピクセルの輝度
     * return -
     */
    void setOnePixel(uint8_t row, uint8_t column, uint8_t brightness)
    {
      hub_display_pixel(row,column,brightness);
    }

    /**
     * イメージの行列(5x5)で表示する
     * param image 輝度の行列。２次元配列でも良い
     * return -
     */
    void setImage(uint8_t *image)
    {
      hub_display_image(image);
    }

    /**
     * 数字を表示する
     * param num -99〜99 負の符号はディスプレイの中央の薄い点として表現される
     * return -
     */
    void showNumber(const int8_t num)
    {
      hub_display_number(num);
    }

    /**
     * 1文字あるいは記号を表示する
     * param c 
     * return -
     */
    void showChar(const char c)
    {
      hub_display_char(c);
    }

    /**
     * 文字列を表示する。一文字ずつ一定時間で点灯・消灯する
     * param text 表示する文字列
     * param on 表示される時間(ms)
     * param off 消灯される時間(ms)
     * return -
     */
    void showText(const char* text, uint32_t on, uint32_t off)
    {
      hub_display_text(text,on,off);
    }
    
    /**
     * 文字列をスクロールして表示する。
     * param text 表示する文字列
     * param delay スクロールの感覚(ms)
     * return -
     */
    void scrollText(const char* text, uint32_t delay)
    {
      hub_display_text_scroll(text,delay);
    }
  };
}
#endif //SPIKE_CPP_API_DISPLAY_H_ 
