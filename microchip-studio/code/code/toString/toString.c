#include "toString.h"

char* IntegerToString(int value)
{
	char buff[255];
	char *string;
	
	sprintf(buff,"%d",value);
	string=buff;
	return string;
}
char* DoubleToString(double value,int range)
{
	char buff[255];
	char *string;
	
	dtostrf(value,0,range,buff);
	string=buff;
	return string;
}