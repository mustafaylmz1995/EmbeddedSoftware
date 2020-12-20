#include <stdint.h> //uint32_t for type def c99 standart
//#include <intrinsics.h> //adds __enable_interrupt()
#include "TM4C1294NCPDT.h"
//#include "delay.h"
#include "bsp.h"
#include "miros.h"

void main_blinky1(void);
void main_blinky2(void);

uint32_t stack_blinky1[40];
OSThread *blinky1; 

void main_blinky1(void){

    while(1){
        
			BSP_ledRedOn();
			BSP_delay(1U*BSP_TICKS_PER_SEC/4U);	
			BSP_ledRedOff();		
      BSP_delay(3U*BSP_TICKS_PER_SEC/4U);	
			
    }
}


uint32_t stack_blinky2[40];
OSThread *blinky2;

void main_blinky2(void){

    while(1){
		
			BSP_ledBlueOn();
			BSP_delay(1U*BSP_TICKS_PER_SEC/4U);	
			BSP_ledBlueOff();
      BSP_delay(3U*BSP_TICKS_PER_SEC/4U);
			
    }
    //return 0;
}

int main(){

		BSP_init();
		OS_init();

		OSThread_start(&blinky1, &main_blinky1, stack_blinky1, sizeof(stack_blinky1));
		OSThread_start(&blinky2, &main_blinky2, stack_blinky2, sizeof(stack_blinky2));

		
		while(1){
			
			
		}
	
}