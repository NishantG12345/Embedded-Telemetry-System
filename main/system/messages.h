#ifndef MESSAGES_H
#define MESSAGES_H

#include <stdbool.h>

typedef struct {
    float humidity;
    float temperature;
    bool light_detected;
} sensor_data_t;

#endif