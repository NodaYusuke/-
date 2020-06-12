#include "SE_hitUnderAttack.h"

C_SE_HitUnderAttack::C_SE_HitUnderAttack()
{
	LoadWAVE3D(lpSE_HitUnderAttack, lp3DSE_HitUnderAttack, "DATA/Sound/SE_HitUnderAttack.wav");
	lp3DSE_HitUnderAttack->SetMode(DS3DMODE_DISABLE, DS3D_IMMEDIATE);
}

C_SE_HitUnderAttack::~C_SE_HitUnderAttack()
{
	lpSE_HitUnderAttack->Release();
	lp3DSE_HitUnderAttack->Release();
}

void C_SE_HitUnderAttack::PlaySwitch(bool Play)
{

	if (Play == true) {
		lpSE_HitUnderAttack->SetCurrentPosition(0);
		lpSE_HitUnderAttack->Play(0, 0, 0);
	}
	else {
		lpSE_HitUnderAttack->Stop();
	}
}
