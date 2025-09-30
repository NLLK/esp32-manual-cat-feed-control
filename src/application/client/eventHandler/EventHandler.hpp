#pragma once

#include "../../../common/utils/CommonDateTime.hpp"
#include "../ports/ClientAppearanceInterface.hpp"
#include "../ports/UiMealStateChangedPort.hpp"
#include "../ports/BrightnessControllerPort.hpp"
#include "../ports/UiBrightnessChangeRequestPort.hpp"

class EventHandlerTimeUpdatePort{
public:
    virtual ~EventHandlerTimeUpdatePort(){};
    virtual void updateTime(CommonDateTime time) = 0;
};

class EventHandler: public EventHandlerTimeUpdatePort, public UiMealStateChangedPort, public UiBrightnessChangeRequestPort {
public:
    EventHandler(BrightnessControllerPort* brightnessController = nullptr):
        brightnessController(brightnessController){}

    void setClientAppearanceInterface(ClientAppearanceInterface* clientAppearanceInterface){
        this->clientAppearanceInterface = clientAppearanceInterface;
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
    }
private:
    ClientAppearanceInterface* clientAppearanceInterface = nullptr;
    CommonDateTime currentTime;

    BrightnessControllerPort* brightnessController = nullptr;
};