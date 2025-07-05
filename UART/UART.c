#include <UART.h>

void main(){
   sys_init();
   putc(254); putc(1);
   putc(254); putc(00);
   printf("Write Some thing");
   while(TRUE){
//!      putc(254); putc(192);
//!      letterInput = getc(lcd);
//!      sprintf(letterInput);
   }
}
