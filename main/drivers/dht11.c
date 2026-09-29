//uses pulse width encoding short high for 0 long high for 1
#include "dht11.h"
#include "esp_rom_sys.h"
static bool wait_level(gpio_num_t num, int level, int timeout){
    int time = 0; 
    while(!(gpio_get_level(num) == level)){
        esp_rom_delay_us(1);
        time++;
        if(time >= timeout){
            return false;
        };
    }
    return true;
}
static int check_pulse_width(gpio_num_t num, int timeout){
    int time = 0; 
    while(gpio_get_level(num) == 1){
        esp_rom_delay_us(1);
        time++;
        if(time >= timeout){
            printf("Something went wrong!");
            return 0; 
        }
    }
    return time;
}
bool dht11_init(gpio_num_t num){
    return gpio_set_direction(num,GPIO_MODE_INPUT) == ESP_OK; 
}   

bool dht11_read(gpio_num_t num, dht11_data* sensor_data){
    gpio_set_direction(num,GPIO_MODE_OUTPUT); 
    gpio_set_level(num, 0); 
    esp_rom_delay_us(18000);
    gpio_set_level(num, 1); 
    gpio_set_direction(num, GPIO_MODE_INPUT);
    if(!wait_level(num,0,100)){
     printf("Handshake failed");
     return false;
    }
    if(!wait_level(num,1,100)){
     printf("Handshake failed");
     return false;
    }
    if(!wait_level(num,0,100)){
     printf("Handshake failed");
     return false;
    }
    int bits[40];
    for(int i = 0; i < 40; i++){
       if(wait_level(num,1,100)){
            int time = check_pulse_width(num, 100);
            if(time == 0){
                return false;
            }
            bits[i] = (time > 40) ?  1 : 0;
       }
       else{
            printf("something went wrong with reading");
            return false; 
       }
    }

    uint8_t bytes[5] = {0};
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 8; j++){
           bytes[i] = (bytes[i] << 1) | bits[i*8 + j]; 
        }
    }
    int sum = (bytes[0] + bytes[1] + bytes[2] + bytes[3]);
    if((sum && 0xFF) == bytes[4]){
        sensor_data->temperature = bytes[2] + (bytes[3]/10.0f);
        sensor_data->humidity = bytes[0] +(bytes[1]/10.0f);
        return true;
    }
    else {
        return false;
    }
}


