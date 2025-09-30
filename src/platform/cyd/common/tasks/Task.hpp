#pragma once

#include <Arduino.h>

#define TASK_CONST_SECOND (1000 / portTICK_PERIOD_MS)

class Task {
protected:
    TaskHandle_t taskHandle = nullptr;
    const char* taskName;
    uint32_t stackDepth;
    UBaseType_t priority;
    uint8_t core;
    uint32_t delayBeforeStartMs = 0;

    static const uint8_t DEFAULT_CORE_FOR_TASKS = 1;
    
    virtual void run() = 0;

    static void taskFunction(void* params) {
        Task* task = static_cast<Task*>(params);
        if(task) {
            vTaskDelay(task->delayBeforeStartMs / portTICK_PERIOD_MS);
            task->run();
        }
        vTaskDelete(nullptr);
    }

public:
    Task(const char* name, uint32_t stackSize, UBaseType_t prio, uint8_t core = DEFAULT_CORE_FOR_TASKS) 
        : taskName(name), stackDepth(stackSize), priority(prio), core(core) {}
    
    virtual ~Task() {
        stop();
    }
    
    bool start() {
        if(taskHandle != nullptr) {
            return false;
        }
        
        return xTaskCreatePinnedToCore(
            taskFunction,    
            taskName,        
            stackDepth,      
            this,            
            priority,       
            &taskHandle,    
            core
        ) == pdPASS;
    }
    
    void stop() {
        if(taskHandle != nullptr) {
            vTaskDelete(taskHandle);
            taskHandle = nullptr;
        }
    }
    
    void suspend() {
        if(taskHandle != nullptr) {
            vTaskSuspend(taskHandle);
        }
    }
    
    void resume() {
        if(taskHandle != nullptr) {
            vTaskResume(taskHandle);
        }
    }
    
    bool isRunning() const {
        return taskHandle != nullptr;
    }

    void setDelayBeforeStart(uint32_t delay){
        delayBeforeStartMs = delay;
    }
};