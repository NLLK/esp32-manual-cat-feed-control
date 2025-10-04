#pragma once

#include "../repository/DaysMealsRepository.hpp"

#include "common/model/MealEntity.hpp"

class DaysMealsService{
public: 
    DaysMealsService(DaysMealsRepository* daysMealsRepository = nullptr) : daysMealsRepository(daysMealsRepository){}

    int updateMealStatus(MealEntity meal){
        std::list<DaysMeals> mealsDates;
        daysMealsRepository->getListWithDates(&mealsDates);

        bool foundInList = false;
        DaysMeals foundDate = findDateInList(&mealsDates, meal.getDateTime(), &foundInList);

        foundDate.append(meal);
        
        if (!foundInList){
            daysMealsRepository->create(foundDate);
        }else{
            daysMealsRepository->update(foundDate);
        }

        return 0;
    }

    DaysMeals getMealsOfTheDay(CommonDateTime day){
        DaysMeals result;

        int err = daysMealsRepository->getByDay(day, &result);

        return result;
    }

private:
    DaysMealsRepository* daysMealsRepository = nullptr;

private:
    DaysMeals findDateInList(std::list<DaysMeals>* mealsDates, CommonDateTime dateToFind, bool* isFound){
        for (DaysMeals meal: *mealsDates){
            if (meal.getDay().isTheSameDay(dateToFind)){
                *isFound = true; 
                return meal;
            }
        }
        *isFound = false;
        return DaysMeals();
    }
};