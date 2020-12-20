
int main(){
    int counter = 0;
    while(counter <7){
      ++counter;
      
      if((counter & 1) != 0){
        /*do smt*/
        counter += 2;
      }else{
        counter += 3;
        /*do smt*/
      }
    }

    return 0;
}
