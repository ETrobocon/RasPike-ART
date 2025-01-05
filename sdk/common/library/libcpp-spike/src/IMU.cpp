//
// Button.cpp
//
// Copyright (c) 2025 Embedded Technology Software Design Robot Contest
//

#include <pbio/button.h>
#include <pbio/error.h>

#include "IMU.h"

using namespace spikeapi;

AccelerationDto IMU::getAcceleration(void)
{
    float accel[3];
    hub_imu_get_acceleration(accel);
    return AccelerationDto( 
        accel[0], 
        accel[1], 
        accel[2]
    );
}

AngularVelocityDto IMU::getAngularVelocity(void)
{
    float accel[3];
    hub_imu_get_angular_velocity(accel);
    return AngularVelocityDto( 
        accel[0], 
        accel[1], 
        accel[2]
    );
}

