#pragma once
#include"../../state.h"
//state�N���X�̔h���N���X
//�v���C���[�̑O�i�̃N���X
//NowState�ɃZ�b�g���邱�ƂőO�i���s��
class C_E_Move :public C_State
{
public:
	C_E_Move();
	HitElement GetCharaState();
	C_State* Action(EnemyActionElement* actionElement);
private:
	int moveCnt;
	bool wayFlg;
};