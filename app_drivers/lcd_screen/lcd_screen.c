#include "lcd_screen.h"

/**
 * @brief clears the reg select pin / read/write pin and the databus pins
 * 
 * @param config lcd port/pin config
 */

static void clear_pins(const lcd_config_t *config){
    for(int i = 0; i < 8; i++){
        HAL_GPIO_WritePin(config->data_bus[i].port, config->data_bus[i].pin, GPIO_PIN_RESET);
    }
    HAL_GPIO_WritePin(config->reg_select.port, config->reg_select.pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(config->read_write.port, config->read_write.pin, GPIO_PIN_RESET);
}

/**
 * @brief clears the databus pins
 * 
 * @param config lcd port/pin config
 */

static void clear_databus(const lcd_config_t *config){
    for(int i = 0; i < 8; i++){
        HAL_GPIO_WritePin(config->data_bus[i].port, config->data_bus[i].pin, GPIO_PIN_RESET);
    }
}

/**
 * @brief clears the reg select pin and read/write pin
 * 
 * @param config lcd port/pin config 
 */

static void clear_rs_rw(const lcd_config_t* config){
    HAL_GPIO_WritePin(config->reg_select.port, config->reg_select.pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(config->read_write.port, config->read_write.pin, GPIO_PIN_RESET);
}

/**
 * @brief clears the display to its original state
 * 
 * @param config lcd port/pin config 
 */

void display_clear(const lcd_config_t *config){
    clear_pins(config);
    HAL_GPIO_WritePin(config->data_bus[0].port, config->data_bus[0].pin, GPIO_PIN_SET);
}

/**
 * @brief shifts the entire display to the left
 * 
 * @param config lcd port/pin config
 * @note the cursor follows the display shift
 */

void shift_display_left(const lcd_config_t *config){
    clear_pins(config);
    HAL_GPIO_WritePin(config->data_bus[3].port, config->data_bus[3].pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(config->data_bus[4].port, config->data_bus[4].pin, GPIO_PIN_SET);
}

/**
 * @brief shifts the entire display to the right
 * 
 * @param config lcd port/pin config
 * @note the cursor follows the displays shift
 */

void shift_display_right(const lcd_config_t *config){
    clear_pins(config);
    HAL_GPIO_WritePin(config->data_bus[2].port, config->data_bus[2].pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(config->data_bus[3].port, config->data_bus[3].pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(config->data_bus[4].port, config->data_bus[4].pin, GPIO_PIN_SET);
}

/**
 * @brief shifts the cursor one value to the left
 * 
 * @param config lcd port/pin config 
 */

void shift_cursor_left(const lcd_config_t* config){
    clear_pins(config);
    HAL_GPIO_WritePin(config->data_bus[4].port, config->data_bus[4].pin, GPIO_PIN_SET);
}

/**
 * @brief shifts the cursor one value to the right
 * 
 * @param config lcd port/pin config 
 */

void shift_cursor_right(const lcd_config_t* config){
    clear_pins(config);
    HAL_GPIO_WritePin(config->data_bus[4].port, config->data_bus[4].pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(config->data_bus[2].port, config->data_bus[2].pin, GPIO_PIN_SET);
}

/**
 * @brief writes to the screen
 * 
 * @param config 
 * @param ch 
 */

void display_write(const lcd_config_t *config, const uint8_t ch){
    
}

/**
 * @brief turns on the display
 * 
 * @param config lcd port/pin config
 */

void display_on(const lcd_config_t *config){
    
}

/**
 * @brief turns off the display
 * 
 * @param config lcd port/pin config
 */

void display_off(const lcd_config_t *config){

}

/**
 * @brief returns the cursor to the main edge of the display
 * 
 * @param config lcd port/pin config
 */

void cursor_home(const lcd_config_t *config){
    clear_pins(config);
    HAL_GPIO_WritePin(config->data_bus[1].port, config->data_bus[1].pin, GPIO_PIN_SET);
}

/**
 * @brief turns cursor on
 * 
 * @param config lcd port/pin config
 */

void cursor_on(const lcd_config_t *config){

}

/**
 * @brief turns cursor off
 * 
 * @param config lcd port/pin config
 */

void cursor_off(const lcd_config_t *config){

}

/**
 * @brief 
 * 
 * @param config lcd port/pin config 
 */

void display_ch_blink(const lcd_config_t *config){

}