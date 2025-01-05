//
// Button.h
//
// Copyright (c) 2025 Embedded Technology Software Design Robot Contest
//

#ifndef SPIKE_CPP_API_BUTTON_H_
#define SPIKE_CPP_API_BUTTON_H_

#include "dto/ButtonStatusDto.h"

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
     * ボタンが押されているかを確認する
     * @param pressed 押されているボタンのビットOR値（何も押されていなければ 0）を返す
     * @return -
     */
    ButtonStatusDto isPressed();
}; // class Button
}  // namespace spikeapi

#endif // !SPIKE_CPP_API_BUTTON_H_
