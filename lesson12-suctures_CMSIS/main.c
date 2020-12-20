#include <stdint.h> //uint32_t for type def c99 standart
#include "TM4C1294NCPDT.h"
#include "delay.h"

#define LED_RED (1U << 0)
#define LED_BLUE (1U << 4)

typedef struct  {
    uint8_t y;
    uint16_t x;
    
}Point;

Point pa, pb;

typedef struct {
  Point top_left;
  Point bottom_right;
}Window;

typedef struct {
  Point corners[3];  
}Triangle;

Window w, w2;
Triangle t;

int main(){
    Point *pp;
    Window *wp;
  
    pa.x = sizeof(Point);
    pa.y = 0xAAU;
  
    w.top_left.x = 1U;
    w.bottom_right.y = 2U;
    
    
    t.corners[0].x = 1U;
    t.corners[2].x = 2U;
    
    pb = pa;
    w2 = w;
    
    pp = &pa;
    wp = &w2;
    
    (*pp).x = 1U; //paranthesis needed because dot operator is high precedence
    
    (*wp).top_left = *pp;
    
    pp->x = 1U;
    wp->top_left = *pp;
    
    
    SYSCTL->RCGCGPIO |= (1U << 5); //GPIO Clock Gating openning adress giving port 
    //SYSCTL_RCGCGPIO_R   |= (1U << 12); //GPIO Clock Gating openning adress giving port 
    
    GPIOF_AHB->DIR  |= (LED_RED | LED_BLUE); //GPIO direction to out
    //GPIO_PORTN_DIR_R    |= (LED_RED | LED_BLUE); //GPIO direction to out
    
    GPIOF_AHB->DEN |= (LED_RED | LED_BLUE); //GPIO digital enable
    //GPIO_PORTN_DEN_R    |= (LED_RED | LED_BLUE); //GPIO digital enable

    GPIOF_AHB->DATA |= LED_BLUE;
    //GPIO_PORTN_DATA_BITS_R[LED_BLUE] = LED_BLUE;
          
    while(1){

        GPIOF_AHB->DATA   |= LED_RED;
        //GPIO_PORTN_DATA_BITS_R[LED_RED] = LED_RED;
        delay(1000000);
        
        GPIOF_AHB->DATA &= ~LED_RED;
        //GPIO_PORTN_DATA_BITS_R[LED_RED] = 0;
        delay(2000000);
    }
    //return 0;
}

