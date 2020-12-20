/*
This file is created for educational purposes.
Do not use on real time applications or your project.
For any kind of hazardous problem users are responsible.

Contact:
Mustafa Yilmaz
mustafaylmz1995@gmail.com
*/

#include <stdint.h> //uint32_t for type def c99 standart
#include "miros.h"
#include "TM4C1294NCPDT.h" /* the TM4C MCU Peripheral Access Layer (TI) */



// Decide how to keep track current and next thread
// we add 2 OSThread object
OSThread * volatile OS_curr; /* pointer to current thread */
OSThread * volatile OS_next; /* pointer to next thread to run */
// We add volatile because they are in interrupts
// We add them after the asterix because we want to volatile pointer
// If we add before the asterisk we get non-volatile pointer
// pointing a volatile OSThread struct



void OS_init(void){
		/*Set the PendSV interrupt priority to the lowest level*/
		*(uint32_t volatile *)0xE000ED20 |= (0xFFU << 16);
		// To make it is universal(M0, M3, M4) we changed SYSPRI3 register in terms of
		// register instead of CMSIS file
}


void OS_sched(void){
		/* OS_next = ...*/
		
		if(OS_next != OS_curr){
				*(uint32_t volatile *)0xE000ED04 = (1U << 28);
		}
	
}


/*register saves*/
void OSThread_start(OSThread *me, OSThreadHandler threadHandler, void *stkSto, uint32_t stkSize){

		// To round down to 8 byte boundry for Cortex-M
		// high to low for stack
		uint32_t *sp = (uint32_t *)((((uint32_t)stkSto +stkSize)/ 8) *8);
		
		uint32_t *stk_limit;
			
			/* fabricate Cortex-M ISR stack frame for blinky1 */
		*(--sp) = (1U << 24);  /* xPSR */
		*(--sp) = (uint32_t)threadHandler; /* PC */
		*(--sp) = 0x0000000EU; /* LR  */
		*(--sp) = 0x0000000CU; /* R12 */
		*(--sp) = 0x00000003U; /* R3  */
		*(--sp) = 0x00000002U; /* R2  */
		*(--sp) = 0x00000001U; /* R1  */
		*(--sp) = 0x00000000U; /* R0  */
		/* additionally, fake registers R4-R11 */
		*(--sp) = 0x0000000BU; /* R11 */
		*(--sp) = 0x0000000AU; /* R10 */
		*(--sp) = 0x00000009U; /* R9 */
		*(--sp) = 0x00000008U; /* R8 */
		*(--sp) = 0x00000007U; /* R7 */
		*(--sp) = 0x00000006U; /* R6 */
		*(--sp) = 0x00000005U; /* R5 */
		*(--sp) = 0x00000004U; /* R4 */

		/* save the top of the stack in thread's attribute */
		me->sp = sp;

		/*To see unused stacks in memory view*/
		stk_limit = (uint32_t *)(((((uint32_t)stkSto - 1U) /8) +1U)*8);
		
		/*pre-fill the unused part of stack with 0xDEADBEEF*/
		for(sp = sp-1U; sp >= stk_limit; --sp){
				*sp = 0xDEADBEEFU;
		}
}


__asm
void PendSV_IRQHandler(void){
	
	IMPORT OS_curr /*extern variables*/
	IMPORT  OS_next /*extern variables*/
		
// Opcode	   instr.		
//	in the first time OS_curr will be zero out of reset. 
		CPSID         I
	
//	if(OS_curr != (OSThread *)0){ 
		LDR           r1,=OS_curr
		LDR           r1,[r1,#0x00]
		CBZ           r1,PendSV_restore
	
//		/*push regiters r4-r11 on the stack*/ 
		PUSH					{r4-r11}

//		OS_curr->sp  = sp; 
		LDR           r1,=OS_curr
		LDR           r1,[r1,#0x00]	
		STR           sp,[r1,#0x00]
//	} 
		
PendSV_restore
		
//	sp = OS_next->sp; 
		LDR           r1,=OS_next
		LDR           r1,[r1,#0x00]
		LDR           sp,[r1,#0x00]
		
//	OS_curr = OS_next; 
		LDR           r1,=OS_next
		LDR           r1,[r1,#0x00]
		LDR           r2,=OS_curr
		STR           r1,[r2,#0x00]
		
//	/*pop regiters r4-r11 */ 
		POP					{r4-r11}
		
//	__enable_irq(); 
		CPSIE         I
		
// return to the next thread		
		BX            lr

}
