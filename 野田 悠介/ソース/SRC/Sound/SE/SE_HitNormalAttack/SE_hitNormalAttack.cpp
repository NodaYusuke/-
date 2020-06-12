#include "SE_hitNormalAttack.h"

C_SE_HitNormalAttack::C_SE_HitNormalAttack()
{
	LoadWAVE3D(lpSE_HitNormalAttack, lp3DSE_HitNormalAttack, "DATA/Sound/SE_HitNormalAttack.wav");
	lp3DSE_HitNormalAttack->SetMode(DS3DMODE_DISABLE, DS3D_IMMEDIATE);
}

C_SE_HitNormalAttack::~C_SE_HitNormalAttack()
{
	lpSE_HitNormalAttack->Release();
	lp3DSE_HitNormalAttack->Release();
}

void C_SE_HitNormalAttack::PlaySwitch(bool Play)
{

	if (Play == true) {
		lpSE_HitNormalAttack->SetCurrentPosition(0);
		lpSE_HitNormalAttack->Play(0, 0, 0);
	}
	else {
		lpSE_HitNormalAttack->Stop();
	}
}
