/* Board Support Package */

#include "TM4C1294NCPDT.h"
#include "bsp.h"

__stackless void assert_failed (char const *file, int line){
  /* TBD: damage control*/
  
  NVIC_SystemReset(); /*Reset the system*/
 
}
void SysTick_IRQHandler(void){
  GPIOF_AHB->DATA ^= LED_RED;
  GPIOF_AHB->DATA ^= LED_BLUE;
   
}