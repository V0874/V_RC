#include "lcd_screen.h"

/**
 * @brief control commands to configure the display
 * 
 */

// clears the display and returns it to its original state
static const uint8_t CLEAR_DISPLAY = 0x01;
// returns the display to its original state if shifted
static const uint8_t RETURN_HOME = 0x02;
// configures the entry mode
static const uint8_t ENTRY_MODE_SETUP = 0x04;
// configures the display
static const uint8_t DISPLAY_SETUP = 0x08;
// configures cursor or display shift
static const uint8_t CURSOR_DISPLAY_SHIFT_SETUP = 0x10;
// configures data length / number of display lines / font
static const uint8_t FUNC_SETUP = 0x20;
// configures the cgram address and data is written/read from the mpu for cgram
static const uint8_t CGRAM_ADDR_SETUP = 0x40;

/**
 * @brief secondary commands to use with the control commands
 * 
 */

// toggles display: 1 = on 0 = off
static const uint8_t DISPLAY_TOGGLE = 0x04;
// toggles cursor: 1 = on 0 = off
static const uint8_t CURSOR_TOGGLE = 0x02;
// toggles character indicated by cursor blink: 1 = on 0 = off
static const uint8_t BLINK_TOGGLE = 0x01;
/* toggles display shift to the right or left: 1 = shifts display to right 
if i/d is 0 / left if 0 ---- if 0, the display does not shift at all*/
static const uint8_t SHIFT_DISPLAY_TOGGLE = 0x01;
// toggles increment/decrement on character entry: 1 = increment 0 = decrement
static const uint8_t INCREMENT_DECREMENT_TOGGLE = 0x02; 
// toggles the display shift to the right or left: 1 = right 0 = left
static const uint8_t SHIFT_RL_TOGGLE = 0x04;
// toggles the display shift / cursor move: 1 = display shift 0 = cursor move
static const uint8_t SHIFT_CURSOR_TOGGLE = 0x08;
// toggles the number of display lines: 1 = 2 lines 0 = 1 line
static const uint8_t NUMBER_LINES_TOGGLE = 0x08;
// toggles the font pixel selection: 1 = 5 x 10 dots 0 = 5 x 8 dots
static const uint8_t FONT_TOGGLE = 0x04;
// toggles the data length: 1 = 8 bits 0 = 4 bits
static const uint8_t DATA_LENGTH_TOGGLE = 0x10;

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
 * @param[in] ms delay in miliseconds 
 */

static void pulse(lcd_config_t *cfg, uint32_t ms){
    set_pin_high(cfg->e.port, cfg->e.pin);

    delay_us(ms);
    
    set_pin_low(cfg->e.port, cfg->e.pin);
    
    delay_us(ms);
}

/**
 * @brief sends a 4 bit nibble to the databus
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
    pulse(cfg, 2);
}

/**
 * @brief sends the high nibble only. this is needed for the initialization sequence.
 * 
 * @param[in] cfg port/pin configuration
 * @param[in] cmd command to send
 */

static void send_high_nib(lcd_config_t* cfg, const uint8_t cmd){
    const uint8_t high_nib = (cmd & HIGH_NIB_MASK) >> 4;

    set_pin_low(cfg->rs.port, cfg->rs.pin);
    set_pin_low(cfg->rw.port, cfg->rw.pin);

    send_nib(cfg, high_nib);    
}

/**
 * @brief sends a command for display configuration
 * 
 * @param[in] cfg port/pin configuration 
 * @param[in] cmd  command to send
 */

static void send_command(lcd_config_t *cfg, const uint8_t cmd){
    const uint8_t high_nib = (cmd & HIGH_NIB_MASK) >> 4;
    const uint8_t low_nib = cmd & LOW_NIB_MASK;

    set_pin_low(cfg->rs.port, cfg->rs.pin);
    set_pin_low(cfg->rw.port, cfg->rw.pin);

    send_nib(cfg, high_nib);
    send_nib(cfg, low_nib);
}

/**
 * @brief runs the initialization sequence for the display
 * 
 * @param[in] cfg port/pin configuration 
 */

void lcd_init(lcd_config_t *cfg){
    delay_ms(50);
    
    // pulse 8 bit data length three times to set data length mode

    send_high_nib(cfg, 0x30);

    delay_ms(5);

    send_high_nib(cfg, 0x30);

    delay_us(120);

    send_high_nib(cfg, 0x30);

    delay_us(120);

    // sets 4 bit mode

    send_high_nib(cfg, 0x20);

    delay_us(40);

    send_command(cfg, 0x28);

    delay_us(40);

    // toggles the display off
    send_command(cfg, 0x08);
    
    delay_us(40);

    // clears the display
    send_command(cfg, 0x01);

    delay_ms(2);

    // sets the entry mode, increment by 1, shift display off
    send_command(cfg, 0x06);

    delay_us(120);

    // toggles display on
    send_command(cfg, 0x0C);

    delay_us(40);
}

/**
 * @brief writes a character to the display
 * 
 * @param[in] cfg port/pin configuration
 * @param[in] ch char to send 
 */

void write_char(lcd_config_t *cfg, uint8_t ch){
    uint8_t high_nib = (ch & HIGH_NIB_MASK) >> 4;
    uint8_t low_nib = ch & LOW_NIB_MASK;

    set_pin_high(cfg->rs.port, cfg->rs.pin);
    set_pin_low(cfg->rw.port, cfg->rw.pin);

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
 * @brief setup entry mode configuration
 * 
 * @param[in] cfg port/pin configuration
 * @param[in] id increment/decrement cursor on read/write
 * @param[in] s shifts display right/left on read/write
 * @note increment = 1 decrement = 0
 *       shift left = 1 shift right = 0
 */      

void entry_mode_setup(lcd_config_t *cfg, uint8_t id, uint8_t s){
    uint8_t entry_mode = ENTRY_MODE_SETUP;

    if(id == 1) entry_mode |= INCREMENT_DECREMENT_TOGGLE;
    if(s == 1) entry_mode |= SHIFT_DISPLAY_TOGGLE;
    
    send_command(cfg, entry_mode);
}

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

void display_setup(lcd_config_t *cfg, uint8_t d, uint8_t c, uint8_t b){
    uint8_t display_config = DISPLAY_SETUP;

    if(d == 1) display_config |= DISPLAY_TOGGLE;
    if(c == 1) display_config |= CURSOR_TOGGLE;
    if(b == 1) display_config |= BLINK_TOGGLE;

    send_command(cfg, display_config);
}

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

void cursor_display_shift_setup(lcd_config_t *cfg, uint8_t sc, uint8_t rl){
    uint8_t cursor_display_config = CURSOR_DISPLAY_SHIFT_SETUP;

    if(sc == 1) cursor_display_config |= SHIFT_CURSOR_TOGGLE;
    if(rl == 1) cursor_display_config |= SHIFT_RL_TOGGLE;

    send_command(cfg, cursor_display_config);
}

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

void func_setup(lcd_config_t *cfg, uint8_t dl, uint8_t n, uint8_t f){
    uint8_t func_setup = FUNC_SETUP;

    if(dl == 1) func_setup |= DATA_LENGTH_TOGGLE;
    if(n == 1) func_setup |= NUMBER_LINES_TOGGLE;
    if(f == 1) func_setup |= FONT_TOGGLE;

    send_command(cfg, func_setup);
}

/**
 * @brief setup cgram address
 * 
 * @param[in] cfg port/pin configuration 
 */

void cgram_addr_setup(lcd_config_t *cfg){
    send_command(cfg, CGRAM_ADDR_SETUP);
}
