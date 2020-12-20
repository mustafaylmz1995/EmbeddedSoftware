#include <stdint.h> //uint32_t for type def c99 standart
//#include <intrinsics.h> //adds __enable_interrupt()
//#include "TM4C1294NCPDT.h"
//#include "delay.h"
#include "bsp.h"

#define LED_RED (1U<<4)
#define LED_BLUE (1U<<0)

uint32_t stack_blinky1[40];
uint32_t* sp_blinky1;


void main_blinky1(void){

    while(1){
        
			BSP_ledRedOn();
			BSP_delay(1U*BSP_TICKS_PER_SEC/4U);	
			BSP_ledRedOff();		
      BSP_delay(3U*BSP_TICKS_PER_SEC/4U);	
			
    }
}


uint32_t stack_blinky2[40];
uint32_t *sp_blinky2;

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

	
	sp_blinky1 = &stack_blinky1[40];
	sp_blinky2 = &stack_blinky2[40];
	
	BSP_init();
	
//	uint32_t volatile run = 0U;
//	if(run){
//		main_blinky1();
//	}else{
//		main_blinky2();
//	}
	
	*(--sp_blinky1) = 0x01000000U; //(1U << 24); 
	*(--sp_blinky1) = (uint32_t)&main_blinky1;
  *(--sp_blinky1) = 0x0000000EU;
	*(--sp_blinky1) = 0x0000000CU;
	*(--sp_blinky1) = 0x00000003U;
	*(--sp_blinky1) = 0x00000002U;
	*(--sp_blinky1) = 0x00000001U;
	*(--sp_blinky1) = 0x00000000U;
	
	
	*(--sp_blinky2) = (1U << 24);
	*(--sp_blinky2) = (uint32_t)&main_blinky2;
  *(--sp_blinky2) = 0x0000000EU;
	*(--sp_blinky2) = 0x0000000CU;
	*(--sp_blinky2) = 0x00000003U;
	*(--sp_blinky2) = 0x00000002U;
	*(--sp_blinky2) = 0x00000001U;
	*(--sp_blinky2) = 0x00000000U;
	

	while(1){
		
//		BSP_ledRedOn();
//		BSP_delay(BSP_TICKS_PER_SEC/4U);
//		BSP_ledRedOff();
//		BSP_delay(BSP_TICKS_PER_SEC*3U/4U);
//		
//		BSP_ledBlueOn();
//		BSP_delay(BSP_TICKS_PER_SEC/4U);
//		BSP_ledBlueOff();
//		BSP_delay(BSP_TICKS_PER_SEC*3U/4U);
		
	}
	
	
	
	
	


}
