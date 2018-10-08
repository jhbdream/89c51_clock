#include "Clock_state.h"
#include "reg51.h"
#include "segment.h"
segment SHOW={00,11,22};
int WatchCount=0;
//时钟运行
Trasition STATR_A_E0 = {
    Show_ALL,
	STATE_A
};
 

Trasition STATR_A_E1 = {

    Switch,
    STATE_B
};
 

Trasition STATR_A_E2 = {

    Switch,
    STATE_E
};
	
Trasition STATR_B_E0 = {
 
    Show_Hour,
	STATE_B
};
 

Trasition STATR_B_E1 = {
	Switch,
	STATE_C

};
 
Trasition STATR_B_E2 = {
 
	Hour_Inc,
	STATE_B
};

Trasition STATR_B_E3 = {
    Hour_Dec,
	STATE_B
    
};

Trasition STATR_C_E0 = {
 
    Show_Min,
	STATE_C
};

Trasition STATR_C_E1 = {
 
    Switch,
	STATE_D
};

Trasition STATR_C_E2 = {
 
    Min_Dec,
	STATE_C
};

Trasition STATR_C_E3 = {
 
    Min_Inc,
	STATE_C
};

Trasition STATR_D_E0 = {
 
    Show_Sec,
	STATE_D
};

Trasition STATR_D_E1 = {
 
    Switch,
	STATE_A
};
Trasition STATR_D_E2 = {
 
    Sec_Dec,
	STATE_D
};

Trasition STATR_D_E3 = {
 
    Sec_Inc,
	STATE_D
};

Trasition STATR_E_E0 = {
 
    
	Stopwatch,
	STATE_E
};

Trasition STATR_E_E1 = {
 
    Switch,
	STATE_A
};
Trasition STATR_E_E2 = {
 
    Start,
	STATE_E
};

Trasition STATR_E_E3 = {
 
    ZERO,
	STATE_E
};


Trasition NULL = {
 
    Switch,
	STATE_A
};
code pTrasition transition_table[5][4] = {
	&STATR_A_E0 , &STATR_A_E1, &STATR_A_E2, &NULL,
	&STATR_B_E0 , &STATR_B_E1, &STATR_B_E2, &STATR_B_E3,
	&STATR_C_E0 , &STATR_C_E1, &STATR_C_E2, &STATR_C_E3,
	&STATR_D_E0 , &STATR_D_E1, &STATR_D_E2, &STATR_D_E3,
	&STATR_E_E0 , &STATR_E_E1, &STATR_E_E2, &STATR_E_E3

};
 
void Show_ALL()
{
	SHOW.hour = Time.hour;
	SHOW.min = Time.min;
	SHOW.sec = Time.sec;	
	write_buf( &SHOW );
	
}

void Switch()
{
	
}

void Show_Hour()
{
	SHOW.hour = Time.hour;
	SHOW.min = NONE;
	SHOW.sec = NONE;	
	write_buf( &SHOW );


}
void Hour_Inc()
{
	Time.hour++;
	if(Time.hour > 23)	
		Time.hour = 0;
}

void Hour_Dec()
{
 	Time.hour--;
	if(Time.hour < 0)	
		Time.hour = 23; 
}


void Show_Min()
{
	SHOW.hour =NONE ;
	SHOW.min = Time.min;
	SHOW.sec = NONE;
	write_buf( &SHOW );
	
}
void Min_Inc()
{
 	Time.min++;
	if(Time.min > 59)	
		Time.min = 0; 
}
void Min_Dec()
{
  	Time.min--;
	if(Time.min < 0)	
		Time.min = 59; 
  
}

void Show_Sec()
{
	
	SHOW.hour=NONE;
	SHOW.min=NONE;
	SHOW.sec = Time.sec;
	write_buf( &SHOW );

}
void Sec_Inc()
{
	Time.sec++;
	if(Time.sec > 59)	
		Time.sec = 0;
}

void Sec_Dec()
{
  	Time.sec--;
	if(Time.sec < 0)	
		Time.sec= 59; 
}


void Stopwatch()
{
	
	SHOW.hour 	= WATCH.min;
	SHOW.min 	= WATCH.sec;
	SHOW.sec 	= WatchCount;	
	write_buf( &SHOW );	

}

void Start()
{
	
	
	TR1 = ~TR1;//启动计数
	
}


void ZERO()
{
	WATCH.min = 0;
	WATCH.sec = 0;
	WatchCount = 0;
}