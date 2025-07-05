#include <main.h>

void main(){
   output_a(0);
   output_b(0);
   set_tris_a(0b11111);
   set_tris_b(0);
   output_a(0);
   output_b(0);
   
   counter = read_eeprom(0);
   delay_ms(100);
//!   CC_switch(counter);
   while(TRUE)
   {
//!      output_b(ccArray[counter]);
      output_b(CC_array(counter));
      if(input(pin_a0)){
         while(input(pin_a0));
         if(counter<9){
//!            CC_switch(++counter);
            counter++;
         }
         write_eeprom(0, counter);
         delay_ms(100);
      }
      if(input(pin_a1)){
         while(input(pin_a1));
         if(counter>0){
//!            CC_switch(--counter);
            counter--;
         }
         write_eeprom(0, counter),
         delay_ms(100);
      }
   }
}
