#pragma once
#include<d3dx9.h>
//�A�j���[�V�����p�̃N���X
//animePric�֐��Ɉ����Ƃ���startMat,endMat,animeFrame��n�����ƂŃA�j�����쐬����N���X
class C_Anime
{
public:
	C_Anime();
	~C_Anime();
	D3DXMATRIX animePric(const D3DXMATRIX* startMat, const D3DXMATRIX* endMat, float animeFrame);
};
