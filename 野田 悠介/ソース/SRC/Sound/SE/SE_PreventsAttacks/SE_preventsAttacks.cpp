#include "SE_preventsAttacks.h"

C_SE_PreventsAttacks::C_SE_PreventsAttacks()
{
	LoadWAVE3D(lpSE_PreventsAttacks, lp3DSE_PreventsAttacks, "DATA/Sound/SE_PreventsAttacks.wav");
	lp3DSE_PreventsAttacks->SetMode(DS3DMODE_DISABLE, DS3D_IMMEDIATE);
}

C_SE_PreventsAttacks::~C_SE_PreventsAttacks()
{
	lpSE_PreventsAttacks->Release();
	lp3DSE_PreventsAttacks->Release();
}

void C_SE_PreventsAttacks::PlaySwitch(bool Play)
{

	if (Play == true) {
		lpSE_PreventsAttacks->SetCurrentPosition(0);
		lpSE_PreventsAttacks->Play(0, 0, 0);
	}
	else {
		lpSE_PreventsAttacks->Stop();
	}
}
