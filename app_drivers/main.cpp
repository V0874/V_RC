#include "stm32f4xx_hal.h"
#include "lcd_screen/lcd_screen.h"
#include "gpio/gpio.h"
#include "adc/adc.h"
#include "uart/uart.h"


int main(){

    TIM_HandleTypeDef timer = {0};

    UART_HandleTypeDef huart = {0};
  
    ADC_HandleTypeDef adc = {0}; 

    ADC_ChannelConfTypeDef adc_conf = {0};

    lcd_config_t lcd_pins = {
    .rs = {.port = GPIOB, .pin = GPIO_PIN_12},
    .rw = {.port = GPIOB, .pin = GPIO_PIN_13},
    .e =  {.port = GPIOB, .pin = GPIO_PIN_14},
    .db = { 
          {GPIOB, GPIO_PIN_6},{GPIOB, GPIO_PIN_7},
          {GPIOB, GPIO_PIN_8},{GPIOB, GPIO_PIN_9}
          }
    };


    volatile uint32_t y_axis = 0;
    volatile uint32_t x_axis = 0;
    
    uint8_t adc_ybuff[4] = {0};
    uint8_t adc_xbuff[4] = {0};

    uint8_t y_msg[] = "ADC Y Value: ";
    uint8_t x_msg[] = "ADC X Value: ";
  
    bool conv_x_ready = false;



    uart_init(&huart);

    adc_init(&adc, &adc_conf);

    lcd_gpio_init();
  
    timer4_init(&timer);

    lcd_init(&lcd_pins);

    write_char(&lcd_pins, '^');
    write_char(&lcd_pins, '_');
    write_char(&lcd_pins, '^');


    while(1){
        
        HAL_ADC_Start(&adc);

        if(HAL_ADC_PollForConversion(&adc, HAL_MAX_DELAY) == HAL_OK && conv_x_ready == false){
            y_axis = HAL_ADC_GetValue(&adc);
            adc_change_ch(&adc, &adc_conf, ADC_CHANNEL_1);
            HAL_ADC_Start(&adc);
            utoa(adc_ybuff, y_axis, 4);
            conv_x_ready = true;

            // HAL_UART_Transmit(&huart, y_msg, sizeof(y_msg) - 1, HAL_MAX_DELAY);
            // HAL_UART_Transmit(&huart, adc_ybuff, sizeof(adc_ybuff), HAL_MAX_DELAY);
    }
   
        if(HAL_ADC_PollForConversion(&adc, HAL_MAX_DELAY) == HAL_OK && conv_x_ready == true){
            x_axis = HAL_ADC_GetValue(&adc);
            adc_change_ch(&adc, &adc_conf, ADC_CHANNEL_0);
            HAL_ADC_Start(&adc);
            utoa(adc_xbuff, x_axis, 4);
            conv_x_ready = false;

            // HAL_UART_Transmit(&huart, x_msg, sizeof(x_msg) - 1, HAL_MAX_DELAY);
            // HAL_UART_Transmit(&huart, adc_xbuff, sizeof(adc_xbuff), HAL_MAX_DELAY);
        }
    }
}