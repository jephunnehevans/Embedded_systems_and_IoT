#include <New.h>

void main(){
   sys_init();
   
   while(TRUE)
   {
      output_high(main_led);
      delay_ms(700);
      output_low(main_led);
      delay_ms(300);
      
      if(trig==1){
         for(x=0;x<4;x++){
            output_high(irs_led);
            delay_ms(3000);
            output_low(irs_led);
            delay_ms(2000);
         }
         trig = 0;
      }
   }
}
