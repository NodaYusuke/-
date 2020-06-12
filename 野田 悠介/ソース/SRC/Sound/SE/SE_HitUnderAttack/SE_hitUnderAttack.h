#pragma once
#include"../../SoundBase/soundBase.h"

class C_SE_HitUnderAttack :public C_SoundBase
{
public:
	C_SE_HitUnderAttack();
	~C_SE_HitUnderAttack();
	void PlaySwitch(bool);
private:
	LPDIRECTSOUNDBUFFER8 lpSE_HitUnderAttack;//音を入れる入れ物
	LPDIRECTSOUND3DBUFFER8 lp3DSE_HitUnderAttack;//音の設定データ

};