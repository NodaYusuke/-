#pragma once
#include"../function.h"
#include"../extern.h"
#include"../numDecision.h"
//�}�E�X�̌��݂̈ʒu�������Ă����N���X
//Update�֐��̖߂�l���}�E�X�̈ʒu
class C_Mouse
{
private:
	POINT BasePt;
public:
	C_Mouse();
	~C_Mouse();
	int Update();
};