#pragma once
#include"../../SoundBase/soundBase.h"

class C_SE_HitUnderAttack :public C_SoundBase
{
public:
	C_SE_HitUnderAttack();
	~C_SE_HitUnderAttack();
	void PlaySwitch(bool);
private:
	LPDIRECTSOUNDBUFFER8 lpSE_HitUnderAttack;//����������ꕨ
	LPDIRECTSOUND3DBUFFER8 lp3DSE_HitUnderAttack;//���̐ݒ�f�[�^

};