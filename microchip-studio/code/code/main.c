#include <avr/io.h>
#include "toString/toString.h"
#include "lcd16x2_PB/lcd16x2_PB.h"
#include "lcd16x2_PD/lcd16x2_PD.h"

int main(void)
{
	/* 
	- D4=PB0
	- D5=PB1
	- D6=PB2
	- D7=PB3
	- RS=PB4
	- RW=PB5
	- EN=PB6
	*/
	// LCD Init Uses PB Region
	lcdInit_PB();
	
	// Set The LCD Cursor At x = 0 , y = 0
	lcdSetCursor_PB(0, 0);
	// Print, Parameters Can Only Be Strings
	lcdPrint_PB("use religion PB");
	
	// Print value 2024 use IntegerToString And Set The Cursor x = 0 , y = 1
	lcdPrintWithCursor_PB(0, 1, IntegerToString(2024));
	
	
	
	
	
	/*
	- D4=PD0
	- D5=PD1
	- D6=PD2
	- D7=PD3
	- RS=PD4
	- RW=PD5
	- EN=PD6
	*/
	// LCD Init Uses PD Region
	lcdInit_PD();
	
	// Set The LCD Cursor At x = 0 , y = 0
	lcdSetCursor_PD(0, 0);
	// Print, Parameters Can Only Be Strings
	lcdPrint_PD("use religion PD");
	
	// Print value 1234 use IntegerToString And Set The Cursor x = 0 , y = 1
	lcdPrintWithCursor_PD(0, 1, IntegerToString(1234));
}
