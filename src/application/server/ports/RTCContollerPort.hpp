#pragma once

#include "common/utils/CommonDateTime.hpp"

class RTCControllerPort{
public: 
    virtual ~RTCControllerPort(){}
    virtual void setCurrentTime(CommonDateTime time) = 0;
};