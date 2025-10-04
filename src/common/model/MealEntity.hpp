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

    std::string toString(){
        char buffer[sizeof("MealEntity(BREAKFAST, 2025-01-01 11:22, false\0)")] = {'\0',};
        sprintf(buffer, "MealEntity(%s, %s, %s)", MealTypeStringMapper::map(type).c_str(), time.getDateTimeString().c_str(), status ? "true" : "false");

        return std::string(buffer);
    }

private:
    MealType type;
    bool status;
    CommonDateTime time;
};