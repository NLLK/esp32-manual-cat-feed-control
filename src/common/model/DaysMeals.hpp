#pragma once

#include "map"

#include "./MealEntity.hpp"

class DaysMeals{
public: 
    DaysMeals(){}

    void append(MealEntity meal){
        if (day.isEmpty()){
            if (!meal.getDateTime().isEmpty()){
                day = meal.getDateTime();
            }
        }

        if (meal.getDateTime().isTheSameDay(day)){
            meals[meal.getType()] = meal;
        }
    }

    const std::map<MealType, MealEntity> getAll(){
        return meals;
    }

    CommonDateTime getDay(){
        return day;
    }

    void setDay(CommonDateTime day){
        this->day = day;
    }

private:
    std::map<MealType,MealEntity> meals;
    CommonDateTime day;
};