#include "gpio.h"

/**
 * @brief inits the pins needed for the display
 * 
 */

 void lcd_gpio_init(){
    GPIO_InitTypeDef lcd_gpio;

    __HAL_RCC_GPIOB_CLK_ENABLE();

    lcd_gpio.Pin = GPIO_PIN_6 | GPIO_PIN_7 |
                   GPIO_PIN_8 | GPIO_PIN_9 |
                   GPIO_PIN_12| GPIO_PIN_13;
                   
    lcd_gpio.Mode = GPIO_MODE_OUTPUT_OD;
    lcd_gpio.Pull = GPIO_PULLUP;
    lcd_gpio.Speed = GPIO_SPEED_FREQ_LOW;

    HAL_GPIO_Init(GPIOB, &lcd_gpio);
 }

 /**
  * @brief sets the pin high
  * @note we don't want to clog our drivers up with HAL functions
  * 
  * @param[in] port  
  * @param[in] pin 
  */

void set_pin_high(GPIO_TypeDef* port, uint16_t pin){
   HAL_GPIO_WritePin(port, pin, GPIO_PIN_SET);
}

/**
 * @brief sets the pin low
 * 
 * @param[in] port 
 * @param[in] pin 
 */

void set_pin_low(GPIO_TypeDef* port, uint16_t pin){
   HAL_GPIO_WritePin(port, pin, GPIO_PIN_RESET);
}
