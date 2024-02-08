#ifndef LCD16X2_PD_H_
#define LCD16X2_PD_H_

/*
- D4=PD0
- D5=PD1
- D6=PD2
- D7=PD3
- RS=PD4
- RW=PD5
- EN=PD6
*/
#include <avr/io.h>
#include <util/delay.h>


//PD4
#define LCD_RS 4
//PD5
#define LCD_RW 5
//PD6
#define LCD_EN 6

void wait_PD();
void lcdCommand_PD(unsigned char cmnd);
void lcdData_PD(unsigned char data);
void lcdInit_PD();
void lcdClear_PD();
void lcdSetCursor_PD(unsigned char x, unsigned char y);
void lcdPrint_PD(char *str);
void lcdPrintWithCursor_PD(unsigned char x,unsigned char y,char *str);

#endif /* LCD16X2_PD_H_ */