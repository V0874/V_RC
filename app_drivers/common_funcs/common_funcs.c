#include "common_funcs.h"

void utoa(uint8_t *buffer, uint32_t adc_value){
    uint8_t value = 0;
    uint8_t ascii_offset = 48;

    for(int i = sizeof(buffer) - 1; i >= 0; i--){
        value = adc_value % 10 + ascii_offset;
        adc_value = adc_value / 10;
        buffer[i] = value;
    }
}