#ifndef LCD_SCREEN_H
#define LCD_SCREEN_H

/*

@file lcd_screen.c
@brief lcd_screen source file
@device HD44780U
@author V0874
@date 01/02/2026

*/

#include <stdint.h>
#include "gpio.h"
#include "gpio_types.h"
#include "common_funcs.h"

/**
 * @brief lcd reg/databus structure
 * @note 4 bit mode is supported for this implementation
 * @note 8 bit mode could be supported but would need a new command func
 */

typedef struct{
lcd_t rs;
lcd_t rw;
lcd_t e;
lcd_t db[4];
} lcd_config_t;

/**
 * @brief clear the display
 * 
 * @param[in] cfg port/pin configuration 
 */

void clear_display(lcd_config_t *cfg);

/**
 * @brief return the cursor home
 * 
 * @param[in] cfg port/pin configuration 
 */

void return_home(lcd_config_t *cfg);

/**
 * @brief select entry mode
 * 
 * @param[in] cfg port/pin configuration 
 */

void entry_mode_set(lcd_config_t *cfg);

/**
 * @brief allows for display configuration
 * @note display on/off blinker on/off cursor on/off
 * 
 * @param[in] cfg port/pin configuration 
 */

void display_ctrl_set(lcd_config_t *cfg);

/**
 * @brief cursor/display shift configuration
 * 
 * @param[in] cfg port/pin configuration 
 */

void cursor_display_shift(lcd_config_t *cfg);

/**
 * @brief allows for display function setup
 * 
 * @param[in] cfg port/pin configuration 
 */

void func_set(lcd_config_t *cfg);

/**
 * @brief set the cgram address
 * 
 * @param[in] cfg port/pin configuration 
 */

void set_cgram_addr(lcd_config_t *cfg);

#endif