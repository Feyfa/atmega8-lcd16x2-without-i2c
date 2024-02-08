#include "lcd16x2_PB.h"

void wait_PB()
{
	_delay_ms(3);
}
void lcdCommand_PB(unsigned char cmnd)
{
	// SHIFTING THE VALUE IN BIT (7-4) TO BE IN BIT (3-0) AND BIT (7-4) THE VALUE (0 0 0 0)
	// EXAMPLE: cmnd=(0 0 1 0 1 0 0 0) CHANGE TO PORT=(0 0 0 0 0 0 1 0)
	PORTB = (PORTB & 0xF0) | (cmnd >> 4); 
	
	// ONLY RW=0
	PORTB &= ~(1 << LCD_RW);  
	// ONLY RS=0
	PORTB &= ~(1 << LCD_RS);  
	// ONLY EN=1
	PORTB |=  (1 << LCD_EN);  
	wait_PB();
	// ONLY EN=0
	PORTB &= ~(1 << LCD_EN);  
	
	wait_PB();
	
	// CHANGE THE VALUE IN BIT (7-4) TO (0 0 0 0) AND THE VALUE IN BIT (3-0) REMAINS
	// EXAMPLE: cmnd=(0 0 1 0 1 0 0 0) CHANGES TO (0 0 0 0 1 0 0 0)
	PORTB = (PORTB & 0xF0) | (cmnd & 0X0F);
	
	// ONLY EN=1
	PORTB |= (1 << LCD_EN);  
	wait_PB();
	// ONLY EN=0
	PORTB &= ~(1 << LCD_EN);  
}
void lcdData_PB(unsigned char data)
{
	// SHIFTING THE VALUE IN BIT (7-4) TO BE IN BIT (3-0) AND BIT (7-4) THE VALUE (0 0 0 0)
	// EXAMPLE: data=(0 0 1 0 1 0 0 0) CHANGE TO PORT=(0 0 0 0 0 0 1 0)
	PORTB = (PORTB & 0xF0) | (data >> 4); 
	
	// ONLY RW=0
	PORTB &= ~(1 << LCD_RW); 
	// ONLY RS=1
	PORTB |= (1 << LCD_RS);  
	// ONLY EN=1
	PORTB |= (1 << LCD_EN);  
	wait_PB();
	// ONLY EN=0
	PORTB &= ~(1 << LCD_EN);  
	
	wait_PB();
	
	// CHANGE THE VALUE IN BIT (7-4) TO (0 0 0 0) AND THE VALUE IN BIT (3-0) REMAINS
	// EXAMPLE: data=(0 0 1 0 1 0 0 0) CHANGES TO (0 0 0 0 1 0 0 0)
	PORTB = (PORTB & 0xF0) | (data & 0x0F);
	
	// ONLY EN=1
	PORTB |= (1 << LCD_EN);  
	wait_PB();
	// ONLY EN=0
	PORTB &= ~(1 << LCD_EN);  
}
void lcdInit_PB()
{
	DDRB =0xFF;
	
	// ONLY EN=0
	PORTB &= ~(1 << LCD_EN);  
	_delay_us(5);
	
	lcdCommand_PB(0x33);
	_delay_us(5);
	
	lcdCommand_PB(0x32);
	_delay_us(5);
	
	//4-bit mode,2 line
	lcdCommand_PB(0x28);  
	_delay_us(5);
	
	//display on,cursor off
	lcdCommand_PB(0x0c);  
	_delay_us(5);
	
	//clear screen lcd
	lcdCommand_PB(0x01);  
	_delay_us(5);
	
	//cursor geser ke kanan
	lcdCommand_PB(0x06);  
	_delay_us(5);
}
void lcdClear_PB()
{
	//clear screen lcd
	lcdCommand_PB(0x01);  
	wait_PB();
}
void lcdSetCursor_PB(unsigned char x,unsigned char y)
{	
	unsigned char firstCharAdr[] = { 0x80 , 0xC0 , 0x94 , 0xD4 };
	lcdCommand_PB(firstCharAdr[y]+x);
	wait_PB();
}
void lcdPrint_PB(char *str)
{
	unsigned char i = 0;
	while(str[i] !=0)
	{
		lcdData_PB(str[i]);
		i++;
	}
}
void lcdPrintWithCursor_PB(unsigned char x,unsigned char y,char *str)
{
	lcdSetCursor_PB(x,y);
	lcdPrint_PB(str);
}
