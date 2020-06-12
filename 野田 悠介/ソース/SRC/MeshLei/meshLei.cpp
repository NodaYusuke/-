#include"meshLei.h"

C_MeshLei::C_MeshLei()
{

}

C_MeshLei::~C_MeshLei()
{

}

//メッシュのレイ判定を行う関数======================================================================
//LPD3DXMESH lpMesh; /*メッシュの形状*/
//D3DXMATRIX meshMat;/*メッシュの行列*/
//D3DXVECTOR3 nowPos;/*現在の位置*/
//D3DXMATRIX rotMat;/*発射位置の回転行列*/
//D3DXVECTOR3 vec;  /*ワールド座標のレイ発射方向*/
float C_MeshLei::update(LPD3DXMESH lpMesh, D3DXMATRIX meshMat, D3DXVECTOR3 nowPos, D3DXVECTOR3 vec,D3DXMATRIX rotMat)
{
	//行列でベクトルを加工---------------------------------------
	/*ワールド座標のレイ発射方向を求める*/
	D3DXVec3TransformCoord(&vec , &vec, &rotMat);
	
	//-----------------------------------------------------------
	

	D3DXMATRIX InvMat;   /*メッシュの逆行列*/
	//逆行列の作成------------------------------
	D3DXMatrixInverse(&InvMat, NULL, &meshMat);
	//------------------------------------------
	D3DXVECTOR3 localPos ;/*計算上のレイ発射位置 */
	D3DXVECTOR3 localVec ;/*計算上のレイ発射方向 */
	

	//行列でベクトルを加工------------------------------
	/*ローカル座標のレイ発射位置を求める*/
	D3DXVec3TransformCoord(&localPos, &nowPos, &InvMat);
	//--------------------------------------------------

	//行列でベクトルを加工----------------------------
	/*ローカル座標のレイ発射方向を求める*/
	D3DXVec3TransformNormal(&localVec , &vec , &InvMat);
	
	//------------------------------------------------

	BOOL Hit;     /*当たったかどうか*/
	float meshDis;/*レイがあったた距離(true,false)*/
	
	//メッシュとのレイ判定--------------------------------------------------------------------
	
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