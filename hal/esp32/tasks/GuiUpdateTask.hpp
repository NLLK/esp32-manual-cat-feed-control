#pragma once

#include "lvgl.h"

#include "./Task.hpp"

class GuiUpdateTask: public Task{
public:
    GuiUpdateTask(): Task("GuiUpdate", 6*1024, 1, 0){}

protected:
    void run() override {
        Serial.println("Rtc Time Set task started");

        const TickType_t xDelay = (1000/60) / portTICK_PERIOD_MS;

        vTaskDelay(100);
        while(1){
            lv_task_handler(); 
            vTaskDelay(xDelay);
        }
    }
};