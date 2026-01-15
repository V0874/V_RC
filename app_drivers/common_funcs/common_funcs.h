#ifndef COMMON_FUNCS_H
#define COMMON_FUNCS_H

#include <stdint.h>
#include <stddef.h>
#include "stm32f4xx_hal.h"

void utoa(uint8_t *buffer, uint32_t value, size_t size);

  /**
 * @brief microsecond delay 
 * 
 * @param[in] delay 16 bit value for delay 
 */

  void delay_us(uint32_t delay);

  /**
   * @brief wrapper for basic millisecond timer
   * 
   * @param[in] delay 32 bit delay value 
   */

  void delay_ms(uint32_t delay);

#endif