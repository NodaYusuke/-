#pragma once
#include"../../SoundBase/soundBase.h"

class C_BGM_WinResult :public C_SoundBase
{
public:
	C_BGM_WinResult();
	~C_BGM_WinResult();
	void PlaySwitch(bool);
private:
	LPDIRECTSOUNDBUFFER8 lpBGM_WinResult;//音を入れる入れ物
	LPDIRECTSOUND3DBUFFER8 lp3DBGM_WinResult;//音の設定データ
};