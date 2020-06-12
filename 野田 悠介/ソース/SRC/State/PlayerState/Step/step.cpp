#include "step.h"
#include"../Stay/stay.h"

C_Step::C_Step()
{
	D3DXMatrixIdentity(&stepMat);
	ZeroMemory(&stepVec, sizeof(&stepVec));
	stepTime = STEPTIME;
	setFlg = false;
}

HitElement C_Step::GetCharaState()
{
	HitElement returnElement;
	SetHitElement(&returnElement, OTHER, STEP, OTHER, OTHER);
	return returnElement;
}

C_State* C_Step::Action(PlayerActionElement* actionElement)
{
	if (setFlg == false)
	{
		StepStackUpdate(actionElement->playerStack);

		setFlg = true;
		if (*actionElement->nowMove == REVERSE)
		{
			D3DXVec3TransformNormal(&stepVec, &D3DXVECTOR3(0.0f, 0.0f, -STEPSPEED), actionElement->RotMat);
			D3DXMatrixTranslation(&stepMat, stepVec.x, stepVec.y, stepVec.z);
		}
		if (*actionElement->nowMove == LEFT)
		{
			D3DXVec3TransformNormal(&stepVec, &D3DXVECTOR3(SIDESTEPSPEED, 0.0f, 0.0f), actionElement->RotMat);
			D3DXMatrixTranslation(&stepMat, stepVec.x, stepVec.y, stepVec.z);
		}
		if (*actionElement->nowMove == RIGHT)
		{
			D3DXVec3TransformNormal(&stepVec, &D3DXVECTOR3(-SIDESTEPSPEED, 0.0f, 0.0f), actionElement->RotMat);
			D3DXMatrixTranslation(&stepMat, stepVec.x, stepVec.y, stepVec.z);
		}
	}

	*actionElement->TransMat = stepMat * *actionElement->TransMat;
	
	//playerを回転させる
	D3DXMatrixRotationY(actionElement->RotMat, D3DXToRadian(*actionElement->playerElement->ToAng));

	//ステップ時間が残されている
	if (stepTime > 0)
	{
		//時間の減少
		stepTime--;
		return nullptr;
	}

	return new C_Stay();
}


