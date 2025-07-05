#include <16F876A.h>
#use fast_io(a)
#use fast_io(b)
#use fast_io(c)
#FUSES XT,NOWDT,PUT,NOBROWNOUT,NOLVP,CPD,NOWRT,NODEBUG
#use delay(crystal=4000000)

#define LCD_DATA_PORT getenv("SFR:PORTC")
#define LCD_ENABLE_PIN  PIN_C2
#define LCD_RS_PIN      PIN_C0
#define LCD_RW_PIN      PIN_C1
#define LCD_DATA4       PIN_C3
#define LCD_DATA5       PIN_C4
#define LCD_DATA6       PIN_C5
#define LCD_DATA7       PIN_C6
#include "lcd.c"

void lcd_cls(){
   lcd_putc('\f');
}

void lcd_ln(unsigned int8 y, x=1){
   lcd_gotoxy(x, y);
}

unsigned int1 f=1;
unsigned int8 t = 0;
char code[5] = {'\o', '\o', '\o', '\o', '\o'};
char correct_code[5] = {'1', '2', '3', '4', '\o'};

void sys_init(){
   output_a(0); output_b(0); output_c(0);
   set_tris_a(0); set_tris_b(0b11110000); set_tris_c(0);
   output_a(0); output_b(0); output_c(0);
   
   PORT_B_PULLUPS(0);
   
   lcd_init(); lcd_cls(); lcd_ln(1);
   printf(lcd_putc "Passcode Safe");
   delay_ms(1000);
}

unsigned int8 type(){
   while(true){
      output_b(0); output_b(2);
      if(input(pin_b4)){
         while(input(pin_b4));
         return '1';
      }
      if(input(pin_b5)){
         while(input(pin_b5));
         return '4';
      }
      if(input(pin_b6)){
         while(input(pin_b6));
         return '7';
      }
//!      if(input(pin_a4)){
//!         while(input(pin_a4));
//!         return ;
//!      }
      
      output_b(0); output_b(4);
      if(input(pin_b4)){
         while(input(pin_b4));
         return '2';
      }
      if(input(pin_b5)){
         while(input(pin_b5));
         return '5';
      }
      if(input(pin_b6)){
         while(input(pin_b6));
         return '8';
      }
      if(input(pin_b7)){
         while(input(pin_b7));
         return '0';
      }
      
      output_b(0); output_b(8);
      if(input(pin_b4)){
         while(input(pin_b4));
         return '3';
      }
      if(input(pin_b5)){
         while(input(pin_b5));
         return '6';
      }
      if(input(pin_b6)){
         while(input(pin_b6));
         return '9';
      }
//!      if(input(pin_a4)){
//!         while(input(pin_a4));
//!         return ;
//!      }
   }
}

