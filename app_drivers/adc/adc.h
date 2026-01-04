#include "../../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_adc.h"

void adc_init(ADC_HandleTypeDef *adc, ADC_ChannelConfTypeDef *adc_conf);
void adc_change_ch(ADC_HandleTypeDef *adc, ADC_ChannelConfTypeDef *config, uint32_t channel);