#pragma once
#include"../../SoundBase/soundBase.h"

class C_SE_TopAttack :public C_SoundBase
{
public:
	C_SE_TopAttack();
	~C_SE_TopAttack();
	void PlaySwitch(bool);
private:
	LPDIRECTSOUNDBUFFER8 lpSE_TopAttack;//����������ꕨ
	LPDIRECTSOUND3DBUFFER8 lp3DSE_TopAttack;//���̐ݒ�f�[�^
	
};