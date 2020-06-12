#include"anime.h"
C_Anime::C_Anime()
{
	//D3DXMatrixIdentity()
}

C_Anime::~C_Anime()
{
}

D3DXMATRIX C_Anime::animePric(const D3DXMATRIX* startMat,const D3DXMATRIX * endMat,float animeFrame)
{
	//クォータニオン変数//回転のみ------------------------------
	D3DXMATRIX nowMat = *startMat;
	D3DXQUATERNION startQuo,/*はじめ*/
		           endQuo,  /*終わり*/
		           nowQuo   /*現在地*/;
	//行列をクォータニオンに変える
	D3DXQuaternionRotationMatrix(&startQuo, startMat);
	D3DXQuaternionRotationMatrix(&endQuo, endMat);
	//中間の回転を求める
	//                  現在     最初　　 　最後    現在の進行度
	D3DXQuaternionSlerp(&nowQuo, &startQuo, &endQuo, animeFrame);
	//クォータニオンを行列に戻す
	D3DXMatrixRotationQuaternion(&nowMat, &nowQuo);
	//-------------------------------------------------------------

	//移動---------------------------------------------------------
	D3DXVECTOR3 startPos, endPos, nowPos;
	//行列をベクトルに直す
	startPos = D3DXVECTOR3(startMat->_41, startMat->_42, startMat->_43);
	endPos = D3DXVECTOR3(endMat->_41, endMat->_42, endMat->_43);

	D3DXVec3Lerp(&nowPos, &startPos, &endPos, animeFrame);
	//--------------------------------------------------------------

	nowMat._41 = nowPos.x;
	nowMat._42 = nowPos.y;
	nowMat._43 = nowPos.z;
	return nowMat;
}