#pragma once

#include "application/client/ports/BrightnessControllerPort.hpp"

#include <LVGL_CYD.h>

class BrightnessControllerAdapter: public BrightnessControllerPort{
public:
    BrightnessControllerAdapter(){}
    
    void setBrightness(uint8_t percents) override{
        if (percents < 2){
            percents = 2;
        }
        LVGL_CYD::backlight(255*percents/100);
    }
};
