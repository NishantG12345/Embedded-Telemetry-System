#include "system_state.h"
temperature_state_t temp_state(float temperature_f){
    if (temperature_f >= 75) return HOT; 
    else if(temperature_f < 70) return COLD;
    else return NORMAL;
}