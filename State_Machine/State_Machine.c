#include"State_Machine.h"
#include "key.h"

//ÿһ�������� һ��action
void step(pStateMachine machine)
{
	
	static unsigned char val;
	static pTrasition T;
	
	val = key_scan();
	T = transition_table[machine->current][val];
    
	machine->current = T->next;
	
    (*(T->action))();
}

