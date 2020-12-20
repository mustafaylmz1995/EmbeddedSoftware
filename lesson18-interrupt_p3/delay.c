#include "delay.h"

void delay(int volatile iter) { //definition

    while(iter > 0){ //delay loop
        --iter;
    }        
}