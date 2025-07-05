#include <Tmr0_counter.h>

void main(){
   sys_init();
   while(TRUE){
      lcd_clear(); lcd_line(1);
      printf(lcd_putc "Press the botton",);
      delay_ms(50);
      lcd_line(2);
      printf(lcd_putc "Counter = %u", GET_RTCC());
      delay_ms(50);
   }
}
