#pragma once
#include"../../SoundBase/soundBase.h"

class C_SE_UnderAttack :public C_SoundBase
{
public:
	C_SE_UnderAttack();
	~C_SE_UnderAttack();
	void PlaySwitch(bool);
private:
	LPDIRECTSOUNDBUFFER8 lpSE_UnderAttack;//音を入れる入れ物
	LPDIRECTSOUND3DBUFFER8 lp3DSE_UnderAttack;//音の設定データ

};