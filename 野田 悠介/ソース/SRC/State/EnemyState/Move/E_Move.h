#pragma once
#include"../../state.h"
//stateクラスの派生クラス
//プレイヤーの前進のクラス
//NowStateにセットすることで前進を行う
class C_E_Move :public C_State
{
public:
	C_E_Move();
	HitElement GetCharaState();
	C_State* Action(EnemyActionElement* actionElement);
private:
	int moveCnt;
	bool wayFlg;
};