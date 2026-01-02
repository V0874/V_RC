#include "uart.h"

void HAL_UART_MspInit(UART_HandleTypeDef *huart){
    __HAL_RCC_USART1_CLK_ENABLE();

    __HAL_RCC_GPIOA_CLK_ENABLE();

    GPIO_InitTypeDef uart = {0};

    uart.Pin = GPIO_PIN_9 | GPIO_PIN_10;
    uart.Mode = GPIO_MODE_AF_PP;
    uart.Pull = GPIO_NOPULL;
    uart.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    uart.Alternate = GPIO_AF7_USART1;

    HAL_GPIO_Init(GPIOA, &uart);
}

void uart_init(UART_HandleTypeDef *huart){
    huart->Instance = USART1;

    huart->Init.BaudRate = 115200;
    huart->Init.StopBits = UART_STOPBITS_1;
    huart->Init.Mode = UART_MODE_TX_RX;
    huart->Init.WordLength = UART_WORDLENGTH_8B;
    huart->Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart->Init.OverSampling = UART_OVERSAMPLING_8;

    HAL_UART_Init(huart);
}