#include "enemyStateManeger.h"
#include"../../../numDecision.h"

C_E_StateManeger::C_E_StateManeger()
{
	stateSeed=rand()%RANDOMSEED;
	time = 0;
	commandRimit = stateSeed;
	commandState = STAYCOM;
	setCommand = false;
}

void C_E_StateManeger::ResetCommand()
{
	stateSeed = rand() % RANDOMSEED;
	time = 0;
	commandRimit = stateSeed;
	commandState = STAYCOM;
	setCommand = false;
}

void C_E_StateManeger::MoveWayDecision(int* moveWay, const int* nowCommand, bool* wayFlg, const float* st)
{
	if (*wayFlg == true)
		return;
	*wayFlg = true;
	if (*st <= 30)
	{
		*moveWay = REVERSE;
		return;
	}
	int decisionNum = rand() % 2;
	if (decisionNum == 0)
	{
		*moveWay = RIGHT;
		return;
	}
	*moveWay = LEFT;
	return;
}

C_E_StateManeger::~C_E_StateManeger()
{
}

int C_E_StateManeger::SetNextState(const StateStack* playerStack, States *player, States* enemy)
{
	if (setCommand == true)
	    return commandState;

	time += 10;
	if (time / 60 == 1)
	{
		commandRimit += UPATTACKRIMIT;
	}
	if (commandRimit >= 100)
	{
		setCommand = true;
		commandState = ATTACKCOM;
		return commandState;

	}
	commandState = MOVECOM;
	return commandState;

}


