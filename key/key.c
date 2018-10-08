#include "key.h"
#include "stdio.h"
#include "time.h"
#include "reg51.h"
sbit Line =P3^4;
unsigned int key_scan()
{
#ifdef juzhen
	unsigned char i = 0, j = 0, read,temp;
	unsigned char key_val = 0;
		for ( i = 0; i < 4; i++)
		{
			KEY_PORT = ~(1 << i); 
			
			for( j = 0; j < 4; j++)
			{
					
				temp = KEY_PORT;
				
				if( ~temp & (unsigned char)( 1 << (j + 4) ) )
				{
					key_val = i * 4 + j + 1;
					while(~temp & ( 1 << (j + 4) ))
					{
						temp = KEY_PORT;
					}
						return key_val;
				}
				
			}
			
		}
	return key_val;
#else 
	unsigned char i = 0,temp;
	unsigned char key_val = 0;
		
	Line = 0;	
	P2=0xFF;
	temp = P2 & 0X07;	
	if( temp != 0X07)
	{	
		switch(temp)
		{
			case 0x06:	key_val = 1;	break;
			case 0x05:	key_val = 2;	break;
			case 0x03:	key_val = 3;	break;
		
		}
	}	
	do
	{
		P2=0XFF;
		temp = P2 & 0X07;	
	
	}while(temp != 0X07);

	return key_val;
		
#endif
}