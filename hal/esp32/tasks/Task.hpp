#include <Arduino.h>

class Task {
protected:
    TaskHandle_t taskHandle = nullptr;
    const char* taskName;
    uint32_t stackDepth;
    UBaseType_t priority;

    const uint8_t DEFAULT_CORE_FOR_TASKS = 1;
    
    virtual void run() = 0;

    static void taskFunction(void* params) {
        Task* task = static_cast<Task*>(params);
        if(task) {
            task->run();
        }
        vTaskDelete(nullptr);
    }

public:
    Task(const char* name, uint32_t stackSize, UBaseType_t prio) 
        : taskName(name), stackDepth(stackSize), priority(prio) {}
    
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
            DEFAULT_CORE_FOR_TASKS
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
};