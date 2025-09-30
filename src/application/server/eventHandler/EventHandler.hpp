#pragma once

#include "../service/DaysMealsService.hpp"
#include "../ports/RTCContollerPort.hpp"

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
        daysMealsService->updateMealStatus(entity);
    }

    DaysMeals getMealsOfTheDay(CommonDateTime day){
        return daysMealsService->getMealsOfTheDay(day);
    }
    CommonDateTime getCurrentTime(){
        return currentTime;
    }

    void updateTime(CommonDateTime time){
        currentTime = time;
    }

    void setTime(CommonDateTime time){
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
