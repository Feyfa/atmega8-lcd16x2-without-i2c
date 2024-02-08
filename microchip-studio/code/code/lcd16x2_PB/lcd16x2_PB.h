#ifndef LCD16X2_PB_H_
#define LCD16X2_PB_H_

/*
- D4=PB0
- D5=PB1
- D6=PB2
- D7=PB3
- RS=PB4
- RW=PB5
- EN=PB6
*/
#include <avr/io.h>
#include <util/delay.h>

// PB4
#define LCD_RS 4
// PB5
#define LCD_RW 5
// PB6
#define LCD_EN 6

void wait_PB();
void lcdCommand_PB(unsigned char cmnd);
void lcdData_PB(unsigned char data);
void lcdInit_PB();
void lcdClear_PB();
void lcdSetCursor_PB(unsigned char x,unsigned char y);
void lcdPrint_PB(char *str);
void lcdPrintWithCursor_PB(unsigned char x,unsigned char y,char *str);

#endif /* LCD16X2_PB_H_ */