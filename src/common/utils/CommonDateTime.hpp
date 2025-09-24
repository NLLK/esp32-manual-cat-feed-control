#ifndef COMMON_UTILS_COMMONDATETIME_HPP
#define COMMON_UTILS_COMMONDATETIME_HPP

#include "stdint.h"
#include <string>

class CommonDateTime {
public:
    CommonDateTime(uint8_t yearFrom2000 = 0, uint8_t month = 0, uint8_t day = 0, uint8_t hours = 0, uint8_t minutes = 0, uint8_t seconds = 0):
        yearFrom2000(yearFrom2000), month(month), day(day), hours(hours), minutes(minutes), seconds(seconds){
    }

    std::string getTimeString(){
        std::string res;
        char buffer[6] = {'\0',};

        sprintf(buffer, "%02d:%02d", hours, minutes);
        res = std::string(buffer);

        return res;
    }
    
    void setHours(uint8_t hours){
        this->hours = hours;
    }
    void setMinutes(uint8_t minutes){
        this->minutes = minutes;
    }

protected:
    uint8_t yearFrom2000 = 0;
    uint8_t month = 1;
    uint8_t day = 1;
    uint8_t hours = 0;
    uint8_t minutes = 0;
    uint8_t seconds = 0;
};

#endif