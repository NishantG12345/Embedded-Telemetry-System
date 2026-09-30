#ifndef SENSOR_TASK_H
#define SENSOR_TASK_H
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"

typedef struct{
    gpio_num_t gpio_num; 
    QueueHandle_t display_queue; 
    QueueHandle_t control_queue;
} sensor_task_args_t;
void sensor_task(void *args);
#endif