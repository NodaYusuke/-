#pragma once
#include"../function.h"
#include"../numDecision.h"
#include"../Anime/anime.h"
#include"../Mouse/mouse.h"
#include"../Mouse/mouse.h"
#include"../Sound/SoundBase/soundBase.h"
#include"EnemyState/EnemyStateManeger/enemyStateManeger.h"

//状態を表す基底クラス

class C_State
{
public:
	C_State();
	//キャラクターのクラスで呼び出すことで、    
	//モーションを行えるアクション関数の仮想関数
	virtual C_State* Action(EnemyActionElement *enemyActionElement);
	virtual C_State* Action(PlayerActionElement *playerActionElement);
	//戻り値として当たり判定の構造体をもつ関数
	virtual HitElement GetCharaState();

	virtual void Render2D(void);
    //////攻撃モーションを作成する関数----------
	D3DXMATRIX MakeMotionMat(MakeMotionElement makeMotionElement);
	////中段
	//待機	
	D3DXMATRIX MakeNormalStayEndMat();
	//攻撃の終わり
	D3DXMATRIX MakeNormalAttackEndMat();

	////上段
	D3DXMATRIX MakeTopStayEndMat();
	//攻撃準備
	D3DXMATRIX MakeTopAttackPraparationMat();
	//攻撃途中
	D3DXMATRIX MakeTopAttackHalfwayMat();
	//攻撃の終わり
	D3DXMATRIX MakeTopAttackEndMat();
	//攻撃がはじかれた時の終わり
	D3DXMATRIX MakeT_PreventsAttackEndMat();

	////下段
	//待機
	D3DXMATRIX MakeUnderStayEndMat();
	//攻撃準備
	D3DXMATRIX MakeUnderAttackPraparationMat();
	//攻撃途中
	D3DXMATRIX MakeUnderAttackHalfwayMat();
	//攻撃の終わり
	D3DXMATRIX MakeUnderAttackEndMat();
	
	////stack関連の上下関数
	void PositionStackUpUpdate(int* Stack);
	void PositionStackDownUpdate(int* Stack);
	void PositionStackUpdate(StateStack* playerStack, int nowPoint);
	void AttackStackUpdate(StateStack* playerStack);
	void GuardStackUpdate(StateStack* playerStack);
	void StepStackUpdate(StateStack* playerStack);

	////移動時に中断して攻撃を行うときの関数

	//移動後の次の行動を決める関数
	/*マウスの位置に応じて戻り値が変わる*/
	//エネミー
	int ChangStay(const StateStack* playerStack);
	int MostBigStack(const StateStack* playerStack);

	////移動時に壁から出てしまわないようにする関数
	/*bool CanReverse(const D3DXMATRIX* charaMat);*/
	//敵のスタミナを減らす関数
	bool SetStDecrease(float& St, bool& StDecreaseSetFlg,D3DXMATRIX &stMat);
	//自機のスタミナを減らす関数
	bool SetStDecrease(float& St, bool& StDecreaseSetFlg);

	//敵のスタミナを回復する関数
	void StHeel(float& St, D3DXMATRIX& stMat);
	//自機のスタミナを回復する関数
	void StHeel(float * St);

	//当たり判定の変数をセットする関数
	void SetHitElement(HitElement *hitElement,int nowPoint,int nowState,int motionNumber,float frame);
	
	//二度押し
	bool PushKeyFlg(bool* tapFlg, int  *tapCnt, bool* timeSetFlg);
	//ボタンを押しているかどうか
	bool MovePushKeyFlg();

	
protected:
	//animationのクラス
	C_Anime anime;

	//マウスの位置のクラス
	C_Mouse mouse;

	//スタミナをセットしたかどうかのフラグ
	bool    StDecreaseSetFlg;
	
	//音を鳴らすクラス
	C_SoundBase* se;

	//敵の行動を決めるクラス
	C_E_StateManeger e_StateManeger;
	
};