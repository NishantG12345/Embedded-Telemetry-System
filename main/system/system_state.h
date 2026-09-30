#ifndef SYSTEM_STATE_H
#define SYSTEM_STATE_H

typedef enum {
    COLD, 
    NORMAL,
    HOT
} temperature_state_t; 

temperature_state_t temp_state(float temperature_f);

#endif