#include"meshLei.h"

C_MeshLei::C_MeshLei()
{

}

C_MeshLei::~C_MeshLei()
{

}

//���b�V���̃��C������s���֐�======================================================================
//LPD3DXMESH lpMesh; /*���b�V���̌`��*/
//D3DXMATRIX meshMat;/*���b�V���̍s��*/
//D3DXVECTOR3 nowPos;/*���݂̈ʒu*/
//D3DXMATRIX rotMat;/*���ˈʒu�̉�]�s��*/
//D3DXVECTOR3 vec;  /*���[���h���W�̃��C���˕���*/
float C_MeshLei::update(LPD3DXMESH lpMesh, D3DXMATRIX meshMat, D3DXVECTOR3 nowPos, D3DXVECTOR3 vec,D3DXMATRIX rotMat)
{
	//�s��Ńx�N�g�������H---------------------------------------
	/*���[���h���W�̃��C���˕��������߂�*/
	D3DXVec3TransformCoord(&vec , &vec, &rotMat);
	
	//-----------------------------------------------------------
	

	D3DXMATRIX InvMat;   /*���b�V���̋t�s��*/
	//�t�s��̍쐬------------------------------
	D3DXMatrixInverse(&InvMat, NULL, &meshMat);
	//------------------------------------------
	D3DXVECTOR3 localPos ;/*�v�Z��̃��C���ˈʒu */
	D3DXVECTOR3 localVec ;/*�v�Z��̃��C���˕��� */
	

	//�s��Ńx�N�g�������H------------------------------
	/*���[�J�����W�̃��C���ˈʒu�����߂�*/
	D3DXVec3TransformCoord(&localPos, &nowPos, &InvMat);
	//--------------------------------------------------

	//�s��Ńx�N�g�������H----------------------------
	/*���[�J�����W�̃��C���˕��������߂�*/
	D3DXVec3TransformNormal(&localVec , &vec , &InvMat);
	
	//------------------------------------------------

	BOOL Hit;     /*�����������ǂ���*/
	float meshDis;/*���C��������������(true,false)*/
	
	//���b�V���Ƃ̃��C����--------------------------------------------------------------------
	
		D3DXIntersect(lpMesh, &localPos, &localVec, &Hit, NULL, NULL, NULL, &meshDis, NULL, NULL);
		if (Hit == TRUE)
		{
			return meshDis;
		}
		else
		{
			return -1;
		}
	
}
//==================================================================================================