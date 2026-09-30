#ifndef BUZZER_H
#define BUZZER_H
#include <stdbool.h>
#include "driver/gpio.h"

bool buzzer_init(gpio_num_t num); 
void buzzer_set(bool on); 

#endif