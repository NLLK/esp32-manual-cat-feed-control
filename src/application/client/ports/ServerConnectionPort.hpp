#pragma once

#include "common/model/MealEntity.hpp"
#include "common/model/DaysMeals.hpp"

class ServerConnectionPort{
public:
    virtual ~ServerConnectionPort(){};
    virtual void updateMealStatus(MealEntity entity) = 0;
    virtual DaysMeals getMealsOfTheDay(CommonDateTime day) = 0;
    virtual CommonDateTime getCurrentTime() = 0;
    virtual void setCurrentTime(CommonDateTime time) = 0;
};