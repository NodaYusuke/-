#include "E_Move.h"
#include"../Stay/E_Stay.h"
#include"../Attack/E_Attack.h"
C_E_Move::C_E_Move()
{
	moveCnt = rand() % 30 + MOVEWAYCHAGECNT;
	wayFlg = false;
}

HitElement C_E_Move::GetCharaState()
{
	HitElement returnElememt;
	SetHitElement(&returnElememt, OTHER, MOVE, OTHER, OTHER);
	return returnElememt;
}

C_State* C_E_Move::Action(EnemyActionElement* actionElement)
{
	StHeel(actionElement->St);

	int nowCommand;
	nowCommand = e_StateManeger.SetNextState(actionElement->playerStack, actionElement->playerStates, actionElement->enemyStates);

	D3DXVECTOR3 tmpVec;

	D3DXVec3TransformNormal(&tmpVec, &D3DXVECTOR3(0.0f, 0.0f, 0.0f), actionElement->RotMat);

	//playerを回転させる
	D3DXMatrixRotationY(actionElement->RotMat, D3DXToRadian(*actionElement->enemyElement->ToAng));

	if (nowCommand == ATTACKCOM)
	{
		*actionElement->MoveWay = FORWARD;
	}

	e_StateManeger.MoveWayDecision(actionElement->MoveWay,&nowCommand,&wayFlg,actionElement->St);

	switch (*actionElement->MoveWay)
	{
	case FORWARD:
		//キャラクターの移動行列の作成
		D3DXVec3TransformNormal(&tmpVec, &D3DXVECTOR3(0.0f, 0.0f, MOVESPEED), actionElement->RotMat);
		if (*actionElement->enemyElement->Len < NOTGO + MOVESPEED)
		{
			D3DXVec3TransformNormal(&tmpVec, &D3DXVECTOR3(0.0f, 0.0f, *actionElement->enemyElement->Len - NOTGO), actionElement->RotMat);
		}
		break;
	case REVERSE:
		D3DXVec3TransformNormal(&tmpVec, &D3DXVECTOR3(0.0f, 0.0f, -MOVESPEED), actionElement->RotMat);
		break;
	case RIGHT:
		D3DXVec3TransformNormal(&tmpVec, &D3DXVECTOR3(-SIDEMOVESPEED, 0.0f, 0.0f), actionElement->RotMat);
		break;
	case LEFT:
		D3DXVec3TransformNormal(&tmpVec, &D3DXVECTOR3(SIDEMOVESPEED, 0.0f, 0.0f), actionElement->RotMat);
		break;
	}
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
	if ((actionElement->TransMat)->_43 > (POLYSIZE / 2)* POLYNUM + OVERSTAGELENMARGIN)
	{
		(actionElement->TransMat)->_43 = (POLYSIZE / 2) * POLYNUM + OVERSTAGELENMARGIN;
	}

	if (nowCommand == ATTACKCOM
		&& *actionElement->enemyElement->Len <= NOTGO + 0.5)
	{
		return new C_E_Attack;
	}

	if (moveCnt > 0)
	{
		moveCnt--;
		return nullptr;
	}
	e_StateManeger.ResetCommand();
	return new C_E_Stay;
}
