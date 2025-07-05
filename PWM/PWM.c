#include <PWM.h>

void main(){
   sys_init();
   while(TRUE){
      Temp = READ_ADC();
      delay_ms(100);
      
      speedFunction();
      
      displayValues();
      
      SET_PWM1_DUTY(Pt);
      
      if(input(pin_a4)) set_temp();
   }
}
