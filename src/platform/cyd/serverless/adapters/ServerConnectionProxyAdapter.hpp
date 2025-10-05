#pragma once

#include "application/client/ports/ServerConnectionPort.hpp"
#include "application/server/eventHandler/EventHandler.hpp"

class ServerConnectionProxyAdapter: public ServerConnectionPort{
public:
    ServerConnectionProxyAdapter(ApplicationServer::EventHandler* serverEventHandler = nullptr) 
        : serverEventHandler(serverEventHandler){}

    void setServerEventHandler(ApplicationServer::EventHandler* serverEventHandler){
        this->serverEventHandler = serverEventHandler;
    }

    int updateMealStatus(MealEntity entity){
        return serverEventHandler->updateMealStatus(entity);
    };
    int getMealsOfTheDay(CommonDateTime day, DaysMeals* resultHandler){
        return serverEventHandler->getMealsOfTheDay(day, resultHandler);
    }
    int getCurrentTime(CommonDateTime* resultHandler){
        return serverEventHandler->getCurrentTime(resultHandler);
    }
    int setCurrentTime(CommonDateTime time){
        return serverEventHandler->setTime(time);
    }
private:
    ApplicationServer::EventHandler* serverEventHandler = nullptr;
};
