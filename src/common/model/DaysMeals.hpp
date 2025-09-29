#pragma once

#include "set"

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
            meals.insert(meal);
        }
    }

    const std::set<MealEntity> getAll(){
        return meals;
    }

    CommonDateTime getDay(){
        return day;
    }

private:
    std::set<MealEntity> meals;
    CommonDateTime day;
};