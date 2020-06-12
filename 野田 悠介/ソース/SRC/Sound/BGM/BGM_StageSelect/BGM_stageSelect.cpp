#include "BGM_stageSelect.h"

C_BGM_StageSelect::C_BGM_StageSelect()
{
	LoadWAVE3D(lpBGM_StageSelect, lp3DBGM_StageSelect, "DATA/Sound/BGM_StageSelect3.wav");
	lp3DBGM_StageSelect->SetMode(DS3DMODE_DISABLE, DS3D_IMMEDIATE);
}

C_BGM_StageSelect::~C_BGM_StageSelect()
{
	lpBGM_StageSelect->Release();
	lp3DBGM_StageSelect->Release();
}

void C_BGM_StageSelect::PlaySwitch(bool Play)
{
	if (Play == true) {
		lpBGM_StageSelect->SetCurrentPosition(0);
		lpBGM_StageSelect->Play(0, 0, DSBPLAY_LOOPING);
	}
	else {
		lpBGM_StageSelect->Stop();
	}
}
