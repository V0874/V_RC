#ifndef GPIO_H
#define GPIO_H

#include "stm32f4xx_hal.h"

/**
 * @brief inits the pins needed for the display
 * 
 */

 void lcd_gpio_init();
 void set_pin_high(GPIO_TypeDef* port, uint16_t pin);
 void set_pin_low(GPIO_TypeDef* port, uint16_t pin);


#endif