#include"player.h"
#include"../../State/PlayerState/Stay/stay.h"
//�v���C���[�̏�����===============================================
C_Player::C_Player(D3DXVECTOR3 Pos, float Ang)
{
	//�̂̏�����---------------------------------------------------
	D3DXMatrixTranslation(&charaTransMat, Pos.x, Pos.y, Pos.z);
	D3DXMatrixRotationY(&charaRotMat, D3DXToRadian(Ang));
	charaMat = charaRotMat * charaTransMat;
	//-------------------------------------------------------------
	
	//���̏�����---------------------------------------------------
	D3DXMatrixTranslation(&headTransMat, 0.0f,2.0f,0.0f);
	//-------------------------------------------------------------

	//�E���E�E���̏�����-------------------------------------------
	D3DXMatrixTranslation(&leftLegTransMat,- 0.4f,- 1.8f,  0.0f);
	D3DXMatrixTranslation(&rightLegTransMat, 0.4f, - 1.8f, 0.0f);
	//-------------------------------------------------------------

	//���̏�����--------------------------------------------------
	
	D3DXMatrixTranslation(&katanaTransMat,  0.0f,  0.5f,  1.2f);
	D3DXMatrixRotationX(&katanaRotMat, D3DXToRadian(45));
	//-------------------------------------------------------------

	//�E��E�E��̏�����-------------------------------------------	
	D3DXMatrixTranslation(&leftArmTransMat,  - 0.2f,  - 0.2f, 0.0f);
	D3DXMatrixTranslation(&rightArmTransMat, 0.2f, - 0.2f,  0.0f);
	D3DXMatrixRotationY(&leftArmRotMat, D3DXToRadian(45));
	D3DXMatrixRotationY(&rightArmRotMat, D3DXToRadian(-45));
	//-------------------------------------------------------------

	//�v���C���[�̍ŏ��̏��
	NowState = new C_Stay();

	CharaInit();
	ZeroMemory(&playerActionElement, sizeof(&playerActionElement));
	playerActionElement.attackTapFlg = &attaclTapFlg;
	playerActionElement.charaMat = &charaMat;
	playerActionElement.playerStack = &playerStack;
	playerActionElement.katanaElementMat = &katanaElementMat;
	playerActionElement.katanaRotMat = &katanaRotMat;
	playerActionElement.katanaTransMat = &katanaTransMat;
	playerActionElement.nowMove = &nowMove;
	playerActionElement.NowPoint = &NowPoint;
	playerActionElement.RotMat = &charaRotMat;
	playerActionElement.TransMat = &charaTransMat;
	playerActionElement.St = &St;
	playerActionElement.stMat = &stMat;

	D3DXMatrixTranslation(&hpMat, GAUGEPOSX,20,0);
	D3DXMatrixTranslation(&stMat, GAUGEPOSX,70,0);
	D3DXMatrixTranslation(&coverMat, GAUGEPOSX -1.0f,16.0f,0);

	LoadTexture(&positionTex, "DATA/Texture/position.png", 900, 300, NULL);
	D3DXMatrixTranslation(&positionMat, SCRW - 300, SCRH - 300, 0);

	ZeroMemory(&playerStack, sizeof(&playerStack));

}

//�v���C���[�̏I������
C_Player::~C_Player()
{
}


int NowMoveVec(int nowMove)
{
	if (GetAsyncKeyState('W') & 0x8000)
	{
		return FORWARD;
	}
	if (GetAsyncKeyState('A') & 0x8000)
	{
		return RIGHT;
	}
	if (GetAsyncKeyState('D') & 0x8000)
	{
		return LEFT;
	}
	if (GetAsyncKeyState('S') & 0x8000)
	{
		return REVERSE;
	}
	return nowMove;
}

//�v���C���[�̍X�V����=========================================
HitElement C_Player::Update(charaElement playerElement)
{	
	/*if (GetAsyncKeyState('X') & 0x8000)
	{
		Hp = 0;
	}*/

	//actionElement�Ɉ������Z�b�g����
	playerActionElement.playerElement = &playerElement;

	nowMove = NowMoveVec(nowMove);

	NowPoint = mouse.Update();
	
	//�v���C���[�̍s�������߂�
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
		NextState = NowState->Action(&playerActionElement);

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

	//�v���C���[�̍s��̍쐬
	MakeCharaMatrix();

	return returnElement;
}

bool C_Player::Render2D(bool DamageFlg)
{
	//Hp�̌v�Z
	SetHp(&Hp, HpDamageSetFlg, DamageFlg,&hpMat,duelPosition);
	RECT rcHP = { (long)(HPGAUGEWIDTH * ((MAXHP - Hp) / 100.0f)),0,(long)(HPGAUGEWIDTH),(long)(HPGAUGEHEIGHT) };
	lpSprite->SetTransform(&hpMat);
	lpSprite->Draw(hpTex, &rcHP, &D3DXVECTOR3(0, 0, 0), NULL, D3DCOLOR_ARGB(255, 255, 255, 255));

	RECT rcST = { (long)(STGAUGEWIDTH * ((MAXST - St) / 100.0f)),0,(long)(STGAUGEWIDTH),(long)(STGAUGEHEIGHT) };
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

	RECT rcPosition = { 300 * NowPoint,0,300 * (1 + NowPoint),300 };
	lpSprite->SetTransform(&positionMat);
	lpSprite->Draw(positionTex, &rcPosition, &D3DXVECTOR3(0, 0, 0), NULL, D3DCOLOR_ARGB(255, 255, 255, 255));

	return SurvivalChara(&Hp);
}

void C_Player::TestRender2D()
{
	NowState->Render2D();
}

const StateStack* C_Player::ReturnStack()
{
	return &playerStack;
}

float C_Player::HPGetter()
{
	return Hp;
}

float C_Player::STGetter()
{
	return St;
}
