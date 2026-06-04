#include "i2c.h"

 void HAL_I2C_MspInit(I2C_HandleTypeDef *hi2c){
    __HAL_RCC_I2C1_CLK_ENABLE();

    __HAL_RCC_GPIOB_CLK_ENABLE();

    GPIO_InitTypeDef gpioB = {0};

    gpioB.Pin = GPIO_PIN_6 | GPIO_PIN_7;
    gpioB.Mode = GPIO_MODE_AF_OD;
    gpioB.Pull = GPIO_PULLUP;
    gpioB.Alternate = GPIO_AF4_I2C1;
    gpioB.Speed = GPIO_SPEED_FREQ_LOW;

    HAL_GPIO_Init(GPIOB, &gpioB);
 }

 void i2c_init(I2C_HandleTypeDef *hi2c){
    hi2c->Instance = I2C1;

    hi2c->Init.ClockSpeed = 0;
    hi2c->Init.DutyCycle = 0;
    hi2c->Init.OwnAddress1 = 0;
    hi2c->Init.AddressingMode = 0;
    hi2c->Init.DualAddressMode = 0;
    hi2c->Init.OwnAddress2 = 0;
    hi2c->Init.GeneralCallMode = 0;
    hi2c->Init.NoStretchMode = 0;

 }