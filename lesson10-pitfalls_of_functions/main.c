#include <stdint.h> //uint32_t for type def
#include "tm4c1294ncpdt.h"
#include "delay.h"


#define LED_RED (1U << 0)
#define LED_BLUE (1U << 4)


int *swap (int *x , int *y);

int *swap (int *x , int *y){
    static int tmp[2];
    tmp[0] = *x;
    tmp[1] = *y;
    *x = tmp[1];
    *y = tmp[0];
    return tmp;
}


int main(){

      
    SYSCTL_RCGCGPIO_R   |= (1U << 5); //GPIO Clock Gating openning adress giving port 
    GPIO_PORTF_AHB_DIR_R    |= (LED_RED | LED_BLUE); //GPIO direction to out
    GPIO_PORTF_AHB_DEN_R    |= (LED_RED | LED_BLUE); //GPIO digital enable

    GPIO_PORTF_AHB_DATA_BITS_R[LED_BLUE] = LED_BLUE;
    
    int volatile _time = 1000000;
    int x = _time;
    int y = _time/2;
    
    while(1){

        int *p = swap(&x, &y);
        GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] = LED_RED;
        delay(p[0]);
        
        GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] = 0;
        delay(p[1]);
        
        GPIO_PORTF_AHB_DATA_BITS_R[LED_BLUE] = LED_BLUE;
        delay(p[1]);
        
        GPIO_PORTF_AHB_DATA_BITS_R[LED_BLUE] = 0;
        delay(p[0]);        
    
    }
    //return 0;
}

