#pragma once

#include "common/model/MealEntity.hpp"
#include "common/model/DaysMeals.hpp"

class ServerConnectionPort{
public:
    virtual ~ServerConnectionPort(){};
    virtual int updateMealStatus(MealEntity entity) = 0;
    virtual int getMealsOfTheDay(CommonDateTime day, DaysMeals* resultHandler) = 0;
    virtual int getCurrentTime(CommonDateTime* resultHandler) = 0;
    virtual int setCurrentTime(CommonDateTime time) = 0;
};