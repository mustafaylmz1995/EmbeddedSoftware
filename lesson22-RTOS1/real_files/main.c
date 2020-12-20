#include <stdint.h> //uint32_t for type def c99 standart
//#include <intrinsics.h> //adds __enable_interrupt()
//#include "TM4C1294NCPDT.h"
#include "delay.h"
#include "bsp.h"

void main_blinky1(void);
void main_blinky2(void);

uint32_t stack_blinky1[40];
uint32_t *sp_blinky1; 

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
	
	/* fabricate Cortex-M ISR stack frame for blinky1 */
	*(--sp_blinky1) = (1U << 24);  /* xPSR */
	*(--sp_blinky1) = (uint32_t)&main_blinky1; /* PC */
	*(--sp_blinky1) = 0x0000000EU; /* LR  */
	*(--sp_blinky1) = 0x0000000CU; /* R12 */
	*(--sp_blinky1) = 0x00000003U; /* R3  */
	*(--sp_blinky1) = 0x00000002U; /* R2  */
	*(--sp_blinky1) = 0x00000001U; /* R1  */
	*(--sp_blinky1) = 0x00000000U; /* R0  */
	/* additionally, fake registers R4-R11 */
	*(--sp_blinky1) = 0x0000000BU; /* R11 */
	*(--sp_blinky1) = 0x0000000AU; /* R10 */
	*(--sp_blinky1) = 0x00000009U; /* R9 */
	*(--sp_blinky1) = 0x00000008U; /* R8 */
	*(--sp_blinky1) = 0x00000007U; /* R7 */
	*(--sp_blinky1) = 0x00000006U; /* R6 */
	*(--sp_blinky1) = 0x00000005U; /* R5 */
	*(--sp_blinky1) = 0x00000004U; /* R4 */


	/* fabricate Cortex-M ISR stack frame for blinky2 */
	*(--sp_blinky2) = (1U << 24);  /* xPSR */
	*(--sp_blinky2) = (uint32_t)&main_blinky2; /* PC */
	*(--sp_blinky2) = 0x0000000EU; /* LR  */
	*(--sp_blinky2) = 0x0000000CU; /* R12 */
	*(--sp_blinky2) = 0x00000003U; /* R3  */
	*(--sp_blinky2) = 0x00000002U; /* R2  */
	*(--sp_blinky2) = 0x00000001U; /* R1  */
	*(--sp_blinky2) = 0x00000000U; /* R0  */
	/* additionally, fake registers R4-R11 */
	*(--sp_blinky2) = 0x0000000BU; /* R11 */
	*(--sp_blinky2) = 0x0000000AU; /* R10 */
	*(--sp_blinky2) = 0x00000009U; /* R9 */
	*(--sp_blinky2) = 0x00000008U; /* R8 */
	*(--sp_blinky2) = 0x00000007U; /* R7 */
	*(--sp_blinky2) = 0x00000006U; /* R6 */
	*(--sp_blinky2) = 0x00000005U; /* R5 */
	*(--sp_blinky2) = 0x00000004U; /* R4 */
	
	
	while(1){
		
		
	}
	
	
	
	
	


}
