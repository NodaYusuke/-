#pragma once
#include"../SceneBace/sceneBase.h"
//ChangScene‚Énew‚·‚é‚±‚Æ‚ÅƒV[ƒ“‚ğØ‚è‘Ö‚¦‚é‚±‚Æ‚ª‚Å‚«‚é
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