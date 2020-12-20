
/* start and end of stack defined in the linker script ---------------------*/
extern int __stack_start__;
extern int __stack_end__;

/* Weak prototypes for error handlers --------------------------------------*/
/**
* \note
* The function assert_failed defined at the end of this file defines
* the error/assertion handling policy for the application and might
* need to be customized for each project. This function is defined in
* assembly to avoid accessing the stack, which might be corrupted by
* the time assert_failed is called.
*/
__attribute__ ((naked)) void assert_failed(char const *module, int loc);

/* Function prototypes -----------------------------------------------------*/
void Default_IRQHandler(void);  /* Default empty handler */
void Reset_IRQHandler(void);    /* Reset Handler */
void SystemInit(void);       /* CMSIS system initialization */

/*----------------------------------------------------------------------------
* weak aliases for each Exception handler to the Default_Handler.
* Any function with the same name will override these definitions.
*/
/* Cortex-M Processor fault exceptions... */
void NonMaskableInt_IRQHandler    (void) __attribute__ ((weak));
void HardFault_IRQHandler         (void) __attribute__ ((weak));
void MemoryManagement_IRQHandler  (void) __attribute__ ((weak));
void BusFault_IRQHandler          (void) __attribute__ ((weak));
void UsageFault_IRQHandler        (void) __attribute__ ((weak));

/* Cortex-M Processor non-fault exceptions... */
void SVCall_IRQHandler            (void) __attribute__ ((weak, alias("Default_IRQHandler")));      
void DebugMonitor_IRQHandler      (void) __attribute__ ((weak, alias("Default_IRQHandler")));      
void PendSV_IRQHandler            (void) __attribute__ ((weak, alias("Default_IRQHandler")));      
void SysTick_IRQHandler           (void) __attribute__ ((weak, alias("Default_IRQHandler")));    

/* external interrupts...   */
void GPIOA_IRQHandler             (void) __attribute__ ((weak, alias("Default_IRQHandler")));     
void GPIOB_IRQHandler             (void) __attribute__ ((weak, alias("Default_IRQHandler")));      
void GPIOC_IRQHandler             (void) __attribute__ ((weak, alias("Default_IRQHandler")));      
void GPIOD_IRQHandler             (void) __attribute__ ((weak, alias("Default_IRQHandler")));       
void GPIOE_IRQHandler             (void) __attribute__ ((weak, alias("Default_IRQHandler")));   
void UART0_IRQHandler             (void) __attribute__ ((weak, alias("Default_IRQHandler")));   
void UART1_IRQHandler             (void) __attribute__ ((weak, alias("Default_IRQHandler")));        
void SSI0_IRQHandler              (void) __attribute__ ((weak, alias("Default_IRQHandler")));     
void I2C0_IRQHandler              (void) __attribute__ ((weak, alias("Default_IRQHandler")));     
void PWM0_FAULT_IRQHandler        (void) __attribute__ ((weak, alias("Default_IRQHandler")));         
void PWM0_0_IRQHandler            (void) __attribute__ ((weak, alias("Default_IRQHandler")));      
void PWM0_1_IRQHandler            (void) __attribute__ ((weak, alias("Default_IRQHandler")));     
void PWM0_2_IRQHandler            (void) __attribute__ ((weak, alias("Default_IRQHandler")));      
void QEI0_IRQHandler              (void) __attribute__ ((weak, alias("Default_IRQHandler")));      
void ADC0SS0_IRQHandler           (void) __attribute__ ((weak, alias("Default_IRQHandler")));      
void ADC0SS1_IRQHandler           (void) __attribute__ ((weak, alias("Default_IRQHandler")));       
void ADC0SS2_IRQHandler           (void) __attribute__ ((weak, alias("Default_IRQHandler")));        
void ADC0SS3_IRQHandler           (void) __attribute__ ((weak, alias("Default_IRQHandler")));          
void WATCHDOG0_IRQHandler         (void) __attribute__ ((weak, alias("Default_IRQHandler")));            
void TIMER0A_IRQHandler           (void) __attribute__ ((weak, alias("Default_IRQHandler")));            
void TIMER0B_IRQHandler           (void) __attribute__ ((weak, alias("Default_IRQHandler")));     
void TIMER1A_IRQHandler           (void) __attribute__ ((weak, alias("Default_IRQHandler")));     
void TIMER1B_IRQHandler           (void) __attribute__ ((weak, alias("Default_IRQHandler")));     
void TIMER2A_IRQHandler           (void) __attribute__ ((weak, alias("Default_IRQHandler")));       
void TIMER2B_IRQHandler           (void) __attribute__ ((weak, alias("Default_IRQHandler")));       
void COMP0_IRQHandler             (void) __attribute__ ((weak, alias("Default_IRQHandler")));      
void COMP1_IRQHandler             (void) __attribute__ ((weak, alias("Default_IRQHandler")));        
void COMP2_IRQHandler             (void) __attribute__ ((weak, alias("Default_IRQHandler")));        
void SYSCTL_IRQHandler            (void) __attribute__ ((weak, alias("Default_IRQHandler")));          
void FLASH_CTRL_IRQHandler        (void) __attribute__ ((weak, alias("Default_IRQHandler")));         
void GPIOF_IRQHandler             (void) __attribute__ ((weak, alias("Default_IRQHandler")));       
void GPIOG_IRQHandler             (void) __attribute__ ((weak, alias("Default_IRQHandler")));        
void GPIOH_IRQHandler             (void) __attribute__ ((weak, alias("Default_IRQHandler")));         
void UART2_IRQHandler             (void) __attribute__ ((weak, alias("Default_IRQHandler")));      
void SSI1_IRQHandler              (void) __attribute__ ((weak, alias("Default_IRQHandler")));     
void TIMER3A_IRQHandler           (void) __attribute__ ((weak, alias("Default_IRQHandler")));       
void TIMER3B_IRQHandler           (void) __attribute__ ((weak, alias("Default_IRQHandler")));      
void I2C1_IRQHandler              (void) __attribute__ ((weak, alias("Default_IRQHandler")));     
void CAN0_IRQHandler              (void) __attribute__ ((weak, alias("Default_IRQHandler")));       
void CAN1_IRQHandler              (void) __attribute__ ((weak, alias("Default_IRQHandler")));   
void EMAC0_IRQHandler             (void) __attribute__ ((weak, alias("Default_IRQHandler")));  
void HIB_IRQHandler               (void) __attribute__ ((weak, alias("Default_IRQHandler")));  
void USB0_IRQHandler              (void) __attribute__ ((weak, alias("Default_IRQHandler")));   
void PWM0_3_IRQHandler            (void) __attribute__ ((weak, alias("Default_IRQHandler")));       
void UDMA_IRQHandler              (void) __attribute__ ((weak, alias("Default_IRQHandler")));     
void UDMAERR_IRQHandler           (void) __attribute__ ((weak, alias("Default_IRQHandler")));      
void ADC1SS0_IRQHandler           (void) __attribute__ ((weak, alias("Default_IRQHandler")));      
void ADC1SS1_IRQHandler           (void) __attribute__ ((weak, alias("Default_IRQHandler")));       
void ADC1SS2_IRQHandler           (void) __attribute__ ((weak, alias("Default_IRQHandler")));      
void ADC1SS3_IRQHandler           (void) __attribute__ ((weak, alias("Default_IRQHandler")));      
void EPI0_IRQHandler              (void) __attribute__ ((weak, alias("Default_IRQHandler")));    
void GPIOJ_IRQHandler             (void) __attribute__ ((weak, alias("Default_IRQHandler")));      
void GPIOK_IRQHandler             (void) __attribute__ ((weak, alias("Default_IRQHandler")));     
void GPIOL_IRQHandler             (void) __attribute__ ((weak, alias("Default_IRQHandler")));         
void SSI2_IRQHandler              (void) __attribute__ ((weak, alias("Default_IRQHandler")));   
void SSI3_IRQHandler              (void) __attribute__ ((weak, alias("Default_IRQHandler")));            
void UART3_IRQHandler             (void) __attribute__ ((weak, alias("Default_IRQHandler")));   
void UART4_IRQHandler             (void) __attribute__ ((weak, alias("Default_IRQHandler")));    
void UART5_IRQHandler             (void) __attribute__ ((weak, alias("Default_IRQHandler")));    
void UART6_IRQHandler             (void) __attribute__ ((weak, alias("Default_IRQHandler")));     
void UART7_IRQHandler             (void) __attribute__ ((weak, alias("Default_IRQHandler")));      
void I2C2_IRQHandler              (void) __attribute__ ((weak, alias("Default_IRQHandler")));     
void I2C3_IRQHandler              (void) __attribute__ ((weak, alias("Default_IRQHandler")));    
void TIMER4A_IRQHandler           (void) __attribute__ ((weak, alias("Default_IRQHandler")));         
void TIMER4B_IRQHandler           (void) __attribute__ ((weak, alias("Default_IRQHandler")));            
void TIMER5A_IRQHandler           (void) __attribute__ ((weak, alias("Default_IRQHandler")));     
void TIMER5B_IRQHandler           (void) __attribute__ ((weak, alias("Default_IRQHandler")));          
void SYSEXC_IRQHandler            (void) __attribute__ ((weak, alias("Default_IRQHandler")));    
void I2C4_IRQHandler              (void) __attribute__ ((weak, alias("Default_IRQHandler")));     
void I2C5_IRQHandler              (void) __attribute__ ((weak, alias("Default_IRQHandler")));    
void GPIOM_IRQHandler             (void) __attribute__ ((weak, alias("Default_IRQHandler")));     
void GPION_IRQHandler             (void) __attribute__ ((weak, alias("Default_IRQHandler")));    
void GPIOP0_IRQHandler            (void) __attribute__ ((weak, alias("Default_IRQHandler")));     
void GPIOP1_IRQHandler            (void) __attribute__ ((weak, alias("Default_IRQHandler")));    
void GPIOP2_IRQHandler            (void) __attribute__ ((weak, alias("Default_IRQHandler")));     
void GPIOP3_IRQHandler            (void) __attribute__ ((weak, alias("Default_IRQHandler")));      
void GPIOP4_IRQHandler            (void) __attribute__ ((weak, alias("Default_IRQHandler")));       
void GPIOP5_IRQHandler            (void) __attribute__ ((weak, alias("Default_IRQHandler")));        
void GPIOP6_IRQHandler            (void) __attribute__ ((weak, alias("Default_IRQHandler")));       
void GPIOP7_IRQHandler            (void) __attribute__ ((weak, alias("Default_IRQHandler")));      
void GPIOQ0_IRQHandler            (void) __attribute__ ((weak, alias("Default_IRQHandler")));      
void GPIOQ1_IRQHandler            (void) __attribute__ ((weak, alias("Default_IRQHandler")));      
void GPIOQ2_IRQHandler            (void) __attribute__ ((weak, alias("Default_IRQHandler")));      
void GPIOQ3_IRQHandler            (void) __attribute__ ((weak, alias("Default_IRQHandler")));      
void GPIOQ4_IRQHandler            (void) __attribute__ ((weak, alias("Default_IRQHandler")));       
void GPIOQ5_IRQHandler            (void) __attribute__ ((weak, alias("Default_IRQHandler")));      
void GPIOQ6_IRQHandler            (void) __attribute__ ((weak, alias("Default_IRQHandler")));      
void GPIOQ7_IRQHandler            (void) __attribute__ ((weak, alias("Default_IRQHandler")));     
void TIMER6A_IRQHandler           (void) __attribute__ ((weak, alias("Default_IRQHandler")));      
void TIMER6B_IRQHandler           (void) __attribute__ ((weak, alias("Default_IRQHandler")));        
void TIMER7A_IRQHandler           (void) __attribute__ ((weak, alias("Default_IRQHandler")));       
void TIMER7B_IRQHandler           (void) __attribute__ ((weak, alias("Default_IRQHandler")));      
void I2C6_IRQHandler              (void) __attribute__ ((weak, alias("Default_IRQHandler")));     
void I2C7_IRQHandler              (void) __attribute__ ((weak, alias("Default_IRQHandler")));  
void I2C8_IRQHandler              (void) __attribute__ ((weak, alias("Default_IRQHandler")));   
void I2C9_IRQHandler              (void) __attribute__ ((weak, alias("Default_IRQHandler")));

//-----------------------------------------------------------------------------------------


__attribute__ ((section(".isr_vector")))

int const g_pfnVectors[] ={
    (int)&__stack_end__,               // 0
    (int)&Reset_IRQHandler,            // 1 //gives adress of func
    (int)&NonMaskableInt_IRQHandler,   //2
    (int)&HardFault_IRQHandler,        //3
    (int)&MemoryManagement_IRQHandler, //4
    (int)&BusFault_IRQHandler,         //5
    (int)&UsageFault_IRQHandler,       //6
    0,                                 //7
    0,                                 //8
    0,                                 //9
    0,                                 //10
    (int)&SVCall_IRQHandler,           //11
    (int)&DebugMonitor_IRQHandler,     //12
    0,                                 //13
    (int)&PendSV_IRQHandler,           //14
    (int)&SysTick_IRQHandler,          //15
    
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



/* reset handler -----------------------------------------------------------*/
void Reset_IRQHandler(void) {
    extern int main(void);
    extern int __libc_init_array(void);
    extern unsigned __data_start;  /* start of .data in the linker script */
    extern unsigned __data_end__;  /* end of .data in the linker script */
    extern unsigned const __data_load; /* initialization values for .data  */
    extern unsigned __bss_start__; /* start of .bss in the linker script */
    extern unsigned __bss_end__;   /* end of .bss in the linker script */
    extern void software_init_hook(void) __attribute__((weak));

    unsigned const *src;
    unsigned *dst;

    //SystemInit(); /* CMSIS system initialization */

    /* copy the data segment initializers from flash to RAM... */
    src = &__data_load;
    for (dst = &__data_start; dst < &__data_end__; ++dst, ++src) {
        *dst = *src;
    }

    /* zero fill the .bss segment in RAM... */
    for (dst = &__bss_start__; dst < &__bss_end__; ++dst) {
        *dst = 0;
    }

    /* init hook provided? */
    if (&software_init_hook != (void (*)(void))(0)) {
        /* give control to the RTOS */
        software_init_hook(); /* this will also call __libc_init_array */
    }
    else {
        /* call all static constructors in C++ (harmless in C programs) */
        __libc_init_array();
        (void)main(); /* application's entry point; should never return! */
    }

    /* the previous code should not return, but assert just in case... */
    assert_failed("Reset_IRQHandler", __LINE__);
}


/* fault exception handlers ------------------------------------------------*/
__attribute__((naked)) void NonMaskableInt_IRQHandler(void);
void NonMaskableInt_IRQHandler(void) {
    __asm volatile (
        "    ldr r0,=str_nmi\n\t"
        "    mov r1,#1\n\t"
        "    b assert_failed\n\t"
        "str_nmi: .asciz \"NMI\"\n\t"
        "  .align 2\n\t"
    );
}
/*..........................................................................*/
__attribute__((naked)) void MemoryManagement_IRQHandler(void);
void MemoryManagement_IRQHandler(void) {
    __asm volatile (
        "    ldr r0,=str_mem\n\t"
        "    mov r1,#1\n\t"
        "    b assert_failed\n\t"
        "str_mem: .asciz \"MemManage\"\n\t"
        "  .align 2\n\t"
    );
}
/*..........................................................................*/
__attribute__((naked)) void HardFault_IRQHandler(void);
void HardFault_IRQHandler(void) {
    __asm volatile (
        "    ldr r0,=str_hrd\n\t"
        "    mov r1,#1\n\t"
        "    b assert_failed\n\t"
        "str_hrd: .asciz \"HardFault\"\n\t"
        "  .align 2\n\t"
    );
}
/*..........................................................................*/
__attribute__((naked)) void BusFault_IRQHandler(void);
void BusFault_IRQHandler(void) {
    __asm volatile (
        "    ldr r0,=str_bus\n\t"
        "    mov r1,#1\n\t"
        "    b assert_failed\n\t"
        "str_bus: .asciz \"BusFault\"\n\t"
        "  .align 2\n\t"
    );
}
/*..........................................................................*/
__attribute__((naked)) void UsageFault_IRQHandler(void);
void UsageFault_IRQHandler(void) {
    __asm volatile (
        "    ldr r0,=str_usage\n\t"
        "    mov r1,#1\n\t"
        "    b assert_failed\n\t"
        "str_usage: .asciz \"UsageFault\"\n\t"
        "  .align 2\n\t"
    );
}
/*..........................................................................*/
__attribute__((naked)) void Default_IRQHandler(void);
void Default_IRQHandler(void) {
    __asm volatile (
        "    ldr r0,=str_dflt\n\t"
        "    mov r1,#1\n\t"
        "    b assert_failed\n\t"
        "str_dflt: .asciz \"Default\"\n\t"
        "  .align 2\n\t"
    );
}
