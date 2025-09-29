#pragma once

#include "list"

#include "../../../common/model/DaysMeals.hpp"

class DaysMealsRepository{
public:
    virtual ~DaysMealsRepository(){};
    virtual int create(DaysMeals entity) = 0;
    virtual int getByDay(CommonDateTime day, DaysMeals* result) = 0;
    virtual int update(DaysMeals entity) = 0;
    virtual int remove(DaysMeals entity) = 0;
    virtual int getListWithDates(std::list<DaysMeals>* result) = 0;
};