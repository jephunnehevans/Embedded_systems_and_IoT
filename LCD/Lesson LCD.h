#include <16F84A.h>
#FUSES XT,NOWDT,PUT,PROTECT
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
#include "string.h"

unsigned int a;
char colour[5] = "John";

