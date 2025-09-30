#pragma once

#include "../../../common/utils/CommonDateTime.hpp"
#include "../ports/ClientAppearanceInterface.hpp"
#include "../ports/UiMealStateChangedPort.hpp"
#include "../ports/BrightnessControllerPort.hpp"
#include "../ports/UiBrightnessChangeRequestPort.hpp"
#include "../ports/ServerConnectionPort.hpp"


class EventHandlerTimeUpdatePort{
public:
    virtual ~EventHandlerTimeUpdatePort(){};
    virtual void updateTime(CommonDateTime time) = 0;
};

class EventHandler: public EventHandlerTimeUpdatePort, public UiMealStateChangedPort, public UiBrightnessChangeRequestPort {
public:
    EventHandler(BrightnessControllerPort* brightnessController = nullptr, ServerConnectionPort* serverConnection = nullptr):
        brightnessController(brightnessController), serverConnection(serverConnection){}

    void setClientAppearanceInterface(ClientAppearanceInterface* clientAppearanceInterface){
        this->clientAppearanceInterface = clientAppearanceInterface;
    }

    void setServerConnection(ServerConnectionPort* serverConnection){
        this->serverConnection = serverConnection;
    }

    void updateTime(CommonDateTime time){
        currentTime = time;
        clientAppearanceInterface->setCurrentTime(time);
    }

    void setTime(CommonDateTime time){
        updateTime(time);
    }

    void setBrightness(uint8_t percent){
        brightnessController->setBrightness(percent);
    }

    void mealStateChanged(MealType mealType, bool newState){
        clientAppearanceInterface->setMealStatus(mealType, newState, currentTime);

        MealEntity meal(mealType, newState, currentTime);
        serverConnection->updateMealStatus(meal);
    }
private:
    //DI
    ClientAppearanceInterface* clientAppearanceInterface = nullptr;
    ServerConnectionPort* serverConnection = nullptr;
    BrightnessControllerPort* brightnessController = nullptr;

    //state
    CommonDateTime currentTime;
};