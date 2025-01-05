//
// Button.cpp
//
// Copyright (c) 2025 Embedded Technology Software Design Robot Contest
//

#include <spike/hub/button.h>

#include "Button.h"

using namespace spikeapi;

ButtonStatusDto Button::isPressed(void)
{
    hub_button_t pressed; 
    pbio_error_t err = hub_button_is_pressed(&pressed); 
    return ButtonStatusDto( 
        static_cast<bool>(pressed & HUB_BUTTON_LEFT), 
        static_cast<bool>(pressed & HUB_BUTTON_CENTER), 
        static_cast<bool>(pressed & HUB_BUTTON_RIGHT), 
        static_cast<bool>(pressed & HUB_BUTTON_BT)
    );
}

