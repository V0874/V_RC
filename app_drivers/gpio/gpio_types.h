#ifndef GPIO_TYPES
#define GPIO_TYPES

#include "stm32f4xx_hal.h"

typedef struct{
 GPIO_TypeDef* port;
 uint16_t pin;
} lcd_t;


#endif