#ifndef GPIO_H
#define GPIO_H

#include "stm32f4xx_hal.h"


/**
 * @brief these are just two test functions
 * 
 */

void led_flash();
void gpio_init();


/**
 * @brief sets the pin high 
 * 
 * @param[in] port 
 * @param[in] pin 
 * @note atomic write
 */

static inline void set_pin_high(GPIO_TypeDef* port, uint16_t pin){
    port->BSRR = (1 << pin);
}

/**
 * @brief sets the pin low
 * 
 * @param[in] port 
 * @param[in] pin
 * @note atomic write 
 */

static inline void set_pin_low(GPIO_TypeDef* port, uint16_t pin){
    port->BSRR = (1 << (pin+16));
}

#endif