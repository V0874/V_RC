/*

@file lcd_screen.c
@brief lcd_screen source file
@device HD44780U
@version 0.1
@author V0874
@date 01/02/2026

*/

#include <stdint.h>
#include "stm32f4xx_hal.h"

// define lcd port for pins
#define LCD_PORT GPIOA

// define lcd register select / read/write  / databus pins 
#define LCD_PIN_RS GPIO_PIN_13
#define LCD_PIN_RW GPIO_PIN_14
#define LCD_PIN_DB0 GPIO_PIN_15
#define LCD_PIN_DB1 GPIO_PIN_3
#define LCD_PIN_DB2 GPIO_PIN_4
#define LCD_PIN_DB3 GPIO_PIN_5
#define LCD_PIN_DB4 GPIO_PIN_6
#define LCD_PIN_DB5 GPIO_PIN_7
#define LCD_PIN_DB6 GPIO_PIN_8
#define LCD_PIN_DB7 GPIO_PIN_9

// Initialize screen and LCD pins
void lcd_init();

void display_write(uint8_t ch);

void read_busy_flag();

void display_clear();

void cursor_home();

void display_on();

void display_off();

void cursor_on();

void cursor_off();

void display_ch_blink();

void cursor_shift();

void display_shift();


