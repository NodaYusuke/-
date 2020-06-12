#pragma once
#include"../../state.h"
//stateクラスの派生クラス
//プレイヤーの前進のクラス
//NowStateにセットすることで前進を行う
class C_Move :public C_State
{
public:
	C_Move();
	HitElement GetCharaState();
	C_State* Action(PlayerActionElement *actionElement);

private:
	bool tapFlg[3];//WASDを押したかどうかフラグ
	int  tapCnt;   //二度押しの時間
	bool outFlg;   //ボタンを離したフラグ
	bool timeSetFlg;//時間をセットしたかどうかのフラグ
};