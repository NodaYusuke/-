#pragma once
#include"include.h"
struct VERTEX
{
	D3DXVECTOR3 Pos;

	D3DCOLOR Color;

	D3DXVECTOR2 Tex;
};

struct XFILE
{
	LPD3DXMESH lpMesh;	//メッシュの形状のデータ

	DWORD NumMaterial;	//グループの個数

	D3DMATERIAL9 *Mat;	//マテリアルの内容　＊　グループ数

	LPDIRECT3DTEXTURE9 *Tex;	//テクスチャの内容　＊　グループ数
};

struct Color
{
	float r;
	float g;
	float b;
};
struct MakeMotionElement
{
	float angX;
	float angY;
	float angZ;
	D3DXVECTOR3 WeaponPos;
};

struct States
{
	const float* ST;
	const float* HP;
};

//キャラクターの行動によって増加するstackを
//まとめる構造体
struct StateStack
{
	int topStack;   //上段のstack//切り替え、時間経過で増加
	int normalStack;//中段のstack//切り替え、時間経過で増加
	int underStack; //下段のstack//切り替え、時間経過で増加
	int attackStack;//攻撃のstack//攻撃回数で増加
	int guardStack; //防御のstack//防御回数で増加
	int stepStack;  //回避のstack//回避回数で増加
};

//当たり判定の構造体
struct HitElement
{
	float animeFrame;//アニメの進行度
	int   NowState;  //攻撃しているかどうか
	int   nowMotion;
	int   Position;  //どこの行動か
};

struct HitAttackElement
{
	const HitElement &myElement;
	const HitElement &duelElement;
	int* damageCnt;
	bool AttackHitFlg;
};
//chara作成時に受け渡す構造体
struct charaElement
{
	const D3DXMATRIX *duelMat;
	const HitElement *duelElement;
	bool AttackHitFlg;
	const float* Len;
	float* ToAng;//相手までの回転角度
	bool* duelDamageFlg;
	D3DXVECTOR3 *camPos;          /*カメラの座標*/
};
//StateクラスのAction関数の引数
struct EnemyActionElement
{
	D3DXMATRIX* katanaElementMat;/*刀の行列*/
	D3DXMATRIX* katanaTransMat;  /*刀の移動行列*/
	D3DXMATRIX* katanaRotMat;    /*刀の回転行列*/
	D3DXMATRIX* charaMat;        /*キャラの行列*/
	D3DXMATRIX* RotMat;          /*キャラの回転行列*/
	D3DXMATRIX* TransMat;        /*キャラの移動行列*/
	D3DXMATRIX* stMat;           /*スタミナ表示用の行列*/
	float* St;                   /*スタミナ*/
	charaElement* enemyElement;  /*キャラ作成時に渡す変数*/
	int* nowMove;                /*現在の移動方向*/
	const StateStack* playerStack;/*playerのStack*/
	int* NowPosition;
	int* MoveWay;/*動く方向*/
	States* playerStates;
	States* enemyStates;
};

struct PlayerActionElement
{
	D3DXMATRIX* katanaElementMat;/*刀の行列*/
	D3DXMATRIX* katanaTransMat;  /*刀の移動行列*/
	D3DXMATRIX* katanaRotMat;    /*刀の回転行列*/
	D3DXMATRIX* charaMat;        /*キャラの行列*/
	D3DXMATRIX* RotMat;          /*キャラの回転行列*/
	D3DXMATRIX* TransMat;        /*キャラの移動行列*/
	D3DXMATRIX* stMat;           /*スタミナ表示用の行列*/
	float* St;                   /*スタミナ*/
	bool* attackTapFlg;	         /*攻撃ボタンを押しているかどうかのフラグ*/
	StateStack* playerStack;     /*プレイヤーのstack*/
	charaElement *playerElement; /*キャラ作成時に渡す変数*/
	int* nowMove;                /*現在の移動方向*/
	int* NowPoint;               /*マウスの位置*/
};

