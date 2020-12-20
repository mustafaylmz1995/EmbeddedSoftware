#include "fact.h"

unsigned fact(unsigned n){
    //recursive def
    //0! = 1
    //1! = 1
  
  
  if(n == 0U){
    return 1U;
  }else{
    return n * fact(n-1U);
  }
  
}