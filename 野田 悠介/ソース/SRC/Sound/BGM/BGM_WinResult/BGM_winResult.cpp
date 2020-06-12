#include"BGM_winResult.h"

C_BGM_WinResult::C_BGM_WinResult()
{
	LoadWAVE3D(lpBGM_WinResult, lp3DBGM_WinResult, "DATA/Sound/BGM_Win.wav");
	lp3DBGM_WinResult->SetMode(DS3DMODE_DISABLE, DS3D_IMMEDIATE);
}

C_BGM_WinResult::~C_BGM_WinResult()
{
	lpBGM_WinResult->Release();
	lp3DBGM_WinResult->Release();
}

void C_BGM_WinResult::PlaySwitch(bool Play)
{
	if (Play == true) {
		lpBGM_WinResult->SetCurrentPosition(0);
		lpBGM_WinResult->Play(0, 0, DSBPLAY_LOOPING);
	}
	else {
		lpBGM_WinResult->Stop();
	}
}