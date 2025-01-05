//
// Button.h
//
// Copyright (c) 2025 Embedded Technology Software Design Robot Contest
//

#ifndef SPIKE_CPP_API_BUTTON_H_
#define SPIKE_CPP_API_BUTTON_H_

namespace spikeapi {
/**
 * SPIKE ボタンクラス
 */
class Button
{
public:
    /**
     * コンストラクタ
     * @param -
     * @return -
     */
    Button(void) = default;

    /**
     * LEFTボタンが押されているかを確認する
     * @param -
     * @return -
     */
   bool isLeftPressed();
  
    /**
     * CENTERボタンが押されているかを確認する
     * @param -
     * @return -
     */
   bool isCenterPressed();

    /**
     * RIGHTボタンが押されているかを確認する
     * @param -
     * @return -
     */
   bool isRightPressed();

    /**
     * BRUETOOTHボタンが押されているかを確認する
     * @param -
     * @return -
     */
   bool isBluetoothPressed();

  
}; // class Button
}  // namespace spikeapi

#endif // !SPIKE_CPP_API_BUTTON_H_
