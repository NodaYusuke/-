#pragma once
#include"../SceneBace/sceneBase.h"
#include"../../Sound/BGM/BGM_WinResult/BGM_winResult.h"

//勝利のリザルト//sceneBaseの子クラス

class C_WinResult :public C_SceneBase
{
public:
	C_WinResult();
	~C_WinResult();
	bool Update();
	void Render2D();
private:
	LPDIRECT3DTEXTURE9 winBattleEndTex[3];
	D3DXMATRIX winBattleEndTexMat[3];

	LPDIRECT3DTEXTURE9 blueWindmillTex;
	D3DXMATRIX blueWindmillMat;

	LPDIRECT3DTEXTURE9 yellowWindmillTex;
	D3DXMATRIX yellowWindmillMat;

	LPDIRECT3DTEXTURE9 stageSelectTextTex;
	D3DXMATRIX stageSelectTextMat;

	LPDIRECT3DTEXTURE9 nextStageTextTex;
	D3DXMATRIX nextStageTextMat;

	LPDIRECT3DTEXTURE9 cursorTex;
	D3DXMATRIX cursorMat;

	bool  lClickFlg;
	float ScalCnt;
	C_BGM_WinResult* bgm;
};