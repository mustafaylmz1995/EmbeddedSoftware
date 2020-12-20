#include <stdint.h> //uint32_t for type def
#include "tm4c1294ncpdt.h"

/*General-Purpose Input/Output Run Mode Clock Gating Control
Write between always in paranthesis to use all context
*/
#define RCGCGPIO (*((unsigned int *)0x400FE608U))  //also we can write here

#define GPION_BASE 0x40064000U
//pin direction register
#define GPION_DIR (*((unsigned int *)(GPION_BASE + 0x400U)))
//pin direction enable
#define GPION_DEN (*((unsigned int *)(GPION_BASE + 0x51CU)))
//Data
#define GPION_DATA (*((unsigned int *)(GPION_BASE + 0x3FCU)))

/*
In the header file, these equal them.

RCGCGPIO        --> SYSCTL_RCGCGPIO_R
GPION_BASE      --> GPIO_PORTN_DATA_BITS_R
GPION_DIR       --> GPIO_PORTN_DIR_R
GPION_DEN       --> GPIO_PORTN_DEN_R
GPION_DATA      --> GPIO_PORTN_DATA_R
*/

int main(){
    SYSCTL_RCGCGPIO_R    = 0x1000U; //GPIO Clock Gating openning adress giving port 
    GPIO_PORTN_DIR_R   = 0x03U; //GPIO direction to out
    GPIO_PORTN_DEN_R   = 0x03U; //GPIO digital enable
    
    volatile int s = 100;
    
    while(s--){
        GPIO_PORTN_DATA_R      = 0x03U; //open
        volatile int counter = 0;
        while(counter < 1000000){ //delay loop
          counter++;
        }
        counter = 0;
        GPIO_PORTN_DATA_R      = 0x00U; //close
        while(counter < 1000000){
          counter++;
        }
    }
    return 0;
}


/*
volatile register can be change simultaneously
compiler can not change in the volatile object
we can add volatile before or after the type
*/
