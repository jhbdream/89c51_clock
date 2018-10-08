#include "reg51.h"
#include "time.h"
#include "segment.h"
#include "key.h"
#include "State_Machine.h"
#include "Clock_State.h"

int count=0;
void main()
{
	StateMachine ASmachine={0};
	
	TIME_Init();
		
	//write_buf( &Time );
	while(1)
	{		
		display();
		step(&ASmachine);
		
	}
}

void TO_time() interrupt 1 using 1
{
	TH0=(65536-50000)/256;
	TL0=(65536-50000)%256;
	
	count++;
	if(count > 20)
	{
		Time.sec++;
			
		if(Time.sec == 60)
		{
			Time.sec = 0;
			Time.min++;
		}


		if(Time.min == 60)
		{
			Time.hour ++;
			Time.min = 0;
		}
				
		if(Time.hour == 24)
		{
			Time.hour = 0;
		}

		count = 0;
	
	}

}

void T1_time() interrupt 3 using 1
{
	TH1=(65536-10000)/256;
	TL1=(65536-10000)%256;
	
	WatchCount++;
	
	if(WatchCount > 99)
	{
		WatchCount = 0;
		WATCH.sec++;
	}
	
	if(WATCH.sec > 60)
	{
		WATCH.sec = 0;
		WATCH.min++;
	
	}
}