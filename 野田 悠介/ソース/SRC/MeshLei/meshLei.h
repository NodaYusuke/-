#pragma once
#include"../function.h"
#include"../extern.h"
//メッシュのレイ判定を行う関数
/*戻り値はfloat型(当たった場合　0以上:当たらなかった-1)*/
/*引数は1:lpMesh(メッシュの形状),2:D3DXMATRIX(メッシュの行列),3:D3DXVECTOR3(現在の位置),4;発射方向,5:D3DXMATRIX(発射位置の回転行列)*/

class C_MeshLei
{
public:
	C_MeshLei();
	~C_MeshLei();
	float update(LPD3DXMESH lpMesh, D3DXMATRIX meshMat, D3DXVECTOR3 nowPos,D3DXVECTOR3 vec,D3DXMATRIX RotMat);
};