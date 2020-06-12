#pragma once
#include"../SceneBace/sceneBase.h"
#include"../SceneManeger/sceneManeger.h"
#include"../../Sound/BGM/BGM_LoseRsult/BGM_loseResult.h"
//”s–k‚ÌƒŠƒUƒ‹ƒg//sceneBase‚ÌŽqƒNƒ‰ƒX

class C_LoseResult :public C_SceneBase
{
public:
	C_LoseResult();
	~C_LoseResult();
	bool Update();
	void Render2D();
protected:
	LPDIRECT3DTEXTURE9 loseBattleEndTex[3];
	D3DXMATRIX loseBattleEndTexMat[3];

	LPDIRECT3DTEXTURE9 cursorTex;
	D3DXMATRIX cursorMat;

	LPDIRECT3DTEXTURE9 blueWindmillTex;
	D3DXMATRIX blueWindmillMat;

	LPDIRECT3DTEXTURE9 stageSelectTextTex;
	D3DXMATRIX stageSelectTextMat;

	LPDIRECT3DTEXTURE9 purpleWindmillTex;
	D3DXMATRIX purpleWindmillMat;

	LPDIRECT3DTEXTURE9 retryTextTex;
	D3DXMATRIX retryTextMat;

	bool  blueClickFlg;
	bool  purpleClickFlg;
	float blueScalCnt;
	float purpleScalCnt;
	C_BGM_LoseResult* bgm;
	bool blueKeyFlg;/*˜AŽË–hŽ~*/
	bool purpleKeyFlg;/*˜AŽË–hŽ~*/
};