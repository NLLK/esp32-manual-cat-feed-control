#ifndef USBCOMMANDSTASK_HPP
#define USBCOMMANDSTASK_HPP

#include <Arduino.h>
#include <ArduinoJson.h>

#include "./Task.hpp"

class UsbCommandsTask: public Task{  
public: 
    UsbCommandsTask():Task("USBCommunication", 4096, 1){}

private:
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
           Serial.println("set_time");
        }
    }
};
#endif