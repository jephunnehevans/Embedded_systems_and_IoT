#include <16F876A.h>
#device ADC=8
#use fast_io(a)
#use fast_io(b)
#use fast_io(c)
#FUSES XT,NOWDT,PUT,NOBROWNOUT,NOLVP,CPD,NOWRT,NODEBUG,PROTECT
#use delay(crystal=4000000)

#define LCD_DATA_PORT getenv("SFR:PORTC")
#define LCD_ENABLE_PIN  PIN_C3
#define LCD_RS_PIN      PIN_C1
#define LCD_RW_PIN      PIN_C2
#define LCD_DATA4       PIN_C4
#define LCD_DATA5       PIN_C5
#define LCD_DATA6       PIN_C6
#define LCD_DATA7       PIN_C7
#include "lcd.c"


void sys_init(){
   output_a(0); output_b(0); output_c(0);
   set_tris_a(0b111111);
   set_tris_b(0); set_tris_c(0);
   output_a(0); output_b(0); output_c(0);
   
   SETUP_ADC(ADC_CLOCK_INTERNAL);
   SETUP_ADC_PORTS(AN0_AN1_VSS_VREF);
   SET_ADC_CHANNEL(0);
   
   lcd_init(); lcd_putc('\f'); lcd_gotoxy(1,1);
   printf(lcd_putc "     Digital    ",);
   lcd_gotoxy(1,2);
   printf(lcd_putc "   Thermometer  ",);
   delay_ms(3000);
}

void tempCtrl(unsigned int tempVal){
char state[7];
   if(tempVal>=41){
      output_high(pin_b1); output_low(pin_b2);
      state = "Cooler";
   }
   else if(tempVal<=40){
      output_high(pin_b2); output_low(pin_b1);
      state = "Heater";
   }
   
   lcd_gotoxy(1,2);
   printf(lcd_putc "State: %s", state);
   delay_ms(500);
}

void showTemp(float temp){
   delay_ms(10);
   lcd_putc('\f');
   
   lcd_gotoxy(1,1);
   printf(lcd_putc "Temp = %g%cC", temp, 223);
   
   tempCtrl(temp);
}
