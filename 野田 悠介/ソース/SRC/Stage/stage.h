#pragma once
#include"../function.h"
#include"../extern.h"
#include"../numDecision.h"

//ステージを形成するクラス

class C_Stage
{
public:
	C_Stage();
	~C_Stage();
	void Render3D();

private:
	D3DXMATRIX fieldScaleMat;

	D3DXMATRIX brackShereMat;
	XFILE brackShereMesh;

	LPDIRECT3DTEXTURE9 floorTex;
	VERTEX v[4];
};
