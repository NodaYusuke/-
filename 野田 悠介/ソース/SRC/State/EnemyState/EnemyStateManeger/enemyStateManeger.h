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
	//行動決定の種
	int stateSeed;
	//攻撃を行う限界値
	int commandRimit;
	//一秒を図るカウント
	int time;
	//行動を支持する値
	int commandState;

	bool setCommand;
};