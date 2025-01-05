//
// AccelerationDto.h
//
// Copyright (c) 2025 Embedded Technology Software Design Robot Contest
//

#ifndef SPIKE_CPP_API_ACCELERATION_DTO_H_
#define SPIKE_CPP_API_ACCELERATION_DTO_H_

#include <pbio/button.h>

namespace spikeapi {
/**
 * IMUの加速度を表すDtoクラス
 */
class AccelerationDto
{
public:
    /**
     * コンストラクタ
     * @param -
     * @return -
     */
    AccelerationDto(float x, float y, float z) 
    : mX(x), mY(y), mZ(z) {};

    /**
     * X軸の加速度を取得する
     * @param -
     * @return X軸の加速度
     */
    float getX() const { 
        return mX; 
    }
    
    /**
     * Y軸の加速度を取得する
     * @param -
     * @return Y軸の加速度
     */
    float getY() const { 
        return mY; 
    }

    /**
     * Z軸の加速度を取得する
     * @param -
     * @return Z軸の加速度
     */
    float getZ() const { 
        return mZ; 
    }
    
private: 
    /** X軸の加速度 */
    float mX; 
    
    /** Y軸の加速度 */
    float mY;
    
    /** Z軸の加速度 */
    float mZ;

}; // class AccelerationDto
}  // namespace spikeapi

#endif // !SPIKE_CPP_API_ACCELERATION_DTO_H_
