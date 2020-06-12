#include"BGM_game.h"

C_BGM_Game::C_BGM_Game()
{
	LoadWAVE3D(lpBGM_Game, lp3DBGM_Game, "DATA/Sound/BGM_Game.wav");
	lp3DBGM_Game->SetMode(DS3DMODE_DISABLE, DS3D_IMMEDIATE);
}

C_BGM_Game::~C_BGM_Game()
{
	lpBGM_Game->Release();
	lp3DBGM_Game->Release();
}

void C_BGM_Game::PlaySwitch(bool Play)
{
	if (Play == true) {
		lpBGM_Game->SetCurrentPosition(0);
		lpBGM_Game->Play(0, 0, DSBPLAY_LOOPING);
	}
	else {
		lpBGM_Game->Stop();
	}
}
