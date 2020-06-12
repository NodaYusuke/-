#include"enemy.h"
#include"../../State/EnemyState/Stay/E_Stay.h"
#include"../../State/EnemyState/Move/E_Move.h"
//�v���C���[�̏�����===============================================
C_Enemy::C_Enemy(D3DXVECTOR3 Pos, float Ang)
{

	position = NORMAL;
	moveWay = FORWARD;

	moveWayChangeCnt = 0;

	//�̂̏�����---------------------------------------------------
	D3DXMatrixTranslation(&charaTransMat, Pos.x, Pos.y, Pos.z);
	D3DXMatrixRotationY(&charaRotMat, D3DXToRadian(Ang));
	charaMat = charaRotMat * charaTransMat;
	//-------------------------------------------------------------

	//���̏�����---------------------------------------------------
	D3DXMatrixTranslation(&headTransMat, 0.0f, 2.0f, 0.0f);
	//-------------------------------------------------------------

	//�E���E�E���̏�����-------------------------------------------
	D3DXMatrixTranslation(&leftLegTransMat, -0.4f, -1.8f, 0.0f);
	D3DXMatrixTranslation(&rightLegTransMat, 0.4f, -1.8f, 0.0f);
	//-------------------------------------------------------------

	//���̏�����--------------------------------------------------

	D3DXMatrixTranslation(&katanaTransMat, 0.0f, 0.5f, 1.2f);
	D3DXMatrixRotationX(&katanaRotMat, D3DXToRadian(45));
	//-------------------------------------------------------------

	//�E��E�E��̏�����-------------------------------------------	
	D3DXMatrixTranslation(&leftArmTransMat, -0.2f, -0.2f, 0.0f);
	D3DXMatrixTranslation(&rightArmTransMat, 0.2f, -0.2f, 0.0f);
	D3DXMatrixRotationY(&leftArmRotMat, D3DXToRadian(45));
	D3DXMatrixRotationY(&rightArmRotMat, D3DXToRadian(-45));
	//-------------------------------------------------------------

	//�G�l�~�[�̍ŏ��̍s��
	NowState = new C_E_Move();
	CharaInit();
	//�A�N�V�����֐��̈����̏�����
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

//�v���C���[�̏I������=============================================
C_Enemy::~C_Enemy()
{
}

bool C_Enemy::Render2D(bool DamageFlg)
{
	//Hp�̌v�Z
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



//�v���C���[�̍X�V����=========================================
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
	
	//�G�l�~�[�̍s�������߂�
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
	//���݁@�s����ς�ł���
	if (NowState != nullptr)
	{
		//����AI�A�N�V���������s
		NextState = NowState->Action(&enemyActionElement);

		//���̃V�[��������ꍇ(�f�B�X�N�̍����ւ�)
		if (NextState != nullptr)
		{
			//���݂̃V�[�����폜
			delete NowState;

			//���̃V�[�������݂̃V�[���Ɉڂ�
			NowState = NextState;
		}
	}

	//�v���C���[�̏�Ԃ��擾
	returnElement = NowState->GetCharaState();

	//�G�t�F�N�g�̍쐬
	MakeAttackEffect();

	//�G�l�~�[�̍s��̍쐬
	MakeCharaMatrix();

	return returnElement;
}
