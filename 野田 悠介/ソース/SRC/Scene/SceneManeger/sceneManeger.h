#pragma once
#include"../SceneBace/sceneBase.h"
//ChangSceneにnewすることでシーンを切り替えることができる
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