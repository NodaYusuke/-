#include"gameScene.h"
#include"../TitleScene/titleScene.h"
#include"../WinResultScene/WinResultScene.h"
#include"../LoseResultScene/LoseResult.h"
#include"../SceneManeger/sceneManeger.h"
#include"../../Chara/Player/player.h"
#include"../../Chara/Enemy/enemy.h"

extern C_SceneManeger sceneManeger;
enum { player = 0/*自機*/, enemy/*敵*/ };

C_Game::C_Game()
{
	scaleSize[0] = SCALESIZE;
	scaleSize[1] = SCALESIZE;

	LoadTexture(&winBattleEndTex[0],"DATA/Texture/winBattleEndTex1.png", 400, 400, NULL);
	LoadTexture(&winBattleEndTex[1],"DATA/Texture/winBattleEndTex2.png", 400, 400, NULL);
	LoadTexture(&winBattleEndTex[2],"DATA/Texture/titleBackTex2.jpg", 1300, 720, NULL);

	LoadTexture(&loseBattleEndTex[0], "DATA/Texture/loseBattleEndTex1.png", 400, 400, NULL);
	LoadTexture(&loseBattleEndTex[1], "DATA/Texture/loseBattleEndTex2.png", 400, 400, NULL);
	LoadTexture(&loseBattleEndTex[2], "DATA/Texture/loseResult.jpg", 1300, 720, NULL);

	D3DXMatrixTranslation(&BattleEndTexTransMat[0], 100, 110, 0);
	D3DXMatrixTranslation(&BattleEndTexTransMat[1], 680, 110, 0);

	D3DXMatrixTranslation(&winBattleEndTexMat[2], SCRW, 0, 0);
	D3DXMatrixTranslation(&loseBattleEndTexMat[2], SCRW, 0, 0);

	D3DXMatrixScaling(&BattleEndTexScaleMat[0], scaleSize[0], scaleSize[0], 0);
	D3DXMatrixScaling(&BattleEndTexScaleMat[1], scaleSize[1], scaleSize[1], 0);

	LoadTexture(&battleStartTex[0],"DATA/Texture/battleStartTex1.png", 600, 100, NULL);
	LoadTexture(&battleStartTex[1],"DATA/Texture/battleStartTex2.png", 600, 100, NULL);

	battleStartTexCnt = BATTLESTARTTEXCNTNUM;

	D3DXMatrixTranslation(&battleStartTexMat, (SCRW - 600)/2.0f, 300, 0);


	LoadTexture(&timeTex, "DATA/Texture/suzi5.png", 500, 75, NULL);
	timeCnt = LIMITTIME;
	D3DXMatrixTranslation(&timeTexMat[0],570,20,0 );
	D3DXMatrixTranslation(&timeTexMat[1],620,20, 0);
	D3DXMatrixTranslation(&timeTexMat[2],670,20, 0);

	//ライトの設定====================================
	lpD3DDevice->SetRenderState(D3DRS_LIGHTING, true);
	ZeroMemory(&Light, sizeof(Light));//中身を０で初期化
	Light.Type = D3DLIGHT_DIRECTIONAL;
	//ディレクショナルライト---------------------------
	Light.Diffuse.r = 1.0f;
	Light.Diffuse.g = 1.0f;	//ライトは基本白
	Light.Diffuse.b = 1.0f;
	//ライトのあったていないところの明るさ-------------
	Light.Ambient.r = 0.8f;
	Light.Ambient.g = 0.8f;
	Light.Ambient.b = 0.8f;
	Light.Direction = D3DXVECTOR3(-1.0f, -1.0f, -1.0f);
	//光が進む方向
	lpD3DDevice->SetLight(0, &Light);
	lpD3DDevice->LightEnable(0, TRUE);

	Target = MISS;

	battleContinuedFlg = true;
	//プレイヤーの呼び出し=============================
	playerFlg = true;
	D3DXVECTOR3 playerPos;/*プレイヤーの座標*/
	playerPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	float playerAng = 0.0f;//プレイヤーの角度
	chara.push_back(new C_Player(playerPos,playerAng));
	damageCnt[player] = 0;
	playerAttackHitFlg = false;
	//エネミーの呼び出し=============================
	enemyFlg = true;
	D3DXVECTOR3 enemyPos;/*敵の座標*/
	enemyPos = D3DXVECTOR3(0.0f, 0.0f, 15.0f);
	float enemyAng = 180.0f;
	chara.push_back(new C_Enemy(enemyPos, enemyAng));
	damageCnt[enemy] = 0;
	enemyAttackHitFlg = false;
	
	//カメラの初期化
	TestPos = D3DXVECTOR3(4.0f, 8.0f, -6.0f);
	cameraVec = D3DXVECTOR3(10.0f, 8.0f, -6.0f);

	bgm = new C_BGM_Game();
	bgm->PlaySwitch(true);

	ZeroMemory(&camPos, sizeof(&camPos));

}

C_Game::~C_Game()
{
	SafeRelease(battleStartTex[0]);
	SafeRelease(battleStartTex[1]);

	SafeRelease(winBattleEndTex[0]);
	SafeRelease(winBattleEndTex[1]);
	SafeRelease(winBattleEndTex[2]);

	SafeRelease(timeTex);

	delete chara[player];
	delete chara[enemy];

	chara.clear();

	delete bgm;
}

bool C_Game::Update()
{
	if (EscTitle() == true)
	{
		sceneManeger.ChangScene(new C_Title());
		return false;
	}
	//
	////キー操作------------------------------------
	////画面切り替え
	//if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	//{
	//	if (KeyFlg == false)
	//	{
	//		sceneManeger.ChangScene(new C_WinResult());
	//		KeyFlg = true;
	//		return false;
	//	}
	//}
	//else
	//{
	//	KeyFlg = false;
	//}


	//戦いが継続しているか調べる
	if (playerFlg == false ||
		enemyFlg == false)
		//どちらかが倒れている場合
		//ゲームシーンを終わらせる
		battleContinuedFlg = false;

	//キャラクターの更新--------------------------------
	if (battleContinuedFlg == false)
	{
		if (enemyFlg == false)
		{
			if (winBattleEndTexMat[2]._41 <= 0)
			{
				sceneManeger.ChangScene(new C_WinResult());
				return false;
			}
			if (scaleSize[0] > 1.0f)
			{
				scaleSize[0] -= 0.01f;
				if (scaleSize[0] < 1.0f)
				{
					scaleSize[0] = 1.0f;
				}
			}
			else
			{
				if (scaleSize[1] > 1.0f)
				{
					scaleSize[1] -= 0.01f;
					if (scaleSize[1] < 1.0f)
					{
						scaleSize[1] = 1.0f;
					}
				}
				else
				{
					if (winBattleEndTexMat[2]._41 > 0)
					{
						D3DXMATRIX tmpTrans;
						D3DXMatrixTranslation(&tmpTrans, -8, 0, 0);
						winBattleEndTexMat[2] *= tmpTrans;
					}
				}
			}
		}
		if (playerFlg == false)
		{
			if (loseBattleEndTexMat[2]._41 <= 0)
			{
				sceneManeger.ChangScene(new C_LoseResult());
				return false;
			}
			if (scaleSize[0] > 1.0f)
			{
				scaleSize[0] -= 0.01f;
				if (scaleSize[0] < 1.0f)
				{
					scaleSize[0] = 1.0f;
				}
			}
			else
			{
				if (scaleSize[1] > 1.0f)
				{
					scaleSize[1] -= 0.01f;
					if (scaleSize[1] < 1.0f)
					{
						scaleSize[1] = 1.0f;
					}
				}
				else
				{
					if (loseBattleEndTexMat[2]._41 > 0)
					{
						D3DXMATRIX tmpTrans;
						D3DXMatrixTranslation(&tmpTrans, -8, 0, 0);
						loseBattleEndTexMat[2] *= tmpTrans;
					}
				}
			}
		}
	}
	

	

	D3DXMATRIX              playerMat;/*プレイヤーの行列*/
	D3DXMATRIX               enemyMat;/*敵の行列*/

	//必要情報の取得
	playerMat = chara[player]->GetterCharaMat();
	enemyMat = chara[enemy]->GetterCharaMat();

	if ((StartTexCntSetCamea(camera, battleStartTexCnt, playerMat, enemyMat, TestPos)) == true)
	{
		return true;
	}
	timeCnt--;
	D3DXVECTOR3 TargetVec;//対象までのベクトル
	D3DXVECTOR3 playerPos(playerMat._41, playerMat._42, playerMat._43);//プレイヤーの座標
	D3DXVECTOR3 enemyPos(enemyMat._41, enemyMat._42, enemyMat._43);//エネミーの座標
	//プレイヤーからエネミーまでのベクトルを作成
	TargetVec = enemyPos - playerPos;
	float Len;/*目標との距離*/
	//y軸は必要ないのでつぶす
	TargetVec.y = 0;
	//目標との距離を測る
	Len = D3DXVec3Length(&TargetVec);
	//プレイヤーからエネミーまでの角度を作成
	float playerTargetAng = GetTargetVecAng(&playerMat, TargetVec);
	//プレイヤーの攻撃がエネミーに当たる角度かを調べる
	playerAttackHitFlg = AttackHitAng(playerTargetAng, Len);
	//プレイヤーの現在の角度を調べる
	float playerAng = GetVecAng(TargetVec);
	//プレイヤーの現在の行動を調べる
	HitElement playerHitElement = chara[player]->CharaNowState();



	//エネミーからプレイヤーまでのベクトルを作成
	TargetVec = playerPos - enemyPos;
	//エネミーから対象までの角度を作成
	float enemyTargetAng = GetTargetVecAng(&enemyMat, TargetVec);
	//エネミーの攻撃がプレイヤーに当たる角度かを調べる
	enemyAttackHitFlg = AttackHitAng(enemyTargetAng, Len);
	//エネミーの現在の角度を調べる
	float enemyAng = GetVecAng(TargetVec);
	//エネミーの現在の行動を調べる
	HitElement enemyHitElement = chara[enemy]->CharaNowState();

	//キャラクターのアップデート
	//キャラクターのアップデートの引数
	charaElement playerElement, enemyElement;
	//プレイヤー
	//引数をセット
	SetCharaElement(&playerElement, &enemyMat, &enemyHitElement, playerAttackHitFlg, &Len, &playerAng,&enemyDamageFlg,&camPos);
	//アップデート
	playerHitElement = chara[player]->Update(playerElement);
	const StateStack* playerNowStack;

	playerNowStack = chara[player]->ReturnStack();

	//プレイヤーのHPを持ってくる
	float playerHP = chara[player]->HPGetter();

	//プレイヤーのSTを持ってくる
	float playerST = chara[player]->STGetter();

	States playerState;
	playerState.HP = &playerHP;
	playerState.ST = &playerST;

	//エネミー
	//引数をセット
	SetCharaElement(&enemyElement, &playerMat, &playerHitElement, enemyAttackHitFlg, &Len, &enemyAng,&playerDamageFlg, &camPos);
	//アップデート
	enemyHitElement = chara[enemy]->Update(enemyElement, playerNowStack, &playerState);
	//////当たり判定
	////引数に変数をセット
	//プレイヤー
	HitAttackElement playerHitAttackElement = { playerHitElement, enemyHitElement, &damageCnt[enemy], playerAttackHitFlg };
	//エネミー
	HitAttackElement enemyHitAttackElement = { enemyHitElement, playerHitElement, &damageCnt[player], enemyAttackHitFlg };
	////関数を実行
	//プレイヤー
	if (enemyDamageFlg == false)//エネミーに攻撃が当たる状態
	{
		enemyDamageFlg = HitAttack(playerHitAttackElement);
	}
	//エネミー
	if (playerDamageFlg == false)//プレイヤーに攻撃が当たる状態
	{
		playerDamageFlg = HitAttack(enemyHitAttackElement);
	}
	////ダメージを受けた後の処理
	//エネミー
	charaDamageInvincibleTime(&enemyDamageFlg, &damageCnt[enemy]);
	//プレイヤー
	charaDamageInvincibleTime(&playerDamageFlg, &damageCnt[player]);
	

	//////カメラのアップデート
	//必要情報を取得
	playerMat = chara[player]->GetterCharaMat();
	enemyMat = chara[enemy]->GetterCharaMat();
	////テスト用のカメラ切り替え
	//デフォルト
	if (GetAsyncKeyState(VK_F1) & 0x8000)
	{
		TestPos = D3DXVECTOR3(4.0f, 8.0f, -6.0f);
	}
	//真横
	if (GetAsyncKeyState(VK_F2) & 0x8000)
	{
		TestPos = D3DXVECTOR3(10.0f, 0.0f, 0.0f);
	}
	//見下し
	if (GetAsyncKeyState(VK_F3) & 0x8000)
	{
		TestPos = D3DXVECTOR3(0.0f, 10.0f, -1.0f);
	}
	//真後ろ
	if (GetAsyncKeyState(VK_F4) & 0x8000)
	{
		TestPos = D3DXVECTOR3(0.0f, 0.0f, -10.0f);
	}

	
	//カメラのアップデート
	if (playerFlg == true)
	{
		camPos = camera.Update(playerMat, enemyMat, TestPos);
	}
	else
	{
		D3DXMATRIX tmpMat;
		D3DXMatrixTranslation(&tmpMat, playerMat._41, playerMat._42, playerMat._43);
		camPos = camera.Update(tmpMat, enemyMat, TestPos);
	}
	return true;
}

void C_Game::Render3D()
{

	//描画開始--------------------------------------
	lpD3DDevice->SetRenderState(D3DRS_LIGHTING, true); /*ライトon*/
	//プレイヤー
	chara[player]->Render3D(playerDamageFlg);
	//エネミー
	chara[enemy]->Render3D(enemyDamageFlg);

	lpD3DDevice->SetRenderState(D3DRS_LIGHTING, false);/*ライトoff*/

	//hitEffect.Render3D();/*ヒットエフェクト*/

	stage.Render3D();/*ステージ*/
	//----------------------------------------------

}

void C_Game::Render2D()
{
	//////////////////////////////////////////////////
	///	スプライトの描画処理//////////////////////////
	//////////////////////////////////////////////////
	// 描画開始
	lpSprite->Begin(D3DXSPRITE_ALPHABLEND);

	playerFlg=chara[player]->Render2D(playerDamageFlg);

	enemyFlg =chara[enemy]->Render2D(enemyDamageFlg);

	if (battleStartTexCnt > 60)
	{
		RECT rcBattleStartTex1 = { 0,0,600,100 };
		lpSprite->SetTransform(&battleStartTexMat);
		lpSprite->Draw(battleStartTex[0], &rcBattleStartTex1, &D3DXVECTOR3(0, 0, 0), NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
	}
	if (battleStartTexCnt > 0 && battleStartTexCnt <= 60)
	{
		RECT rcBattleStartTex2 = { 0,0,600,100 };
		lpSprite->SetTransform(&battleStartTexMat);
		lpSprite->Draw(battleStartTex[1], &rcBattleStartTex2, &D3DXVECTOR3(0, 0, 0), NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
	}
	
	RECT rcTimeTex = { (timeCnt / 6000) * TIMETEXSIZEX,0,((timeCnt / 6000) * TIMETEXSIZEX) + TIMETEXSIZEX,75 };
	lpSprite->SetTransform(&timeTexMat[0]);
	lpSprite->Draw(timeTex, &rcTimeTex, &D3DXVECTOR3(0, 0, 0), NULL, D3DCOLOR_ARGB(255, 255, 255, 255));

	RECT rcTimeTex2 = { ((timeCnt % 6000) / 600) * TIMETEXSIZEX,0,((timeCnt % 6000) / 600 * TIMETEXSIZEX) + TIMETEXSIZEX,75 };
	lpSprite->SetTransform(&timeTexMat[1]);
	lpSprite->Draw(timeTex, &rcTimeTex2, &D3DXVECTOR3(0, 0, 0), NULL, D3DCOLOR_ARGB(255, 255, 255, 255));

	RECT rcTimeTex3 = { ((((timeCnt % 6000) % 600))/60) * TIMETEXSIZEX,0,((((timeCnt % 6000) % 600) / 60) * TIMETEXSIZEX) + TIMETEXSIZEX,75 };
	lpSprite->SetTransform(&timeTexMat[2]);
	lpSprite->Draw(timeTex, &rcTimeTex3, &D3DXVECTOR3(0, 0, 0), NULL, D3DCOLOR_ARGB(255, 255, 255, 255));

	if (battleContinuedFlg == false)
	{
		if (enemyFlg == false)
		{
			if (scaleSize[1] == 1.0f)
			{

				RECT rcWinBattleTex3 = { 0,0,1300,720 };
				lpSprite->SetTransform(&winBattleEndTexMat[2]);
				lpSprite->Draw(winBattleEndTex[2], &rcWinBattleTex3, &D3DXVECTOR3(0, 0, 0), NULL, D3DCOLOR_ARGB(255, 255, 255, 255));

			}
			D3DXMatrixScaling(&BattleEndTexScaleMat[0], scaleSize[0], scaleSize[0], 0);

			winBattleEndTexMat[0] = BattleEndTexScaleMat[0] * BattleEndTexTransMat[0];

			RECT rcWinBattleTex1 = { 0,0,400,400 };
			lpSprite->SetTransform(&winBattleEndTexMat[0]);
			lpSprite->Draw(winBattleEndTex[0], &rcWinBattleTex1, &D3DXVECTOR3(0, 0, 0), NULL, D3DCOLOR_ARGB(255, 255, 255, 255));

			if (scaleSize[0] <= 1.0f)
			{
				D3DXMatrixScaling(&BattleEndTexScaleMat[1], scaleSize[1], scaleSize[1], 0);

				winBattleEndTexMat[1] = BattleEndTexScaleMat[1] * BattleEndTexTransMat[1];

				RECT rcWinBattleTex2 = { 0,0,400,400 };
				lpSprite->SetTransform(&winBattleEndTexMat[1]);
				lpSprite->Draw(winBattleEndTex[1], &rcWinBattleTex2, &D3DXVECTOR3(0, 0, 0), NULL, D3DCOLOR_ARGB(255, 255, 255, 255));

			}
		}
		if (playerFlg == false)
		{
			if (scaleSize[1] == 1.0f)
			{

				RECT rcLoseBattleTex3 = { 0,0,1300,720 };
				lpSprite->SetTransform(&loseBattleEndTexMat[2]);
				lpSprite->Draw(loseBattleEndTex[2], &rcLoseBattleTex3, &D3DXVECTOR3(0, 0, 0), NULL, D3DCOLOR_ARGB(255, 255, 255, 255));

			}
			D3DXMatrixScaling(&BattleEndTexScaleMat[0], scaleSize[0], scaleSize[0], 0);

			loseBattleEndTexMat[0] = BattleEndTexScaleMat[0] * BattleEndTexTransMat[0];

			RECT rcLoseBattleTex1 = { 0,0,400,400 };
			lpSprite->SetTransform(&loseBattleEndTexMat[0]);
			lpSprite->Draw(loseBattleEndTex[0], &rcLoseBattleTex1, &D3DXVECTOR3(0, 0, 0), NULL, D3DCOLOR_ARGB(255, 255, 255, 255));

			if (scaleSize[0] <= 1.0f)
			{
				D3DXMatrixScaling(&BattleEndTexScaleMat[1], scaleSize[1], scaleSize[1], 0);

				loseBattleEndTexMat[1] = BattleEndTexScaleMat[1] * BattleEndTexTransMat[1];

				RECT rcloseBattleTex2 = { 0,0,400,400 };
				lpSprite->SetTransform(&loseBattleEndTexMat[1]);
				lpSprite->Draw(loseBattleEndTex[1], &rcloseBattleTex2, &D3DXVECTOR3(0, 0, 0), NULL, D3DCOLOR_ARGB(255, 255, 255, 255));

			}
		}
	}

	// 描画終了
	lpSprite->End();
	chara[player]->TestRender2D();

}

void C_Game::SetCamera()
{
	camera.SetCamera();
}

bool C_Game::AttackHitAng(float TargetAng,float Len)
{
	if (-10 <= TargetAng && TargetAng <= 10 && Len < 4.3)
	return true;
	return false;
}

bool C_Game::AttackGuard(int NowState, int NowPosition, int duelNowPosition, int* damageCnt)
{
	if (NowState == GUARD &&//敵が防御している
		NowPosition == duelNowPosition)
	{
		return false;
	}
	*damageCnt = DAMEAGECNTNUM;/*無敵時間*/
	return true;
}

bool C_Game::HitAttack(HitAttackElement charaHitAttackElement)
{
	if (*charaHitAttackElement.damageCnt != 0/*敵がダメージを受け付ける状態*/ ||
		charaHitAttackElement.AttackHitFlg == false||
		charaHitAttackElement.myElement.NowState != ATTACK)
		return false;
	if (charaHitAttackElement.myElement.Position == TOP)
	{
		if (charaHitAttackElement.myElement.nowMotion == 1 &&
			charaHitAttackElement.myElement.animeFrame >= 0.8f/*アニメの進行度が8以上*/)
		{
			return AttackGuard(charaHitAttackElement.duelElement.NowState,
				               charaHitAttackElement.myElement.Position,
				               charaHitAttackElement.duelElement.Position,
				               charaHitAttackElement.damageCnt);
		}
	}
	else
	{
		if (charaHitAttackElement.myElement.animeFrame >= 0.8f/*アニメの進行度が8以上*/)
		{
			return AttackGuard(charaHitAttackElement.duelElement.NowState,
				               charaHitAttackElement.myElement.Position,
				               charaHitAttackElement.duelElement.Position,
				               charaHitAttackElement.damageCnt);
		}
	}
	return false;
}

void C_Game::charaDamageInvincibleTime(bool* damageFlg, int* damageCnt)
{
	if (*damageFlg == false)return;
	if (*damageCnt > 0)
	{
		(*damageCnt)--;
	}
	else
	{
		*damageCnt = 0;
		*damageFlg = false;
	}
	return;
}

bool C_Game::StartTexCntSetCamea(C_Camera& camera, int &battleStartTexCnt, const D3DXMATRIX& playerMat, const D3DXMATRIX& enemyMat, const D3DXVECTOR3& pos)
{
	if (battleStartTexCnt > 0)
	{
		camera.Update(playerMat, enemyMat, pos);
		battleStartTexCnt--;
		return true;
	}
	return false;
}



void C_Game::SetCharaElement(charaElement* charaElement,
	                 const D3DXMATRIX  *duelMat,
	                 const HitElement  *duelElement,
                     bool          AttackHitFlg,
                     const float*  Len,
                     float*        ToAng,
                     bool *damageflg,
	                 D3DXVECTOR3 *camPos)
{
	charaElement->duelElement = duelElement;
	charaElement->duelMat = duelMat;
	charaElement->AttackHitFlg = AttackHitFlg;
	charaElement->Len = Len;
	charaElement->ToAng = ToAng;
	charaElement->duelDamageFlg = damageflg;
	charaElement->camPos = camPos;
}

float C_Game::GetTargetVecAng(const D3DXMATRIX *charaMat,D3DXVECTOR3 targetVec)
{
	targetVec.y = 0;
	D3DXVec3Normalize(&targetVec, &targetVec);
	D3DXVECTOR3 charaVec;
	D3DXVec3TransformNormal(&charaVec, &D3DXVECTOR3(0, 0, 1), charaMat);
	float Dot;
	Dot = D3DXVec3Dot(&charaVec, &targetVec);
	if (Dot > 1)Dot = 1;
	if (Dot < -1)Dot = -1;
	double Ang;
	Ang = D3DXToDegree(acos(Dot));
	if (targetVec.x < 0)Ang *= -1;
	return (float)Ang;
}