#pragma once
#include"../../SoundBase/soundBase.h"

class C_BGM_WinResult :public C_SoundBase
{
public:
	C_BGM_WinResult();
	~C_BGM_WinResult();
	void PlaySwitch(bool);
private:
	LPDIRECTSOUNDBUFFER8 lpBGM_WinResult;//‰¹‚ğ“ü‚ê‚é“ü‚ê•¨
	LPDIRECTSOUND3DBUFFER8 lp3DBGM_WinResult;//‰¹‚Ìİ’èƒf[ƒ^
};