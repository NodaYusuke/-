#include "chara.h"

C_Chara::C_Chara()
{
	LoadTexture(&hpTex, "DATA/Texture/HP.png", 550, 50, NULL);
	LoadTexture(&stTex, "DATA/Texture/ST.png", 550, 25, NULL);
	LoadTexture(&st_NotStateTex, "DATA/Texture/ST_NotState.png", 550, 25, NULL);
	LoadTexture(&coverTex, "DATA/Texture/Cover.png", 560, 85, NULL);
	LoadTexture(&effectTex, "DATA/Texture/white.png", 158, 210, NULL);
	LoadMesh(&legMesh, "DATA/Xfile/leg.x");
	LoadMesh(&bodyMesh, "DATA/Xfile/body.x");
	LoadMesh(&headMesh, "DATA/Xfile/head.x");
	LoadMesh(&katanaMesh, "DATA/Xfile/katana.x");
	LoadMesh(&armMesh, "DATA/Xfile/hand.x");
	NowState       = nullptr;
	NextState      = nullptr;
	NowPoint       = NULL;
	effectStartFlg = false;

	
	ZeroMemory(&returnElement, sizeof(returnElement));
	attaclTapFlg = false;
	Hp = MAXHP;
	St = MAXST;
	HpDamageSetFlg = false;
	/*ZeroMemory(&eff, sizeof(&eff));*/
	effActivateFlg = false;
	endActionSetFlg = false;
	duelPosition = 0;
	nowMove = 0;
}

C_Chara::~C_Chara()
{
	//���b�V���̉��-----------------------------------------------
	ReleaseMesh(&katanaMesh);
	ReleaseMesh(&headMesh);
	ReleaseMesh(&bodyMesh);
	ReleaseMesh(&legMesh);
	ReleaseMesh(&armMesh);
	SafeRelease(hpTex);
	SafeRelease(effectTex);
	//-------------------------------------------------------------
}

HitElement C_Chara::Update(charaElement charaElement)
{
	HitElement TmpElement;
	ZeroMemory(&TmpElement, sizeof(TmpElement));
	return TmpElement;
}

HitElement C_Chara::Update(charaElement charaElement, const StateStack* playerStack, States* player)
{
	return HitElement();
}

void C_Chara::Render3D(bool DamageFlg)
{  
	//�e�N�X�`���̓\��t���E�Ȃ�
	lpD3DDevice->SetTexture(0, NULL);
	//�U������Ă��Ȃ�
	if (DamageFlg == false)
	{
		lpD3DDevice->SetTransform(D3DTS_WORLD, &katanaMat);
		DrawMesh(&katanaMesh);
		lpD3DDevice->SetTransform(D3DTS_WORLD, &leftLegMat);
		DrawMesh(&legMesh);
		lpD3DDevice->SetTransform(D3DTS_WORLD, &rightLegMat);
		DrawMesh(&legMesh);
		lpD3DDevice->SetTransform(D3DTS_WORLD, &leftArmMat);
		DrawMesh(&armMesh);
		lpD3DDevice->SetTransform(D3DTS_WORLD, &rightArmMat);
		DrawMesh(&armMesh);
		lpD3DDevice->SetTransform(D3DTS_WORLD, &charaMat);
		DrawMesh(&bodyMesh);
		lpD3DDevice->SetTransform(D3DTS_WORLD, &headMat);
		DrawMesh(&headMesh);
	}
	//�U������Ă���
	/*�ԐF�ŕ\��*/
	else
	{
		Color red;
		red = { 255,0,0 };
		lpD3DDevice->SetTransform(D3DTS_WORLD, &katanaMat);
		DrawMesh(&katanaMesh, red);
		lpD3DDevice->SetTransform(D3DTS_WORLD, &leftLegMat);
		DrawMesh(&legMesh, red);
		lpD3DDevice->SetTransform(D3DTS_WORLD, &rightLegMat);
		DrawMesh(&legMesh, red);
		lpD3DDevice->SetTransform(D3DTS_WORLD, &leftArmMat);
		DrawMesh(&armMesh, red);
		lpD3DDevice->SetTransform(D3DTS_WORLD, &rightArmMat);
		DrawMesh(&armMesh, red);
		lpD3DDevice->SetTransform(D3DTS_WORLD, &charaMat);
		DrawMesh(&bodyMesh, red);
		lpD3DDevice->SetTransform(D3DTS_WORLD, &headMat);
		DrawMesh(&headMesh, red);
	}
	//�a���̕\���ݒ�
	D3DXMATRIX IntMat;
	D3DXMatrixIdentity(&IntMat);

	HitElement hitElement;
	hitElement = NowState->GetCharaState();

	if (hitElement.NowState == ATTACK)
	{
		lpD3DDevice->SetRenderState(D3DRS_LIGHTING, FALSE);//���C�goff
		lpD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);//���Z����on//100%

		lpD3DDevice->SetFVF(FVF_VERTEX);
		lpD3DDevice->SetTexture(0, effectTex);
		lpD3DDevice->SetTransform(D3DTS_WORLD, &IntMat);
		for (int i = 0; i < EFFECTNUM - 1; i++)
		{

			//���_�̐ݒ�@�@�@�@�@ ���_�̍��W�@�@�@�@�����Ɏg���x�N�g���@�@�@�@�@���������s��
			D3DXVec3TransformCoord(&v[0].Pos, &D3DXVECTOR3(0.0f, 2.4f, 0.0f), &effectMat[i + 1]);
			D3DXVec3TransformCoord(&v[1].Pos, &D3DXVECTOR3(0.0f, 2.4f, 0.0f), &effectMat[i]);
			D3DXVec3TransformCoord(&v[2].Pos, &D3DXVECTOR3(0.0f, 0.1f, 0.0f), &effectMat[i]);
			D3DXVec3TransformCoord(&v[3].Pos, &D3DXVECTOR3(0.0f, 0.1f, 0.0f), &effectMat[i + 1]);
			v[0].Tex = D3DXVECTOR2((float)1 - (1 / 49) * (i + 1), 0.0f);
			v[1].Tex = D3DXVECTOR2((float)1 - (1 / 49) * i, 0.0f);
			v[2].Tex = D3DXVECTOR2((float)1 - (1 / 49) * i, 1.0f);
			v[3].Tex = D3DXVECTOR2((float)1 - (1 / 49) * (i + 1), 1.0f);


			lpD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2/*�|���S���̐�*/, v, sizeof(VERTEX));


		}
		lpD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);//���Z����off//�|����a�l�̋t
																	   /*INV/���]*//*SRC/*//*ALPHA/���l*/
		lpD3DDevice->SetRenderState(D3DRS_LIGHTING, TRUE);//���C�gon
	}
}

bool C_Chara::Render2D(bool DamageFlg)
{
	return false;
}

void C_Chara::TestRender2D()
{
}

D3DXMATRIX C_Chara::GetterCharaMat()
{
	return charaMat;
}

HitElement C_Chara::CharaNowState()
{
	return returnElement;
}

void C_Chara::SetHp(float* Hp, bool& HpDamageSetFlg, const bool& DamageFlg,D3DXMATRIX *hpMat,int Position)
{
	if (DamageFlg == true &&
		HpDamageSetFlg == false)
	{
		if (*Hp > 0)
		{
			if (Position == TOP)
			{
				*Hp -= 20;
				hpMat->_41 += (20 / MAXHP) * HPGAUGEWIDTH;

			}
			else
			{
				*Hp -= 10;
				hpMat->_41 += (10 / MAXHP) * HPGAUGEWIDTH;
			}
			
		}
		if (*Hp < 0)
		{
			*Hp = 0;
		}
		HpDamageSetFlg = true;
		return;
	}
	if (DamageFlg == false)
	{
		HpDamageSetFlg = false;
	}
	return;
}

void C_Chara::SetHp(float* Hp, bool& HpDamageSetFlg, const bool& DamageFlg, int Position)
{
	if (DamageFlg == true &&
		HpDamageSetFlg == false)
	{
		if (Position == TOP)
		{
			*Hp -= 20;
		}
		else
		{
			*Hp -= 10;
		}
		if (*Hp < 0)
		{
			*Hp = 0;
		}
		HpDamageSetFlg = true;
		return;
	}
	if (DamageFlg == false)
	{
		HpDamageSetFlg = false;
	}
	return;
}

bool C_Chara::SurvivalChara(const float* Hp)
{
	if (*Hp <= 0)
	{
		return false;
	}
	return true;
}

bool C_Chara::MakeHitEffect(const float frame, const int motionNum, const D3DXMATRIX* TmpMat, const D3DXVECTOR3* camPos)
{
	if (frame >= 0.8f
		&& motionNum == 1)
	{
		D3DXVECTOR3 TmpPos;
		TmpPos = D3DXVECTOR3(TmpMat->_41, TmpMat->_42, TmpMat->_43);

		/*eff = new C_HitEffect(camPos, &TmpPos);*/
		return true;
	}

	return false;
}

void C_Chara::MakeAttackEffect()
{
	if (returnElement.NowState != ATTACK)
	{
		if (effectStartFlg == true)
		{
			for (int i = 0; i < EFFECTNUM; i++)
			{
				D3DXMatrixIdentity(&effectMat[i]);
			}
			//���������Ă��Ȃ�
			effectStartFlg = false;
		}
	}
	else
	{
		//�G�t�F�N�g�̏��������܂��s���Ă��Ȃ�
		if (effectStartFlg == false)
		{
			//������
			for (int i = 0; i < EFFECTNUM; i++)
			{
				effectMat[i] = katanaMat;
			}
			//����������
			effectStartFlg = true;
		}
		//�G�t�F�N�g�̍s��̔z����쐬
		for (int i = EFFECTNUM - 1; i > 0; i--)
		{
			effectMat[i] = effectMat[i - 1];
		}
		//�G�t�F�N�g��0�Ԗڂɓ��̍s����Z�b�g
		effectMat[0] = katanaMat;
	}
}

void C_Chara::CharaInit()
{
	v[0].Color = D3DCOLOR_ARGB(255, 255, 255, 255);
	v[1].Color = D3DCOLOR_ARGB(255, 255, 255, 255);
	v[2].Color = D3DCOLOR_ARGB(255, 255, 255, 255);
	v[3].Color = D3DCOLOR_ARGB(255, 255, 255, 255);

	//�v���C���[�̍s�񍇐�-----------------------------------------
	//���̍s��@  ���̈ړ��s��       ���̐e�N���X�i�̂̍s��j
	headMat = headTransMat * charaMat;
	//�����̍s��@�����̈ړ��s��     �����̐e�N���X�i�̂̍s��j
	leftLegMat = leftLegTransMat * charaMat;
	//�E���̍s��@�E���̈ړ��s��     �E���̐e�N���X�i�̂̍s��j
	rightLegMat = rightLegTransMat * charaMat;


	katanaElementMat = katanaRotMat * katanaTransMat;
	//���̍s��@  ���̉�]�s��     ���̈ړ��s��       ���̐e�N���X�i�̂̍s��j
	katanaMat = katanaElementMat * charaMat;
	//���r�̍s��@���r�̉�]�s��   ���r�̈ړ��s��     ���r�̐e�N���X�i���̍s��j
	leftArmMat = leftArmRotMat * leftArmTransMat * katanaMat;
	//�E�r�̍s��@�E�r�̉�]�s��   �E�r�̈ړ��s��     �E�r�̐e�N���X�i���̍s��j
	rightArmMat = rightArmRotMat * rightArmTransMat * katanaMat;
	//-------------------------------------------------------------

	//�G�t�F�N�g�̏�����
	for (int i = 0; i < EFFECTNUM; i++)
	{
		D3DXMatrixIdentity(&effectMat[i]);
	}

	//�}�E�X�̏�����
	NowPoint = NORMAL;
	
	//�v���C���[�̏�Ԃ�����ϐ��̏�����
	ZeroMemory(&returnElement, sizeof(returnElement));
}


void C_Chara::MakeCharaMatrix()
{
	//�s�񍇐�-----------------------------------------------------
	charaMat = charaRotMat * charaTransMat;

	katanaMat = katanaElementMat * charaMat;

	//���̍s��@  ���̈ړ��s��      ���̐e�N���X�i�̂̍s��j
	headMat = headTransMat * charaMat;
	//�����̍s��@�����̈ړ��s��    �����̐e�N���X�i�̂̍s��j
	leftLegMat = leftLegTransMat * charaMat;
	//�E���̍s��@�E���̈ړ��s��    �E���̐e�N���X�i�̂̍s��j
	rightLegMat = rightLegTransMat * charaMat;

	//���r�̍s��@���r�̉�]�s��   ���r�̈ړ��s��     ���r�̐e�N���X�i���̍s��j
	leftArmMat = leftArmRotMat * leftArmTransMat * katanaMat;
	//�E�r�̍s��@�E�r�̉�]�s��   �E�r�̈ړ��s��     �E�r�̐e�N���X�i���̍s��j
	rightArmMat = rightArmRotMat * rightArmTransMat * katanaMat;
	//--------------------------------------------------------------------------

}
