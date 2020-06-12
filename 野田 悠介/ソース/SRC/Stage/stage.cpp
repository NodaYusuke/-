#include "stage.h"

C_Stage::C_Stage()
{
	LoadTexture(&floorTex, "DATA/Texture/floor.jpg", 2048, 1365, NULL);
	D3DXMatrixScaling(&fieldScaleMat, 40.0f, 40.0f, 40.0f);

	LoadMesh(&brackShereMesh, "DATA/Xfile/blackSphere.x");
	D3DXMatrixIdentity(&brackShereMat);
	brackShereMat = fieldScaleMat * brackShereMat;
	v[0].Color = D3DCOLOR_ARGB(255, 255, 255, 255);
	v[1].Color = D3DCOLOR_ARGB(255, 255, 255, 255);
	v[2].Color = D3DCOLOR_ARGB(255, 255, 255, 255);
	v[3].Color = D3DCOLOR_ARGB(255, 255, 255, 255);
}

C_Stage::~C_Stage()
{
	SafeRelease(floorTex);
}

void C_Stage::Render3D()
{
	lpD3DDevice->SetRenderState(D3DRS_LIGHTING, true);

	lpD3DDevice->SetTexture(0, NULL);
	lpD3DDevice->SetTransform(D3DTS_WORLD, &brackShereMat);
	DrawMesh(&brackShereMesh);
	
	lpD3DDevice->SetRenderState(D3DRS_LIGHTING, false);

	lpD3DDevice->SetFVF(FVF_VERTEX);//FVFのセット
	lpD3DDevice->SetTexture(0, floorTex);
	D3DXMATRIX GroundMat;

	//床の作成
	for (int i = 0; i < POLYNUM; i++)
	{
		for (int k = 0; k < POLYNUM; k++)
		{
			//頂点の座標を設定する
			
			v[0].Pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			v[1].Pos = D3DXVECTOR3(0.0f, 0.0f, POLYSIZE);
			v[2].Pos = D3DXVECTOR3(POLYSIZE, 0.0f, POLYSIZE);
			v[3].Pos = D3DXVECTOR3(POLYSIZE, 0.0f, 0.0f);

			v[0].Tex = D3DXVECTOR2(0,0);
			v[1].Tex = D3DXVECTOR2(1,0);
			v[2].Tex = D3DXVECTOR2(1,1);
			v[3].Tex = D3DXVECTOR2(0,1);

			//真ん中のポリゴンを中心にするため辺の長さの半分ずらしている
			D3DXMatrixTranslation(&GroundMat, i * POLYSIZE - (POLYNUM * POLYSIZE) / 2.0f, -1.6f, k * POLYSIZE - (POLYNUM * POLYSIZE) / 2.0f);
			lpD3DDevice->SetTransform(D3DTS_WORLD, &GroundMat);
			lpD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, v, sizeof(VERTEX));

		}
	}

   //壁の作成
	/*右*/
	for (int i = 0; i < POLYNUM; i++)
	{
		for (int k = 0; k < POLYNUM; k++)
		{
			//頂点の座標を設定する

			v[0].Pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			v[1].Pos = D3DXVECTOR3(0.0f, 0.0f, POLYSIZE);
			v[2].Pos = D3DXVECTOR3(0.0f, POLYSIZE, POLYSIZE);
			v[3].Pos = D3DXVECTOR3(0.0f, POLYSIZE, 0.0f);

			v[0].Tex = D3DXVECTOR2(0, 0);
			v[1].Tex = D3DXVECTOR2(1, 0);
			v[2].Tex = D3DXVECTOR2(1, 1);
			v[3].Tex = D3DXVECTOR2(0, 1);

			//真ん中のポリゴンを中心にするため辺の長さの半分ずらしている
			D3DXMatrixTranslation(&GroundMat, (POLYNUM * POLYSIZE) / 2.0f,i * POLYSIZE -1.6f, k * POLYSIZE - (POLYNUM * 10.0f) / 2.0f);
			lpD3DDevice->SetTransform(D3DTS_WORLD, &GroundMat);
			lpD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, v, sizeof(VERTEX));

		}
	}
	/*左*/
	for (int i = 0; i < POLYNUM; i++)
	{
		for (int k = 0; k < POLYNUM; k++)
		{
			//頂点の座標を設定する

			v[0].Pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			v[1].Pos = D3DXVECTOR3(0.0f, 0.0f, POLYSIZE);
			v[2].Pos = D3DXVECTOR3(0.0f, POLYSIZE, POLYSIZE);
			v[3].Pos = D3DXVECTOR3(0.0f, POLYSIZE, 0.0f);

			v[0].Tex = D3DXVECTOR2(0, 0);
			v[1].Tex = D3DXVECTOR2(1, 0);
			v[2].Tex = D3DXVECTOR2(1, 1);
			v[3].Tex = D3DXVECTOR2(0, 1);

			//真ん中のポリゴンを中心にするため辺の長さの半分ずらしている
			D3DXMatrixTranslation(&GroundMat, -(POLYNUM * POLYSIZE) / 2.0f, i * POLYSIZE - 1.6f, k * POLYSIZE - (POLYNUM * POLYSIZE) / 2.0f);
			lpD3DDevice->SetTransform(D3DTS_WORLD, &GroundMat);
			lpD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, v, sizeof(VERTEX));

		}
	}
	/*奥*/
	for (int i = 0; i < POLYNUM; i++)
	{
		for (int k = 0; k < POLYNUM; k++)
		{
			//頂点の座標を設定する

			v[0].Pos = D3DXVECTOR3( 0.0f,  0.0f, 0.0f);
			v[1].Pos = D3DXVECTOR3(POLYSIZE,  0.0f, 0.0f);
			v[2].Pos = D3DXVECTOR3(POLYSIZE, POLYSIZE, 0.0f);
			v[3].Pos = D3DXVECTOR3( 0.0f, POLYSIZE, 0.0f);

			v[0].Tex = D3DXVECTOR2(0, 0);
			v[1].Tex = D3DXVECTOR2(1, 0);
			v[2].Tex = D3DXVECTOR2(1, 1);
			v[3].Tex = D3DXVECTOR2(0, 1);

			//真ん中のポリゴンを中心にするため辺の長さの半分ずらしている
			D3DXMatrixTranslation(&GroundMat, i * POLYSIZE - (POLYNUM * POLYSIZE) / 2, k * POLYSIZE - 1.6f, (POLYNUM * POLYSIZE) / 2.0f);
			lpD3DDevice->SetTransform(D3DTS_WORLD, &GroundMat);
			lpD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, v, sizeof(VERTEX));

		}
	}
	/*手前*/
	for (int i = 0; i < POLYNUM; i++)
	{
		for (int k = 0; k < POLYNUM; k++)
		{
			//頂点の座標を設定する

			v[0].Pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			v[1].Pos = D3DXVECTOR3(POLYSIZE, 0.0f, 0.0f);
			v[2].Pos = D3DXVECTOR3(POLYSIZE, POLYSIZE, 0.0f);
			v[3].Pos = D3DXVECTOR3(0.0f, POLYSIZE, 0.0f);

			v[0].Tex = D3DXVECTOR2(0, 0);
			v[1].Tex = D3DXVECTOR2(1, 0);
			v[2].Tex = D3DXVECTOR2(1, 1);
			v[3].Tex = D3DXVECTOR2(0, 1);

			//真ん中のポリゴンを中心にするため辺の長さの半分ずらしている
			D3DXMatrixTranslation(&GroundMat, i * POLYSIZE - (POLYNUM * POLYSIZE) / 2, k * POLYSIZE - 1.6f, -(POLYNUM * POLYSIZE) / 2.0f);
			lpD3DDevice->SetTransform(D3DTS_WORLD, &GroundMat);
			lpD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, v, sizeof(VERTEX));

		}
	}
}