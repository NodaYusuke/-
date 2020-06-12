#pragma once
#include"../extern.h"
#include"../function.h"
#include"../numDecision.h"
//カメラ操作のクラス
//Update関数に引数として1:カメラの位置 2:カメラの注視点を渡すことでカメラを作成するクラス
class C_Camera
{
public:
	C_Camera();
	~C_Camera();
	void SetCamera();
	//引数 1:カメラの位置 2:カメラの注視点
	D3DXVECTOR3 Update(D3DXMATRIX Mat1, D3DXMATRIX Mat2, D3DXVECTOR3 Vec);
private:
	D3DXMATRIX mView, mProj;
	D3DXVECTOR3 cameraPos  = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 cameraLook = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 cameraHead = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
}; 