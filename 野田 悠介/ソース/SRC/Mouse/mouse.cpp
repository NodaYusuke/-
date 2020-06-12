#include"mouse.h"


//マウスの初期化====================
C_Mouse::C_Mouse()
{
	BasePt.x = 640;
	BasePt.y = 360;
	ClientToScreen(hwnd, &BasePt);
}
C_Mouse::~C_Mouse()
{

}
 int C_Mouse::Update()
{
	POINT Pt;
	GetCursorPos(&Pt);

	//ここまでの行では回りっぱなしになる
	if ((Pt.y - BasePt.y) < -100)
	{
		return TOP;
	}
	
	if ((Pt.y - BasePt.y) > 100)
	{
		return UNDER;
	}
	return NORMAL;
}