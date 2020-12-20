#include <stdint.h> //uint32_t for type def
#include "tm4c1294ncpdt.h"
#include "delay.h"

#include "fact.h"


#define LED_RED (1U << 0)
#define LED_BLUE (1U << 4)



int main(){

    unsigned volatile result;
    
    result = fact(0U);
    result = 2U + 3U*fact(1U);
    (void)fact(5U); //when you dont need to use return value
    
    SYSCTL_RCGCGPIO_R   |= (1U << 5); //GPIO Clock Gating openning adress giving port 
    GPIO_PORTF_AHB_DIR_R    |= (LED_RED | LED_BLUE); //GPIO direction to out
    GPIO_PORTF_AHB_DEN_R    |= (LED_RED | LED_BLUE); //GPIO digital enable

    GPIO_PORTF_AHB_DATA_BITS_R[LED_BLUE] = LED_BLUE;
    
    
    int volatile s = 1000;
    while(s--){

        GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] = LED_RED;
        delay(1000000);
        
        GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] = 0;
        delay(500000);
        
        GPIO_PORTF_AHB_DATA_BITS_R[LED_BLUE] = LED_BLUE;
        delay(1000000);
        
        GPIO_PORTF_AHB_DATA_BITS_R[LED_BLUE] = 0;
        delay(500000);
    }
    return 0;
}