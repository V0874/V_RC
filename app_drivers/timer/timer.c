#include "timer.h"

/**
 * @brief initializes lower level periphs - timer clock / gpio
 * @note we don't need gpio as it is just a basic timer and we are just keeping time
 * @param[in] timer timer configuration handle 
 */

void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *timer){
    __HAL_RCC_TIM4_CLK_ENABLE();
}

/**
 * @brief initializes timer 4 - basic timer
 * 
 * @param[in] timer timer configuration handle 
 */

  void timer4_init(TIM_HandleTypeDef *timer){
   timer->Instance = TIM4;

   timer->Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
   timer->Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
   timer->Init.CounterMode = TIM_COUNTERMODE_UP;
   timer->Init.Period = 0x3e7;
   timer->Init.Prescaler = 0x0f;
   timer->Init.RepetitionCounter = 0x00;

   HAL_TIM_Base_Init(timer);
   HAL_TIM_Base_Start(timer);
  }


