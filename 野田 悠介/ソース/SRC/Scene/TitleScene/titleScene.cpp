#include"titleScene.h"
#include"../StageSelectScene/stageSelectScene.h"
#include"../SceneManeger/sceneManeger.h"

#include"../../Sound/SoundBase/soundBase.h"
#include"../../Sound/BGM/BGM_Title/BGM_title.h"

extern C_SceneManeger sceneManeger;

enum { BGM = 0 };
C_Title::C_Title()
{
	EscKeyFlg = true;

	titleTextAlpha = 255;
	textAlphaSwitchFlg = false;
	textAlphaSwitchCnt = TEXTALPHASWICHCNT;
	 
	LoadTexture(&titleTex, "DATA/Texture/title2.png", 1280, 720, NULL);
	D3DXMatrixIdentity(&titleMat);

	LoadTexture(&titleTextTex, "DATA/Texture/titleText.png", 400, 100, NULL);
	
	LoadTexture(&titleBackTex, "DATA/Texture/titleBackTex.jpg", 1280, 720, NULL);
	D3DXMatrixIdentity(&titleBackMat);

	D3DXMatrixTranslation(&titleTextMat, (SCRW-400.0f)/2.0f, 500, 0);

	bgm = new C_BGM_Title();
	//BGMのスイッチを入れる
	bgm->PlaySwitch(true);
}
C_Title::~C_Title()
{
	SafeRelease(titleTex);
	SafeRelease(titleTextTex);
	//BGMのスイッチを切る
	bgm->PlaySwitch(false);

	delete bgm;

}
bool C_Title::Update()
{
	if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
	{
		if (EscKeyFlg == false)
		{
			/*if ((MessageBox(NULL, "終了しますか？", "起動確認", MB_YESNO | MB_DEFBUTTON2 | MB_ICONQUESTION) == IDYES))
			{*/
				PostQuitMessage(0);
				EscKeyFlg = true;
				return false;
			/*}*/
		}
	}
	else
	{
		EscKeyFlg = false;
	}

	bool KeyFlg = false;
	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
	{
		if (KeyFlg == false)
		{
			sceneManeger.ChangScene(new C_StageSelect());
			KeyFlg = true;
			return false;
		}
	}
	else
	{
		KeyFlg = false;
	}
	return true;
}
void C_Title::Render2D()
{
	lpSprite->Begin(D3DXSPRITE_ALPHABLEND);

	RECT rcTitleBack = { 0,0,SCRW,SCRH };
	lpSprite->SetTransform(&titleBackMat);
	lpSprite->Draw(titleBackTex, &rcTitleBack, &D3DXVECTOR3(0, 0, 0), NULL, D3DCOLOR_ARGB(255, 255, 255, 255));

	RECT rcTitle = { 0,0,SCRW,SCRH };
	lpSprite->SetTransform(&titleMat);
	lpSprite->Draw(titleTex, &rcTitle, &D3DXVECTOR3(0, 0, 0), NULL, D3DCOLOR_ARGB(255, 255, 255, 255));

	if (textAlphaSwitchCnt > 0)
	{
		textAlphaSwitchCnt--;
	}
	if (textAlphaSwitchFlg == false)
	{
		titleTextAlpha = 255;
		if (textAlphaSwitchCnt <= 0)
		{
			textAlphaSwitchFlg = true;
			textAlphaSwitchCnt = TEXTALPHASWICHCNT;
		}
	}
	if (textAlphaSwitchFlg == true)
	{
		titleTextAlpha = 100;
		if (textAlphaSwitchCnt <= 0)
		{
			textAlphaSwitchFlg = false;
			textAlphaSwitchCnt = TEXTALPHASWICHCNT;
		}
	}

	RECT rcTitleText = { 0,0,400,100 };
	lpSprite->SetTransform(&titleTextMat);
	lpSprite->Draw(titleTextTex, &rcTitleText, &D3DXVECTOR3(0, 0, 0), NULL, D3DCOLOR_ARGB(titleTextAlpha, 255, 255, 255));

	lpSprite->End();
}
