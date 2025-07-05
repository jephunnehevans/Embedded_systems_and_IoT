#include <RTC with scheduling.h>

void main(){
   sys_init();
   while(TRUE){
      // = RTC_read()
      lcd_cls(); lcd_ln(1);
      print_time();
      lcd_ln(2);
      printf(lcd_putc " Time %c", 0);
      delay_ms(500);
      
      if(compare_time_with_RTC(apl1On)) output_high(Apl1);
      if(compare_time_with_RTC(apl1Off)) output_low(Apl1);
      if(compare_time_with_RTC(apl2On)) output_high(Apl2);
      if(compare_time_with_RTC(apl2Off)) output_low(Apl2);
      if(compare_time_with_RTC(apl3On)) output_high(Apl3);
      if(compare_time_with_RTC(apl3Off)) output_low(Apl3);
      
      
//!      void schedule_time(){
//!   
//!   set_hour(0, 1);
//!   set_minute(0, 1);
//!   set_second(0, 1);
//!   
//!}
   }
}
