#pragma once

#include "../../../../application/server/repository/DaysMealsRepository.hpp"

class DaysMealsRepositoryImpl: public DaysMealsRepository{
public:
    int create(DaysMeals entity){
        return -1;
    }
    int getByDay(CommonDateTime day, DaysMeals* result){
        return -1;
    }
    int update(DaysMeals entity){
        return -1;
    }
    int remove(DaysMeals entity){
        return -1;
    }
    int getListWithDates(std::list<DaysMeals>* result){
        return -1;
    }
};