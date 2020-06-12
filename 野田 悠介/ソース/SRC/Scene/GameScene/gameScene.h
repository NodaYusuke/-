#pragma once
#include"../SceneBace/sceneBase.h"
#include"../../Chara/chara.h"
#include"../../Stage/stage.h"
#include"../../MeshLei/meshLei.h"
#include"../../Camera/camera.h"
#include"../../Sound/BGM/BGM_Game/BGM_game.h"
//�Q�[���V�[��//sceneBase�̔h���N���X
//AttackHitAng�֐��͍U���������邩�ǂ������ׂ�
//SetCharaElement�֐��͍\���̂ɕϐ����Z�b�g����
//GetTargetVecAng�֐��̓^�[�Q�b�g�܂ł̊p�x�𒲂ׂ�
//AttackGuard�֐��͍U�����h�䂳�ꂽ���ǂ������ׂ�
//HitAttack�֐��͑��肪�U�������炤��Ԃ����ׂ�
//charaDamageInvincibleTime�֐��̓L�������U�����󂯂���̖��G���Ԃ��Ǘ�����
class C_Game :public C_SceneBase
{
public:
	C_Game();
	~C_Game();
	bool Update();
	void Render3D();
	void Render2D();
	void SetCamera();
	bool AttackHitAng(float TargetAng, float Len);
	void SetCharaElement(charaElement* chraElement,const  D3DXMATRIX *duelMat, const HitElement *duelElement, bool AttackHitFlg, const float* Len, float* ToAng,bool* danmageFlg,D3DXVECTOR3* camPos);
	float GetTargetVecAng(const D3DXMATRIX* charaMat, D3DXVECTOR3 targetVec);
	bool AttackGuard(int NowState, int NowPosition, int duelNowPosition, int* damageCnt);
	bool HitAttack(HitAttackElement charaHitAttackElement);
	void charaDamageInvincibleTime(bool* damageFlg, int* damageCnt);
	bool StartTexCntSetCamea(C_Camera & camera ,int &battleStartTexCnt,const D3DXMATRIX &playerMat, const D3DXMATRIX& enemyMat,const D3DXVECTOR3 & pos );
private:
	D3DLIGHT9 Light;	 //�Ɩ�
	C_Stage   stage;     //�X�e�[�W�̃N���X
	C_MeshLei meshLei;   //���b�V�����C�̃N���X
	C_Camera  camera;    //�J�����̃N���X
	std::vector<C_Chara*>chara;//�L�����N�^�[�̃N���X

	//�J�����̃e�X�g�p�ϐ�
	D3DXVECTOR3 TestPos;  //�e�X�g�p���W
	D3DXVECTOR3 cameraVec;//�e�X�g�p�x�N�g��
	
	//player�֘A----------------------------------
	bool playerFlg;            /*player�������Ă邩�ǂ���*/
	bool playerDamageFlg=false;/*�U�����󂯂����ǂ���*/
	bool playerAttackHitFlg;
	//--------------------------------------------
	//enemy�֘A------------------------------------
	bool enemyFlg;            /*�G�������Ă��邩�ǂ���*/
	bool enemyDamageFlg=false;/*�U�����󂯂����ǂ���*/
	bool enemyAttackHitFlg;
	//---------------------------------------------

	int damageCnt[2];    /*�F���ς�鎞��*/
	float Target;/*�G�Ƃ̋����@-1�͂������Ă��Ȃ�*/

	//text�\���p
	LPDIRECT3DTEXTURE9 winBattleEndTex[3];
	D3DXMATRIX winBattleEndTexMat[3];

	LPDIRECT3DTEXTURE9 loseBattleEndTex[3];
	D3DXMATRIX loseBattleEndTexMat[3];

	D3DXMATRIX BattleEndTexTransMat[2];
	D3DXMATRIX BattleEndTexScaleMat[2];


	float scaleSize[2];
	//�킢�������Ă���
	/*true�Ōp���@false�ŏI��*/
	bool battleContinuedFlg;

	//�퓬�J�n���ɕ\�������摜�̕ϐ�
	LPDIRECT3DTEXTURE9 battleStartTex[2];
	D3DXMATRIX battleStartTexMat;
	int battleStartTexCnt;/*�\������鎞��*/

	LPDIRECT3DTEXTURE9 timeTex;
	D3DXMATRIX timeTexMat[3];
	int timeCnt;

	C_BGM_Game* bgm;

	D3DXVECTOR3 camPos;
};