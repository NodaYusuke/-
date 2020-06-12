#pragma once
#include"../../SoundBase/soundBase.h"

class C_SE_HitTopAttack :public C_SoundBase
{
public:
	C_SE_HitTopAttack();
	~C_SE_HitTopAttack();
	void PlaySwitch(bool);
private:
	LPDIRECTSOUNDBUFFER8 lpSE_HitTopAttack;//音を入れる入れ物
	LPDIRECTSOUND3DBUFFER8 lp3DSE_HitTopAttack;//音の設定データ

};