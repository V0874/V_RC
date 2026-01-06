/*

@file lcd_screen.c
@brief lcd_screen source file
@device HD44780U
@author V0874
@date 01/02/2026

*/

#include <stdint.h>
#include <stdbool.h>
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
 * @note 8 bit mode can be supported but must be configured
 */

typedef struct{
lcd_t rs;
lcd_t rw;
lcd_t e;
lcd_t db[4];
} lcd_config_t;

/**
 * @brief clears the display to its original state
 * 
 * @param[in] cfg lcd port/pin config 
 */

void display_clear(const lcd_config_t *cfg);

 /**
 * @brief returns the cursor to the main edge of the display
 * 
 * @param[in] cfg lcd port/pin config
 */

void cursor_home(const lcd_config_t *cfg);

/**
 * @brief shifts the entire display to the left
 * 
 * @param[in] cfg lcd port/pin config
 * @note the cursor follows the display shift
 */

void shift_display_left(const lcd_config_t *cfg);

/**
 * @brief shifts the entire display to the right
 * 
 * @param[in] cfg lcd port/pin config
 * @note the cursor follows the displays shift
 */

void shift_display_right(const lcd_config_t *cfg);

/**
 * @brief shifts the cursor one value to the left
 * 
 * @param[in] cfg lcd port/pin config 
 */

void shift_cursor_left(const lcd_config_t* cfg);

/**
 * @brief shifts the cursor one value to the right
 * 
 * @param[in] cfg lcd port/pin config 
 */

void shift_cursor_right(const lcd_config_t* cfg);

/**
 * @brief writes to the screen
 * 
 * @param[in] cfg port/pin lcd config 
 * @param[in] ch accepts most ascii char
 * @note some special characters must be built
 */

void display_write(const lcd_config_t *cfg, const uint8_t ch);

/**
 * @brief turns on the display
 * 
 * @param[in] cfg lcd port/pin config
 */

void display_on(const lcd_config_t *cfg);

/**
 * @brief turns off the display
 * 
 * @param[in] cfg lcd port/pin config
 */

void display_off(const lcd_config_t *cfg);

/**
 * @brief turns cursor on
 * 
 * @param[in] cfg lcd port/pin config
 */

void cursor_on(const lcd_config_t *cfg);

/**
 * @brief turns cursor off
 * 
 * @param[in] cfg lcd port/pin config
 */

void cursor_off(const lcd_config_t *cfg);

/**
 * @brief turns blink on for current cursor position
 * 
 * @param[in] cfg lcd port/pin config 
 */

void blink_on(const lcd_config_t *cfg);

/**
 * @brief turns blink off for current cursor position
 * 
 * @param cfg lcd port/pin config 
 */

void blink_off(const lcd_config_t *cfg);
