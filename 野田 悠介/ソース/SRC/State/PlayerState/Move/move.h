#pragma once
#include"../../state.h"
//state�N���X�̔h���N���X
//�v���C���[�̑O�i�̃N���X
//NowState�ɃZ�b�g���邱�ƂőO�i���s��
class C_Move :public C_State
{
public:
	C_Move();
	HitElement GetCharaState();
	C_State* Action(PlayerActionElement *actionElement);

private:
	bool tapFlg[3];//WASD�����������ǂ����t���O
	int  tapCnt;   //��x�����̎���
	bool outFlg;   //�{�^���𗣂����t���O
	bool timeSetFlg;//���Ԃ��Z�b�g�������ǂ����̃t���O
};