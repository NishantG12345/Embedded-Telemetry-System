#include <stdio.h>
#include "tasks/sensor_task.h"
#include "tasks/display_task.h"
#include "tasks/event_task.h"
#include "tasks/control_task.h"
#include "system/messages.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "drivers/dht11.h"
#include "drivers/oled.h"
#include "drivers/light_sensor.h"
#include "drivers/rgb_led.h"
#include "drivers/buzzer.h"
#include "drivers/pir.h"

void app_main(void){
QueueHandle_t display_queue;
display_queue = xQueueCreate(5, sizeof(sensor_data_t));

QueueHandle_t control_queue;
control_queue = xQueueCreate(5, sizeof(sensor_data_t));

if (display_queue == NULL || control_queue == NULL) {
    printf("Failed to create queues\n");
    return;
}

static sensor_task_args_t sensor_args; 
sensor_args.gpio_num = GPIO_NUM_16;
sensor_args.display_queue = display_queue;
sensor_args.control_queue = control_queue;

static display_task_args_t display_args;
display_args.queue = display_queue; 

static control_task_args_t control_args;
control_args.queue = control_queue; 

TaskHandle_t event_task_handle; 
TaskHandle_t sensor_task_name; 
TaskHandle_t display_task_name;
TaskHandle_t control_task_name;

dht11_init(GPIO_NUM_16);
oled_init(GPIO_NUM_21, GPIO_NUM_22);
light_sensor_init(GPIO_NUM_34);
rgb_led_init(GPIO_NUM_5, GPIO_NUM_18, GPIO_NUM_19);
// rgb_led_set_color(RGB_RED);
// vTaskDelay(pdMS_TO_TICKS(1000));

// rgb_led_set_color(RGB_GREEN);
// vTaskDelay(pdMS_TO_TICKS(1000));

// rgb_led_set_color(RGB_BLUE);
// vTaskDelay(pdMS_TO_TICKS(1000));

// rgb_led_set_color(RGB_NONE);
// buzzer_init(GPIO_NUM_23);

    xTaskCreate(
        sensor_task,
        "sensor_task",
        2048,
        &sensor_args,
        3,
        &sensor_task_name
    );


    xTaskCreate(
        display_task,
        "display_task",
        4096,
        &display_args,
        3,
        &display_task_name
    ); 
    xTaskCreate(
        event_task,
        "event_task",
        2048,
        NULL,
        1,
        &event_task_handle
    ); 
    pir_init(GPIO_NUM_13, event_task_handle);

    xTaskCreate(
        control_task,
        "control_task",
        2048,
        &control_args,
        4,
        &control_task_name
    ); 
    
    
}
