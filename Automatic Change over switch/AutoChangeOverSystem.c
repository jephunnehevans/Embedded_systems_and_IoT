#include <AutoChangeOverSystem.h>

void main(){
   sys_init();
   while(TRUE){
      SET_ADC_CHANNEL(0);
      Vn = READ_ADC();
      delay_ms(10);
      SET_ADC_CHANNEL(1);
      Vg = READ_ADC();
      delay_ms(10);
      SET_ADC_CHANNEL(2);
      I = READ_ADC();
      delay_ms(10);
      lcd_cls(); lcd_ln(1);
      printf(lcd_putc "Vn = %ld", Vn);
      lcd_ln(2);
      printf(lcd_putc "I = %d, Vg = %ld", I, Vg);
      delay_ms(1000); 
   }
}
