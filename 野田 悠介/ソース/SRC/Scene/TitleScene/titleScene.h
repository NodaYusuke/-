#pragma once
#include"../SceneBace/sceneBase.h"
#include"../../Sound/BGM/BGM_Title/BGM_title.h"
//タイトル//sceneBaseの子クラス
class C_Title:public C_SceneBase
{
public:
	C_Title();
	~C_Title();
	bool Update();
	void Render2D();
private:
	LPDIRECT3DTEXTURE9 titleTex;
	D3DXMATRIX titleMat;

	LPDIRECT3DTEXTURE9 titleBackTex;
	D3DXMATRIX titleBackMat;

	LPDIRECT3DTEXTURE9 titleTextTex;
	D3DXMATRIX titleTextMat;

	int titleTextAlpha;
	bool textAlphaSwitchFlg;
	int textAlphaSwitchCnt;

	//	C_SoundBase *bgm;
	C_BGM_Title* bgm;

	bool EscKeyFlg;/*連射防止*/

};