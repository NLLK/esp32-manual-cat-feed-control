#pragma once

#include "../service/DaysMealsService.hpp"
#include "../ports/RTCContollerPort.hpp"

#include "middleware/logger/Logger.hpp"
#define CLASS_NAME_HEADER std::string("server.EventHandler: ")

namespace ApplicationServer{
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

class EventHandler : public EventHandlerTimeUpdatePort, public EventHandlerTimeSetPort{
public: 
    EventHandler(DaysMealsService* daysMealsService = nullptr, RTCControllerPort* rtc = nullptr) 
        : daysMealsService(daysMealsService), rtc(rtc){

    }

    void updateMealStatus(MealEntity entity){
        LOG.info(CLASS_NAME_HEADER + "updateMealStatus called: %s", entity.toString().c_str());
        daysMealsService->updateMealStatus(entity);
    }

    DaysMeals getMealsOfTheDay(CommonDateTime day){
        LOG.info(CLASS_NAME_HEADER + "getMealsOfTheDay called");
        return daysMealsService->getMealsOfTheDay(day);
    }
    CommonDateTime getCurrentTime(){
        LOG.info(CLASS_NAME_HEADER + "getCurrentTime called");
        return currentTime;
    }

    void updateTime(CommonDateTime time){
        LOG.info(CLASS_NAME_HEADER + "updateTime called");
        currentTime = time;
    }

    void setTime(CommonDateTime time){
        LOG.info(CLASS_NAME_HEADER + "setTime called");
        rtc->setCurrentTime(time);
        updateTime(time);
    }
    
private:
    //DI
    DaysMealsService* daysMealsService = nullptr;
    RTCControllerPort* rtc = nullptr;

    //state
    CommonDateTime currentTime;
};
};
