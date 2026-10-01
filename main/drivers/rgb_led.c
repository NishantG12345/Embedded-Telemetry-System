#include "rgb_led.h"
static gpio_num_t red_gpio;
static gpio_num_t blue_gpio;
static gpio_num_t green_gpio;

bool rgb_led_init(gpio_num_t red_pin, gpio_num_t green_pin, gpio_num_t blue_pin){
    red_gpio = red_pin;
    green_gpio = green_pin;
    blue_gpio = blue_pin;
    if(gpio_set_direction(red_pin, GPIO_MODE_OUTPUT) != ESP_OK) return false;
    if(gpio_set_direction(green_pin, GPIO_MODE_OUTPUT) != ESP_OK) return false;
    if(gpio_set_direction(blue_pin, GPIO_MODE_OUTPUT) != ESP_OK) return false;
    return true;
}   
void rgb_led_set_color(colors_t color){
    
    switch(color){
        case RGB_RED:
            gpio_set_level(red_gpio, 1);
            gpio_set_level(green_gpio, 0);
            gpio_set_level(blue_gpio, 0);
            printf("RGB -> RED\n");
            break;
        case RGB_GREEN:
            gpio_set_level(red_gpio, 0); 
            gpio_set_level(green_gpio, 1);
            gpio_set_level(blue_gpio, 0);
            printf("RGB -> GREEN\n");
            break;
        case RGB_BLUE:
            gpio_set_level(red_gpio, 0);
            gpio_set_level(green_gpio, 0); 
            gpio_set_level(blue_gpio, 1);
            printf("RGB -> BLUE\n");

            break;
        case RGB_NONE:
            gpio_set_level(red_gpio, 0);  
            gpio_set_level(green_gpio, 0);
            gpio_set_level(blue_gpio, 0);
            printf("RGB -> OFF\n");

            break;
    }

}