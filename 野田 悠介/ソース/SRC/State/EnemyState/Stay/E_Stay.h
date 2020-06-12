#pragma once
#include"../../state.h"
//stateクラスの派生クラス
//敵の中段待機のクラス
//NowStateにセットすることで状況に応じた待機を行う
class C_E_Stay :public C_State
{
public:
	C_E_Stay();
	C_State* Action(EnemyActionElement* actionElement);
	
private:
	D3DXMATRIX       endMat;/*モーションの最後の行列*/
	D3DXMATRIX     startMat;/*モーションの最初の行列*/
	float        animeFrame;/*アニメの進行度*/
	bool        animeSetFlg;/*アニメの行列をセットしたかどうか*/
	int motionNumber;
	bool ChagePositionSetFlg;
	int positionChangFlg;
};