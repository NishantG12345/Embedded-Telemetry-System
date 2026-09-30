#include "event_task.h"
#include "../drivers/buzzer.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <stdio.h>
void event_task(void *args){
    while(1){
        if(ulTaskNotifyTake(pdTRUE, portMAX_DELAY)){
            printf("motion detected"); 
            buzzer_set(true);
            vTaskDelay(pdMS_TO_TICKS(250));
            buzzer_set(false);
        }
        
    }
}