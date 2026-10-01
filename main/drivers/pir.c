#include "pir.h"

static TaskHandle_t event_task_handle;
static void IRAM_ATTR pir_isr(void *arg){
    BaseType_t higher_priority_task = pdFALSE;
    vTaskNotifyGiveFromISR(event_task_handle,&higher_priority_task); 
    portYIELD_FROM_ISR(higher_priority_task);

}
bool pir_init(gpio_num_t num, TaskHandle_t task){
    event_task_handle = task; 
    if(gpio_set_direction(num, GPIO_MODE_INPUT) != ESP_OK) return false; 
    if(gpio_set_intr_type(num, GPIO_INTR_POSEDGE) != ESP_OK)return false;

    if(gpio_install_isr_service(0) != ESP_OK) return false;
    
    if(gpio_isr_handler_add(num, pir_isr, NULL) != ESP_OK) return false;
    return true;
}



