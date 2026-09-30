#ifndef MESSAGES_H
#define MESSAGES_H
#include <stdint.h>

typedef struct{
    float humidity;
    float temperature;
    uint16_t light_reading; 
} sensor_data_t; 
#endif