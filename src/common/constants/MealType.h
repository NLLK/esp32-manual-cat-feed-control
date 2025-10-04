#ifndef CLIENT_UI_CONSTANTS_MEALTYPE
#define CLIENT_UI_CONSTANTS_MEALTYPE

#include "string.h"

enum class MealType{
    BREAKFAST,
    LUNCH,
    DINNER,
    DINNER2
};

class MealTypeToString{
public:
    static std::string map(MealType mealType){
        switch(mealType){
            case MealType::BREAKFAST: return "BREAKFAST";
            case MealType::LUNCH: return "LUNCH";
            case MealType::DINNER: return "DINNER";
            case MealType::DINNER2: return "DINNER2";
            default: return "ERROR";
        }
    }
};

#endif