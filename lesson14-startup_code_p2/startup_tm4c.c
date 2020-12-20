/*Startup code for TM4C*/


//ampersand ".intvec" baslangic vektor tablosu oldugunu bildirmek icin 
// const keyword ROM da baslatilmasi icin eklendi
int const __vector_table[] @ ".intvec"= {
    0x20004000,
    0x9,
  
};