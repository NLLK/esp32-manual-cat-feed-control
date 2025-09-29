#pragma once

#include "stdio.h"

#include "../../../../application/client/ports/BrightnessControllerPort.hpp"

class BrightnessControllerAdapter: public BrightnessControllerPort{
public:
    BrightnessControllerAdapter(){}
    
    void setBrightness(uint8_t percents) override{
        printf("change brightness to %d%%\n", percents);
        fflush(stdout);
    }
};
