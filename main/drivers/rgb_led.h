#ifndef RGB_LED_H
#define RGB_LED_H
#include <stdbool.h>
#include "driver/gpio.h"
typedef enum{
    RGB_RED,
    RGB_BLUE,
    RGB_GREEN,
    RGB_NONE
} colors_t;
bool rgb_led_init(gpio_num_t red_pin, gpio_num_t green_pin, gpio_num_t blue_pin); 
void rgb_led_set_color(colors_t color); 
#endif