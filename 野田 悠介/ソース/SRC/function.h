#pragma once
#include"struct.h"
//ä÷êîêÈåæ//
template<class T>
inline void SafeRelease(T& lpAdd)
{
	if (lpAdd != nullptr)
	{
		lpAdd->Release();
		lpAdd = nullptr;
	}
}

void DrawMesh(XFILE *XFile);
void DrawMesh(XFILE* XFile, Color rgb);
void LoadMesh(struct XFILE* XFile, const char FName[]);
void ReleaseMesh(struct XFILE *XFile);
void LoadTexture(LPDIRECT3DTEXTURE9 *lpTex, const char fname[], int W, int H, D3DCOLOR Color);
float TurnToAng(D3DXMATRIX* Mat, float TargetAng, float PlusAng);
float GetVecAng(D3DXVECTOR3 Vec);
void LoadWAVE3D(LPDIRECTSOUNDBUFFER8& pDSData, LPDIRECTSOUND3DBUFFER8& pDSData3D, const char* fname);