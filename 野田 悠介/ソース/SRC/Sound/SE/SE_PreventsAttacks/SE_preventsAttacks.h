#pragma once
#include"../../SoundBase/soundBase.h"
class C_SE_PreventsAttacks :public C_SoundBase
{
public:
	C_SE_PreventsAttacks();
	~C_SE_PreventsAttacks();
	void PlaySwitch(bool);
private:
	LPDIRECTSOUNDBUFFER8 lpSE_PreventsAttacks;//‰¹‚ğ“ü‚ê‚é“ü‚ê•¨
	LPDIRECTSOUND3DBUFFER8 lp3DSE_PreventsAttacks;//‰¹‚Ìİ’èƒf[ƒ^

	C_SE_PreventsAttacks* se;
};