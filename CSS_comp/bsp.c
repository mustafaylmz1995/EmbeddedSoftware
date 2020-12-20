/* Board Support Package */

#include "TM4C1294NCPDT.h"
#include "bsp.h"

__attribute__((naked)) void assert_failed (char const *file, int line){
  /* TBD: damage control*/
  
  NVIC_SystemReset(); /*Reset the system*/
 
}

void SysTick_IRQHandler(void){
  GPION->DATA ^= LED_BLUE;
}
