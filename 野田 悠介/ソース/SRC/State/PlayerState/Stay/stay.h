#pragma once
#include"../../state.h"
//state�N���X�̔h���N���X
//�v���C���[�̑ҋ@�̃N���X
//NowState�ɃZ�b�g���邱�ƂŃJ�[�\���ɉ������ҋ@���s��
class C_Stay :public C_State
{
public:
	C_Stay();
	C_State* Action(PlayerActionElement *actionElement);
	HitElement GetCharaState();
private:
	D3DXMATRIX       endMat;/*���[�V�����̍Ō�̍s��*/
	D3DXMATRIX     startMat;/*���[�V�����̍ŏ��̍s��*/
	float        animeFrame;/*�A�j���̐i�s�x*/
	bool        animeSetFlg;/*�A�j���̍s����Z�b�g�������ǂ���*/
	int startPoint;
	int motionNumber;
	
};