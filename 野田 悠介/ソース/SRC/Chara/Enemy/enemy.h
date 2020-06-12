#pragma once
#include"../chara.h"
//�L�����N�^�[�N���X�̔h���N���X
//�G�l�~�[�̃N���X
class C_Enemy :public C_Chara
{
public:
	C_Enemy(D3DXVECTOR3 Pos, float Ang);
	~C_Enemy();
	HitElement Update(charaElement enemyElement, const StateStack* playerStack, States* player);
	bool Render2D(bool DamageFlg);
	
protected:
	int position;
	EnemyActionElement enemyActionElement;//�����p�̕ϐ�
	int moveWay;//��������
	int moveWayChangeCnt;
};