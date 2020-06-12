#pragma once
#include"../../SoundBase/soundBase.h"

class C_BGM_Game :public C_SoundBase
{
public:
	C_BGM_Game();
	~C_BGM_Game();
	void PlaySwitch(bool);
private:
	LPDIRECTSOUNDBUFFER8 lpBGM_Game;//‰¹‚ğ“ü‚ê‚é“ü‚ê•¨
	LPDIRECTSOUND3DBUFFER8 lp3DBGM_Game;//‰¹‚Ìİ’èƒf[ƒ^
};
