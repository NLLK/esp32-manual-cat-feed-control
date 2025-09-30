#pragma once

#include "../../../../application/client/ports/ServerConnectionPort.hpp"
#include "../../../../application/server/eventHandler/EventHandler.hpp"

class ServerConnectionProxyAdapter: public ServerConnectionPort{
public:
    ServerConnectionProxyAdapter(ApplicationServer::EventHandler* serverEventHandler = nullptr) 
        : serverEventHandler(serverEventHandler){}

    void setServerEventHanlder(ApplicationServer::EventHandler* serverEventHandler){
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
private:
    ApplicationServer::EventHandler* serverEventHandler = nullptr;
};
