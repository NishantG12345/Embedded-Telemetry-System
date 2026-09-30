#include "display_task.h"
#include "../system/messages.h"
#include "../drivers/oled.h"
#include <stdio.h>

void display_task(void *args){
display_task_args_t *task_args = (display_task_args_t *) args;
sensor_data_t sensor_data; 

while(1){
    if(xQueueReceive(task_args->queue, &sensor_data, portMAX_DELAY) == pdPASS){
        char message[32];
        snprintf(message, sizeof(message), "T: %.1fC H: %.1f%%", sensor_data.temperature, sensor_data.humidity); 
        oled_clear(); 
        oled_write_text(message); 
    }

}
}
