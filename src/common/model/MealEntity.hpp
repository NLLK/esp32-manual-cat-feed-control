#pragma once

#include "../constants/MealType.h"
#include "../utils/CommonDateTime.hpp"

class MealEntity{
public:

    MealEntity(){}

    MealEntity(MealType type, bool status, CommonDateTime time) 
    : type(type), status(status), time(time){}

    bool operator< (const MealEntity& e) const {
        return (int)type < (int)e.type;
    }

    CommonDateTime getDateTime(){
        return time;
    }

    bool getStatus(){
        return status;
    }

    MealType getType(){
        return type;
    }

private:
    MealType type;
    bool status;
    CommonDateTime time;
};