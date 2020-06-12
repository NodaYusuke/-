#include "WinResultScene.h"
#include"../StageSelectScene/stageSelectScene.h"
#include"../SceneManeger/sceneManeger.h"
#include"../StageSelectScene/stageSelectScene.h"
#include"../TitleScene/titleScene.h"


extern C_SceneManeger sceneManeger;

C_WinResult::C_WinResult()
{
	lClickFlg = false;
	ScalCnt = 1.0f;

	LoadTexture(&winBattleEndTex[0], "DATA/Texture/winBattleEndTex1.png", 400, 400, NULL);
	LoadTexture(&winBattleEndTex[1], "DATA/Texture/winBattleEndTex2.png", 400, 400, NULL);
	LoadTexture(&winBattleEndTex[2], "DATA/Texture/titleBackTex2.jpg", 1300, 720, NULL);
	D3DXMatrixTranslation(&winBattleEndTexMat[0], 100, 110, 0);
	D3DXMatrixTranslation(&winBattleEndTexMat[1], 680, 110, 0);
	D3DXMatrixIdentity(&winBattleEndTexMat[2]);

	LoadTexture(&blueWindmillTex, "DATA/Texture/blueWindmill.png", 300, 300, NULL);
	D3DXMatrixTranslation(&blueWindmillMat, 350, 570, 0);

	LoadTexture(&yellowWindmillTex, "DATA/Texture/yellowWindmill.png", 300, 300, NULL);
	D3DXMatrixTranslation(&yellowWindmillMat, 930, 570, 0);
	
	LoadTexture(&stageSelectTextTex, "DATA/Texture/stageSelectText.png", 300, 100, NULL);
	D3DXMatrixTranslation(&stageSelectTextMat, 200, 320, 0);

	LoadTexture(&nextStageTextTex, "DATA/Texture/nextStageText.png", 300, 100, NULL);
	D3DXMatrixTranslation(&nextStageTextMat, 780, 320, 0);
	
	LoadTexture(&cursorTex, "DATA/Texture/momizi2.png", 80, 80, NULL);
	D3DXMatrixIdentity(&cursorMat);

	bgm = new C_BGM_WinResult();
	bgm->PlaySwitch(true);
}

C_WinResult::~C_WinResult()
{
	SafeRelease(winBattleEndTex[0]);
	SafeRelease(winBattleEndTex[1]);
	SafeRelease(winBattleEndTex[2]);
	SafeRelease(blueWindmillTex);
	SafeRelease(yellowWindmillTex);
	SafeRelease(stageSelectTextTex);
	SafeRelease(nextStageTextTex);
	bgm->PlaySwitch(false);
}

bool C_WinResult::Update()
{
	if (EscTitle() == true)
	{
		sceneManeger.ChangScene(new C_Title());
		return false;
	}

	if (winBattleEndTexMat[0]._42 >= -30)
	{
		winBattleEndTexMat[0]._42 -= 2.0f;
		winBattleEndTexMat[1]._42 -= 2.0f;
	}
	else
	{
		POINT Pt;
		GetCursorPos(&Pt);
		D3DXMatrixTranslation(&cursorMat, Pt.x, Pt.y, 0);
		if (Pt.x >= 200 && Pt.x <= 500 && Pt.y >= 420 && Pt.y <= 720)
		{
			D3DXMATRIX TmpRot;
			D3DXMatrixRotationZ(&TmpRot, D3DXToRadian(-5));
			blueWindmillMat = TmpRot * blueWindmillMat;

			bool KeyFlg = false;/*˜AŽË–hŽ~*/

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
			D3DXMatrixScaling(&TmpScal, ScalCnt, ScalCnt, 0);
			blueWindmillMat = TmpScal * TmpRot * blueWindmillMat;
		}
		if (ScalCnt >= 3)
		{
			sceneManeger.ChangScene(new C_StageSelect());
			return false;
		}
	}
	return true;
}

void C_WinResult::Render2D()
{
	//////////////////////////////////////////////////
	///	ƒXƒvƒ‰ƒCƒg‚Ì•`‰æˆ—//////////////////////////
	//////////////////////////////////////////////////
	// •`‰æŠJŽn
	lpSprite->Begin(D3DXSPRITE_ALPHABLEND);

	RECT rcWinBattleTex3 = { 0,0,1300,720 };
	lpSprite->SetTransform(&winBattleEndTexMat[2]);
	lpSprite->Draw(winBattleEndTex[2], &rcWinBattleTex3, &D3DXVECTOR3(0, 0, 0), NULL, D3DCOLOR_ARGB(255, 255, 255, 255));

	RECT rcWinBattleTex1 = { 0,0,500,500 };
	lpSprite->SetTransform(&winBattleEndTexMat[0]);
	lpSprite->Draw(winBattleEndTex[0], &rcWinBattleTex1, &D3DXVECTOR3(0, 0, 0), NULL, D3DCOLOR_ARGB(255, 255, 255, 255));

	RECT rcWinBattleTex2 = { 0,0,500,500 };
	lpSprite->SetTransform(&winBattleEndTexMat[1]);
	lpSprite->Draw(winBattleEndTex[1], &rcWinBattleTex2, &D3DXVECTOR3(0, 0, 0), NULL, D3DCOLOR_ARGB(255, 255, 255, 255));


	if (winBattleEndTexMat[0]._42 < -30)
	{
		RECT rcNextStageText = { 0,0,300,100 };
		lpSprite->SetTransform(&nextStageTextMat);
		lpSprite->Draw(nextStageTextTex, &rcNextStageText, &D3DXVECTOR3(0, 0, 0), NULL, D3DCOLOR_ARGB(255, 255, 255, 255));

		RECT rcYellowWindmill = { 0,0,300,300 };
		lpSprite->SetTransform(&yellowWindmillMat);
		lpSprite->Draw(yellowWindmillTex, &rcYellowWindmill, &D3DXVECTOR3(150, 150, 0), NULL, D3DCOLOR_ARGB(100, 100, 100, 100));

		RECT rcStageSelectText = { 0,0,300,100 };
		lpSprite->SetTransform(&stageSelectTextMat);
		lpSprite->Draw(stageSelectTextTex, &rcStageSelectText, &D3DXVECTOR3(0, 0, 0), NULL, D3DCOLOR_ARGB(255, 255, 255, 255));

		RECT rcBlueWindmill = { 0,0,300,300 };
		lpSprite->SetTransform(&blueWindmillMat);
		lpSprite->Draw(blueWindmillTex, &rcBlueWindmill, &D3DXVECTOR3(150, 150, 0), NULL, D3DCOLOR_ARGB(255, 255, 255, 255));

		RECT rccursorTex = { 0,0,80,80 };
		lpSprite->SetTransform(&cursorMat);
		lpSprite->Draw(cursorTex, &rccursorTex, &D3DXVECTOR3(100, 100, 0), NULL, D3DCOLOR_ARGB(255, 255, 255, 255));

	}
	// •`‰æI—¹
	lpSprite->End();
}
