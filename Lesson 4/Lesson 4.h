#include <16F84A.h>
#FUSES XT,NOWDT,PUT,PROTECT                    //No Watch Dog Timer

#use delay(crystal=4000000)

unsigned int8 count=0, maxVal=10, minVal=0;

void method1(){
   if(input(pin_a0)&&(count<maxVal)){
      while(input(pin_a0));
      output_b(++count);
   }
   if((input(pin_a1))&&(count>minVal)){
      while(input(pin_a1));
      output_b(--count);
   }
}

void method2(){
   if(input(pin_a0)){
      while(input(pin_a0));
      ++count;
      if(count>maxVal)count=maxVal;
      output_b(count);
   }
   if(input(pin_a1)){
      while(input(pin_a1));
      count--;
      if((count<(minVal+1))||(count>maxVal))count=minVal;
      output_b(count);
   }
}

void method3(){
   if(input(pin_a0)){
      while(input(pin_a0));
      if(count<maxVal)output_b(++count);
   }
   if(input(pin_a1)){
      while(input(pin_a1));
      if(count>minVal)output_b(--count);
   }
}



