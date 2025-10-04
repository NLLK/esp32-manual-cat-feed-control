#pragma once

#include "../repository/DaysMealsRepository.hpp"

#include "common/model/MealEntity.hpp"

#include "middleware/logger/Logger.hpp"
#define CLASS_NAME_HEADER std::string("server.DaysMealsService: ")

class DaysMealsService{
public: 
    DaysMealsService(DaysMealsRepository* daysMealsRepository = nullptr) : daysMealsRepository(daysMealsRepository){}

    int updateMealStatus(MealEntity meal){
        LOG.info(CLASS_NAME_HEADER + "updateMealStatus called: %s", meal.toString().c_str());

        DaysMeals daysMeal;
        int res = daysMealsRepository->getByDay(meal.getDateTime(), &daysMeal);

        daysMeal.append(meal);

        if (res == 0){
            daysMealsRepository->create(daysMeal);
        }else if (res > 0){
            daysMealsRepository->update(daysMeal);
            res = 0;
        }else{
            res = -1;
        }

        LOG.info(CLASS_NAME_HEADER + "updateMealStatus returns: %d", res);
        return res;
    }

    DaysMeals getMealsOfTheDay(CommonDateTime day){
        DaysMeals result;

        int err = daysMealsRepository->getByDay(day, &result);

        return result;
    }

private:
    DaysMealsRepository* daysMealsRepository = nullptr;

};