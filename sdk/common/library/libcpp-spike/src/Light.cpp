//
// Light.cpp
//
// Copyright (c) 2025 Embedded Technology Software Design Robot Contest
//

#include "Light.h"

using namespace spikeapi;

void Light::turnOnHSV(ColorHSVDto &colorHSV)
{
    pbio_color_hsv_t hsv = {colorHSV.getHue(), colorHSV.getSaturation(), colorHSV.getValue()}; 
    hub_light_on_hsv(&hsv);
}

void Light::turnOnColor(LightColorDto color)
{
    pbio_color_t c = {(pbio_color_t)color.getColor()}; 
    hub_light_on_color(c); 
}
