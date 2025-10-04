#pragma once

#include "lvgl.h"

#include "./Task.hpp"

class GuiUpdateTask: public Task{
public:
    GuiUpdateTask(): Task("GuiUpdate", 6*1024, 2, 0){}

protected:
    void run() override {
        Serial.println("LVGL update task started");

        const TickType_t xDelay = (1000/30) / portTICK_PERIOD_MS;

        vTaskDelay(100);
        while(1){
            lv_task_handler(); 
            vTaskDelay(xDelay);
        }
    }
};