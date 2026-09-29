#include "../drivers/dht11.h"
#include "../system/messages.h"
#include "sensor_task.h"

void sensor_task(void *args){
    dht11_data dht_data;
    sensor_data_t sensor_data;
    sensor_task_args_t *task_args = (sensor_task_args_t *) args;
    TickType_t lastWakeTime = xTaskGetTickCount(); 
    TickType_t period = pdMS_TO_TICKS(2000); 
    uint16_t light_reading;
    while(1){
    if(dht11_read(task_args->gpio_num, &dht_data)){
        sensor_data.temperature = dht_data.temperature;
        sensor_data.humidity = dht_data.humidity;  
        if(light_sensor_read(&light_reading)){
            sensor_data.adc_reading = light_reading;
        }
        else{
            printf("Light Reading Failed\n");
        }
        if(xQueueSend(task_args->queue, &sensor_data, pdMS_TO_TICKS(100)) == pdPASS){
            printf("Successfully added sensor data to queue\n");
        }
        else{
            printf("Sensor Queue is full");
        }
    else{
        printf("Couldn't read DHT\n");
    }
    }
    vTaskDelayUntil(&lastWakeTime, period); 
    }
}