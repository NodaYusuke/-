#pragma once
#include"../../SoundBase/soundBase.h"
class C_SE_PreventsAttacks :public C_SoundBase
{
public:
	C_SE_PreventsAttacks();
	~C_SE_PreventsAttacks();
	void PlaySwitch(bool);
private:
	LPDIRECTSOUNDBUFFER8 lpSE_PreventsAttacks;//音を入れる入れ物
	LPDIRECTSOUND3DBUFFER8 lp3DSE_PreventsAttacks;//音の設定データ

	C_SE_PreventsAttacks* se;
};