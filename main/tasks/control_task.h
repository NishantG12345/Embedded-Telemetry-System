#ifndef CONTROL_TASK_H
#define CONTROL_TASK_H
#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"
typedef struct{
    QueueHandle_t queue; 
} control_task_args_t;
void control_task(void *args);
#endif