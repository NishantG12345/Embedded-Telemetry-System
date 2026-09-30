#ifndef OLED_H
#define OLED_H
#include <stdbool.h>
#include "driver/gpio.h"

bool oled_init(gpio_num_t sda, gpio_num_t scl);
bool oled_clear(void);
bool oled_write_text(const char *text);

#endif