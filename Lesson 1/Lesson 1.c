#include <Lesson 1.h>

unsigned int8 y=0;

void main()
{
   output_a(0);
   output_b(0);
   set_tris_a(0b00011111);
   set_tris_b(0);
   output_a(0);
   output_b(0);
   
   while(TRUE)
   {
      if(input(pin_a0)==0){
         output_high(pin_b7);
         delay_ms(300);
         output_low(pin_b7);
      }
   }

}
