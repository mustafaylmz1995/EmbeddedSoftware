#include <stdint.h> //uint32_t for type def c99 standart
//#include <intrinsics.h> //adds __enable_interrupt()
//#include "TM4C1294NCPDT.h"
#include "delay.h"
#include "bsp.h"

#if 0
int main(){
	
	BSP_init();
	
    while(1){
        
			BSP_ledRedOn();
			BSP_delay(BSP_TICKS_PER_SEC/4U);	
			BSP_ledRedOff();		
      BSP_delay(3U*BSP_TICKS_PER_SEC/4U);	
			
			
			BSP_ledBlueOn();
			BSP_delay(2U*BSP_TICKS_PER_SEC/4U);	
			BSP_ledBlueOff();
      BSP_delay(BSP_TICKS_PER_SEC/4U);
			
    }
    //return 0;
}
#endif

//Non-Blocking Version

int main(){

	BSP_init();
	
	while(1){
		
		static enum {
			INITIAL = 0,
			OFF_STATE = 1,
			ON_STATE = 2
		} st = INITIAL;
		
		static uint32_t start;
		
		switch(st){
			case INITIAL :
				start = BSP_tickCtr();
				st = OFF_STATE;
				break;
			case OFF_STATE :
				if((BSP_tickCtr() - start) > BSP_TICKS_PER_SEC){
					BSP_ledRedOn();
					BSP_ledBlueOff();
					start = BSP_tickCtr();
					st = ON_STATE;
				}
				break;
			case ON_STATE :
				if((BSP_tickCtr() - start) > BSP_TICKS_PER_SEC){
					BSP_ledRedOff();
					BSP_ledBlueOn();
					start = BSP_tickCtr();
					st = OFF_STATE;
				}
				break;
			default :
				//error()
				break;
			
			
		}
		
		
	}
	

	//return 0;
	
}
