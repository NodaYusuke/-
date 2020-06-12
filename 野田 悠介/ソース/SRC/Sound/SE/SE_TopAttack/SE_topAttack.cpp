#include "SE_topAttack.h"

C_SE_TopAttack::C_SE_TopAttack()
{
	LoadWAVE3D(lpSE_TopAttack, lp3DSE_TopAttack,"DATA/Sound/SE_TopAttack.wav");
	lp3DSE_TopAttack->SetMode(DS3DMODE_DISABLE, DS3D_IMMEDIATE);
}

C_SE_TopAttack::~C_SE_TopAttack()
{
	lpSE_TopAttack->Release();
	lp3DSE_TopAttack->Release();
}

void C_SE_TopAttack::PlaySwitch(bool Play)
{
	
	if (Play==true) {
		lpSE_TopAttack->SetCurrentPosition(0);
		lpSE_TopAttack->Play(0, 0, 0);
	}
	else {
		lpSE_TopAttack->Stop();
	}
}
