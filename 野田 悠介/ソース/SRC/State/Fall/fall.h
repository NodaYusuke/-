#pragma once
#include"../state.h"

class C_Fall :public C_State
{
public:
	C_Fall();
	C_State* Action(EnemyActionElement*);
	C_State* Action(PlayerActionElement*);
private:
	D3DXMATRIX startRotMat;
	D3DXMATRIX startTransMat;
	D3DXMATRIX endRotMat;
	D3DXMATRIX endTransMat;
	float animeFrame;
	bool setFlg;
};