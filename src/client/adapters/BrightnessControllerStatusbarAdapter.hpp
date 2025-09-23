#ifndef CLIENT_ADAPTERS_BRIGHTNESSCONTROLLERSTATUSBARADAPTER_HPP
#define CLIENT_ADAPTERS_BRIGHTNESSCONTROLLERSTATUSBARADAPTER_HPP

#include "app_hal.h"

#include "../ui/components/Statusbar.hpp"

class BrightnessControllerStatusbarAdapter: public StatusbarPort{
public:
    BrightnessControllerStatusbarAdapter(){}
    void clickedAtX(uint8_t x) override{
        hal_setBrighness(x);
    }
};

#endif