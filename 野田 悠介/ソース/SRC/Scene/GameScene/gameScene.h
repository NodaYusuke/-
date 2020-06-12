#pragma once
#include"../SceneBace/sceneBase.h"
#include"../../Chara/chara.h"
#include"../../Stage/stage.h"
#include"../../MeshLei/meshLei.h"
#include"../../Camera/camera.h"
#include"../../Sound/BGM/BGM_Game/BGM_game.h"
//ゲームシーン//sceneBaseの派生クラス
//AttackHitAng関数は攻撃が当たるかどうか調べる
//SetCharaElement関数は構造体に変数をセットする
//GetTargetVecAng関数はターゲットまでの角度を調べる
//AttackGuard関数は攻撃が防御されたかどうか調べる
//HitAttack関数は相手が攻撃をくらう状態か調べる
//charaDamageInvincibleTime関数はキャラが攻撃を受けた後の無敵時間を管理する
class C_Game :public C_SceneBase
{
public:
	C_Game();
	~C_Game();
	bool Update();
	void Render3D();
	void Render2D();
	void SetCamera();
	bool AttackHitAng(float TargetAng, float Len);
	void SetCharaElement(charaElement* chraElement,const  D3DXMATRIX *duelMat, const HitElement *duelElement, bool AttackHitFlg, const float* Len, float* ToAng,bool* danmageFlg,D3DXVECTOR3* camPos);
	float GetTargetVecAng(const D3DXMATRIX* charaMat, D3DXVECTOR3 targetVec);
	bool AttackGuard(int NowState, int NowPosition, int duelNowPosition, int* damageCnt);
	bool HitAttack(HitAttackElement charaHitAttackElement);
	void charaDamageInvincibleTime(bool* damageFlg, int* damageCnt);
	bool StartTexCntSetCamea(C_Camera & camera ,int &battleStartTexCnt,const D3DXMATRIX &playerMat, const D3DXMATRIX& enemyMat,const D3DXVECTOR3 & pos );
private:
	D3DLIGHT9 Light;	 //照明
	C_Stage   stage;     //ステージのクラス
	C_MeshLei meshLei;   //メッシュレイのクラス
	C_Camera  camera;    //カメラのクラス
	std::vector<C_Chara*>chara;//キャラクターのクラス

	//カメラのテスト用変数
	D3DXVECTOR3 TestPos;  //テスト用座標
	D3DXVECTOR3 cameraVec;//テスト用ベクトル
	
	//player関連----------------------------------
	bool playerFlg;            /*playerが生きてるかどうか*/
	bool playerDamageFlg=false;/*攻撃を受けたかどうか*/
	bool playerAttackHitFlg;
	//--------------------------------------------
	//enemy関連------------------------------------
	bool enemyFlg;            /*敵が生きているかどうか*/
	bool enemyDamageFlg=false;/*攻撃を受けたかどうか*/
	bool enemyAttackHitFlg;
	//---------------------------------------------

	int damageCnt[2];    /*色が変わる時間*/
	float Target;/*敵との距離　-1はあったていない*/

	//text表示用
	LPDIRECT3DTEXTURE9 winBattleEndTex[3];
	D3DXMATRIX winBattleEndTexMat[3];

	LPDIRECT3DTEXTURE9 loseBattleEndTex[3];
	D3DXMATRIX loseBattleEndTexMat[3];

	D3DXMATRIX BattleEndTexTransMat[2];
	D3DXMATRIX BattleEndTexScaleMat[2];


	float scaleSize[2];
	//戦いが続いている
	/*trueで継続　falseで終了*/
	bool battleContinuedFlg;

	//戦闘開始時に表示される画像の変数
	LPDIRECT3DTEXTURE9 battleStartTex[2];
	D3DXMATRIX battleStartTexMat;
	int battleStartTexCnt;/*表示される時間*/

	LPDIRECT3DTEXTURE9 timeTex;
	D3DXMATRIX timeTexMat[3];
	int timeCnt;

	C_BGM_Game* bgm;

	D3DXVECTOR3 camPos;
};