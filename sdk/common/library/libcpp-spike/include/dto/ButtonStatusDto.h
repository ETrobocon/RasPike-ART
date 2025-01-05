//
// ButtonStatusDto.h
//
// Copyright (c) 2025 Embedded Technology Software Design Robot Contest
//

#ifndef SPIKE_CPP_API_BUTTON_STATUS_DTO_H_
#define SPIKE_CPP_API_BUTTON_STATUS_DTO_H_

#include <pbio/button.h>

namespace spikeapi {
/**
 * ボタンの押下状態を表すDtoクラス
 */
class ButtonStatusDto
{
public:
    /**
     * コンストラクタ
     * @param -
     * @return -
     */
    ButtonStatusDto(bool left, bool center, bool right, bool bt) 
    : mLeft(left), mCenter(center), mRight(right), mBt(bt) {};

    /**
     * 左ボタンが押されているかを確認する
     * @param -
     * @return true:押されている/false:押されていない
     */
    bool isLeftPressed() const { 
        return mLeft; 
    } 
    
    /**
     * 中央ボタンが押されているかを確認する
     * @param -
     * @return true:押されている/false:押されていない
     */
    bool isCenterPressed() const { 
        return mCenter; 
    }
    
    /**
     * 右ボタンが押されているかを確認する
     * @param -
     * @return true:押されている/false:押されていない
     */
    bool isRightPressed() const { 
        return mRight; 
    } 
    
    /**
     * BTボタンが押されているかを確認する
     * @param -
     * @return true:押されている/false:押されていない
     */
    bool isBtPressed() const { 
        return mBt; 
    }

private: 
    /** 左ボタンの押下状態 */
    bool mLeft; 
    
    /** 中央ボタンの押下状態 */
    bool mCenter;
    
    /** 右ボタンの押下状態 */
    bool mRight;
    
    /** BTボタンの押下状態 */
    bool mBt;
}; // class ButtonStatusDto
}  // namespace spikeapi

#endif // !SPIKE_CPP_API_BUTTON_STATUS_DTO_H_
