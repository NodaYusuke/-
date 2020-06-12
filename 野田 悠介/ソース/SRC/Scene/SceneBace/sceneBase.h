#pragma once
#include"../../function.h"
#include"../../extern.h"
#include"../../numDecision.h"
//シーンの親クラス
//継承して使う
class C_SceneBase
{
public:
	virtual ~C_SceneBase();
	virtual bool Update(void);
	virtual void Render3D(void);
	virtual void Render2D(void);
	virtual void SetCamera(void);
	void Frame(void);
	bool EscTitle(void);
protected:
	bool EscKeyFlg;
};