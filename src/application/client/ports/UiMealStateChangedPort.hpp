#pragma once 

#include "common/constants/MealType.h"

class UiMealStateChangedPort{
public:
    virtual ~UiMealStateChangedPort(){}
    virtual void mealStateChanged(MealType mealType, bool newState) = 0;
}; 