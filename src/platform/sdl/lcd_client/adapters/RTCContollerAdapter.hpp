#pragma once

#include "stdio.h"

#include "../../../../application/client/ports/RTCContollerPort.hpp"

class RTCContollerAdapter : public RTCControllerPort{
public: 
    RTCContollerAdapter(){}

    void setCurrentTime(CommonDateTime time) override {
        printf("set current time into rtc to %s\n", time.getTimeString().c_str());
        fflush(stdout);
    }
};
