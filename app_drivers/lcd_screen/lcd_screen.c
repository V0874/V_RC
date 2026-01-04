#include "lcd_screen.h"

void lcd_init(){
    __HAL_RCC_GPIOA_CLK_ENABLE();

    GPIO_InitTypeDef lcd_pins = {0};

    lcd_pins.Pin = LCD_PIN_RS |  LCD_PIN_RW |
                  LCD_PIN_DB0 | LCD_PIN_DB1 |
                  LCD_PIN_DB2 | LCD_PIN_DB3 |
                  LCD_PIN_DB4 | LCD_PIN_DB5 |
                  LCD_PIN_DB6 | LCD_PIN_DB7;
    
    lcd_pins.Mode = GPIO_MODE_OUTPUT_PP;
    lcd_pins.Pull = GPIO_NOPULL;
    lcd_pins.Speed = GPIO_SPEED_LOW;

    HAL_GPIO_Init(LCD_PORT, &lcd_pins);
}

void display_write(uint8_t ch){

}

void display_clear(){
HAL_GPIO_WritePin(LCD_PORT, LCD_PIN_DB0, GPIO_PIN_SET);
}

void display_on(){

}

void display_off(){

}

void cursor_home(){
HAL_GPIO_WritePin(LCD_PORT, LCD_PIN_DB1, GPIO_PIN_SET);
}

void cursor_on(){

}

void cursor_off(){

}

void display_ch_blink(){

}

void cursor_shift(){

}

void display_shift(){

}



