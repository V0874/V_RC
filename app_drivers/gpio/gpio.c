#include "gpio.h"

void led_flash(){
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);
    
    HAL_Delay(1000);

    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);

    HAL_Delay(1000);
}

void gpio_init(){
    __HAL_RCC_GPIOC_CLK_ENABLE();

    GPIO_InitTypeDef onboard_led = {0};
    
    onboard_led.Pin = GPIO_PIN_13;
    onboard_led.Mode = GPIO_MODE_OUTPUT_PP;
    onboard_led.Pull = GPIO_NOPULL;
    onboard_led.Speed = GPIO_SPEED_FREQ_LOW;

    HAL_GPIO_Init(GPIOC, &onboard_led);
}