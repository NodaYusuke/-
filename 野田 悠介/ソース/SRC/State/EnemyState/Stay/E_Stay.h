#pragma once
#include"../../state.h"
//state�N���X�̔h���N���X
//�G�̒��i�ҋ@�̃N���X
//NowState�ɃZ�b�g���邱�Ƃŏ󋵂ɉ������ҋ@���s��
class C_E_Stay :public C_State
{
public:
	C_E_Stay();
	C_State* Action(EnemyActionElement* actionElement);
	
private:
	D3DXMATRIX       endMat;/*���[�V�����̍Ō�̍s��*/
	D3DXMATRIX     startMat;/*���[�V�����̍ŏ��̍s��*/
	float        animeFrame;/*�A�j���̐i�s�x*/
	bool        animeSetFlg;/*�A�j���̍s����Z�b�g�������ǂ���*/
	int motionNumber;
	bool ChagePositionSetFlg;
	int positionChangFlg;
};