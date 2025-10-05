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
    virtual int setTime(CommonDateTime time) = 0;
};

class EventHandler : public EventHandlerTimeUpdatePort, public EventHandlerTimeSetPort{
public: 
    EventHandler(DaysMealsService* daysMealsService = nullptr, RTCControllerPort* rtc = nullptr) 
        : daysMealsService(daysMealsService), rtc(rtc){

    }

    int updateMealStatus(MealEntity entity){
        LOG.info(CLASS_NAME_HEADER + "updateMealStatus called: %s", entity.toString().c_str());
        daysMealsService->updateMealStatus(entity);

        return 0;
    }

    int getMealsOfTheDay(CommonDateTime day, DaysMeals* resultHandler){
        LOG.info(CLASS_NAME_HEADER + "getMealsOfTheDay called");

        *resultHandler = daysMealsService->getMealsOfTheDay(day); 

        return 0;
    }
    int getCurrentTime(CommonDateTime* resultHandler){
        LOG.info(CLASS_NAME_HEADER + "getCurrentTime called");
        *resultHandler = currentTime;
        return 0;
    }

    void updateTime(CommonDateTime time){
        LOG.info(CLASS_NAME_HEADER + "updateTime called");
        currentTime = time;
    }

    int setTime(CommonDateTime time){
        LOG.info(CLASS_NAME_HEADER + "setTime called");
        rtc->setCurrentTime(time);
        updateTime(time);

        return 0;
    }
    
private:
    //DI
    DaysMealsService* daysMealsService = nullptr;
    RTCControllerPort* rtc = nullptr;

    //state
    CommonDateTime currentTime;
};
};
