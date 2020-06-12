#include"BGM_loseResult.h"

C_BGM_LoseResult::C_BGM_LoseResult()
{
	LoadWAVE3D(lpBGM_LoseResult, lp3DBGM_LoseResult, "DATA/Sound/BGM_Lose.wav");
	lp3DBGM_LoseResult->SetMode(DS3DMODE_DISABLE, DS3D_IMMEDIATE);
	
}

C_BGM_LoseResult::~C_BGM_LoseResult()
{
	lpBGM_LoseResult->Release();
	lp3DBGM_LoseResult->Release();
}

void C_BGM_LoseResult::PlaySwitch(bool Play)
{
	if (Play == true) {
		lpBGM_LoseResult->SetCurrentPosition(0);
		lpBGM_LoseResult->Play(0, 0, DSBPLAY_LOOPING);
	}
	else {
		lpBGM_LoseResult->Stop();
	}
}
