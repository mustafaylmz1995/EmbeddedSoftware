/*Startup code for TM4C*/
#include "TM4C1294NCPDT.h"

extern int CSTACK$$Limit;
void __iar_program_start(void);

//void Reset_IRQHandler(void);            
void NonMaskableInt_IRQHandler(void);   
void HardFault_IRQHandler(void);        
void MemoryManagement_IRQHandler(void); 
                     
void BusFault_IRQHandler(void);         
                       
void UsageFault_IRQHandler(void);       
void SVCall_IRQHandler(void);           
void DebugMonitor_IRQHandler(void);     
void PendSV_IRQHandler(void);           
void SysTick_IRQHandler(void);

void unused_Handler(void);

int const __vector_table[] @ ".intvec"= {
    (int)&CSTACK$$Limit,        // 0
    (int)&__iar_program_start,  // 1 //gives adress of func
    (int)&NonMaskableInt_IRQHandler,          //2
    (int)&HardFault_IRQHandler,    //3
    (int)&MemoryManagement_IRQHandler,    //4
    (int)&BusFault_IRQHandler,     //5
    (int)&UsageFault_IRQHandler,   //6
    0,                          //7
    0,                          //8
    0,                          //9
    0,                          //10
    (int)&SVCall_IRQHandler,          //11
    (int)&DebugMonitor_IRQHandler,     //12
    0,                          //13
    (int)&PendSV_IRQHandler,       //14
    (int)&SysTick_IRQHandler,      //15
    
    /*External_interrupts(IRQs)*/

    (int)&GPIOA_IRQHandler           ,  //16 
    (int)&GPIOB_IRQHandler           ,  //17 
    (int)&GPIOC_IRQHandler           ,  //18 
    (int)&GPIOD_IRQHandler           ,  //19 
    (int)&GPIOE_IRQHandler           ,  //20 
    (int)&UART0_IRQHandler           ,  //21 
    (int)&UART1_IRQHandler           ,  //22 
    (int)&SSI0_IRQHandler            ,  //23 
    (int)&I2C0_IRQHandler            ,  //24 
    (int)&PWM0_FAULT_IRQHandler      ,  //25 
    (int)&PWM0_0_IRQHandler          ,  //26 
    (int)&PWM0_1_IRQHandler          ,  //27 
    (int)&PWM0_2_IRQHandler          ,  //28 
    (int)&QEI0_IRQHandler            ,  //29 
    (int)&ADC0SS0_IRQHandler         ,  //30 
    (int)&ADC0SS1_IRQHandler         ,  //31 
    (int)&ADC0SS2_IRQHandler         ,  //32 
    (int)&ADC0SS3_IRQHandler         ,  //33 
    (int)&WATCHDOG0_IRQHandler       ,  //34 
    (int)&TIMER0A_IRQHandler         ,  //35 
    (int)&TIMER0B_IRQHandler         ,  //36 
    (int)&TIMER1A_IRQHandler         ,  //37 
    (int)&TIMER1B_IRQHandler         ,  //38 
    (int)&TIMER2A_IRQHandler         ,  //39 
    (int)&TIMER2B_IRQHandler         ,  //40 
    (int)&COMP0_IRQHandler           ,  //41 
    (int)&COMP1_IRQHandler           ,  //42 
    (int)&COMP2_IRQHandler           ,  //43 
    (int)&SYSCTL_IRQHandler          ,  //44 
    (int)&FLASH_CTRL_IRQHandler      ,  //45 
    (int)&GPIOF_IRQHandler           ,  //46 
    (int)&GPIOG_IRQHandler           ,  //47
    (int)&GPIOH_IRQHandler           ,  //48 
    (int)&UART2_IRQHandler           ,  //49 
    (int)&SSI1_IRQHandler            ,  //50 
    (int)&TIMER3A_IRQHandler         ,  //51 
    (int)&TIMER3B_IRQHandler         ,  //52 
    (int)&I2C1_IRQHandler            ,  //53 
    (int)&CAN0_IRQHandler            ,  //54 
    (int)&CAN1_IRQHandler            ,  //55 
    (int)&EMAC0_IRQHandler           ,  //56 
    (int)&HIB_IRQHandler             ,  //57 
    (int)&USB0_IRQHandler            ,  //58 
    (int)&PWM0_3_IRQHandler          ,  //59 
    (int)&UDMA_IRQHandler            ,  //60 
    (int)&UDMAERR_IRQHandler         ,  //61 
    (int)&ADC1SS0_IRQHandler         ,  //62 
    (int)&ADC1SS1_IRQHandler         ,  //63 
    (int)&ADC1SS2_IRQHandler         ,  //64 
    (int)&ADC1SS3_IRQHandler         ,  //65
    (int)&EPI0_IRQHandler            ,  //66 
    (int)&GPIOJ_IRQHandler           ,  //67 
    (int)&GPIOK_IRQHandler           ,  //68 
    (int)&GPIOL_IRQHandler           ,  //69 
    (int)&SSI2_IRQHandler            ,  //70 
    (int)&SSI3_IRQHandler            ,  //71 
    (int)&UART3_IRQHandler           ,  //72 
    (int)&UART4_IRQHandler           ,  //73 
    (int)&UART5_IRQHandler           ,  //74 
    (int)&UART6_IRQHandler           ,  //75 
    (int)&UART7_IRQHandler           ,  //76 
    (int)&I2C2_IRQHandler            ,  //77 
    (int)&I2C3_IRQHandler            ,  //78 
    (int)&TIMER4A_IRQHandler         ,  //79 
    (int)&TIMER4B_IRQHandler         ,  //80 
    (int)&TIMER5A_IRQHandler         ,  //81 
    (int)&TIMER5B_IRQHandler         ,  //82 
    (int)&SYSEXC_IRQHandler          ,  //83
    0				     ,  //84
    0                                ,  //85
    (int)&I2C4_IRQHandler            ,  //86 
    (int)&I2C5_IRQHandler            ,  //87
    (int)&GPIOM_IRQHandler           ,  //88
    (int)&GPION_IRQHandler           ,  //89
    0                                ,  //90
    0                                ,  //91
    (int)&GPIOP0_IRQHandler          ,  //92 
    (int)&GPIOP1_IRQHandler          ,  //93
    (int)&GPIOP2_IRQHandler          ,  //94
    (int)&GPIOP3_IRQHandler          ,  //95
    (int)&GPIOP4_IRQHandler          ,  //96
    (int)&GPIOP5_IRQHandler          ,  //97
    (int)&GPIOP6_IRQHandler          ,  //98
    (int)&GPIOP7_IRQHandler          ,  //99
    (int)&GPIOQ0_IRQHandler          ,  //100
    (int)&GPIOQ1_IRQHandler          ,  //101
    (int)&GPIOQ2_IRQHandler          ,  //102
    (int)&GPIOQ3_IRQHandler          ,  //103 
    (int)&GPIOQ4_IRQHandler          ,  //104 
    (int)&GPIOQ5_IRQHandler          ,  //105 
    (int)&GPIOQ6_IRQHandler          ,  //106
    (int)&GPIOQ7_IRQHandler          ,  //107
    0                                ,  //108
    0                                ,  //109
    0                                ,  //110
    0                                ,  //111
    0                                ,  //112
    0                                ,  //113
    (int)&TIMER6A_IRQHandler         ,  //114
    (int)&TIMER6B_IRQHandler         ,  //115
    (int)&TIMER7A_IRQHandler         ,  //116
    (int)&TIMER7B_IRQHandler         ,  //117
    (int)&I2C6_IRQHandler            ,  //118
    (int)&I2C7_IRQHandler            ,  //119
    0                                ,  //120
    0                                ,  //121
    0                                ,  //122
    0                                ,  //123
    0                                ,  //124
    (int)&I2C8_IRQHandler            ,  //125
    (int)&I2C9_IRQHandler            ,  //126
    0                                ,  //127
    0                                ,  //128
    0                                   //129
};

__stackless void NonMaskableInt_IRQHandler(void){
  assert_failed("NonMaskableInt", __LINE__);
}

__stackless void HardFault_IRQHandler(void){
  assert_failed("HardFault", __LINE__);
}

__stackless void MemoryManagement_IRQHandler(void){
  assert_failed("MemoryManagement", __LINE__);
}

__stackless void BusFault_IRQHandler(void){
  assert_failed("BusFault", __LINE__);
}

__stackless void UsageFault_IRQHandler(void){
  assert_failed("UsageFault", __LINE__);
}

__stackless void unused_Handler(void){
  assert_failed("unused", __LINE__);
}


//will be or not be decleared until linking process finished
#pragma weak SVCall_IRQHandler        = unused_Handler
#pragma weak DebugMonitor_IRQHandler   = unused_Handler
#pragma weak PendSV_IRQHandler     = unused_Handler
#pragma weak SysTick_IRQHandler    = unused_Handler

//void Reset_IRQHandler(void);
            
//#pragma weak NonMaskableInt_IRQHandler   = unused_Handler 
//#pragma weak HardFault_IRQHandler        = unused_Handler 
//#pragma weak MemoryManagement_IRQHandler = unused_Handler 
//#pragma weak BusFault_IRQHandler         = unused_Handler
//#pragma weak UsageFault_IRQHandler       = unused_Handler 

//#pragma weak SVCall_IRQHandler           = unused_Handler 
//#pragma weak DebugMonitor_IRQHandler     = unused_Handler 
//#pragma weak PendSV_IRQHandler           = unused_Handler 
//#pragma weak SysTick_IRQHandler          = unused_Handler

#pragma weak GPIOA_IRQHandler            = unused_Handler 
#pragma weak GPIOB_IRQHandler            = unused_Handler 
#pragma weak GPIOC_IRQHandler            = unused_Handler 
#pragma weak GPIOD_IRQHandler            = unused_Handler 
#pragma weak GPIOE_IRQHandler            = unused_Handler 
#pragma weak UART0_IRQHandler            = unused_Handler 
#pragma weak UART1_IRQHandler            = unused_Handler 
#pragma weak SSI0_IRQHandler             = unused_Handler 
#pragma weak I2C0_IRQHandler             = unused_Handler 
#pragma weak PWM0_FAULT_IRQHandler       = unused_Handler 
#pragma weak PWM0_0_IRQHandler           = unused_Handler 
#pragma weak PWM0_1_IRQHandler           = unused_Handler 
#pragma weak PWM0_2_IRQHandler           = unused_Handler 
#pragma weak QEI0_IRQHandler             = unused_Handler 
#pragma weak ADC0SS0_IRQHandler          = unused_Handler 
#pragma weak ADC0SS1_IRQHandler          = unused_Handler 
#pragma weak ADC0SS2_IRQHandler          = unused_Handler 
#pragma weak ADC0SS3_IRQHandler          = unused_Handler 
#pragma weak WATCHDOG0_IRQHandler        = unused_Handler 
#pragma weak TIMER0A_IRQHandler          = unused_Handler 
#pragma weak TIMER0B_IRQHandler          = unused_Handler 
#pragma weak TIMER1A_IRQHandler          = unused_Handler 
#pragma weak TIMER1B_IRQHandler          = unused_Handler 
#pragma weak TIMER2A_IRQHandler          = unused_Handler 
#pragma weak TIMER2B_IRQHandler          = unused_Handler 
#pragma weak COMP0_IRQHandler            = unused_Handler 
#pragma weak COMP1_IRQHandler            = unused_Handler 
#pragma weak COMP2_IRQHandler            = unused_Handler 
#pragma weak SYSCTL_IRQHandler           = unused_Handler 
#pragma weak FLASH_CTRL_IRQHandler       = unused_Handler 
#pragma weak GPIOF_IRQHandler            = unused_Handler 
#pragma weak GPIOG_IRQHandler            = unused_Handler 
#pragma weak GPIOH_IRQHandler            = unused_Handler 
#pragma weak UART2_IRQHandler            = unused_Handler 
#pragma weak SSI1_IRQHandler             = unused_Handler 
#pragma weak TIMER3A_IRQHandler          = unused_Handler 
#pragma weak TIMER3B_IRQHandler          = unused_Handler 
#pragma weak I2C1_IRQHandler             = unused_Handler 
#pragma weak CAN0_IRQHandler             = unused_Handler 
#pragma weak CAN1_IRQHandler             = unused_Handler 
#pragma weak EMAC0_IRQHandler            = unused_Handler 
#pragma weak HIB_IRQHandler              = unused_Handler 
#pragma weak USB0_IRQHandler             = unused_Handler 
#pragma weak PWM0_3_IRQHandler           = unused_Handler 
#pragma weak UDMA_IRQHandler             = unused_Handler 
#pragma weak UDMAERR_IRQHandler          = unused_Handler 
#pragma weak ADC1SS0_IRQHandler          = unused_Handler 
#pragma weak ADC1SS1_IRQHandler          = unused_Handler 
#pragma weak ADC1SS2_IRQHandler          = unused_Handler 
#pragma weak ADC1SS3_IRQHandler          = unused_Handler 
#pragma weak EPI0_IRQHandler             = unused_Handler 
#pragma weak GPIOJ_IRQHandler            = unused_Handler 
#pragma weak GPIOK_IRQHandler            = unused_Handler 
#pragma weak GPIOL_IRQHandler            = unused_Handler 
#pragma weak SSI2_IRQHandler             = unused_Handler 
#pragma weak SSI3_IRQHandler             = unused_Handler 
#pragma weak UART3_IRQHandler            = unused_Handler 
#pragma weak UART4_IRQHandler            = unused_Handler 
#pragma weak UART5_IRQHandler            = unused_Handler 
#pragma weak UART6_IRQHandler            = unused_Handler 
#pragma weak UART7_IRQHandler            = unused_Handler 
#pragma weak I2C2_IRQHandler             = unused_Handler 
#pragma weak I2C3_IRQHandler             = unused_Handler 
#pragma weak TIMER4A_IRQHandler          = unused_Handler 
#pragma weak TIMER4B_IRQHandler          = unused_Handler 
#pragma weak TIMER5A_IRQHandler          = unused_Handler 
#pragma weak TIMER5B_IRQHandler          = unused_Handler 
#pragma weak SYSEXC_IRQHandler           = unused_Handler 
#pragma weak I2C4_IRQHandler             = unused_Handler 
#pragma weak I2C5_IRQHandler             = unused_Handler 
#pragma weak GPIOM_IRQHandler            = unused_Handler 
#pragma weak GPION_IRQHandler            = unused_Handler 
#pragma weak GPIOP0_IRQHandler           = unused_Handler 
#pragma weak GPIOP1_IRQHandler           = unused_Handler 
#pragma weak GPIOP2_IRQHandler           = unused_Handler 
#pragma weak GPIOP3_IRQHandler           = unused_Handler 
#pragma weak GPIOP4_IRQHandler           = unused_Handler 
#pragma weak GPIOP5_IRQHandler           = unused_Handler 
#pragma weak GPIOP6_IRQHandler           = unused_Handler 
#pragma weak GPIOP7_IRQHandler           = unused_Handler 
#pragma weak GPIOQ0_IRQHandler           = unused_Handler 
#pragma weak GPIOQ1_IRQHandler           = unused_Handler 
#pragma weak GPIOQ2_IRQHandler           = unused_Handler 
#pragma weak GPIOQ3_IRQHandler           = unused_Handler 
#pragma weak GPIOQ4_IRQHandler           = unused_Handler 
#pragma weak GPIOQ5_IRQHandler           = unused_Handler 
#pragma weak GPIOQ6_IRQHandler           = unused_Handler 
#pragma weak GPIOQ7_IRQHandler           = unused_Handler 
#pragma weak TIMER6A_IRQHandler          = unused_Handler 
#pragma weak TIMER6B_IRQHandler          = unused_Handler 
#pragma weak TIMER7A_IRQHandler          = unused_Handler 
#pragma weak TIMER7B_IRQHandler          = unused_Handler 
#pragma weak I2C6_IRQHandler             = unused_Handler 
#pragma weak I2C7_IRQHandler             = unused_Handler 
#pragma weak I2C8_IRQHandler             = unused_Handler 
#pragma weak I2C9_IRQHandler             = unused_Handler


