#pragma once
#include"../../SoundBase/soundBase.h"

class C_SE_HitNormalAttack :public C_SoundBase
{
public:
	C_SE_HitNormalAttack();
	~C_SE_HitNormalAttack();
	void PlaySwitch(bool);
private:
	LPDIRECTSOUNDBUFFER8 lpSE_HitNormalAttack;//����������ꕨ
	LPDIRECTSOUND3DBUFFER8 lp3DSE_HitNormalAttack;//���̐ݒ�f�[�^

};