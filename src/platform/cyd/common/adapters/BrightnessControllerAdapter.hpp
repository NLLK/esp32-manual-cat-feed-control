#pragma once

#include "application/client/ports/BrightnessControllerPort.hpp"

#include <LVGL_CYD.h>

class BrightnessControllerAdapter: public BrightnessControllerPort{
public:
    BrightnessControllerAdapter(){}
    
    void setBrightness(uint8_t percents) override{
        if (percents < 10){
            percents = 10;
        }
        LVGL_CYD::backlight(255*percents/100);
    }
};
