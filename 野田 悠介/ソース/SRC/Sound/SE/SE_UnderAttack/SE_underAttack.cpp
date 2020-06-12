#include "SE_underAttack.h"

C_SE_UnderAttack::C_SE_UnderAttack()
{
	LoadWAVE3D(lpSE_UnderAttack, lp3DSE_UnderAttack, "DATA/Sound/SE_UnderAttack.wav");
	lp3DSE_UnderAttack->SetMode(DS3DMODE_DISABLE, DS3D_IMMEDIATE);
}

C_SE_UnderAttack::~C_SE_UnderAttack()
{
	lpSE_UnderAttack->Release();
	lp3DSE_UnderAttack->Release();
}

void C_SE_UnderAttack::PlaySwitch(bool Play)
{

	if (Play == true) {
		lpSE_UnderAttack->SetCurrentPosition(0);
		lpSE_UnderAttack->Play(0, 0, 0);
	}
	else {
		lpSE_UnderAttack->Stop();
	}
}
