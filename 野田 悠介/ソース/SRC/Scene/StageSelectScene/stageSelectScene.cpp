#include "stageSelectScene.h"
#include"../GameScene/gameScene.h"
#include"../SceneManeger/sceneManeger.h"
#include"../TitleScene/titleScene.h"
extern C_SceneManeger sceneManeger;

C_StageSelect::C_StageSelect()
{
	ScalCnt = 1.0f;
	lClickFlg = false;
	LoadTexture(&backTex, "DATA/Texture/stageSelectbackTex.jpg", 1280, 720, NULL);
	D3DXMatrixIdentity(&backMat);

	LoadTexture(&StageSelectTex, "DATA/Texture/stageSelectText.png", 300, 100, NULL);
	D3DXMatrixTranslation(&StageSelectMat, (SCRW - 300) / 2, 100, 0);

	LoadTexture(&easyBackTex, "DATA/Texture/greenWindmill.png", 300, 300, NULL);
	D3DXMatrixTranslation(&easyBackMat, 250, 450, 0);
	LoadTexture(&easyTex, "DATA/Texture/easyTex.png", 300, 100, NULL);
	D3DXMatrixTranslation(&easyTexMat, 100, 200, 0);

	LoadTexture(&normalBackTex, "DATA/Texture/yellowWindmill.png", 300, 300, NULL);
	D3DXMatrixTranslation(&normalBackMat, 500, 300, 0);
	LoadTexture(&normalTex, "DATA/Texture/normalTex.png", 300, 100, NULL);
	D3DXMatrixTranslation(&normalTexMat, 500, 200, 0);

	LoadTexture(&difficultBackTex, "DATA/Texture/redWindmill.png", 300, 300, NULL);
	D3DXMatrixTranslation(&difficultBackMat, 900, 300, 0);
	LoadTexture(&difficultTex, "DATA/Texture/difficultTex.png", 300, 100, NULL);
	D3DXMatrixTranslation(&difficultTexMat, 900, 200, 0);

	LoadTexture(&cursorTex, "DATA/Texture/momizi2.png", 80, 80, NULL);
	D3DXMatrixIdentity(&cursorMat);

	bgm = new C_BGM_StageSelect();
	bgm->PlaySwitch(true);
}

C_StageSelect::~C_StageSelect()
{
	SafeRelease(backTex);
	SafeRelease(easyBackTex);
	SafeRelease(easyTex);
	SafeRelease(normalBackTex);
	SafeRelease(normalTex);
	SafeRelease(difficultBackTex);
	SafeRelease(difficultTex);
	bgm->PlaySwitch(false);
	delete bgm;
}

bool C_StageSelect::Update()
{
	if (EscTitle() == true)
	{
		sceneManeger.ChangScene(new C_Title());
		return false;
	}

	POINT Pt;
	GetCursorPos(&Pt);

	D3DXMatrixTranslation(&cursorMat, Pt.x, Pt.y, 0);

	if (Pt.x >= 100 && Pt.x <= 400 && Pt.y >= 300 && Pt.y <= 600
		&&lClickFlg==false)
	{
		D3DXMATRIX TmpRot;
		D3DXMatrixRotationZ(&TmpRot, D3DXToRadian(-5));

		easyBackMat = TmpRot * easyBackMat;

		static bool KeyFlg = true;/*連射防止*/

		if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
		{
			if (KeyFlg == false)
			{
				lClickFlg = true;
				KeyFlg = true;
			}
		}
		else
		{
			KeyFlg = false;
		}
	}
	if (lClickFlg == true)
	{
		ScalCnt += 0.1f;
		D3DXMATRIX TmpRot;
		D3DXMatrixRotationZ(&TmpRot, D3DXToRadian(-5));
		D3DXMATRIX TmpScal;
		D3DXMatrixScaling(&TmpScal, ScalCnt, ScalCnt,0);
		easyBackMat = TmpScal * TmpRot * easyBackMat;
	}
	if (ScalCnt >= 3)
	{
		sceneManeger.ChangScene(new C_Game());
		return false;
	}
	return true;
}

void C_StageSelect::Render2D()
{
	lpSprite->Begin(D3DXSPRITE_ALPHABLEND);

	RECT rcBackTex = { 0,0,SCRW,SCRH };
	lpSprite->SetTransform(&backMat);
	lpSprite->Draw(backTex, &rcBackTex, &D3DXVECTOR3(0, 0, 0), NULL, D3DCOLOR_ARGB(255, 255, 255, 255));

	RECT rcStageSelectTex = { 0,0,300,100 };
	lpSprite->SetTransform(&StageSelectMat);
	lpSprite->Draw(StageSelectTex, &rcStageSelectTex, &D3DXVECTOR3(0, 0, 0), NULL, D3DCOLOR_ARGB(255, 255, 255, 255));

	//新前の表示設定
	RECT rcEasyBackTex = { 0,0,300,300 };
	lpSprite->SetTransform(&easyBackMat);
	lpSprite->Draw(easyBackTex, &rcEasyBackTex, &D3DXVECTOR3(150, 150, 0), NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
	if (lClickFlg == false)
	{
		RECT rcEasyTex = { 0,0,300,100 };
		lpSprite->SetTransform(&easyTexMat);
		lpSprite->Draw(easyTex, &rcEasyTex, &D3DXVECTOR3(0, 0, 0), NULL, D3DCOLOR_ARGB(255, 255, 255, 255));

		//名人の表示設定
		RECT rcNormalBackTex = { 0,0,300,300 };
		lpSprite->SetTransform(&normalBackMat);
		lpSprite->Draw(normalBackTex, &rcNormalBackTex, &D3DXVECTOR3(0, 0, 0), NULL, D3DCOLOR_ARGB(100, 100, 100, 100));

		RECT rcNormalTex = { 0,0,300,100 };
		lpSprite->SetTransform(&normalTexMat);
		lpSprite->Draw(normalTex, &rcNormalTex, &D3DXVECTOR3(0, 0, 0), NULL, D3DCOLOR_ARGB(255, 255, 255, 255));

		//達人の表示設定
		RECT rcDifficultBackTex = { 0,0,300,300 };
		lpSprite->SetTransform(&difficultBackMat);
		lpSprite->Draw(difficultBackTex, &rcDifficultBackTex, &D3DXVECTOR3(0, 0, 0), NULL, D3DCOLOR_ARGB(100, 100, 100, 100));

		RECT rcDifficultTex = { 0,0,300,100 };
		lpSprite->SetTransform(&difficultTexMat);
		lpSprite->Draw(difficultTex, &rcDifficultTex, &D3DXVECTOR3(0, 0, 0), NULL, D3DCOLOR_ARGB(255, 255, 255, 255));

		RECT rccursorTex = { 0,0,80,80 };
		lpSprite->SetTransform(&cursorMat);
		lpSprite->Draw(cursorTex, &rccursorTex, &D3DXVECTOR3(100,100, 0), NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
	}
	lpSprite->End();
}
