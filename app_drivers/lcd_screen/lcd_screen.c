#include "lcd_screen.h"

/**
 * @brief pulses the E pin to latch the data sent on the bus
 * 
 * @param[in] cfg port/pin config 
 */

static void pulse(const lcd_config_t *cfg){
    HAL_GPIO_WritePin(cfg->e.port, cfg->e.pin, GPIO_PIN_SET);

    HAL_Delay(1);

    HAL_GPIO_WritePin(cfg->e.port, cfg->e.pin, GPIO_PIN_RESET);
}

/**
 * @brief clears the databus pins
 * 
 * @param[in] cfg lcd port/pin config
 */

static void clear_databus(const lcd_config_t *cfg){
    for(int i = 0; i < 4; i++){
        HAL_GPIO_WritePin(cfg->db[i].port, cfg->db[i].pin, GPIO_PIN_RESET);
    }
    pulse(cfg);
}

/**
 * @brief clears the reg select pin and read/write pin
 * 
 * @param[in] cfg lcd port/pin cfg 
 */

static void clear_rs_rw(const lcd_config_t* cfg){
    HAL_GPIO_WritePin(cfg->rs.port, cfg->rs.pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(cfg->rw.port, cfg->rw.pin, GPIO_PIN_RESET);

    pulse(cfg);
}

/**
 * @brief clears the reg select pin / read/write pin and the databus pins
 * 
 * @param[in] cfg lcd port/pin config
 */

static void clear_pins(const lcd_config_t *cfg){
    clear_databus(cfg);
    clear_rs_rw(cfg);
    
    pulse(cfg);
}

/**
 * @brief clears the display to its original state
 * 
 * @param[in] cfg lcd port/pin config 
 */

void display_clear(const lcd_config_t *cfg){
    clear_pins(cfg);

    HAL_GPIO_WritePin(cfg->db[0].port, cfg->db[0].pin, GPIO_PIN_SET);

    pulse(cfg);
    }

 /**
 * @brief returns the cursor to the main edge of the display
 * 
 * @param[in] cfg lcd port/pin config
 */

void cursor_home(const lcd_config_t *cfg){
    clear_pins(cfg);

    HAL_GPIO_WritePin(cfg->db[1].port, cfg->db[1].pin, GPIO_PIN_SET);

    pulse(cfg);
}   

/**
 * @brief shifts the entire display to the left
 * 
 * @param[in] cfg lcd port/pin config
 * @note the cursor follows the display shift
 */

void shift_display_left(const lcd_config_t *cfg){
    clear_pins(cfg);

    HAL_GPIO_WritePin(cfg->db[3].port, cfg->db[3].pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(cfg->db[4].port, cfg->db[4].pin, GPIO_PIN_SET);

    pulse(cfg);
}

/**
 * @brief shifts the entire display to the right
 * 
 * @param[in] cfg lcd port/pin config
 * @note the cursor follows the displays shift
 */

void shift_display_right(const lcd_config_t *cfg){
    clear_pins(cfg);

    HAL_GPIO_WritePin(cfg->db[2].port, cfg->db[2].pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(cfg->db[3].port, cfg->db[3].pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(cfg->db[4].port, cfg->db[4].pin, GPIO_PIN_SET);

    pulse(cfg);
}

/**
 * @brief shifts the cursor one value to the left
 * 
 * @param[in] cfg lcd port/pin config 
 */

void shift_cursor_left(const lcd_config_t* cfg){
    clear_pins(cfg);

    HAL_GPIO_WritePin(cfg->db[4].port, cfg->db[4].pin, GPIO_PIN_SET);

    pulse(cfg);
}

/**
 * @brief shifts the cursor one value to the right
 * 
 * @param[in] cfg lcd port/pin config 
 */

void shift_cursor_right(const lcd_config_t* cfg){
    clear_pins(cfg);

    HAL_GPIO_WritePin(cfg->db[4].port, cfg->db[4].pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(cfg->db[2].port, cfg->db[2].pin, GPIO_PIN_SET);

    pulse(cfg);
}

/**
 * @brief writes to the screen
 * 
 * @param[in] cfg port/pin lcd config 
 * @param[in] ch accepts most ascii char
 * @note some special characters must be built
 */

void display_write(const lcd_config_t *cfg, const uint8_t ch){
    
}

/**
 * @brief turns on the display
 * 
 * @param[in] cfg lcd port/pin config
 */

void display_on(const lcd_config_t *cfg){
    HAL_GPIO_WritePin(cfg->db[2].port, cfg->db[2].pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(cfg->db[3].port, cfg->db[3].pin, GPIO_PIN_SET);

    pulse(cfg);
}

/**
 * @brief turns off the display
 * 
 * @param[in] cfg lcd port/pin config
 */

void display_off(const lcd_config_t *cfg){
    HAL_GPIO_WritePin(cfg->db[2].port, cfg->db[2].pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(cfg->db[3].port, cfg->db[3].pin, GPIO_PIN_SET);

    pulse(cfg);
}

/**
 * @brief turns cursor on
 * 
 * @param[in] cfg lcd port/pin config
 */

void cursor_on(const lcd_config_t *cfg){
    HAL_GPIO_WritePin(cfg->db[1].port, cfg->db[1].pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(cfg->db[3].port, cfg->db[3].pin, GPIO_PIN_SET);

    pulse(cfg);
}

/**
 * @brief turns cursor off
 * 
 * @param[in] cfg lcd port/pin config
 */

void cursor_off(const lcd_config_t *cfg){
    HAL_GPIO_WritePin(cfg->db[1].port, cfg->db[1].pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(cfg->db[3].port, cfg->db[3].pin, GPIO_PIN_SET);

    pulse(cfg);
}

/**
 * @brief turns blink on for current cursor position
 * 
 * @param[in] cfg lcd port/pin config 
 */

void blink_on(const lcd_config_t *cfg){
    HAL_GPIO_WritePin(cfg->db[0].port, cfg->db[0].pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(cfg->db[3].port, cfg->db[3].pin, GPIO_PIN_SET);

    pulse(cfg);
}

/**
 * @brief turns blink off for current cursor position
 * 
 * @param cfg lcd port/pin config 
 */

void blink_off(const lcd_config_t *cfg){
    HAL_GPIO_WritePin(cfg->db[0].port, cfg->db[0].pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(cfg->db[3].port, cfg->db[3].pin, GPIO_PIN_SET);

    pulse(cfg);
}

