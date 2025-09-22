#include "tasks.h"

void task_gui(void *pvParameters){
	const TickType_t xDelay = (1000/60) / portTICK_PERIOD_MS;

	vTaskDelay(100);
	while(1){
		lv_task_handler(); 
		vTaskDelay(xDelay);
	}
}