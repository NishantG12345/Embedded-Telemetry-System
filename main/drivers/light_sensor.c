#include "light_sensor.h"
#include "esp_adc/adc_oneshot.h"

static adc_oneshot_unit_handle_t adc1_handle;

bool light_sensor_init(void){
    adc_oneshot_unit_init_cfg_t init_config1 = {
    .unit_id = ADC_UNIT_1,
    .ulp_mode = ADC_ULP_MODE_DISABLE,
};
    if(adc_oneshot_new_unit(&init_config1, &adc1_handle)!= ESP_OK) return false;
    adc_oneshot_chan_cfg_t config = {
    .bitwidth = ADC_BITWIDTH_DEFAULT,
    .atten = ADC_ATTEN_DB_12,
};
 if(adc_oneshot_config_channel(adc1_handle, ADC_CHANNEL_6, &config)!= ESP_OK) return false;
 return true;
}

bool light_sensor_read(uint16_t *light_reading){
    if(light_reading == NULL){
        return false;
    }
    int raw = 0; 
    if(adc_oneshot_read(adc1_handle, ADC_CHANNEL_6, &raw) != ESP_OK) return false;
    *light_reading = (uint16_t)raw; //adc api returns as int 
    return true; 
}