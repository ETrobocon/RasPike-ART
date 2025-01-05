//
// AccelerationDto.h
//
// Copyright (c) 2025 Embedded Technology Software Design Robot Contest
//

#ifndef SPIKE_CPP_API_ANGULAR_VELOCITY_DTO_H_
#define SPIKE_CPP_API_ANGULAR_VELOCITY_DTO_H_

namespace spikeapi {
/**
 * IMUの角速度を表すDtoクラス
 */
class AngularVelocityDto
{
public:
    /**
     * コンストラクタ
     * @param -
     * @return -
     */
    AngularVelocityDto(float x, float y, float z) 
    : mX(x), mY(y), mZ(z) {};

    /**
     * X軸の角速度を取得する
     * @param -
     * @return X軸の角速度
     */
    float getX() const { 
        return mX; 
    }
    
    /**
     * Y軸の角速度を取得する
     * @param -
     * @return Y軸の角速度
     */
    float getY() const { 
        return mY; 
    }

    /**
     * Z軸の角速度を取得する
     * @param -
     * @return Z軸の角速度
     */
    float getZ() const { 
        return mZ; 
    }
    
private: 
    /** X軸の角速度 */
    float mX; 
    
    /** Y軸の角速度 */
    float mY;
    
    /** Z軸の角速度 */
    float mZ;

}; // class AngularVelocityDto
}  // namespace spikeapi

#endif // !SPIKE_CPP_API_ANGULAR_VELOCITY_DTO_H_
