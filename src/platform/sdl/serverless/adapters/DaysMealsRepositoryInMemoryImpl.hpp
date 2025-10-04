#pragma once

#include "chrono"

#include "application/server/repository/DaysMealsRepository.hpp"

class DaysMealsRepositoryInMemoryImpl: public DaysMealsRepository{
public:
    DaysMealsRepositoryInMemoryImpl(){
        auto now = std::chrono::system_clock::now();
        std::time_t time = std::chrono::system_clock::to_time_t(now);
        std::tm local_time = *std::localtime(&time);

        CommonDateTime dt(local_time.tm_year-1900, local_time.tm_mon + 1, local_time.tm_mday, local_time.tm_hour, local_time.tm_min, local_time.tm_sec);
        
        DaysMeals meals;
        
        for (int i = 0; i < 2; i++){
            dt.hours = 8 + i*4;

            MealEntity entity(MealType::BREAKFAST, true, dt);

            meals.append(entity);
        }      
        mem.push_back(meals);  
    }

    int create(DaysMeals entity){
        mem.push_back(entity);
        return 0;
    }
    int getByDay(CommonDateTime day, DaysMeals* result){
        for (DaysMeals value: mem){
            if (value.getDay().isTheSameDay(day)){
                *result = value; 
                return 1;
            }
        }
        return -1;
    }
    int update(DaysMeals entity){
        remove(entity);
        create(entity);
        return 0;
    }
    int remove(DaysMeals entity) {
        CommonDateTime day = entity.getDay();

        mem.remove_if([day](DaysMeals value) {
            return value.getDay().isTheSameDay(day); 
        });
        return -1;
    }
    int getListWithDates(std::list<DaysMeals>* result){
        *result = mem;
        return -1;
    }
private:
    std::list<DaysMeals> mem;
};