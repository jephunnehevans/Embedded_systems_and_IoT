#include <Calculator.h>

// A single digit calculator

void main(){
   sys_init();
   while(TRUE){
      lcd_putc('\f');
      lcd_gotoxy(16,1);
      lcd_putc('_');
      n[0] = scan_N();
      lcd_gotoxy(16,1);
      printf(lcd_putc "%s", n);
      num1 = atoi(n);
      
      lcd_gotoxy(1,2);
      lcd_putc('_');
      sign = scan_O();
      lcd_gotoxy(1,2);
      printf(lcd_putc "%c", sign);
      
      lcd_gotoxy(16,2);
      lcd_putc('_');
      n[0] = scan_N();
      lcd_gotoxy(16,2);
      printf(lcd_putc "%s", n);
      num2 = atoi(n);
      
      
      for(;;){
         output_b(255);
         output_low(pin_b6);
         if(!input(pin_b3)){
            while(!input(pin_b3));
            lcd_putc('\f');
            lcd_gotoxy(1,1);
            printf(lcd_putc "%u %c %u", num1, sign, num2);
            lcd_gotoxy(1,2);
            printf(lcd_putc "ANSWER = %f", calc(num1, num2, sign));
         }
         output_b(255);
         output_low(pin_b4);
         if(!input(pin_b3)){
            while(!input(pin_b3));
            break;
         }
      }
   }
}
