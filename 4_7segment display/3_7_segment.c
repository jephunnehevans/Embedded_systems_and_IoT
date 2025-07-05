#include <3_7_segment.h>

void main(){
   sys_init();
   while(TRUE){
      if(input(inc)){
         while(input(inc));
         counter++;
         if(counter>9999)counter=9999;
      }
      if(input(dec)){
         while(input(dec));
         counter--;
         if(counter<1 || counter>9999)counter=0;
      }
   }
}
