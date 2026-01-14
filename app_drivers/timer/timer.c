#include "timer.h"

void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *timer){
    __HAL_RCC_TIM4_CLK_ENABLE();
}


 /**
  * @brief initializes timer4
  * 
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
  }
