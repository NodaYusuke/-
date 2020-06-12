#pragma once
#include"../../state.h"

//stateクラスの派生クラス
//プレイヤーの上段攻撃のクラス
//NowStateにセットすることで上段攻撃を行う
class C_E_Attack :public C_State
{
public:
	C_E_Attack();
	~C_E_Attack();
	C_State* Action(EnemyActionElement* actionElement);
	HitElement GetCharaState();;
private:
	D3DXMATRIX   endMat;/*モーションの最後の行列*/
	D3DXMATRIX startMat;/*モーションの最初の行列*/
	float    animeFrame;/*アニメの進行度*/
	bool    animeSetFlg;/*アニメの行列をセットしたかどうか*/
	int    motionNumber;/*現在行っているモーションの番号*/
};