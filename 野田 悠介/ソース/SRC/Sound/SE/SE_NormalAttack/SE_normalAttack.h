#pragma once
#include"../../SoundBase/soundBase.h"

class C_SE_NormalAttack :public C_SoundBase
{
public:
	C_SE_NormalAttack();
	~C_SE_NormalAttack();
	void PlaySwitch(bool);
private:
	LPDIRECTSOUNDBUFFER8 lpSE_NormalAttack;//����������ꕨ
	LPDIRECTSOUND3DBUFFER8 lp3DSE_NormalAttack;//���̐ݒ�f�[�^

};