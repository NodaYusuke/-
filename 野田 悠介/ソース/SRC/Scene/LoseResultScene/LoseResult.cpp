#include"LoseResult.h"
#include"../StageSelectScene/stageSelectScene.h"
#include"../SceneManeger/sceneManeger.h"
#include"../StageSelectScene/stageSelectScene.h"
#include"../TitleScene/titleScene.h"
#include"../GameScene/gameScene.h"

extern C_SceneManeger sceneManeger;

C_LoseResult::C_LoseResult()
{
	purpleKeyFlg = false;
	blueKeyFlg = false;
	blueClickFlg = false;
	purpleClickFlg = false;
	blueScalCnt = 1.0f;
	purpleScalCnt = 1.0f;
	LoadTexture(&loseBattleEndTex[0], "DATA/Texture/loseBattleEndTex1.png", 400, 400, NULL);
	LoadTexture(&loseBattleEndTex[1], "DATA/Texture/loseBattleEndTex2.png", 400, 400, NULL);
	LoadTexture(&loseBattleEndTex[2], "DATA/Texture/loseResult.jpg", 1300, 720, NULL);
	D3DXMatrixTranslation(&loseBattleEndTexMat[0], 100, 110, 0);
	D3DXMatrixTranslation(&loseBattleEndTexMat[1], 680, 110, 0);
	D3DXMatrixIdentity(&loseBattleEndTexMat[2]);

	LoadTexture(&cursorTex, "DATA/Texture/momizi2.png", 80, 80, NULL);
	D3DXMatrixIdentity(&cursorMat);

	LoadTexture(&blueWindmillTex, "DATA/Texture/blueWindmill.png", 300, 300, NULL);
	D3DXMatrixTranslation(&blueWindmillMat, 930, 570, 0);

	LoadTexture(&stageSelectTextTex, "DATA/Texture/stageSelectText.png", 300, 100, NULL);
	D3DXMatrixTranslation(&stageSelectTextMat, 780, 320, 0);

	LoadTexture(&purpleWindmillTex, "DATA/Texture/purpleWindmill.png", 300, 300, NULL);
	D3DXMatrixTranslation(&purpleWindmillMat, 350, 570, 0);

	LoadTexture(&retryTextTex, "DATA/Texture/Retry.png", 300, 100, NULL);
	D3DXMatrixTranslation(&retryTextMat, 200, 320, 0);

	bgm = new C_BGM_LoseResult();
	bgm->PlaySwitch(true);
}

C_LoseResult::~C_LoseResult()
{
	SafeRelease(loseBattleEndTex[0]);
	SafeRelease(loseBattleEndTex[1]);
	SafeRelease(loseBattleEndTex[2]);
	SafeRelease(blueWindmillTex);
	SafeRelease(purpleWindmillTex);
	SafeRelease(stageSelectTextTex);
	SafeRelease(retryTextTex);
	bgm->PlaySwitch(false);
	delete bgm;
}

bool C_LoseResult::Update()
{

	if (EscTitle() == true)
	{
		sceneManeger.ChangScene(new C_Title());
		return false;
	}

	if (loseBattleEndTexMat[0]._42 >= -30)
	{
		loseBattleEndTexMat[0]._42 -= 2.0f;
		loseBattleEndTexMat[1]._42 -= 2.0f;
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
			purpleWindmillMat = TmpRot * purpleWindmillMat;

			if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
			{
				if (purpleKeyFlg == false)
				{
					purpleClickFlg = true;
					purpleKeyFlg = true;
				}

			}
			else
			{
				purpleKeyFlg = false;
			}
		}
		if (purpleClickFlg == true)
		{
			purpleScalCnt += 0.1f;
			D3DXMATRIX TmpRot;
			D3DXMatrixRotationZ(&TmpRot, D3DXToRadian(-5));
			D3DXMATRIX TmpScal;
			D3DXMatrixScaling(&TmpScal, purpleScalCnt, purpleScalCnt, 0);
			purpleWindmillMat = TmpScal * TmpRot * purpleWindmillMat;
		}
		if (purpleScalCnt >= 3)
		{
			sceneManeger.ChangScene(new C_Game());
			return false;
		}

		if (Pt.x >= 930 && Pt.x <= 1230 && Pt.y >= 420 && Pt.y <= 720)
		{
			D3DXMATRIX TmpRot;
			D3DXMatrixRotationZ(&TmpRot, D3DXToRadian(-5));
			blueWindmillMat = TmpRot * blueWindmillMat;

			

			if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
			{
				if (blueKeyFlg == false)
				{
					blueClickFlg = true;
					blueKeyFlg = true;
				}

			}
			else
			{
				blueKeyFlg = false;
			}
		}
		if (blueClickFlg == true)
		{
			blueScalCnt += 0.1f;
			D3DXMATRIX TmpRot;
			D3DXMatrixRotationZ(&TmpRot, D3DXToRadian(-5));
			D3DXMATRIX TmpScal;
			D3DXMatrixScaling(&TmpScal, blueScalCnt, blueScalCnt, 0);
			blueWindmillMat = TmpScal * TmpRot * blueWindmillMat;
		}
		if (blueScalCnt >= 3)
		{
			sceneManeger.ChangScene(new C_StageSelect());
			return false;
		}
		
	}
	
	return true;
}

void C_LoseResult::Render2D()
{
	//////////////////////////////////////////////////
	///	スプライトの描画処理//////////////////////////
	//////////////////////////////////////////////////
	// 描画開始
	lpSprite->Begin(D3DXSPRITE_ALPHABLEND);

	RECT rcloseBattleTex3 = { 0,0,1300,720 };
	lpSprite->SetTransform(&loseBattleEndTexMat[2]);
	lpSprite->Draw(loseBattleEndTex[2], &rcloseBattleTex3, &D3DXVECTOR3(0, 0, 0), NULL, D3DCOLOR_ARGB(255, 255, 255, 255));

	RECT rcloseBattleTex1 = { 0,0,500,500 };
	lpSprite->SetTransform(&loseBattleEndTexMat[0]);
	lpSprite->Draw(loseBattleEndTex[0], &rcloseBattleTex1, &D3DXVECTOR3(0, 0, 0), NULL, D3DCOLOR_ARGB(255, 255, 255, 255));

	RECT rcloseBattleTex2 = { 0,0,500,500 };
	lpSprite->SetTransform(&loseBattleEndTexMat[1]);
	lpSprite->Draw(loseBattleEndTex[1], &rcloseBattleTex2, &D3DXVECTOR3(0, 0, 0), NULL, D3DCOLOR_ARGB(255, 255, 255, 255));

	if (loseBattleEndTexMat[0]._42 < -30)
	{
		RECT rcStageSelectText = { 0,0,300,100 };
		lpSprite->SetTransform(&stageSelectTextMat);
		lpSprite->Draw(stageSelectTextTex, &rcStageSelectText, &D3DXVECTOR3(0, 0, 0), NULL, D3DCOLOR_ARGB(255, 255, 255, 255));

		RECT rcRetryText = { 0,0,300,100 };
		lpSprite->SetTransform(&retryTextMat);
		lpSprite->Draw(retryTextTex, &rcRetryText, &D3DXVECTOR3(0, 0, 0), NULL, D3DCOLOR_ARGB(255, 255, 255, 255));


		RECT rcBlueWindmill = { 0,0,300,300 };
		lpSprite->SetTransform(&blueWindmillMat);
		lpSprite->Draw(blueWindmillTex, &rcBlueWindmill, &D3DXVECTOR3(150, 150, 0), NULL, D3DCOLOR_ARGB(255, 255, 255, 255));

		RECT rcPurpleWindmill = { 0,0,300,300 };
		lpSprite->SetTransform(&purpleWindmillMat);
		lpSprite->Draw(purpleWindmillTex, &rcPurpleWindmill, &D3DXVECTOR3(150, 150, 0), NULL, D3DCOLOR_ARGB(255, 255, 255, 255));

		RECT rccursorTex = { 0,0,80,80 };
		lpSprite->SetTransform(&cursorMat);
		lpSprite->Draw(cursorTex, &rccursorTex, &D3DXVECTOR3(100, 100, 0), NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
	
	}
	// 描画終了
	lpSprite->End();
}
