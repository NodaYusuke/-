#include"mouse.h"


//�}�E�X�̏�����====================
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

	//�����܂ł̍s�ł͉����ςȂ��ɂȂ�
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