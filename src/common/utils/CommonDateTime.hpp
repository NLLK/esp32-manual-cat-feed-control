#pragma once

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

    bool isTheSameDay(const CommonDateTime& d){
        return (yearFrom2000 == d.yearFrom2000 && month == d.month && day == d.day);
    }

    bool isEmpty(){
        return yearFrom2000 == 0 && month == 1 && day == 1; //for now, when we still can't travel in time, it's seems enough
    }

    void incrementSeconds(uint8_t s){
        uint16_t t = seconds + s;
        if (t > 59){
            incrementMinutes(t / 60);
            seconds = t % 60;
        }else{
            seconds = t;
        }
    }
    
    void incrementMinutes(uint8_t m){
        uint16_t t = minutes + m;
        if (t > 59){
            incrementHours(t / 60);
            minutes = t % 60;
        }else{
            minutes = t;
        }
    }

    void incrementHours(uint8_t h){
        uint16_t t = hours + h;
        if (t > 23){
            incrementDays(t / 24);
            hours = t % 24;
        }else{
            hours = t;
        }
    }

    void incrementDays(uint8_t d){
        day += d;
    }

public:
    uint8_t yearFrom2000 = 0;
    uint8_t month = 1;
    uint8_t day = 1;
    uint8_t hours = 0;
    uint8_t minutes = 0;
    uint8_t seconds = 0;
};