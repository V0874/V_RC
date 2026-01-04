#include "stm32f4xx_hal.h"

void adc_init(ADC_HandleTypeDef *adc, ADC_ChannelConfTypeDef *adc_conf);
void adc_change_ch(ADC_HandleTypeDef *adc, ADC_ChannelConfTypeDef *config, uint32_t channel);