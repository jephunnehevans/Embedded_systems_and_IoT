#include <ADC.h>

void main(){
   sys_init();
   while(TRUE){
      lcd_clear();
      i = READ_ADC();
      delay_ms(100);
      
//!      a = 0.0196;
//!      a = i * a;
      lcd_gotoxy(1,1);
      printf(lcd_putc "Voltage = %g", i * 0.0196);
      delay_ms(10);
      lcd_gotoxy(1, 2);
      printf(lcd_putc "Convertion = %g", i);
      delay_ms(1000);
   }
}
