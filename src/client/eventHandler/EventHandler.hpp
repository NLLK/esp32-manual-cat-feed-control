#ifndef CLIENT_EVENTHANDLER_EVENTHANDLER_HPP
#define CLIENT_EVENTHANDLER_EVENTHANDLER_HPP

#include "../../common/utils/CommonDateTime.hpp"
#include "../ports/ClientAppearanceInterface.hpp"
#include "../ports/UiMealStateChangedPort.hpp"

class EventHandlerTimeUpdatePort{
public:
    virtual ~EventHandlerTimeUpdatePort(){};
    virtual void setTime(CommonDateTime time) = 0;
};

// class EventHandlerPort{
// public:
//     virtual ~EventHandlerTimeUpdateInterface(){};
//     virtual void setTime(CommonDateTime time) = 0;
// };

class EventHandler: public EventHandlerTimeUpdatePort, public UiMealStateChangedPort {
public:
    EventHandler(){}

    void setClientAppearanceInterface(ClientAppearanceInterface* clientAppearanceInterface){
        this->clientAppearanceInterface = clientAppearanceInterface;
    }

    void setTime(CommonDateTime time){
        currentTime = time;
        clientAppearanceInterface->setCurrentTime(time);
    }

    void mealStateChanged(MealType mealType, bool newState){
        clientAppearanceInterface->setMealStatus(mealType, newState, currentTime);
    }
private:
    ClientAppearanceInterface* clientAppearanceInterface = nullptr;
    CommonDateTime currentTime;
};

#endif