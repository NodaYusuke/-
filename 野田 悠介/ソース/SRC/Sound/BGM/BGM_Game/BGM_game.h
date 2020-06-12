#pragma once
#include"../../SoundBase/soundBase.h"

class C_BGM_Game :public C_SoundBase
{
public:
	C_BGM_Game();
	~C_BGM_Game();
	void PlaySwitch(bool);
private:
	LPDIRECTSOUNDBUFFER8 lpBGM_Game;//音を入れる入れ物
	LPDIRECTSOUND3DBUFFER8 lp3DBGM_Game;//音の設定データ
};
