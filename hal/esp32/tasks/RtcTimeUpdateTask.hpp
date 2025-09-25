#pragma once

#include "Arduino.h"
#include "RTClib.h"
#include <Wire.h>

#include "./Task.hpp"
#include "../src/client/eventHandler/EventHandler.hpp"
#include "../src/common/utils/CommonDateTime.hpp"

class RtcTimeUpdateTask: public Task{
public:
    RtcTimeUpdateTask(EventHandlerTimeUpdatePort* timeUpdatePort = nullptr, SemaphoreHandle_t* xRtcMutex = nullptr): 
        Task("RtcUpdate", 4096, 1), timeUpdatePort(timeUpdatePort), xRtcMutex(xRtcMutex){

    }
private:
    EventHandlerTimeUpdatePort* timeUpdatePort = nullptr;
    SemaphoreHandle_t* xRtcMutex = nullptr;
    RTC_DS1307 rtc;

protected:
    void run() override {
        Serial.println("Rtc Time update task started");
        
        const TickType_t xErrorDelay = (1000) / portTICK_PERIOD_MS;
        const TickType_t xPollDelay = (1*60*1000) / portTICK_PERIOD_MS;

        while(!rtc.begin(&Wire1)){
            static bool once = true;
            if (once){
                Serial.println("RTC DS1307 is not detected, check wiring.");
                once = false;
            }
            
            vTaskDelay(xErrorDelay);
        }
        if (!rtc.isrunning()) {
            Serial.printf("RTC is NOT running, set default to: %s %s", __DATE__, __TIME__);
            // When time needs to be set on a new device, or after a power loss, the
            // following line sets the RTC to the date & time this sketch was compiled
            rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
            // This line sets the RTC with an explicit date & time, for example to set
            // January 21, 2014 at 3am you would call:
            // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
        }

        Serial.println("RTC DS1307 is Ready.");

        while(1){

            DateTime now = rtc.now();

            if (xSemaphoreTake(*xRtcMutex, 5000) == pdTRUE){
                CommonDateTime dt(now.year(), now.month(), now.day(), now.hour(), now.minute(), now.second());
                timeUpdatePort->updateTime(dt);
                xSemaphoreGive(*xRtcMutex);
            }

            Serial.print("Time is: ");
            Serial.print(now.year(), DEC);
            Serial.print('/');
            Serial.print(now.month(), DEC);
            Serial.print('/');
            Serial.print(now.day(), DEC);
            Serial.print(' ');
            Serial.print(now.hour(), DEC);
            Serial.print(':');
            Serial.print(now.minute(), DEC);
            Serial.print(':');
            Serial.print(now.second(), DEC);
            Serial.println();

            vTaskDelay((60-now.second())*1000/ portTICK_PERIOD_MS);
        }
    }
};
