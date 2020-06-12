#pragma once
#include"../../SoundBase/soundBase.h"

class C_SE_TopAttack :public C_SoundBase
{
public:
	C_SE_TopAttack();
	~C_SE_TopAttack();
	void PlaySwitch(bool);
private:
	LPDIRECTSOUNDBUFFER8 lpSE_TopAttack;//音を入れる入れ物
	LPDIRECTSOUND3DBUFFER8 lp3DSE_TopAttack;//音の設定データ
	
};