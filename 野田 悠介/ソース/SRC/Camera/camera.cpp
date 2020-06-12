#include"camera.h"

C_Camera::C_Camera()
{
}

C_Camera::~C_Camera()
{
}
void C_Camera::SetCamera()
{
	lpD3DDevice->BeginScene();
	ZeroMemory(&mView, sizeof(mView));
	ZeroMemory(&mProj, sizeof(&mProj));
	// ���_�s��̐ݒ�
	D3DXMatrixLookAtLH(&mView,
		&cameraPos,// �J�����̈ʒu
		&cameraLook,// �J�����̎��_
		&cameraHead	// �J�����̓��̕���
	);

	// ���e�s��̐ݒ�
									  //����p          //��������/�A�X�y�N�g��   //�����鋗��
	D3DXMatrixPerspectiveFovLH(&mProj, D3DXToRadian(60), (float)SCRW / (float)SCRH, 1.0f, 1500.0f);

	//�s��ݒ�
	lpD3DDevice->SetTransform(D3DTS_VIEW, &mView);
	lpD3DDevice->SetTransform(D3DTS_PROJECTION, &mProj);
}
D3DXVECTOR3 C_Camera::Update(D3DXMATRIX Mat1,D3DXMATRIX Mat2, D3DXVECTOR3 Vec)
{
	D3DXVec3TransformCoord(&cameraPos, &Vec, &Mat1);
	cameraLook = D3DXVECTOR3(Mat2._41, Mat2._42, Mat2._43);
	return cameraPos;
}