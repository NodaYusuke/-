#pragma once
#include"../../SoundBase/soundBase.h"

class C_BGM_LoseResult :public C_SoundBase
{
public:
	C_BGM_LoseResult();
	~C_BGM_LoseResult();
	void PlaySwitch(bool);
private:
	LPDIRECTSOUNDBUFFER8 lpBGM_LoseResult;//音を入れる入れ物
	LPDIRECTSOUND3DBUFFER8 lp3DBGM_LoseResult;//音の設定データ
};