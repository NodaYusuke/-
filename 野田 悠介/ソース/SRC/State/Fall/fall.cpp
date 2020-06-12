#include "fall.h"

C_Fall::C_Fall()
{
	setFlg = false;
	animeFrame = 0;
}

C_State* C_Fall::Action(EnemyActionElement* actionElement)
{
	if (setFlg == false)
	{
		setFlg = true;
		startRotMat = *actionElement->RotMat;
		startTransMat = *actionElement->TransMat;
		D3DXMatrixRotationX(&endRotMat, D3DXToRadian(-90));
		endRotMat *= startRotMat;
		D3DXMatrixTranslation(&endTransMat, actionElement->TransMat->_41, 0, actionElement->TransMat->_43);
	}
	if (animeFrame < 1.0f)
	{
		animeFrame += 0.1f;
	}
	
	*actionElement->RotMat = anime.animePric(&startRotMat, &endRotMat, animeFrame);
	*actionElement->TransMat = anime.animePric(&startTransMat, &endTransMat, animeFrame);

	return nullptr;
}

C_State* C_Fall::Action(PlayerActionElement* actionElement)
{
	if (setFlg == false)
	{
		setFlg = true;
		startRotMat = *actionElement->RotMat;
		startTransMat = *actionElement->TransMat;
		D3DXMatrixRotationX(&endRotMat, D3DXToRadian(-90));
		endRotMat *= startRotMat;
		D3DXMatrixTranslation(&endTransMat, actionElement->TransMat->_41, 0, actionElement->TransMat->_43);
	}
	if (animeFrame < 1.0f)
	{
		animeFrame += 0.1f;
	}

	*actionElement->RotMat = anime.animePric(&startRotMat, &endRotMat, animeFrame);
	*actionElement->TransMat = anime.animePric(&startTransMat, &endTransMat, animeFrame);

	return nullptr;
}
