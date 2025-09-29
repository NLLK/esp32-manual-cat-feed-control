#pragma once

#include "RTClib.h"
#include "./Task.hpp"
#include "../../../../common/utils/CommonDateTime.hpp"

#include <Wire.h>

class RtcTimeSetTask;

class RtcTimeSetTask: public Task{
public:
    RtcTimeSetTask(SemaphoreHandle_t* xRtcMutex = nullptr): 
        Task("RtcSet", 4096, 1), xRtcMutex(xRtcMutex){
    }

    void setTime(CommonDateTime time){
        this->time = time;
    }

private:
    SemaphoreHandle_t* xRtcMutex = nullptr;
    RTC_DS1307 rtc;
    CommonDateTime time; 

protected:
    void run() override {
        Serial.println("Rtc Time Set task started");

        if (xSemaphoreTake(*xRtcMutex, 5000) == pdTRUE){
            rtc.begin(&Wire1);
            rtc.adjust(DateTime(time.yearFrom2000 + 2000, time.month, time.day, time.hours, time.minutes, time.seconds));

            xSemaphoreGive(*xRtcMutex);
        }
        //TODO: fix - time could be set only once per restart
        stop();
    }
};