#pragma once
#include"../SceneBace/sceneBase.h"
#include"../../Mouse/mouse.h"
#include"../../Sound/BGM/BGM_StageSelect/BGM_stageSelect.h"

//タイトル//sceneBaseの子クラス
class C_StageSelect :public C_SceneBase
{
public:
	C_StageSelect();
	~C_StageSelect();
	bool Update();
	void Render2D();
private:
	LPDIRECT3DTEXTURE9 backTex;/*背景画像*/
	D3DXMATRIX backMat;        /*背景行列*/

	LPDIRECT3DTEXTURE9 StageSelectTex;/*難易度選択画像*/
	D3DXMATRIX StageSelectMat;        /*難易度選択行列*/

	LPDIRECT3DTEXTURE9 easyBackTex;/*簡単の背景画像*/
	D3DXMATRIX easyBackMat;/*簡単の背景行列*/
	LPDIRECT3DTEXTURE9 easyTex;/*簡単の画像*/
	D3DXMATRIX easyTexMat;/*簡単のテキスト行列*/

	LPDIRECT3DTEXTURE9 normalBackTex;/*普通の背景画像*/
	D3DXMATRIX normalBackMat;/*普通の背景行列*/
	LPDIRECT3DTEXTURE9 normalTex;/*普通の画像*/
	D3DXMATRIX normalTexMat;/*普通のテキスト行列*/

	LPDIRECT3DTEXTURE9 difficultBackTex;/*難しいの背景画像*/
	D3DXMATRIX difficultBackMat;/*難しいの背景行列*/
	LPDIRECT3DTEXTURE9 difficultTex;/*難しいの画像*/
	D3DXMATRIX difficultTexMat;/*難しいのテキスト行列*/

	LPDIRECT3DTEXTURE9 cursorTex;
	D3DXMATRIX cursorMat;

	float ScalCnt;

	bool  lClickFlg;

	C_BGM_StageSelect* bgm;
};