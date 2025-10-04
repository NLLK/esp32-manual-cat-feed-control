#pragma once

#include "common/utils/CommonDateTime.hpp"
#include "../ports/ClientAppearanceInterface.hpp"
#include "../ports/UiMealStateChangedPort.hpp"
#include "../ports/BrightnessControllerPort.hpp"
#include "../ports/UiBrightnessChangeRequestPort.hpp"
#include "../ports/ServerConnectionPort.hpp"

#include "middleware/logger/Logger.hpp"
#define CLASS_NAME_HEADER std::string("client.EventHandler: ")

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
        LOG.info(CLASS_NAME_HEADER + "updateTime called: %s", time.getDateTimeString().c_str());
        currentTime = time;
        clientAppearanceInterface->setCurrentTime(time);
    }

    void setBrightness(uint8_t percent){
        LOG.info(CLASS_NAME_HEADER + "setBrightness");
        brightnessController->setBrightness(percent);
    }

    void mealStateChanged(MealType mealType, bool newState){
        LOG.info(CLASS_NAME_HEADER + "mealStateChanged called: %s %d", MealTypeStringMapper::map(mealType).c_str(), newState);
        clientAppearanceInterface->setMealStatus(mealType, newState, currentTime);

        MealEntity meal(mealType, newState, currentTime);
        LOG.debug(CLASS_NAME_HEADER + "mealStateChanged created meal: %s", meal.toString().c_str());

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