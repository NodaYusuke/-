#pragma once
#include"../../SoundBase/soundBase.h"

class C_BGM_StageSelect :public C_SoundBase
{
public:
	C_BGM_StageSelect();
	~C_BGM_StageSelect();
	void PlaySwitch(bool);
private:
	LPDIRECTSOUNDBUFFER8 lpBGM_StageSelect;//‰¹‚ğ“ü‚ê‚é“ü‚ê•¨
	LPDIRECTSOUND3DBUFFER8 lp3DBGM_StageSelect;//‰¹‚Ìİ’èƒf[ƒ^
};