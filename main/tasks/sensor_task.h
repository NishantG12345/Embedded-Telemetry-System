#ifndef SENSOR_TASK_H
#define SENSOR_TASK_H

typedef struct{
    gpio_num_t gpio_num; 
    QueueHandle_t queue; 
} sensor_task_args_t;
void sensor_task(void *args);
#endif