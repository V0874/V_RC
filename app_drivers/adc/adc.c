#include "adc.h"

void HAL_ADC_MspInit(ADC_HandleTypeDef *adc){
    __HAL_RCC_ADC1_CLK_ENABLE();

    __HAL_RCC_GPIOA_CLK_ENABLE();

    GPIO_InitTypeDef adc_pins = {0};

    adc_pins.Pin = GPIO_PIN_0 | GPIO_PIN_1;
    adc_pins.Mode = GPIO_MODE_ANALOG;
    adc_pins.Pull = GPIO_NOPULL;

    HAL_GPIO_Init(GPIOA, &adc_pins);    
}

void adc_init(ADC_HandleTypeDef *adc, ADC_ChannelConfTypeDef *adc_conf){
    adc->Instance = ADC1;

    adc->Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV2;
    adc->Init.ContinuousConvMode = ENABLE;
    adc->Init.DataAlign = ADC_DATAALIGN_RIGHT;
    adc->Init.DiscontinuousConvMode = DISABLE;
    adc->Init.EOCSelection = ADC_EOC_SEQ_CONV;
    adc->Init.ExternalTrigConv = ADC_SOFTWARE_START;
    adc->Init.Resolution = ADC_RESOLUTION_12B;


    adc_conf->Channel = ADC_CHANNEL_0;
    adc_conf->Rank = 1;
    adc_conf->SamplingTime = ADC_SAMPLETIME_15CYCLES;
    
    HAL_ADC_Init(adc);
    HAL_ADC_ConfigChannel(adc, adc_conf);
    __HAL_ADC_ENABLE(adc);
}

void adc_change_ch(ADC_HandleTypeDef *adc, ADC_ChannelConfTypeDef *config, uint32_t channel){
    config->Channel = channel;
    HAL_ADC_ConfigChannel(adc, config);
}