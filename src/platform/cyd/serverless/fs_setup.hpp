#include <Arduino.h>
#include <LittleFS.h>

void setup_fs(){    
    if(!LittleFS.begin(true)) {
        Serial.println("ERROR: failed to mount LittleFS");
        return;
    }
    Serial.println("LittleFS mounted successfully");

    if(!LittleFS.exists("/data")) {
        LittleFS.mkdir("/data");
    }
}