#pragma once

#include "./Task.hpp"

#include "application/client/eventHandler/EventHandler.hpp"

class FsmTask: public Task{
public:
    FsmTask(): Task("FsmTask", 6*1024, 1){}

    void setEventHandler(EventHandler* eventHandler){
        this->eventHandler = eventHandler;
    }

protected:
    void run() override {
        Serial.println("LVGL update task started");

        const TickType_t xDelay = (1000/30) / portTICK_PERIOD_MS;

        vTaskDelay(TASK_CONST_SECOND/2);

        eventHandler->getMealsFromTheServer();
    }
private: 
    EventHandler* eventHandler = nullptr;
};