#include <stdint.h> //uint32_t for type def c99 standart
#include "tm4c1294ncpdt.h"
#include "delay.h"

#define LED_RED (1U << 0)
#define LED_BLUE (1U << 1)

int x ;
unsigned y;
short s;
unsigned short us;
long l;
unsigned long ul;
char c;
unsigned char uc;

uint8_t u8a, u8b;
uint16_t u16a, u16b;
uint32_t u32a, u32b;

int8_t s8;
int8_t s16;
int8_t s32;

int main(){

    u8a = sizeof(u8a);          //1 bytes
    u16a = sizeof(uint16_t);    //2 bytes
    u32a = sizeof(uint32_t);    //4 bytes
    
    u8a = 0xa1U;
    u16a = 0xc1c2U;
    u32a = 0xe1e2e3e4U;
    
    
    u8b = u8a;
    u16b = u16a;
    u32b = u32a;
    
    u16a = 40000U;
    u16b = 30000U;
    
    u32a = (uint32_t)u16a + u16b;
    
    u16a = 100U;
    s32 = 10 - (int32_t)u16a;
    
    if((int32_t)u32a > -1){
        u8a = 1U;
    }else{
        u8a = 0U;
    }
    u8a = 0xFFU;
    if((uint8_t)(~u8a) == 0x00U){
      u8b = 1U;
    }
    
    
    SYSCTL_RCGCGPIO_R   |= (1U << 12); //GPIO Clock Gating openning adress giving port 
    GPIO_PORTN_DIR_R    |= (LED_RED | LED_BLUE); //GPIO direction to out
    GPIO_PORTN_DEN_R    |= (LED_RED | LED_BLUE); //GPIO digital enable

    GPIO_PORTN_DATA_BITS_R[LED_BLUE] = LED_BLUE;
          
    while(1){

        GPIO_PORTN_DATA_BITS_R[LED_RED] = LED_RED;
        delay(100);
        
        GPIO_PORTN_DATA_BITS_R[LED_RED] = 0;
        delay(200);
    }
    //return 0;
}

