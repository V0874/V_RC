/*

@file lcd_screen.c
@brief lcd_screen source file
@device HD44780U
@author V0874
@date 01/02/2026

*/

#include <stdint.h>
#include "stm32f4xx_hal.h"

/**
 * @brief gpio type for lcd pins 
 */

typedef struct{
 GPIO_TypeDef* port;
 uint16_t pin;
} lcd_t;

/**
 * @brief lcd reg/databus structure
 */

typedef struct{
lcd_t reg_select;
lcd_t read_write;
lcd_t start_read_write;
lcd_t data_bus[8];
} lcd_config_t;

/**
 * @brief clears the display to its original state
 * 
 * @param config lcd port/pin config 
 */

void display_clear(const lcd_config_t *config);

/**
 * @brief shifts the entire display to the left
 * 
 * @param config lcd port/pin config
 * @note the cursor follows the display shift
 */

void shift_display_left(const lcd_config_t *config);

/**
 * @brief shifts the entire display to the right
 * 
 * @param config lcd port/pin config
 * @note the cursor follows the displays shift
 */

void shift_display_right(const lcd_config_t *config);

/**
 * @brief shifts the cursor one value to the left
 * 
 * @param config lcd port/pin config 
 */

void shift_cursor_left(const lcd_config_t* config);

/**
 * @brief shifts the cursor one value to the right
 * 
 * @param config lcd port/pin config 
 */

void shift_cursor_right(const lcd_config_t* config);

/**
 * @brief writes to the screen
 * 
 * @param config 
 * @param ch 
 */

void display_write(const lcd_config_t *config, const uint8_t ch);

/**
 * @brief turns on the display
 * 
 * @param config lcd port/pin config
 */

void display_on(const lcd_config_t *config);

/**
 * @brief turns off the display
 * 
 * @param config lcd port/pin config
 */

void display_off(const lcd_config_t *config);

/**
 * @brief returns the cursor to the main edge of the display
 * 
 * @param config lcd port/pin config
 */

void cursor_home(const lcd_config_t *config);

/**
 * @brief turns cursor on
 * 
 * @param config lcd port/pin config
 */

void cursor_on(const lcd_config_t *config);

/**
 * @brief turns cursor off
 * 
 * @param config lcd port/pin config
 */

void cursor_off(const lcd_config_t *config);

/**
 * @brief 
 * 
 * @param config lcd port/pin config 
 */

void display_ch_blink(const lcd_config_t *config);