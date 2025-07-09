#include <16F876A.h>
#device ADC=8
#use fast_io(a)
#use fast_io(b)
#use fast_io(c)
#FUSES XT,NOWDT,PUT,NOBROWNOUT,NOLVP,CPD,NOWRT,NODEBUG,PROTECT
#use delay(crystal=4000000)

#define LCD_DATA_PORT getenv("SFR:PORTB")
#define LCD_ENABLE_PIN  PIN_B3
#define LCD_RS_PIN      PIN_B1
#define LCD_RW_PIN      PIN_B2
#define LCD_DATA4       PIN_B4
#define LCD_DATA5       PIN_B5
#define LCD_DATA6       PIN_B6
#define LCD_DATA7       PIN_B7
#include "lcd.c"

unsigned int8 I = 0;
unsigned int16 Vn = 0, Vg = 0;

void lcd_cls(){
   lcd_putc('\f');
}

void lcd_ln(l){
   lcd_gotoxy(1, l);
}

void sys_init(){
   output_a(0); output_b(0); output_c(0);
   set_tris_a(0b111111); set_tris_b(128); set_tris_c(0b00111100);
   output_a(0); output_b(0); output_c(0);
   
   SETUP_ADC(ADC_CLOCK_INTERNAL);
   SETUP_ADC_PORTS(AN0_AN1_AN2_AN4_VSS_VREF);
   
   lcd_init(); lcd_cls(); lcd_ln(1);
   lcd_putc("    Automatic");
   lcd_ln(2);
   lcd_putc("   Change Over");
   delay_ms(1000);
}

