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
 *       8 bit may be supported later but 4 bit is simpler and uses less pins
 */

typedef struct{
lcd_t rs;
lcd_t rw;
lcd_t e;
lcd_t db[4];
} lcd_config_t;

/**
 * @brief runs the initialization sequence for the display
 * 
 * @param[in] cfg port/pin configuration 
 */

void lcd_init(lcd_config_t *cfg);

/**
 * @brief writes a character to the display
 * 
 * @param[in] cfg port/pin configuration
 * @param[in] ch char to send 
 */

void write_char(lcd_config_t *cfg, uint8_t ch);

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
 * @brief setup entry mode configuration
 * 
 * @param[in] cfg port/pin configuration
 * @param[in] id increment/decrement cursor on read/write
 * @param[in] s shifts display right/left on read/write
 * @note increment = 1 decrement = 0
 *       shift left = 1 shift right = 0
 */      

void entry_mode_setup(lcd_config_t *cfg, uint8_t id, uint8_t s);

/**
 * @brief setup display configuration
 * 
 * @param[in] cfg port/pin configuration
 * @param[in] d toggles the display on/off
 * @param[in] c toggles the cursor on/off 
 * @param[in] b toggles blink cursor on/off
 * @note 1 = display on 0 = display off
 *       1 = cursor on 0 = display off
 *       1 = blink on 0 = blink off
 */

void display_setup(lcd_config_t *cfg, uint8_t d, uint8_t c, uint8_t b);

/**
 * @brief setup cursor/display shift configuration
 * 
 * @param[in] cfg port/pin configuration
 * @param[in] sc display shift / cursor move
 * @param[in] rl shift to the right / left 
 * @note sc: 0 rl: 0 = shifts the cursor to the left
 *       sc: 0 rl: 1 = shifts the cursor to the right
 *       sc: 1 rl: 0 shifts the entire display to the left - cursor follows
 *       sc: 1 rl: 1 shifts the entire display to the right - cursor follows
 */

void cursor_display_shift_setup(lcd_config_t *cfg, uint8_t sc, uint8_t rl);

/**
 * @brief setup function configuration
 * 
 * @param[in] cfg port/pin configuration 
 * @param[in] dl data length
 * @param[in] n number of lines
 * @param[in] f font
 * @note 8 bits = 1 / 4 bits = 0
 *       2 lines = 1 / 1 line = 0
 *       5 x 10 dots = 1 / 5 x 8 dots = 0
 */

void func_setup(lcd_config_t *cfg, uint8_t dl, uint8_t n, uint8_t f);

/**
 * @brief setup cgram address
 * 
 * @param[in] cfg port/pin configuration 
 */

void cgram_addr_setup(lcd_config_t *cfg);

#endif