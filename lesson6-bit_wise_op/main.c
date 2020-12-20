#include <stdint.h> //uint32_t for type def
#include "tm4c1294ncpdt.h"

#define LED_RED (1U << 0)
#define LED_BLUE (1U << 1)


int main(){
    int volatile counter = 0;
    
    SYSCTL_RCGCGPIO_R   |= (1U << 12); //GPIO Clock Gating openning adress giving port 
    GPIO_PORTN_DIR_R    |= (LED_RED | LED_BLUE); //GPIO direction to out
    GPIO_PORTN_DEN_R    |= (LED_RED | LED_BLUE); //GPIO digital enable

    GPIO_PORTN_DATA_R   |= LED_BLUE; //open
    
    volatile int s = 100;          
    while(s--){
      GPIO_PORTN_DATA_R |= LED_RED; //open without changing any bit 
        
        while(counter < 1000000){ //delay loop
          counter++;
        }
        counter = 0;
        
        GPIO_PORTN_DATA_R &= ~LED_RED; //close without changing any bit 
        while(counter < 1000000){ //delay loop
          counter++;
        }
        counter = 0;
    }
    return 0;
}
