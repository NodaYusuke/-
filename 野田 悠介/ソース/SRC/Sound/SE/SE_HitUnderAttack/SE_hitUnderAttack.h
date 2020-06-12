#pragma once
#include"../../SoundBase/soundBase.h"

class C_SE_HitUnderAttack :public C_SoundBase
{
public:
	C_SE_HitUnderAttack();
	~C_SE_HitUnderAttack();
	void PlaySwitch(bool);
private:
	LPDIRECTSOUNDBUFFER8 lpSE_HitUnderAttack;//‰¹‚ğ“ü‚ê‚é“ü‚ê•¨
	LPDIRECTSOUND3DBUFFER8 lp3DSE_HitUnderAttack;//‰¹‚Ìİ’èƒf[ƒ^

};