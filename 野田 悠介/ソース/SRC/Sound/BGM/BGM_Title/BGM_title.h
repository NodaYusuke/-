#pragma once
#include"../../SoundBase/soundBase.h"

class C_BGM_Title :public C_SoundBase
{
public:
	C_BGM_Title();
	~C_BGM_Title();
	void PlaySwitch(bool);
private:
	LPDIRECTSOUNDBUFFER8 lpBGM_Title;//音を入れる入れ物
	LPDIRECTSOUND3DBUFFER8 lp3DBGM_Title;//音の設定データ
};
