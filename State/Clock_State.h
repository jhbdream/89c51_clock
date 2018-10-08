#ifndef __CLOCK_STATE_H__
#define __CLOCK_STATE_H__
typedef char State;
 
#define STATE_A 0
#define STATE_B 1
#define STATE_C 2
#define STATE_D 3
#define STATE_E 4
typedef void (*ActionType)();
 
typedef struct
{
	ActionType action;
    char next;
   
} Trasition, * pTrasition;

typedef struct
{
    State current;
	
} StateMachine, * pStateMachine;



extern code pTrasition transition_table[5][4];

extern  int WatchCount;
void Show_ALL();
void Switch();
void Show_Hour();
void Hour_Inc();
void Hour_Dec();
void Hour_Switch();
void Show_Min();
void Min_Inc();
void Min_Dec();
void Min_Switch();
void Show_Sec();
void Sec_Inc();
void Sec_Dec();
void Sec_Switch();
void Stopwatch();
void Start();
void ZERO();

#endif