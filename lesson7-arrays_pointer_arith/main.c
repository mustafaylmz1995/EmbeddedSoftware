#include <stdint.h> //uint32_t for type def
#include "tm4c1294ncpdt.h"

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// In this file, I changed the LED from Port N to Port F 
// in order to have ability to use AHB feature. 
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


//#define LED_RED (1U << 0)
//#define LED_BLUE (1U << 1)
//
//
//int main(){
//  int volatile counter[2] = {0, 0};
//    
//    SYSCTL_RCGCGPIO_R   |= (1U << 12); //GPIO Clock Gating openning adress giving port 
//    GPIO_PORTN_DIR_R    |= (LED_RED | LED_BLUE); //GPIO direction to out
//    GPIO_PORTN_DEN_R    |= (LED_RED | LED_BLUE); //GPIO digital enable
//
//    GPIO_PORTN_DATA_BITS_R[LED_BLUE] = LED_BLUE;
//          
//    while(1){
//      //GPIO_PORTN_DATA_R |= LED_RED; //open without changing any bit 
//      
//        //first 2 bit of this register should be zero so we shift left 2 
//      //(*((unsigned long volatile *)(GPIO_PORTN_DATA_R + (LED_RED << 2)))) = LED_RED;
//      GPIO_PORTN_DATA_BITS_R[LED_RED] = LED_RED;
//      //*(GPIO_PORTN_DATA_BITS_R + LED_RED) = LED_RED;
//      
//        while(counter[0] < 1000000){ //delay loop
//          counter[0]++;
//        }
//        counter[0] = 0;
//        
//        //GPIO_PORTN_DATA_R &= ~LED_RED; //close without changing any bit 
//        //GPIO_PORTN_DATA_BITS_R &= ~LED_RED; //doesnt work!!!
//        GPIO_PORTN_DATA_BITS_R[LED_RED] = 0;
//        while(*(counter+1) < 1000000){ //delay loop
//          counter[1]++;
//        }
//        counter[1] = 0;
//    }
//    return 0;
//}


#define LED_RED (1U << 0)
#define LED_BLUE (1U << 4)

int main(){
    int volatile counter[2] = {0, 0};

    SYSCTL_RCGCGPIO_R    |= (1U << 5); //GPIO Clock Gating openning adress giving port 
    GPIO_PORTF_AHB_DIR_R |= (LED_RED | LED_BLUE); //GPIO direction to out
    GPIO_PORTF_AHB_DEN_R |= (LED_RED | LED_BLUE); //GPIO digital enable
    
    GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] = LED_RED;
    
    int volatile s = 100;
    while(s--){
        GPIO_PORTF_AHB_DATA_BITS_R[LED_BLUE] |= LED_BLUE;//open without changing any bit
        
        //first 5 bits of this register should be zero so we shift left 5 
        //(*((unsigned long volatile *)(GPIO_PORTF_AHB_DATA_BITS_R + (LED_RED << 5)))) = LED_RED;
        GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] = LED_RED;
        //*(GPIO_PORTF_AHB_DATA_BITS_R + LED_RED) = LED_RED;

        while(counter[0] < 1000000){ //delay loop
            counter[0]++;
        }
        counter[0] = 0;

        //GPIO_PORTF_AHB_DATA_BITS_R &= ~LED_RED; //close without changing any bit 
        //GPIO_PORTF_AHB_DATA_BITS_R &= ~LED_RED; //doesnt work!!!
        GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] = 0;
        while(*(counter+1) < 1000000){ //delay loop
            counter[1]++;
        }
        counter[1] = 0;

        }
  
  
  
  
    return 0;
}
