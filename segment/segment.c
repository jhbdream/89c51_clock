#include"segment.h"
#include "reg51.h"
#include "stdio.h"
#include "time.h"
#include "intrins.h"
#define COM   P2
#define DELAY 2
#define DATEPORT P0


sbit DUAN 	=P2^6;
sbit WEI   	=P2^7;


char display_buf[7];
unsigned char code table[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0xFF};
segment Time={00,11,22};
segment WATCH={00,00,00};
void clear()
{
	char i = 0; 
	for (i = 0; i < 6; i++ )
	{
		display_buf[i] = table[SPACE];
	}
}

void write_buf( segment * seg)
{		
	if(seg->hour == NONE)
	{
		display_buf[0]=table[SPACE] ;
		display_buf[1]=table[SPACE];
	}
	else
	{
		display_buf[1]= table[ seg->hour % 10 ] & ~0X80;
		display_buf[0]= table[ seg->hour / 10 ] ;		
	}
	
	if(seg->min == NONE)
	{
		display_buf[2]=table[SPACE];
		display_buf[3]=table[SPACE]  ;
	}
	else
	{
		display_buf[3]= table[ seg->min % 10 ] & ~0X80;
		display_buf[2]= table[ seg->min / 10 ];	
		
	}
	if(seg->sec == NONE)
	{
		display_buf[4]=table[SPACE];
		display_buf[5]=table[SPACE];
	}
	else
	{
		display_buf[5]= table[ seg->sec % 10 ];
		display_buf[4]= table[ seg->sec / 10 ];		
	}
}

//void display()
//{
//	char i = 0;
//	
//	for ( i = 0; i < 6; i++)
//	{
//		P1 =  (0X00 | (1 << i));
//		COM = display_buf[i];
//		delay(DELAY);
//		
//	}
//	
//}

void display()
{
	char i = 0,TEMP;
	
	for ( i = 0; i < 6; i++)
	{
		TEMP = (0X00 | (1 << (5-i)));
		
		DUAN = 1;
		DATEPORT = display_buf[i];
		DUAN = 0;
		DATEPORT = 0X00;
			
		WEI = 1;
		DATEPORT =TEMP;
		WEI = 0;		
		DATEPORT = 0XFF;
//		DATEPORT = display_buf[i];
//		DUAN = 1;
//		DUAN = 0;
		
		delay(DELAY);
		
	}
	
}

void show_num(unsigned char num)
{
	P2=table[num];

}



