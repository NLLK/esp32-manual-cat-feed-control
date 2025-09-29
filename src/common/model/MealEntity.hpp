#pragma once

#include "../constants/MealType.h"
#include "../utils/CommonDateTime.hpp"

class MealEntity{
public:
    MealEntity(MealType type, bool status, CommonDateTime time){}

    bool operator< (const MealEntity& e) const {
        return (int)type < (int)e.type;
    }

    CommonDateTime getDateTime(){
        return time;
    }

private:
    MealType type;
    bool status;
    CommonDateTime time;
};