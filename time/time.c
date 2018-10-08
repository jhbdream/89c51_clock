#include "stdio.h"
#include "reg51.h"
#include "time.h"
// 定义一个延时xms毫秒的延时函数
void delay(unsigned int xms)  // xms代表需要延时的毫秒数
{
    unsigned int x,y;
    for(x=xms;x>0;x--)
        for(y=110;y>0;y--);
}

void TIME_Init()
{
	TMOD = 0x11;                  
	TL0 = 0;                   
	TH0 = 0;
	TL1 = 0;                   
	TH1 = 0;
	TR0 = 1;
	TR1=0;			//秒表计数不开启
	ET1=1;
	ET0 = 1;   	
	EA = 1;      
}


