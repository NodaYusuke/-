#pragma once
#include"../../SoundBase/soundBase.h"
class C_SE_PreventsAttacks :public C_SoundBase
{
public:
	C_SE_PreventsAttacks();
	~C_SE_PreventsAttacks();
	void PlaySwitch(bool);
private:
	LPDIRECTSOUNDBUFFER8 lpSE_PreventsAttacks;//����������ꕨ
	LPDIRECTSOUND3DBUFFER8 lp3DSE_PreventsAttacks;//���̐ݒ�f�[�^

	C_SE_PreventsAttacks* se;
};