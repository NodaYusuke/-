#include"BGM_title.h"

C_BGM_Title::C_BGM_Title()
{
	LoadWAVE3D(lpBGM_Title, lp3DBGM_Title, "DATA/Sound/BGM_Title.wav");
	lp3DBGM_Title->SetMode(DS3DMODE_DISABLE, DS3D_IMMEDIATE);
}

C_BGM_Title::~C_BGM_Title()
{
	lpBGM_Title->Release();
	lp3DBGM_Title->Release();
}

void C_BGM_Title::PlaySwitch(bool Play)
{
	if (Play==true) {
		lpBGM_Title->SetCurrentPosition(0);
		lpBGM_Title->Play(0, 0, DSBPLAY_LOOPING);
	}
	else {
		lpBGM_Title->Stop();
	}
}
