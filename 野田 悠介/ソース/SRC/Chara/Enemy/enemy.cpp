#include"enemy.h"
#include"../../State/EnemyState/Stay/E_Stay.h"
#include"../../State/EnemyState/Move/E_Move.h"
//プレイヤーの初期化===============================================
C_Enemy::C_Enemy(D3DXVECTOR3 Pos, float Ang)
{

	position = NORMAL;
	moveWay = FORWARD;

	moveWayChangeCnt = 0;

	//体の初期化---------------------------------------------------
	D3DXMatrixTranslation(&charaTransMat, Pos.x, Pos.y, Pos.z);
	D3DXMatrixRotationY(&charaRotMat, D3DXToRadian(Ang));
	charaMat = charaRotMat * charaTransMat;
	//-------------------------------------------------------------

	//頭の初期化---------------------------------------------------
	D3DXMatrixTranslation(&headTransMat, 0.0f, 2.0f, 0.0f);
	//-------------------------------------------------------------

	//右足・右足の初期化-------------------------------------------
	D3DXMatrixTranslation(&leftLegTransMat, -0.4f, -1.8f, 0.0f);
	D3DXMatrixTranslation(&rightLegTransMat, 0.4f, -1.8f, 0.0f);
	//-------------------------------------------------------------

	//刀の初期化--------------------------------------------------

	D3DXMatrixTranslation(&katanaTransMat, 0.0f, 0.5f, 1.2f);
	D3DXMatrixRotationX(&katanaRotMat, D3DXToRadian(45));
	//-------------------------------------------------------------

	//右手・右手の初期化-------------------------------------------	
	D3DXMatrixTranslation(&leftArmTransMat, -0.2f, -0.2f, 0.0f);
	D3DXMatrixTranslation(&rightArmTransMat, 0.2f, -0.2f, 0.0f);
	D3DXMatrixRotationY(&leftArmRotMat, D3DXToRadian(45));
	D3DXMatrixRotationY(&rightArmRotMat, D3DXToRadian(-45));
	//-------------------------------------------------------------

	//エネミーの最初の行動
	NowState = new C_E_Move();
	CharaInit();
	//アクション関数の引数の初期化
	ZeroMemory(&enemyActionElement, sizeof(&enemyActionElement));
	enemyActionElement.charaMat = &charaMat;
	enemyActionElement.katanaElementMat = &katanaElementMat;
	enemyActionElement.katanaTransMat = &katanaTransMat;
	enemyActionElement.katanaRotMat = &katanaRotMat;
	enemyActionElement.TransMat = &charaTransMat;
	enemyActionElement.RotMat = &charaRotMat;
	enemyActionElement.St = &St;
	enemyActionElement.stMat = &stMat;
	enemyActionElement.NowPosition = &position;
	enemyActionElement.MoveWay = &moveWay;
	

	D3DXMatrixTranslation(&hpMat, SCRW- HPGAUGEWIDTH - GAUGEPOSX, 20, 0);
	D3DXMatrixTranslation(&stMat, SCRW- HPGAUGEWIDTH - GAUGEPOSX, 70, 0);
	D3DXMatrixTranslation(&coverMat, SCRW- HPGAUGEWIDTH - GAUGEPOSX -1.0f, 16, 0);
}

//プレイヤーの終了処理=============================================
C_Enemy::~C_Enemy()
{
}

bool C_Enemy::Render2D(bool DamageFlg)
{
	//Hpの計算
	SetHp(&Hp, HpDamageSetFlg, DamageFlg,duelPosition);
	RECT rcHP = { 0,0,HPGAUGEWIDTH * (Hp / MAXHP),HPGAUGEHEIGHT };
	lpSprite->SetTransform(&hpMat);
	lpSprite->Draw(hpTex, &rcHP, &D3DXVECTOR3(0, 0, 0), NULL, D3DCOLOR_ARGB(255, 255, 255, 255));

	RECT rcST = { 0,0,STGAUGEWIDTH * (St / MAXST),STGAUGEHEIGHT };
	lpSprite->SetTransform(&stMat);
	if (St > 29)
	{
		lpSprite->Draw(stTex, &rcST, &D3DXVECTOR3(0, 0, 0), NULL, D3DCOLOR_ARGB(255, 255, 255, 255));

	}
	else
	{
		lpSprite->Draw(st_NotStateTex, &rcST, &D3DXVECTOR3(0, 0, 0), NULL, D3DCOLOR_ARGB(255, 255, 255, 255));

	}
	RECT rcCover = { 0,0,560,85 };
	lpSprite->SetTransform(&coverMat);
	lpSprite->Draw(coverTex, &rcCover, &D3DXVECTOR3(0, 0, 0), NULL, D3DCOLOR_ARGB(255, 255, 255, 255));

	return SurvivalChara(&Hp);
}



//プレイヤーの更新処理=========================================
HitElement C_Enemy::Update(charaElement enemyElement, const StateStack* playerStack, States* player)
{
	/*if (GetAsyncKeyState('Z') & 0x8000)
	{
		Hp = 0;
	}*/

	States enemy;
	enemy.HP = &Hp;
	enemy.ST = &St;

	enemyActionElement.enemyElement = &enemyElement;
	enemyActionElement.enemyStates = &enemy;
	enemyActionElement.playerStates = player;
	enemyActionElement.playerStack = playerStack;
	
	//エネミーの行動を決める
	if (endActionSetFlg == false)
	{
		if (Hp <= 0)
		{
			delete NowState;

			NowState = new C_Fall();
			NextState = nullptr;

			endActionSetFlg = true;
		}
	}
	//現在　行動を積んでいる
	if (NowState != nullptr)
	{
		//今のAIアクションを実行
		NextState = NowState->Action(&enemyActionElement);

		//次のシーンがある場合(ディスクの差し替え)
		if (NextState != nullptr)
		{
			//現在のシーンを削除
			delete NowState;

			//次のシーンを現在のシーンに移す
			NowState = NextState;
		}
	}

	//プレイヤーの状態を取得
	returnElement = NowState->GetCharaState();

	//エフェクトの作成
	MakeAttackEffect();

	//エネミーの行列の作成
	MakeCharaMatrix();

	return returnElement;
}
