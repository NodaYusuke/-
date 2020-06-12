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
	//�s������̎�
	int stateSeed;
	//�U�����s�����E�l
	int commandRimit;
	//��b��}��J�E���g
	int time;
	//�s�����x������l
	int commandState;

	bool setCommand;
};