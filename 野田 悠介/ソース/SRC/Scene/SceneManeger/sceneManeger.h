#pragma once
#include"../SceneBace/sceneBase.h"
//ChangScene��new���邱�ƂŃV�[����؂�ւ��邱�Ƃ��ł���
class C_SceneManeger
{
public:
	C_SceneManeger();
	~C_SceneManeger();
	void NowScene(void);
	void ChangScene(C_SceneBase* NewScene);
private:
	C_SceneBase *Scene;
};