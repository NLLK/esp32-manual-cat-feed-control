#pragma once

#include "../../../common/utils/CommonDateTime.hpp"
#include "../../../common/constants/MealType.h"

#include "../service/DaysMealsService.hpp"

class EventHandler{
public: 
    EventHandler(DaysMealsService* daysMealsService = nullptr) : daysMealsService(daysMealsService){

    }

    void updateMealStatus(MealType type, bool status, CommonDateTime time){
        MealEntity entity(type, status, time);

        daysMealsService->updateMealStatus(entity);
    }
private:
    DaysMealsService* daysMealsService = nullptr;
};