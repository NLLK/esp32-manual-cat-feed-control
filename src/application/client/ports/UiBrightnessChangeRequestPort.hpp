#pragma once

#include "stdint.h"

class UiBrightnessChangeRequestPort{
public:
    virtual ~UiBrightnessChangeRequestPort(){};
    virtual void setBrightness(uint8_t percent) = 0;
};