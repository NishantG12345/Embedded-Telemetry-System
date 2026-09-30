#include "control_task.h"  
#include "../system/system_state.h"
#include "../drivers/rgb_led.h"
#include "../system/messages.h"
void control_task(void *args){
    control_task_args_t *task_args = (control_task_args_t *) args;
    sensor_data_t sensor_data; 

    while(1){
        if(xQueueReceive(task_args->queue, &sensor_data, portMAX_DELAY) == pdPASS){
            sensor_data.temperature = (9/5.0f) * (sensor_data.temperature) + 32;
            temperature_state_t state = determine_temp_state(sensor_data.temperature); 
            switch(state){
                case COLD:
                rgb_led_set_color(RGB_BLUE);
                break;
                case NORMAL:
                rgb_led_set_color(RGB_GREEN);
                break;
                case HOT:
                rgb_led_set_color(RGB_RED);
                break;
            }

        }

    }

}