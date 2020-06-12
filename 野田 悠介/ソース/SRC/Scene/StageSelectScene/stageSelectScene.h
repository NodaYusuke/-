#pragma once
#include"../SceneBace/sceneBase.h"
#include"../../Mouse/mouse.h"
#include"../../Sound/BGM/BGM_StageSelect/BGM_stageSelect.h"

//�^�C�g��//sceneBase�̎q�N���X
class C_StageSelect :public C_SceneBase
{
public:
	C_StageSelect();
	~C_StageSelect();
	bool Update();
	void Render2D();
private:
	LPDIRECT3DTEXTURE9 backTex;/*�w�i�摜*/
	D3DXMATRIX backMat;        /*�w�i�s��*/

	LPDIRECT3DTEXTURE9 StageSelectTex;/*��Փx�I���摜*/
	D3DXMATRIX StageSelectMat;        /*��Փx�I���s��*/

	LPDIRECT3DTEXTURE9 easyBackTex;/*�ȒP�̔w�i�摜*/
	D3DXMATRIX easyBackMat;/*�ȒP�̔w�i�s��*/
	LPDIRECT3DTEXTURE9 easyTex;/*�ȒP�̉摜*/
	D3DXMATRIX easyTexMat;/*�ȒP�̃e�L�X�g�s��*/

	LPDIRECT3DTEXTURE9 normalBackTex;/*���ʂ̔w�i�摜*/
	D3DXMATRIX normalBackMat;/*���ʂ̔w�i�s��*/
	LPDIRECT3DTEXTURE9 normalTex;/*���ʂ̉摜*/
	D3DXMATRIX normalTexMat;/*���ʂ̃e�L�X�g�s��*/

	LPDIRECT3DTEXTURE9 difficultBackTex;/*����̔w�i�摜*/
	D3DXMATRIX difficultBackMat;/*����̔w�i�s��*/
	LPDIRECT3DTEXTURE9 difficultTex;/*����̉摜*/
	D3DXMATRIX difficultTexMat;/*����̃e�L�X�g�s��*/

	LPDIRECT3DTEXTURE9 cursorTex;
	D3DXMATRIX cursorMat;

	float ScalCnt;

	bool  lClickFlg;

	C_BGM_StageSelect* bgm;
};