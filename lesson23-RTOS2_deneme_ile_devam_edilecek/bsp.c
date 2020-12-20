/* Board Support Package (BSP) for the EK-TM4C123GXL board */
#include <stdint.h>  /* Standard integers. WG14/N843 C99 Standard */

#include "bsp.h"
#include "miros.h"
#include "TM4C1294NCPDT.h" /* the TM4C MCU Peripheral Access Layer (TI) */

/* on-board LEDs */
#define LED_RED (1U<<4)
#define LED_BLUE (1U<<0)
#define SYS_CLK_HZ 2000000


uint32_t volatile l_tickCtr;

void SysTick_IRQHandler(void) {
		++l_tickCtr;
	
		__disable_irq();
		OS_sched();
		__enable_irq();
}

void BSP_init(void) {
 
    SYSCTL->RCGCGPIO |= (1U << 5); //GPIO Clock Gating openning adress giving port 
    //SYSCTL_RCGCGPIO_R   |= (1U << 12); //GPIO Clock Gating openning adress giving port 
    
    GPIOF_AHB->DIR  |= (LED_RED | LED_BLUE); //GPIO direction to out
    //GPIO_PORTN_DIR_R    |= (LED_RED | LED_BLUE); //GPIO direction to out
    
    GPIOF_AHB->DEN |= (LED_RED | LED_BLUE); //GPIO digital enable
    //GPIO_PORTN_DEN_R    |= (LED_RED | LED_BLUE); //GPIO digital enable

//    GPION->DATA |= LED_BLUE;
    //GPIO_PORTN_DATA_BITS_R[LED_BLUE] = LED_BLUE;
    
	
	
    //               Clk_SRC     INT_EN        EN
//    SysTick->CTRL = (1U << 2) | (1U << 1) | (1U << 0); 
    
	SystemCoreClockUpdate();
	SysTick_Config(SystemCoreClock / BSP_TICKS_PER_SEC);
	
 //   SysTick->VAL  = 0U; //Clear on write
 //   SysTick->LOAD = SYS_CLK_HZ / 2 -1U ;//determines interrupt points
		/* Set the systick interrupt pri. highest */
		NVIC_SetPriority(SysTick_IRQn, 0U);
		
		
		
    __enable_irq(); //clear primask bit and enables ints
 
}

uint32_t BSP_tickCtr(void) {
    uint32_t tickCtr;

    __disable_irq();
    tickCtr = l_tickCtr;
    __enable_irq();

    return tickCtr;
}

void BSP_delay(uint32_t ticks) {
    uint32_t start = BSP_tickCtr();
    while ((BSP_tickCtr() - start) < ticks) {
    }
}

void BSP_ledRedOn(void) {
	GPIOF_AHB->DATA |= LED_RED;
//    GPIO_PORTN_DATA_BITS_R[LED_RED] = LED_RED;
}

void BSP_ledRedOff(void) {
	GPIOF_AHB->DATA &= ~LED_RED;
//    GPIO_PORTN_DATA_BITS_R[LED_RED] = 0U;
}

void BSP_ledBlueOn(void) {
	GPIOF_AHB->DATA |= LED_BLUE;
//    GPIO_PORTN_DATA_BITS_R[LED_BLUE] = LED_BLUE;
}

void BSP_ledBlueOff(void) {
	GPIOF_AHB->DATA &= ~LED_BLUE;
	//    GPIO_PORTN_DATA_BITS_R[LED_BLUE] = 0U;
}

//void BSP_ledGreenOn(void) {
//    GPIOF_AHB->DATA_Bits[LED_GREEN] = LED_GREEN;
//}
//
//void BSP_ledGreenOff(void) {
//    GPIOF_AHB->DATA_Bits[LED_GREEN] = 0U;
//}





