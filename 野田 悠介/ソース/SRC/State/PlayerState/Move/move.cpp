#include "Move.h"
#include"../Stay/stay.h"
#include"../Step/step.h"
#include"../Attack/attack.h"
enum { A = 0, S, D };

C_Move::C_Move()
{
	outFlg = false;
	timeSetFlg = false;
	tapFlg[A] = false;
	tapFlg[S] = false;
	tapFlg[D] = false;
	tapCnt = 0;
}

HitElement C_Move::GetCharaState()
{
	HitElement returnElememt;
	SetHitElement(&returnElememt, OTHER, MOVE, OTHER, OTHER);
	return returnElememt;
}



C_State* C_Move::Action(PlayerActionElement *actionElement)
{
	StHeel(*actionElement->St, *actionElement->stMat);

	//移動攻撃
	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
	{
		if (*actionElement->attackTapFlg == false)
		{
			return new C_Attack();
		}
	}

	D3DXVECTOR3 tmpVec;

	D3DXVec3TransformNormal(&tmpVec, &D3DXVECTOR3(0.0f, 0.0f, 0.0f), actionElement->RotMat);

	//playerを回転させる
	D3DXMatrixRotationY(actionElement->RotMat, D3DXToRadian(*actionElement->playerElement->ToAng));

	if (GetAsyncKeyState('W') & 0x8000)
	{
		//キャラクターの移動行列の作成
		D3DXVec3TransformNormal(&tmpVec, &D3DXVECTOR3(0.0f, 0.0f, MOVESPEED), actionElement->RotMat);
		if (*actionElement->playerElement->Len < NOTGO + MOVESPEED)
		{
			D3DXVec3TransformNormal(&tmpVec, &D3DXVECTOR3(0.0f, 0.0f, *actionElement->playerElement->Len - NOTGO), actionElement->RotMat);
		}
	}
	
	if (GetAsyncKeyState('S') & 0x8000)
	{
		if (outFlg == true
			&& tapCnt > 0
			&& tapFlg[S] == true)
		{
			return new C_Step();
		}
		//キャラクターの移動行列の作成
		D3DXVec3TransformNormal(&tmpVec, &D3DXVECTOR3(0.0f, 0.0f, -MOVESPEED), actionElement->RotMat);
		tapFlg[S] = true;
	}
	else
	{
		if (tapFlg[S] == true)
		{
			outFlg = true;
		}
	}
	if (GetAsyncKeyState('A') & 0x8000)
	{
		if (outFlg == true
			&& tapCnt > 0
			&& tapFlg[A] == true)
		{
			return new C_Step();
		}
		//キャラクターの移動行列の作成
		D3DXVec3TransformNormal(&tmpVec, &D3DXVECTOR3(-SIDEMOVESPEED, 0.0f, 0.0f), actionElement->RotMat);
		tapFlg[A] = true;
	}
	else
	{
		if (tapFlg[A] == true)
		{
			outFlg = true;
		}
	}
	if (GetAsyncKeyState('D') & 0x8000)
	{
		if (outFlg == true
			&& tapCnt > 0
			&& tapFlg[D] == true)
		{
			return new C_Step();
		}
		//キャラクターの移動行列の作成
		D3DXVec3TransformNormal(&tmpVec, &D3DXVECTOR3(SIDEMOVESPEED, 0.0f, 0.0f), actionElement->RotMat);
		tapFlg[D] = true;
	}
	else
	{
		if (tapFlg[D] == true)
		{
			outFlg = true;
		}
	}
	if (PushKeyFlg(tapFlg,&tapCnt,&timeSetFlg) == true)
	{
	D3DXMATRIX tmpMat;/*改造用の行列*/
	D3DXMatrixTranslation(&tmpMat, tmpVec.x, tmpVec.y, tmpVec.z);

	*actionElement->TransMat = tmpMat * *actionElement->TransMat;

	if ((actionElement->TransMat)->_41 < -(POLYSIZE / 2) * POLYNUM - OVERSTAGELENMARGIN)
	{
		(actionElement->TransMat)->_41 = -(POLYSIZE / 2) * POLYNUM - OVERSTAGELENMARGIN;
	}
	if ((actionElement->TransMat)->_41 > (POLYSIZE / 2)* POLYNUM + OVERSTAGELENMARGIN)
	{
		(actionElement->TransMat)->_41 = (POLYSIZE / 2) * POLYNUM + OVERSTAGELENMARGIN;
	}
	if ((actionElement->TransMat)->_43 < -(POLYSIZE / 2) * POLYNUM - OVERSTAGELENMARGIN)
	{
		(actionElement->TransMat)->_43 = -(POLYSIZE / 2) * POLYNUM - OVERSTAGELENMARGIN;
	}
	if ((actionElement->TransMat)->_43 > (POLYSIZE / 2) * POLYNUM + OVERSTAGELENMARGIN)
	{
		(actionElement->TransMat)->_43 = (POLYSIZE / 2) * POLYNUM + OVERSTAGELENMARGIN;
	}
	
	
	if (tapCnt > 0)
	{
		tapCnt--;
	}
	else
	{
		tapFlg[A] = false;
		tapFlg[S] = false;
		tapFlg[D] = false;
		timeSetFlg = false;
	}
		return nullptr;
	}

	return new C_Stay;
}