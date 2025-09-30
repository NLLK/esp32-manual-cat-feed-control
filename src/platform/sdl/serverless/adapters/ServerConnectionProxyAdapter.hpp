#pragma once

#include "../../../../application/client/ports/ServerConnectionPort.hpp"
#include "../../../../application/server/eventHandler/EventHandler.hpp"

class ServerConnectionProxyAdapter: public ServerConnectionPort{
public:
    ServerConnectionProxyAdapter(ApplicationServer::EventHandler* serverEventHandler = nullptr) 
        : serverEventHandler(serverEventHandler){}

    void setServerEventHandler(ApplicationServer::EventHandler* serverEventHandler){
        this->serverEventHandler = serverEventHandler;
    }

    void updateMealStatus(MealEntity entity){
        serverEventHandler->updateMealStatus(entity);
    };
    DaysMeals getMealsOfTheDay(CommonDateTime day){
        return serverEventHandler->getMealsOfTheDay(day);
    }
    CommonDateTime getCurrentTime(){
        return serverEventHandler->getCurrentTime();
    }
    void setCurrentTime(CommonDateTime time){
        serverEventHandler->setTime(time);
    }   

private:
    ApplicationServer::EventHandler* serverEventHandler = nullptr;
};
