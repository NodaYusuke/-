#pragma once
#include"../../extern.h"
#include"../../function.h"
#include<dsound.h>
#include"../../Wavread/wavread.h"
#pragma comment(lib,"dsound.lib")
class C_SoundBase
{
public:
	C_SoundBase() ;
	~C_SoundBase();
	virtual void PlaySwitch(bool);
};