#ifndef GPIO_H
#define GPIO_H

#include "stm32f4xx_hal.h"

/**
 * @brief initializes the pins needed for the lcd display
 * 
 */

 void lcd_gpio_init();

 /**
  * @brief sets the pin high
  * @note we don't want to clog our drivers up with HAL functions
  * 
  * @param[in] port  
  * @param[in] pin 
  */

void set_pin_high(GPIO_TypeDef* port, uint16_t pin);

/**
 * @brief sets the pin low
 * 
 * @param[in] port 
 * @param[in] pin 
 */

void set_pin_low(GPIO_TypeDef* port, uint16_t pin);


#endif