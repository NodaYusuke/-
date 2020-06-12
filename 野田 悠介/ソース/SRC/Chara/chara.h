#pragma once
#include"../function.h"
#include"../extern.h"
#include"../numDecision.h"
#include"../Mouse/mouse.h"
#include"../State/state.h"
#include"../State/Fall/fall.h"
//#include"../HitEffect/hirEffect.h"

//キャラクターの基底クラス
//Update関数はプレイヤーの行動をきめる関数
/*戻り値は当たり判定に必要な構造体*/
//Render3D関数はプレイヤーを表示する関数
/*引数としてdamageFlgを持っていくことで攻撃を受けたとき色が変わる*/
/*false:通常 true:赤く点灯*/
//GetterCharaMat関数は呼び出したクラスのキャラクターの行列を返す
//CharaNowState関数は当たり判定に必要な情報を返す

class C_Chara
{
public:
	C_Chara();
	~C_Chara();
	virtual HitElement Update(charaElement charaElement);
	virtual HitElement Update(charaElement charaElement, const StateStack* playerStack, States *player);
    void Render3D(bool DamageFlg);
	virtual bool Render2D(bool DamageFlg);
	virtual void TestRender2D();
	D3DXMATRIX GetterCharaMat();
	HitElement CharaNowState();
	void SetHp(float* Hp, bool &HpDamageSetFlg, const bool& DamegeFlg,D3DXMATRIX *hpMat, int Position);
	void SetHp(float* Hp, bool &HpDamageSetFlg, const bool& DamegeFlg, int Position);
	bool SurvivalChara(const float* Hp);
	bool MakeHitEffect(const float frame, const int motionNum, const D3DXMATRIX* katanaMat, const D3DXVECTOR3* camPos);
	void MakeAttackEffect();
	void CharaInit();
	void MakeCharaMatrix();
	virtual const StateStack* ReturnStack() { return nullptr; }
	//体力を返す
	virtual float HPGetter() { float tmpNum = 0; return tmpNum; }
	//スタミナを返す
	virtual float STGetter() { float tmpNum = 0; return tmpNum; }
protected:
	//表示用の変数-----------------------------------
	Color red{ 255,0,0 };
	//刀の変数
	D3DXMATRIX katanaRotMat;  //刀の回転行列
	D3DXMATRIX katanaTransMat;//刀の移動行列
	D3DXMATRIX katanaMat;     //刀の回転行列
	D3DXMATRIX katanaElementMat;//移動と回転の合成行列
	XFILE katanaMesh;         //刀のメッシュデータ
	//頭の変数r
	D3DXMATRIX headMat;       //頭の行列
	D3DXMATRIX headTransMat;  //頭の移動行列
	XFILE headMesh;           //頭のメッシュデータ
	//体の変数
	D3DXMATRIX charaMat;       //体の行列
	D3DXMATRIX charaTransMat;  //体の行列
	D3DXMATRIX charaRotMat;    //体の行列
	XFILE bodyMesh;           //体のメッシュデータ
	//足の変数
	D3DXMATRIX leftLegMat;     //左足の行列
	D3DXMATRIX leftLegTransMat;//左足の移動行列
	D3DXMATRIX rightLegMat;     //右足の行列
	D3DXMATRIX rightLegTransMat;//右足の移動行列
	XFILE legMesh;              //足のメッシュデータ
	//腕の変数
	D3DXMATRIX leftArmRotMat;   //左腕の回転行列
	D3DXMATRIX leftArmTransMat; //左腕の移動行列
	D3DXMATRIX leftArmMat;      //左腕の行列
	D3DXMATRIX rightArmRotMat;  //右腕の回転行列
	D3DXMATRIX rightArmTransMat;//右腕の移動行列
	D3DXMATRIX rightArmMat;     //右腕の行列
	XFILE armMesh;              //腕のメッシュデータ
	//エフェクト用の変数--------------------------
	bool               effectStartFlg;/*エフェクトの初期化を行ったかどうか*/
	VERTEX             v[4];
	D3DXMATRIX         effectMat[EFFECTNUM];/*エフェクト用の行列*/
	LPDIRECT3DTEXTURE9 effectTex;
	//行動用の変数---------------------------------
	C_State* NowState; //今搭載している行動
	C_State* NextState;//これから搭載するいる行動
	C_Mouse mouse;     //マウスの位置を返すクラス
	int  NowPoint;     //現在のマウスの位置
	
	
	HitElement    returnElement;//戻り値用の変数
	bool attaclTapFlg;//長押しで連続行動を防止するよう
	//HP用
	LPDIRECT3DTEXTURE9 hpTex;
	D3DXMATRIX hpMat;
	float Hp;/*キャラクターごとの体力*/
	bool HpDamageSetFlg;

	//ST用
	LPDIRECT3DTEXTURE9 stTex;
	D3DXMATRIX stMat;
	float St;/*キャラクターごとのスタミナ*/

	//ST用
	LPDIRECT3DTEXTURE9 st_NotStateTex;

	//COVER用
	LPDIRECT3DTEXTURE9 coverTex;
	D3DXMATRIX coverMat;

	/*C_HitEffect* eff;*/

	bool effActivateFlg;
	bool endActionSetFlg;

	int duelPosition;

	int nowMove;
};