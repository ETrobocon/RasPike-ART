//
// Button.cpp
//
// Copyright (c) 2025 Embedded Technology Software Design Robot Contest
//

extern "C" {
#include <pbio/button.h>
#include <pbio/error.h>
}

#include "IMU.h"

using namespace spikeapi;

void IMU::getAcceleration(IMU::Acceleration &accel)
{
    float ac[3];
    hub_imu_get_acceleration(ac);
    accel.x = ac[0];
    accel.y = ac[1];
    accel.z = ac[2];
}

void IMU::getAngularVelocity(IMU::AngularVelocity &avel)
{
    float av[3];
    hub_imu_get_angular_velocity(av);
    avel.x = av[0];
    avel.y = av[1];
    avel.z = av[2];
}

