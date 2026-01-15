#ifndef TIMER_H
#define TIMER_H

#include "stm32f4xx_hal.h"

/**
 * @brief initializes timer 4 - basic timer
 * 
 * @param[in] timer timer configuration handle 
 */

void timer4_init(TIM_HandleTypeDef *timer);


#endif