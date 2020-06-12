#pragma once
#include"../../../state.h"
//stateクラスの派生クラス
//プレイヤーの上段防御のクラス
//NowStateにセットすることで上段防御を行う
class C_TopGuard :public C_State
{
public:
	C_TopGuard();
	C_State* Action(PlayerActionElement *actionElement);
	HitElement GetCharaState();
private:
	D3DXMATRIX   endMat;/*モーションの最後の行列*/
	D3DXMATRIX startMat;/*モーションの最初の行列*/
	D3DXMATRIX  saveMat;/*1番最初の行列*/
	float    animeFrame;/*アニメの進行度*/
	bool    animeSetFlg;/*アニメの行列をセットしたかどうか*/
	int       nowMotion;/*現在のモーション*/
};