//
// Button.cpp
//
// Copyright (c) 2025 Embedded Technology Software Design Robot Contest
//

extern "C" {
#include <spike/hub/button.h>
}

#include "Button.h"

using namespace spikeapi;

bool Button::isLeftPressed(void)
{
    hub_button_t pressed;
    pbio_error_t err = hub_button_is_pressed(&pressed); 
    /* TODO:error handling */
    return static_cast<bool>(pressed & HUB_BUTTON_LEFT);
}

bool Button::isCenterPressed(void)
{
    hub_button_t pressed;
    pbio_error_t err = hub_button_is_pressed(&pressed); 
    /* TODO:error handling */
    return static_cast<bool>(pressed & HUB_BUTTON_CENTER);
}

bool Button::isRightPressed(void)
{
    hub_button_t pressed;
    pbio_error_t err = hub_button_is_pressed(&pressed); 
    /* TODO:error handling */
    return static_cast<bool>(pressed & HUB_BUTTON_RIGHT);
}

bool Button::isBluetoothPressed(void)
{
    hub_button_t pressed;
    pbio_error_t err = hub_button_is_pressed(&pressed); 
    /* TODO:error handling */
    return static_cast<bool>(pressed & HUB_BUTTON_BT);
}
