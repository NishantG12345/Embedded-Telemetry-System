#include <stdio.h>
#include "tasks/sensor_task.h"
#include "system/messages.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

void app_main(void){
QueueHandle_t sensor_queue;
sensor_queue = xQueueCreate(5, sizeof(sensor_data_t));

static sensor_task_args_t sensor_args; 
sensor_args.gpio_num = 16;
sensor_args.queue = sensor_queue;

TaskHandle_t sensor_task_name; 

    xTaskCreate(
        sensor_task,
        "sensor_task",
        2048,
        &sensor_args,
        3,
        &sensor_task_name
    );
}
