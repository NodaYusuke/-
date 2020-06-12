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
	//�N�H�[�^�j�I���ϐ�//��]�̂�------------------------------
	D3DXMATRIX nowMat = *startMat;
	D3DXQUATERNION startQuo,/*�͂���*/
		           endQuo,  /*�I���*/
		           nowQuo   /*���ݒn*/;
	//�s����N�H�[�^�j�I���ɕς���
	D3DXQuaternionRotationMatrix(&startQuo, startMat);
	D3DXQuaternionRotationMatrix(&endQuo, endMat);
	//���Ԃ̉�]�����߂�
	//                  ����     �ŏ��@�@ �@�Ō�    ���݂̐i�s�x
	D3DXQuaternionSlerp(&nowQuo, &startQuo, &endQuo, animeFrame);
	//�N�H�[�^�j�I�����s��ɖ߂�
	D3DXMatrixRotationQuaternion(&nowMat, &nowQuo);
	//-------------------------------------------------------------

	//�ړ�---------------------------------------------------------
	D3DXVECTOR3 startPos, endPos, nowPos;
	//�s����x�N�g���ɒ���
	startPos = D3DXVECTOR3(startMat->_41, startMat->_42, startMat->_43);
	endPos = D3DXVECTOR3(endMat->_41, endMat->_42, endMat->_43);

	D3DXVec3Lerp(&nowPos, &startPos, &endPos, animeFrame);
	//--------------------------------------------------------------

	nowMat._41 = nowPos.x;
	nowMat._42 = nowPos.y;
	nowMat._43 = nowPos.z;
	return nowMat;
}