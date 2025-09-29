#pragma once

#include "stdint.h"

class BrightnessControllerPort{
public:
    virtual ~BrightnessControllerPort(){}
    virtual void setBrightness(uint8_t percents) = 0;
};