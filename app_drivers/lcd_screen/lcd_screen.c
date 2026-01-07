#include "lcd_screen.h"

/**
 * @brief constants for commands to send to the display
 * 
 */

static const uint8_t CLEAR_DISPLAY = 0x01;
static const uint8_t RETURN_HOME = 0x02;
static const uint8_t ENTRY_MODE_SET = 0x04;
static const uint8_t DISPLAY_CTRL = 0x08;
static const uint8_t CURSOR_DISPLAY_SHIFT = 0x10;
static const uint8_t FUNC_SET = 0x20;
static const uint8_t SET_CGRAM_ADDR = 0x40;

/**
 * @brief constants for masking data/commands into 4 bit values
 * 
 */

static const uint8_t HIGH_NIB_MASK = 0xf0;
static const uint8_t LOW_NIB_MASK = 0x0f;

/**
 * @brief pulse to latch the data to the display
 * 
 * @param[in] cfg port/pin configuration 
 */

static void pulse(lcd_config_t *cfg){
    set_pin_high(cfg->e.port, cfg->e.pin);
    
    delay(1);
    
    set_pin_low(cfg->e.port, cfg->e.pin);
    
    delay(1);
}

/**
 * @brief sends a 4 byte nibble to the databus
 * 
 * @param cfg port/pin configuration
 * @param[in] nib nibble to send 
 */

static void send_nib(lcd_config_t *cfg, const uint8_t nib){
    for(uint8_t i = 0; i < 4; i++){
        if((nib >> i) & 1)
        set_pin_high(cfg->db[i].port, cfg->db[i].pin);
        else
        set_pin_low(cfg->db[i].port, cfg->db[i].pin); 
    }
    pulse(cfg);
}

/**
 * @brief sends a command to send to the display
 * 
 * @param[in] cfg port/pin configuration 
 * @param[in] command  command to send
 */

static void send_command(lcd_config_t *cfg, const uint8_t command){
    const uint8_t high_nib = (command & HIGH_NIB_MASK) >> 4;
    const uint8_t low_nib = command & LOW_NIB_MASK;

    set_pin_low(cfg->rs.port, cfg->rs.pin);

    send_nib(cfg, high_nib);
    send_nib(cfg, low_nib);
}

/**
 * @brief sends a character to the display
 * 
 * @param[in] cfg port/pin configuration
 * @param[in] ch char to send 
 */

void send_char(lcd_config_t *cfg, uint8_t ch){
    uint8_t high_nib = (ch & HIGH_NIB_MASK) >> 4;
    uint8_t low_nib = ch & LOW_NIB_MASK;

    set_pin_high(cfg->rs.port, cfg->rs.pin);

    send_nib(cfg, high_nib);
    send_nib(cfg, low_nib);
}

/**
 * @brief clear the display
 * 
 * @param[in] cfg port/pin configuration 
 */

void clear_display(lcd_config_t *cfg){
    send_command(cfg, CLEAR_DISPLAY);
}

/**
 * @brief return the cursor home
 * 
 * @param[in] cfg port/pin configuration 
 */

void return_home(lcd_config_t *cfg){
    send_command(cfg, RETURN_HOME);
}

/**
 * @brief select entry mode
 * 
 * @param[in] cfg port/pin configuration 
 */

void entry_mode_set(lcd_config_t *cfg){
    send_command(cfg, ENTRY_MODE_SET);
}

/**
 * @brief allows for display configuration
 * @note display on/off blinker on/off cursor on/off
 * 
 * @param[in] cfg port/pin configuration 
 */

void display_ctrl_set(lcd_config_t *cfg){
    send_command(cfg, DISPLAY_CTRL);
}

/**
 * @brief cursor/display shift configuration
 * 
 * @param[in] cfg port/pin configuration 
 */

void cursor_display_shift(lcd_config_t *cfg){
    send_command(cfg, CURSOR_DISPLAY_SHIFT);
}

/**
 * @brief allows for display function setup
 * 
 * @param[in] cfg port/pin configuration 
 */

void func_set(lcd_config_t *cfg){
    send_command(cfg, FUNC_SET);
}

/**
 * @brief set the cgram address
 * 
 * @param[in] cfg port/pin configuration 
 */

void set_cgram_addr(lcd_config_t *cfg){
    send_command(cfg, SET_CGRAM_ADDR);
}