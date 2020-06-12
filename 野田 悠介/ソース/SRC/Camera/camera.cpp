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
	// 視点行列の設定
	D3DXMatrixLookAtLH(&mView,
		&cameraPos,// カメラの位置
		&cameraLook,// カメラの視点
		&cameraHead	// カメラの頭の方向
	);

	// 投影行列の設定
									  //視野角          //幅÷高さ/アスペクト比   //見える距離
	D3DXMatrixPerspectiveFovLH(&mProj, D3DXToRadian(60), (float)SCRW / (float)SCRH, 1.0f, 1500.0f);

	//行列設定
	lpD3DDevice->SetTransform(D3DTS_VIEW, &mView);
	lpD3DDevice->SetTransform(D3DTS_PROJECTION, &mProj);
}
D3DXVECTOR3 C_Camera::Update(D3DXMATRIX Mat1,D3DXMATRIX Mat2, D3DXVECTOR3 Vec)
{
	D3DXVec3TransformCoord(&cameraPos, &Vec, &Mat1);
	cameraLook = D3DXVECTOR3(Mat2._41, Mat2._42, Mat2._43);
	return cameraPos;
}