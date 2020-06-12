#include "topGuard.h"
#include"../../Stay/stay.h"

C_TopGuard::C_TopGuard()
{
	animeFrame = 0;
	animeSetFlg = false;
	nowMotion = 0;
}

HitElement C_TopGuard::GetCharaState()
{
	HitElement returnElememt;
	returnElememt.NowState = GUARD;
	returnElememt.Position = TOP;
	returnElememt.nowMotion = 0;
	returnElememt.animeFrame = animeFrame;
	return returnElememt;
}

D3DXMATRIX MakeTopGuardEndMat()
{
	D3DXVECTOR3 tmpPos;
	D3DXMATRIX transMat, returnMat;
	D3DXMATRIX rotMat[4];
	float tmpAngX, tmpAngY, tmpAngZ;

	tmpPos = D3DXVECTOR3(1.0f, 3.2f, 0.0f);
	tmpAngX =  0;
	tmpAngY = 90;
	tmpAngZ = 90;
	D3DXMatrixRotationX(&rotMat[1], D3DXToRadian(tmpAngX));
	D3DXMatrixRotationY(&rotMat[2], D3DXToRadian(tmpAngY));
	D3DXMatrixRotationZ(&rotMat[3], D3DXToRadian(tmpAngZ));
	rotMat[0] = rotMat[1] * rotMat[2] * rotMat[3];
	D3DXMatrixTranslation(&transMat, tmpPos.x, tmpPos.y, tmpPos.z);
	returnMat = rotMat[0] * transMat;

	return returnMat;
}

C_State* C_TopGuard::Action(PlayerActionElement *actionElement)
{
	if (animeSetFlg == false)//アニメの行列は作成されていない
	{
		GuardStackUpdate(actionElement->playerStack);
		//モーションを作成
		startMat = *actionElement->katanaElementMat;
		saveMat = startMat;
		endMat = MakeTopGuardEndMat();
		animeSetFlg = true;
	}
	if (animeFrame < 1.0f)
	{
		//アニメを進める
		animeFrame += 0.1f;
	}
	*actionElement->katanaElementMat = anime.animePric(&startMat, &endMat, animeFrame);

	if (animeFrame > 1.0f)
	{
		animeFrame = 1.0f;
	}
	//次の状態に移行
	if (GetAsyncKeyState(VK_RBUTTON))
	{
		return nullptr;
	}
	else
	{
		return new C_Stay();
	}
	return nullptr;
}
