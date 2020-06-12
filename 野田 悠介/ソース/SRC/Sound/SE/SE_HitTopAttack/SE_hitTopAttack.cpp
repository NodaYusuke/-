#include "SE_hitTopAttack.h"

C_SE_HitTopAttack::C_SE_HitTopAttack()
{
	LoadWAVE3D(lpSE_HitTopAttack, lp3DSE_HitTopAttack, "DATA/Sound/SE_HitTopAttack.wav");
	lp3DSE_HitTopAttack->SetMode(DS3DMODE_DISABLE, DS3D_IMMEDIATE);
}

C_SE_HitTopAttack::~C_SE_HitTopAttack()
{
	lpSE_HitTopAttack->Release();
	lp3DSE_HitTopAttack->Release();
}

void C_SE_HitTopAttack::PlaySwitch(bool Play)
{

	if (Play == true) {
		lpSE_HitTopAttack->SetCurrentPosition(0);
		lpSE_HitTopAttack->Play(0, 0, 0);
	}
	else {
		lpSE_HitTopAttack->Stop();
	}
}
