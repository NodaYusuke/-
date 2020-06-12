#pragma once
#include"../chara.h"
#include"../../Mouse/mouse.h"
//�L�����N�^�[�N���X�̔h���N���X
//�v���C���[�̃N���X
class C_Player:public C_Chara
{

public:
	C_Player(D3DXVECTOR3 Pos, float Ang);
	~C_Player();
	HitElement Update(charaElement playerElement);
	bool Render2D(bool DamageFlg);
	void TestRender2D();
	const StateStack*  ReturnStack();
	//�̗͂�Ԃ�
	float HPGetter();
	//�X�^�~�i��Ԃ�
	float STGetter();
private:
	LPDIRECT3DTEXTURE9 positionTex;
	D3DXMATRIX positionMat;
	StateStack playerStack;
	PlayerActionElement playerActionElement;
};