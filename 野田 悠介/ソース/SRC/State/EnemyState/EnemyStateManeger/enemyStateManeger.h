#pragma once
#include"../../../struct.h"

enum COMMAND
{
	STAYCOM = 0,
	ATTACKCOM,
	MOVECOM
};

class C_E_StateManeger

{
public:
	C_E_StateManeger();
	~C_E_StateManeger();

	int SetNextState(const StateStack *playerStack, States *player, States* enemy);
	void ResetCommand();
	void MoveWayDecision(int * MoveWay,const int * nowCommand,bool * WayFlg, const float* st);
private:
	//s“®Œˆ’è‚Ìí
	int stateSeed;
	//UŒ‚‚ğs‚¤ŒÀŠE’l
	int commandRimit;
	//ˆê•b‚ğ}‚éƒJƒEƒ“ƒg
	int time;
	//s“®‚ğx‚·‚é’l
	int commandState;

	bool setCommand;
};