#pragma once
#include"../../state.h"
//stateクラスの派生クラス
//プレイヤーの待機のクラス
//NowStateにセットすることでカーソルに応じた待機を行う
class C_Stay :public C_State
{
public:
	C_Stay();
	C_State* Action(PlayerActionElement *actionElement);
	HitElement GetCharaState();
private:
	D3DXMATRIX       endMat;/*モーションの最後の行列*/
	D3DXMATRIX     startMat;/*モーションの最初の行列*/
	float        animeFrame;/*アニメの進行度*/
	bool        animeSetFlg;/*アニメの行列をセットしたかどうか*/
	int startPoint;
	int motionNumber;
	
};