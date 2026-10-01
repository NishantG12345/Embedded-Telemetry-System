#ifndef LIGHT_SENSOR_H
#define LIGHT_SENSOR_H

#include <stdbool.h>
#include "driver/gpio.h"

bool light_sensor_init(gpio_num_t num);
bool light_sensor_read(bool *light_detected);

#endif