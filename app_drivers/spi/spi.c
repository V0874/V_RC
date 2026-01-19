#include "spi.h"

HAL_SPI_MspInit(SPI_HandleTypeDef *spi){
    __HAL_RCC_GPIOA_CLK_ENABLE();

    __HAL_RCC_SPI1_CLK_ENABLE();

    GPIO_InitTypeDef spi_pins = {0};

    spi_pins.Pin = GPIO_PIN_4 | GPIO_PIN_5 |
                   GPIO_PIN_6 | GPIO_PIN_7;

    spi_pins.Mode = GPIO_MODE_AF_PP;
    spi_pins.Pull = GPIO_NOPULL;
    spi_pins.Alternate = GPIO_AF5_SPI1;
    spi_pins.Speed = GPIO_SPEED_FREQ_LOW;

    HAL_GPIO_Init(GPIOA, &spi_pins);
}

void spi_init(SPI_HandleTypeDef *spi){
    spi->Instance = SPI1;

    spi->Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
    spi->Init.CLKPhase = SPI_PHASE_1EDGE;
       spi->Init.CLKPolarity = SPI_POLARITY_LOW;
    spi->Init.CRCCalculation = SPI_CRCCALCULATION_DISABLED;
    spi->Init.DataSize = SPI_DATASIZE_8BIT;
    spi->Init.Direction = SPI_DIRECTION_1LINE;
    spi->Init.FirstBit = SPI_FIRSTBIT_MSB;
    spi->Init.Mode = SPI_MODE_MASTER;
    spi->Init.NSS = SPI_NSS_SOFT;
    spi->Init.TIMode = SPI_TIMODE_DISABLED;

    HAL_SPI_Init(spi);
}