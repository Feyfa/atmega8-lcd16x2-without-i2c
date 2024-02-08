#include "lcd16x2_PD.h"

void wait_PD()
{
	_delay_ms(3);
}
void lcdCommand_PD(unsigned char cmnd)
{
	//MENGGESER NILAI DI BIT (7-4) MENJADI DI BIT (3-0) DAN BIT (7-4) NILAINYA (0 0 0 0)
	//CONTOH : cmnd=(0 0 1 0 1 0 0 0) BERUBAH MENJADI PORTA=(0 0 0 0 0 0 1 0)
	PORTD = (PORTD & 0xF0) | (cmnd >> 4); 
	
	//HANYA RW=0
	PORTD &= ~(1<<LCD_RW);  
	//HANYA RS=0
	PORTD &= ~(1<<LCD_RS);  
	//HANYA EN=1
	PORTD |=  (1<<LCD_EN);  
	wait_PD();
	//HANYA EN=0
	PORTD &= ~(1<<LCD_EN);  
	
	wait_PD();
	
	//MENGUBAH NILAI DI BIT (7-4) MENJADI (0 0 0 0) DAN NILAI DI BIT (3-0) TETAP
	//CONTOH : cmnd=(0 0 1 0 1 0 0 0) BERUBAH MENJADI (0 0 0 0 1 0 0 0)
	PORTD = (PORTD & 0xF0) | (cmnd & 0X0F);
	
	//HANYA EN=1
	PORTD |= (1<<LCD_EN);  
	wait_PD();
	//HANYA EN=0
	PORTD &= ~(1<<LCD_EN);  
	wait_PD();
}
void lcdData_PD(unsigned char data)
{
	//MENGGESER NILAI DI BIT (7-4) MENJADI DI BIT (3-0) DAN BIT (7-4) NILAINYA (0 0 0 0)
	//CONTOH : data=(0 0 1 0 1 0 0 0) BERUBAH MENJADI PORTA=(0 0 0 0 0 0 1 0)
	PORTD = (PORTD & 0xF0) | (data >> 4); 
	
	//HANYA RW=0
	PORTD &= ~(1<<LCD_RW); 
	//HANYA RS=1
	PORTD |= (1<<LCD_RS);  
	//HANYA EN=1
	PORTD |= (1<<LCD_EN);  
	wait_PD();
	//HANYA EN=0
	PORTD &= ~(1<<LCD_EN); 
	
	wait_PD();
	
	//MENGUBAH NILAI DI BIT (7-4) MENJADI (0 0 0 0) DAN NILAI DI BIT (3-0) TETAP
	//CONTOH : data=(0 0 1 0 1 0 0 0) BERUBAH MENJADI (0 0 0 0 1 0 0 0)
	PORTD = (PORTD & 0xF0) | (data & 0x0F);
	
	//HANYA EN=1
	PORTD |= (1<<LCD_EN);  
	wait_PD();
	//HANYA EN=0
	PORTD &= ~(1<<LCD_EN); 
	wait_PD();
}
void lcdInit_PD()
{
	DDRD =0xFF;
	//HANYA EN=0
	PORTD &= ~(1<<LCD_EN);  
	_delay_us(5);
	
	lcdCommand_PD(0x33);
	_delay_us(5);
	
	lcdCommand_PD(0x32);
	_delay_us(5);
	
	//4-bit mode,2 line
	lcdCommand_PD(0x28);  
	_delay_us(5);
	
	//display on,cursor off
	lcdCommand_PD(0x0c);  
	_delay_us(5);
	
	 //clear screen lcd
	lcdCommand_PD(0x01); 
	_delay_us(5);
	
	 //cursor geser ke kanan
	lcdCommand_PD(0x06); 
	_delay_us(5);
}
void lcdClear_PD()
{
	//clear screen lcd
	lcdCommand_PD(0x01);  
	wait_PD();
}
void lcdSetCursor_PD(unsigned char x,unsigned char y)
{
	unsigned char firstCharAdr[] = { 0x80 , 0xC0 , 0x94 , 0xD4 };
	
	lcdCommand_PD(firstCharAdr[y]+x);
	
	_delay_us(5);
}
void lcdPrint_PD(char *str)
{
	unsigned char i = 0;
	while(str[i] !=0)
	{
		lcdData_PD(str[i]);
		i++;
	}
}
void lcdPrintWithCursor_PD(unsigned char x,unsigned char y,char *str)
{
	lcdSetCursor_PD(x,y);
	lcdPrint_PD(str);
}
