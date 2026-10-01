#include "light_sensor.h"

static gpio_num_t light_pin;

bool light_sensor_init(gpio_num_t pin)
{
    light_pin = pin;

    gpio_config_t config = {
        .pin_bit_mask = (1ULL << pin),
        .mode = GPIO_MODE_INPUT,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE
    };

    if (gpio_config(&config) != ESP_OK) {
        return false;
    }

    return true;
}

bool light_sensor_read(bool *light_detected)
{
    if (light_detected == NULL) {
        return false;
    }

    *light_detected = gpio_get_level(light_pin);

    return true;
}