#ifndef LIGHT_SENSOR_H
#define LIGHT_SENSOR_H
#include <stdbool.h>
#include <stdint.h>
bool light_sensor_init(void);
bool light_sensor_read(uint16_t *light_reading);
#endif