#include "tasks.h"
#include "RTClib.h"

RTC_DS1307 rtc;

void task_time_update(void *pvParameters){
    const TickType_t xErrorDelay = (1000) / portTICK_PERIOD_MS;
	const TickType_t xPollDelay = (1*60*1000) / portTICK_PERIOD_MS;

	while(!rtc.begin(&Wire1))
	{
		static bool once = true;
		if (once){
			Serial.println("RTC DS1307 is not detected, check wiring.");
		  	once = false;
	  	}
		
		vTaskDelay(xErrorDelay);
	}
    if (!rtc.isrunning()) {
        Serial.printf("RTC is NOT running, set default to: %s %s", __DATE__, __TIME__);
        // When time needs to be set on a new device, or after a power loss, the
        // following line sets the RTC to the date & time this sketch was compiled
        rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
        // This line sets the RTC with an explicit date & time, for example to set
        // January 21, 2014 at 3am you would call:
        // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
    }

    Serial.println("RTC DS1307 is Ready.");

    while(1){

        DateTime now = rtc.now();

        if (xSemaphoreTake(xRtcMutex, 5000) == pdTRUE){
            // DateTimeSettings currentTime(now.year(), now.month(), now.day(), now.hour(), now.minute(), now.second());
            // DependenciesManager::getDateTimeController()->setSettings(currentTime);
            xSemaphoreGive(xRtcMutex);
        }

        Serial.print("Time is: ");
        Serial.print(now.year(), DEC);
        Serial.print('/');
        Serial.print(now.month(), DEC);
        Serial.print('/');
        Serial.print(now.day(), DEC);
        Serial.print(' ');
        Serial.print(now.hour(), DEC);
        Serial.print(':');
        Serial.print(now.minute(), DEC);
        Serial.print(':');
        Serial.print(now.second(), DEC);
        Serial.println();

        vTaskDelay(xPollDelay);
    }
}

void task_time_set(void *pvParameters){
    // DateTimeSettings* settings = static_cast<DateTimeSettings*>(pvParameters);

    if (xSemaphoreTake(xRtcMutex, 5000) == pdTRUE){
        // rtc.adjust(DateTime(settings->years, settings->months, settings->days, settings->hours, settings->minutes, settings->seconds));
        xSemaphoreGive(xRtcMutex);
    }

    vTaskDelete(nullptr);
}