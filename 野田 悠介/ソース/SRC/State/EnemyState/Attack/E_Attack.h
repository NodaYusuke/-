#pragma once
#include"../../state.h"

//state�N���X�̔h���N���X
//�v���C���[�̏�i�U���̃N���X
//NowState�ɃZ�b�g���邱�Ƃŏ�i�U�����s��
class C_E_Attack :public C_State
{
public:
	C_E_Attack();
	~C_E_Attack();
	C_State* Action(EnemyActionElement* actionElement);
	HitElement GetCharaState();;
private:
	D3DXMATRIX   endMat;/*���[�V�����̍Ō�̍s��*/
	D3DXMATRIX startMat;/*���[�V�����̍ŏ��̍s��*/
	float    animeFrame;/*�A�j���̐i�s�x*/
	bool    animeSetFlg;/*�A�j���̍s����Z�b�g�������ǂ���*/
	int    motionNumber;/*���ݍs���Ă��郂�[�V�����̔ԍ�*/
};