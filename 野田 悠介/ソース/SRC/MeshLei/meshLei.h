#pragma once
#include"../function.h"
#include"../extern.h"
//���b�V���̃��C������s���֐�
/*�߂�l��float�^(���������ꍇ�@0�ȏ�:������Ȃ�����-1)*/
/*������1:lpMesh(���b�V���̌`��),2:D3DXMATRIX(���b�V���̍s��),3:D3DXVECTOR3(���݂̈ʒu),4;���˕���,5:D3DXMATRIX(���ˈʒu�̉�]�s��)*/

class C_MeshLei
{
public:
	C_MeshLei();
	~C_MeshLei();
	float update(LPD3DXMESH lpMesh, D3DXMATRIX meshMat, D3DXVECTOR3 nowPos,D3DXVECTOR3 vec,D3DXMATRIX RotMat);
};