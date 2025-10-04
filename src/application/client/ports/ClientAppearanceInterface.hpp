#ifndef CLIENT_PORTS_CLIENTAPPEARANCEINTERFACE_HPP
#define CLIENT_PORTS_CLIENTAPPEARANCEINTERFACE_HPP

#include "common/constants/MealType.h"
#include "common/utils/CommonDateTime.hpp"

class ClientAppearanceInterface{
public:
    virtual ~ClientAppearanceInterface(){};
    virtual void setCurrentTime(CommonDateTime time) = 0;
    virtual void setMealStatus(MealType type, bool status, CommonDateTime time) = 0;
    virtual void setBatteryPercentage(unsigned short prc) = 0;
};

#endif