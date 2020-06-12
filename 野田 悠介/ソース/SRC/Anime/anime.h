#pragma once
#include<d3dx9.h>
//アニメーション用のクラス
//animePric関数に引数としてstartMat,endMat,animeFrameを渡すことでアニメを作成するクラス
class C_Anime
{
public:
	C_Anime();
	~C_Anime();
	D3DXMATRIX animePric(const D3DXMATRIX* startMat, const D3DXMATRIX* endMat, float animeFrame);
};
