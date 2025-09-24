#ifndef CLIENT_EVENTHANDLER_EVENTHANDLER_HPP
#define CLIENT_EVENTHANDLER_EVENTHANDLER_HPP

#include "../../common/utils/CommonDateTime.hpp"
#include "../ports/ClientAppearanceInterface.hpp"

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

class EventHandler: public EventHandlerTimeUpdatePort{
public:
    EventHandler(){}

    void setClientAppearanceInterface(ClientAppearanceInterface* clientAppearanceInterface){
        this->clientAppearanceInterface = clientAppearanceInterface;
    }

    void setTime(CommonDateTime time){
        currentTime = time;
        clientAppearanceInterface->setCurrentTime(time);
    }
private:
    ClientAppearanceInterface* clientAppearanceInterface = nullptr;
    CommonDateTime currentTime;
};

#endif