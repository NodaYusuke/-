#pragma once
#include"../../../state.h"
//state�N���X�̔h���N���X
//�v���C���[�̏�i�h��̃N���X
//NowState�ɃZ�b�g���邱�Ƃŏ�i�h����s��
class C_TopGuard :public C_State
{
public:
	C_TopGuard();
	C_State* Action(PlayerActionElement *actionElement);
	HitElement GetCharaState();
private:
	D3DXMATRIX   endMat;/*���[�V�����̍Ō�̍s��*/
	D3DXMATRIX startMat;/*���[�V�����̍ŏ��̍s��*/
	D3DXMATRIX  saveMat;/*1�ԍŏ��̍s��*/
	float    animeFrame;/*�A�j���̐i�s�x*/
	bool    animeSetFlg;/*�A�j���̍s����Z�b�g�������ǂ���*/
	int       nowMotion;/*���݂̃��[�V����*/
};