#ifndef CLIENT_PORTS_UIMEALSTATECHANGEDPORT_HPP
#define CLIENT_PORTS_UIMEALSTATECHANGEDPORT_HPP

#include "../../common/constants/MealType.h"

class UiMealStateChangedPort{
public:
    virtual ~UiMealStateChangedPort(){}
    virtual void mealStateChanged(MealType mealType, bool newState) = 0;
}; 
#endif