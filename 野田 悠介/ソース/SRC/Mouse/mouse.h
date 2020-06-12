#pragma once
#include"../function.h"
#include"../extern.h"
#include"../numDecision.h"
//マウスの現在の位置を教えてくれるクラス
//Update関数の戻り値がマウスの位置
class C_Mouse
{
private:
	POINT BasePt;
public:
	C_Mouse();
	~C_Mouse();
	int Update();
};