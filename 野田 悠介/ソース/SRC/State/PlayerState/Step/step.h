#pragma once
#include"../../state.h"
//state�N���X�̔h���N���X
//�v���C���[�̉��(���)�̃N���X
//NowState�ɃZ�b�g���邱�Ƃŉ��(���)���s��
class C_Step :public C_State
{
public:
	C_Step();
	C_State* Action(PlayerActionElement* actionElement);
	HitElement GetCharaState();
private:
	int stepTime;/*�X�e�b�v����*/
	//�L�����N�^�[�̈ړ��s��̍쐬
	D3DXVECTOR3 stepVec;
	D3DXMATRIX stepMat;
	bool setFlg;
};