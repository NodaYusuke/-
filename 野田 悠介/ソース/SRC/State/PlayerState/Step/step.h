#pragma once
#include"../../state.h"
//stateクラスの派生クラス
//プレイヤーの回避(後退)のクラス
//NowStateにセットすることで回避(後退)を行う
class C_Step :public C_State
{
public:
	C_Step();
	C_State* Action(PlayerActionElement* actionElement);
	HitElement GetCharaState();
private:
	int stepTime;/*ステップ時間*/
	//キャラクターの移動行列の作成
	D3DXVECTOR3 stepVec;
	D3DXMATRIX stepMat;
	bool setFlg;
};