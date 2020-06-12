#pragma once
#include"../extern.h"
#include"../function.h"
#include"../numDecision.h"
//�J��������̃N���X
//Update�֐��Ɉ����Ƃ���1:�J�����̈ʒu 2:�J�����̒����_��n�����ƂŃJ�������쐬����N���X
class C_Camera
{
public:
	C_Camera();
	~C_Camera();
	void SetCamera();
	//���� 1:�J�����̈ʒu 2:�J�����̒����_
	D3DXVECTOR3 Update(D3DXMATRIX Mat1, D3DXMATRIX Mat2, D3DXVECTOR3 Vec);
private:
	D3DXMATRIX mView, mProj;
	D3DXVECTOR3 cameraPos  = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 cameraLook = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 cameraHead = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
}; 