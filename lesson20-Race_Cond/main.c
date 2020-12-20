#include <stdint.h> //uint32_t for type def c99 standart
//#include <intrinsics.h> //adds __enable_interrupt()
#include "TM4C1294NCPDT.h"
#include "delay.h"
#include "bsp.h"


int main(){
 
    SYSCTL->RCGCGPIO |= (1U << 5); //GPIO Clock Gating openning adress giving port
    //SYSCTL_RCGCGPIO_R   |= (1U << 12); //GPIO Clock Gating openning adress giving port 
    
    GPIOF_AHB->DIR  |= (LED_RED | LED_BLUE); //GPIO direction to out
    //GPIO_PORTN_DIR_R    |= (LED_RED | LED_BLUE); //GPIO direction to out
    
    GPIOF_AHB->DEN |= (LED_RED | LED_BLUE); //GPIO digital enable
    //GPIO_PORTN_DEN_R    |= (LED_RED | LED_BLUE); //GPIO digital enable

//    GPIOF_AHB->DATA |= LED_BLUE;
    //GPIO_PORTN_DATA_BITS_R[LED_BLUE] = LED_BLUE;
    
    //               Clk_SRC     INT_EN        EN
    SysTick->CTRL = (1U << 2) | (1U << 1) | (1U << 0); 
    
    SysTick->VAL  = 0U; //Clear on write
    SysTick->LOAD = SYS_CLK_HZ / 2 -1U ;//determines interrupt points
    
    __enable_irq(); //clear primask bit and enables ints
          
    while(1){
        __disable_irq(); //clear primask bit and enables ints
        GPIOF_AHB->DATA |= LED_RED;
        //GPIO_PORTN_DATA_BITS_R[LED_RED] = LED_RED;
        //delay(2000000);
        __enable_irq(); //clear primask bit and enables ints

        __disable_irq(); //clear primask bit and enables ints
        GPIOF_AHB->DATA &= ~LED_RED;
        //GPIO_PORTN_DATA_BITS_R[LED_RED] = 0;
        //delay(2000000);
        __enable_irq(); //clear primask bit and enables ints
    }
    //return 0;
}

