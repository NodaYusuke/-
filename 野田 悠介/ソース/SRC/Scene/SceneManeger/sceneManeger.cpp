#include"sceneManeger.h"

C_SceneManeger::C_SceneManeger()
{
	Scene = nullptr;
}
C_SceneManeger::~C_SceneManeger()
{
	if (Scene != nullptr)
	{
		delete Scene;
	}
}
void C_SceneManeger::NowScene(void)
{
	if (Scene != nullptr)
	{
		Scene->Frame();
	}
}

void C_SceneManeger::ChangScene(C_SceneBase *NewScene)
{
	if (Scene != nullptr)
	{
		delete Scene;
	}
	Scene = NewScene;
}