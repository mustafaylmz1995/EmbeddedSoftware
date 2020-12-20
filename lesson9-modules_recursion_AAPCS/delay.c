#include "delay.h"

void delay(int iter) { //definition
    int volatile counter = 0;
    counter = 0;
    while(counter < iter){ //delay loop
        counter++;
    }
         
}