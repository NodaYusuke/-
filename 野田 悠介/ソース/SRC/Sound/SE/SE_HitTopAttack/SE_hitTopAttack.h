#pragma once
#include"../../SoundBase/soundBase.h"

class C_SE_HitTopAttack :public C_SoundBase
{
public:
	C_SE_HitTopAttack();
	~C_SE_HitTopAttack();
	void PlaySwitch(bool);
private:
	LPDIRECTSOUNDBUFFER8 lpSE_HitTopAttack;//‰¹‚ğ“ü‚ê‚é“ü‚ê•¨
	LPDIRECTSOUND3DBUFFER8 lp3DSE_HitTopAttack;//‰¹‚Ìİ’èƒf[ƒ^

};