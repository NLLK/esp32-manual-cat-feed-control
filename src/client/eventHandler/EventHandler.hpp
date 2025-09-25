#ifndef CLIENT_EVENTHANDLER_EVENTHANDLER_HPP
#define CLIENT_EVENTHANDLER_EVENTHANDLER_HPP

#include "../../common/utils/CommonDateTime.hpp"
#include "../ports/ClientAppearanceInterface.hpp"
#include "../ports/UiMealStateChangedPort.hpp"

#include "app_hal.h"

class EventHandlerTimeUpdatePort{
public:
    virtual ~EventHandlerTimeUpdatePort(){};
    virtual void updateTime(CommonDateTime time) = 0;
};

class EventHandlerTimeSetPort{
public:
    virtual ~EventHandlerTimeSetPort(){};
    virtual void setTime(CommonDateTime time) = 0;
};

class EventHandler: public EventHandlerTimeUpdatePort, public EventHandlerTimeSetPort, public UiMealStateChangedPort {
public:
    EventHandler(){}

    void setClientAppearanceInterface(ClientAppearanceInterface* clientAppearanceInterface){
        this->clientAppearanceInterface = clientAppearanceInterface;
    }

    void updateTime(CommonDateTime time){
        currentTime = time;
        clientAppearanceInterface->setCurrentTime(time);
    }

    void setTime(CommonDateTime time){
        hal_setTimeToRtc(time);
        updateTime(time);
    }

    void mealStateChanged(MealType mealType, bool newState){
        clientAppearanceInterface->setMealStatus(mealType, newState, currentTime);
    }
private:
    ClientAppearanceInterface* clientAppearanceInterface = nullptr;
    CommonDateTime currentTime;
};

#endif