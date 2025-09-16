#ifndef TASKS_H
#define TASKS_H

#include "Arduino.h"
#include "lvgl.h"
#include <Wire.h>

extern SemaphoreHandle_t xSerialMutex;   
extern SemaphoreHandle_t xRtcMutex;   

void task_time_update(void *pvParameters);
void task_time_set(void *pvParameters);

#endif