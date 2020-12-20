/*int main(){
    //GPIO Clock Gating openning adress   giving port 
    *((unsigned int *)0x400FE608U)      = 0x1000U; 
    *((unsigned int *)0x40064400U)      = 0x03U; //GPIO direction to out
    *((unsigned int *)0x4006451CU)      = 0x03U; //GPIO digital enable
    
    int s = 100;
    while(s--){
        *((unsigned int *)0x400643FCU)      = 0x03U; //open
        int counter = 0;
        while(counter < 1000000){
          counter++;
        }
        counter = 0;
        *((unsigned int *)0x400643FCU)      = 0x00U; //close
        while(counter < 1000000){
          counter++;
        }
    }
    return 0;
}




*/
int main(){
    //GPIO Clock Gating openning adress   giving port 
    *((unsigned int *)0x400FE608U)      = 0x1000U; 
    *((unsigned int *)0x40064400U)      = 0x03U; //GPIO direction to out
    *((unsigned int *)0x4006451CU)      = 0x03U; //GPIO digital enable
    
    int s = 100;
    while(s--){
        *((unsigned int *)0x400643FCU)      = 0x01U; //open
        int counter = 0;
        while(counter < 1000000){
          counter++;
        }
        counter = 0;
        *((unsigned int *)0x400643FCU)      = 0x00U; //close
        while(counter < 1000000){
          counter++;
        }
        counter = 0;
        *((unsigned int *)0x400643FCU)      = 0x02U; //open
        while(counter < 1000000){
          counter++;
        }
        counter = 0;
        *((unsigned int *)0x400643FCU)      = 0x00U; //close
        while(counter < 1000000){
          counter++;
        }
    }
    return 0;
}