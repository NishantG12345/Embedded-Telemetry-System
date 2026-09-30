#include "buzzer.h"

static gpio_num_t num_1;
bool buzzer_init(gpio_num_t num){
    num_1 = num;
    if(gpio_set_direction(num, GPIO_MODE_OUTPUT) != ESP_OK) return false;
    return true;
}
void buzzer_set(bool on){
    if(on) gpio_set_level(num_1, 1);
    else gpio_set_level(num_1, 0);
}