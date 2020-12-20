/*
This file is created for educational purposes.
Do not use on real time applications or your project.
For any kind of hazardous problem users are responsible.

Contact:
Mustafa Yilmaz
mustafaylmz1995@gmail.com
*/


#ifndef __MIROS_H__
#define __MIROS_H__

#include <stdint.h>

/* Thread Control Block (TCB) */
/* Traditional data structure associated with thread is called as like.*/
typedef struct {
		void *sp; /* stack pointer*/
	
}OSThread;

//pointer a function taking no arguments and returnng void
typedef void (*OSThreadHandler)();

void OS_init(void);

//this func. must be called with interrupt DISABLE
void OS_sched(void);

/*register saves*/
void OSThread_start(OSThread *me, //pointer to TCB 
	OSThreadHandler threadHandler, //function to thread handler
	void *stkSto, // thread start function
	uint32_t stkSize);	//size of stack


#endif //__MIROS_H__
