#include "sceneBase.h"

C_SceneBase::~C_SceneBase()
{
	EscKeyFlg = true;
}

bool C_SceneBase::Update(void)
{
	return false;
}

void C_SceneBase::Render3D(void)
{
}

void C_SceneBase::Render2D(void)
{
}

void C_SceneBase::SetCamera(void)
{

}

void C_SceneBase::Frame(void)
{
	if (Update() == false)
	{
		return;
	}
	lpD3DDevice->BeginScene();
	lpD3DDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0);
	SetCamera();
	Render3D();
	Render2D();
	lpD3DDevice->EndScene();
	lpD3DDevice->Present(NULL, NULL, NULL, NULL);
}

bool C_SceneBase::EscTitle(void)
{
	if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
	{
		if (EscKeyFlg == false)
		{
			EscKeyFlg = true;
			return true;
		}
	}
	else
	{
		EscKeyFlg = false;
	}
	return  false;
}
