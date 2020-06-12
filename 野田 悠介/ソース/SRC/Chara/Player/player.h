#pragma once
#include"../chara.h"
#include"../../Mouse/mouse.h"
//キャラクタークラスの派生クラス
//プレイヤーのクラス
class C_Player:public C_Chara
{

public:
	C_Player(D3DXVECTOR3 Pos, float Ang);
	~C_Player();
	HitElement Update(charaElement playerElement);
	bool Render2D(bool DamageFlg);
	void TestRender2D();
	const StateStack*  ReturnStack();
	//体力を返す
	float HPGetter();
	//スタミナを返す
	float STGetter();
private:
	LPDIRECT3DTEXTURE9 positionTex;
	D3DXMATRIX positionMat;
	StateStack playerStack;
	PlayerActionElement playerActionElement;
};