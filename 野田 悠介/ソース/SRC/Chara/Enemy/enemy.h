#pragma once
#include"../chara.h"
//キャラクタークラスの派生クラス
//エネミーのクラス
class C_Enemy :public C_Chara
{
public:
	C_Enemy(D3DXVECTOR3 Pos, float Ang);
	~C_Enemy();
	HitElement Update(charaElement enemyElement, const StateStack* playerStack, States* player);
	bool Render2D(bool DamageFlg);
	
protected:
	int position;
	EnemyActionElement enemyActionElement;//引数用の変数
	int moveWay;//動く方向
	int moveWayChangeCnt;
};