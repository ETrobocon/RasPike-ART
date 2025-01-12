//
// Light.cpp
//
// Copyright (c) 2025 Embedded Technology Software Design Robot Contest
//

#include "Light.h"

using namespace spikeapi;

void Light::turnOnHSV(Light::HSV &colorHSV)
{
  pbio_color_hsv_t hsv = {colorHSV.h, colorHSV.s, colorHSV.v}; 
  hub_light_on_hsv(&hsv);
}

void Light::turnOnColor(Light::EColor color)
{
  pbio_color_t c = (pbio_color_t)color;
  hub_light_on_color(c); 
}
