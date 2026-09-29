#ifndef DHT11_H
#define DHT11_H
#include "driver/gpio.h"
#include <stdbool.h>

typedef struct {
    float temperature; 
    float humidity;
} dht11_data; 

bool dht11_init(gpio_num_t num); 
bool dht11_read(gpio_num_t num, dht11_data* sensor_data); 

#endif