#pragma once
#include"../../state.h"

//stateクラスの派生クラス
//プレイヤーの上段攻撃のクラス
//NowStateにセットすることで上段攻撃を行う
class C_Attack :public C_State
{
public:
	C_Attack();
	~C_Attack();
	C_State* Action(PlayerActionElement *actionElement);
	HitElement GetCharaState();;
private:
	D3DXMATRIX   endMat;/*モーションの最後の行列*/
	D3DXMATRIX startMat;/*モーションの最初の行列*/
	float    animeFrame;/*アニメの進行度*/
	bool    animeSetFlg;/*アニメの行列をセットしたかどうか*/
	int    motionNumber;/*現在行っているモーションの番号*/
	int   NowPoint;     //現在の構えの位置
	int StackUpdateFlg; //スタックを更新したかどうかのフラグ
};