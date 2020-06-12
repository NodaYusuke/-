#include "SE_normalAttack.h"

C_SE_NormalAttack::C_SE_NormalAttack()
{
	LoadWAVE3D(lpSE_NormalAttack, lp3DSE_NormalAttack, "DATA/Sound/SE_NormalAttack.wav");
	lp3DSE_NormalAttack->SetMode(DS3DMODE_DISABLE, DS3D_IMMEDIATE);
}

C_SE_NormalAttack::~C_SE_NormalAttack()
{
	lpSE_NormalAttack->Release();
	lp3DSE_NormalAttack->Release();
}

void C_SE_NormalAttack::PlaySwitch(bool Play)
{

	if (Play == true) {
		lpSE_NormalAttack->SetCurrentPosition(0);
		lpSE_NormalAttack->Play(0, 0, 0);
	}
	else {
		lpSE_NormalAttack->Stop();
	}
}
