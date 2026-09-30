#ifndef PIR_H
#define PIR_H
#include <stdbool.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

bool pir_init(gpio_num_t num, TaskHandle_t task);
#endif