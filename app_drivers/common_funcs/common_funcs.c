#include "common_funcs.h"

void utoa(uint8_t *buffer, uint32_t value, size_t size){
    uint8_t temp = 0;
    uint8_t ascii_offset = 48;

    for(int i = size - 1; i >= 0; i--){
        temp = value % 10 + ascii_offset;
        value = value / 10;
        buffer[i] = temp;
    }
}