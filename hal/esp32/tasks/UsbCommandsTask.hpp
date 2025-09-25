#pragma once

#include <Arduino.h>
#include <ArduinoJson.h>

#include "./Task.hpp"
#include "../src/client/eventHandler/EventHandler.hpp"
#include "../src/common/utils/CommonDateTime.hpp"

class UsbCommandsTask: public Task{  
public: 
    UsbCommandsTask(EventHandlerTimeUpdatePort* timeUpdatePort = nullptr):Task("USBCommunication", 4096, 1), timeUpdatePort(timeUpdatePort){}

private:
    EventHandlerTimeUpdatePort* timeUpdatePort = nullptr;

    char buffer[256];
    uint16_t bufferIndex = 0;

protected:
    void run() override {
        Serial.println("USB Debug Task started");
        
        while(1) {
            while(Serial.available() > 0) {
                char c = Serial.read();
                
                if(c == '\n' || bufferIndex >= sizeof(buffer) - 1) {
                    if(bufferIndex > 0) {
                        buffer[bufferIndex] = '\0';
                        processJsonCommand(buffer);
                        bufferIndex = 0;
                    }
                } else {
                    buffer[bufferIndex++] = c;
                }
            }
            
            vTaskDelay(pdMS_TO_TICKS(10));
        }
    }

    void processJsonCommand(const char* jsonStr) {
        StaticJsonDocument<200> doc;
        DeserializationError error = deserializeJson(doc, jsonStr);
        
        if(error) return;
        
        const char* command = doc["cmd"];
        if(!command) {
            return;
        }
        
        if(strcmp(command, "set_time") == 0) {
            CommonDateTime dt;
            sscanf(doc["value"], "%d/%d/%d %d:%d", &dt.yearFrom2000, &dt.month, &dt.day, &dt.hours, &dt.minutes);
            dt.yearFrom2000 -= 2000;

            timeUpdatePort->setTime(dt);
        }
    }
};
