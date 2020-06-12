#pragma once
#include"../function.h"
#include"../extern.h"
#include"../numDecision.h"
#include"../Mouse/mouse.h"
#include"../State/state.h"
#include"../State/Fall/fall.h"
//#include"../HitEffect/hirEffect.h"

//�L�����N�^�[�̊��N���X
//Update�֐��̓v���C���[�̍s�������߂�֐�
/*�߂�l�͓����蔻��ɕK�v�ȍ\����*/
//Render3D�֐��̓v���C���[��\������֐�
/*�����Ƃ���damageFlg�������Ă������ƂōU�����󂯂��Ƃ��F���ς��*/
/*false:�ʏ� true:�Ԃ��_��*/
//GetterCharaMat�֐��͌Ăяo�����N���X�̃L�����N�^�[�̍s���Ԃ�
//CharaNowState�֐��͓����蔻��ɕK�v�ȏ���Ԃ�

class C_Chara
{
public:
	C_Chara();
	~C_Chara();
	virtual HitElement Update(charaElement charaElement);
	virtual HitElement Update(charaElement charaElement, const StateStack* playerStack, States *player);
    void Render3D(bool DamageFlg);
	virtual bool Render2D(bool DamageFlg);
	virtual void TestRender2D();
	D3DXMATRIX GetterCharaMat();
	HitElement CharaNowState();
	void SetHp(float* Hp, bool &HpDamageSetFlg, const bool& DamegeFlg,D3DXMATRIX *hpMat, int Position);
	void SetHp(float* Hp, bool &HpDamageSetFlg, const bool& DamegeFlg, int Position);
	bool SurvivalChara(const float* Hp);
	bool MakeHitEffect(const float frame, const int motionNum, const D3DXMATRIX* katanaMat, const D3DXVECTOR3* camPos);
	void MakeAttackEffect();
	void CharaInit();
	void MakeCharaMatrix();
	virtual const StateStack* ReturnStack() { return nullptr; }
	//�̗͂�Ԃ�
	virtual float HPGetter() { float tmpNum = 0; return tmpNum; }
	//�X�^�~�i��Ԃ�
	virtual float STGetter() { float tmpNum = 0; return tmpNum; }
protected:
	//�\���p�̕ϐ�-----------------------------------
	Color red{ 255,0,0 };
	//���̕ϐ�
	D3DXMATRIX katanaRotMat;  //���̉�]�s��
	D3DXMATRIX katanaTransMat;//���̈ړ��s��
	D3DXMATRIX katanaMat;     //���̉�]�s��
	D3DXMATRIX katanaElementMat;//�ړ��Ɖ�]�̍����s��
	XFILE katanaMesh;         //���̃��b�V���f�[�^
	//���̕ϐ�r
	D3DXMATRIX headMat;       //���̍s��
	D3DXMATRIX headTransMat;  //���̈ړ��s��
	XFILE headMesh;           //���̃��b�V���f�[�^
	//�̂̕ϐ�
	D3DXMATRIX charaMat;       //�̂̍s��
	D3DXMATRIX charaTransMat;  //�̂̍s��
	D3DXMATRIX charaRotMat;    //�̂̍s��
	XFILE bodyMesh;           //�̂̃��b�V���f�[�^
	//���̕ϐ�
	D3DXMATRIX leftLegMat;     //�����̍s��
	D3DXMATRIX leftLegTransMat;//�����̈ړ��s��
	D3DXMATRIX rightLegMat;     //�E���̍s��
	D3DXMATRIX rightLegTransMat;//�E���̈ړ��s��
	XFILE legMesh;              //���̃��b�V���f�[�^
	//�r�̕ϐ�
	D3DXMATRIX leftArmRotMat;   //���r�̉�]�s��
	D3DXMATRIX leftArmTransMat; //���r�̈ړ��s��
	D3DXMATRIX leftArmMat;      //���r�̍s��
	D3DXMATRIX rightArmRotMat;  //�E�r�̉�]�s��
	D3DXMATRIX rightArmTransMat;//�E�r�̈ړ��s��
	D3DXMATRIX rightArmMat;     //�E�r�̍s��
	XFILE armMesh;              //�r�̃��b�V���f�[�^
	//�G�t�F�N�g�p�̕ϐ�--------------------------
	bool               effectStartFlg;/*�G�t�F�N�g�̏��������s�������ǂ���*/
	VERTEX             v[4];
	D3DXMATRIX         effectMat[EFFECTNUM];/*�G�t�F�N�g�p�̍s��*/
	LPDIRECT3DTEXTURE9 effectTex;
	//�s���p�̕ϐ�---------------------------------
	C_State* NowState; //�����ڂ��Ă���s��
	C_State* NextState;//���ꂩ�瓋�ڂ��邢��s��
	C_Mouse mouse;     //�}�E�X�̈ʒu��Ԃ��N���X
	int  NowPoint;     //���݂̃}�E�X�̈ʒu
	
	
	HitElement    returnElement;//�߂�l�p�̕ϐ�
	bool attaclTapFlg;//�������ŘA���s����h�~����悤
	//HP�p
	LPDIRECT3DTEXTURE9 hpTex;
	D3DXMATRIX hpMat;
	float Hp;/*�L�����N�^�[���Ƃ̗̑�*/
	bool HpDamageSetFlg;

	//ST�p
	LPDIRECT3DTEXTURE9 stTex;
	D3DXMATRIX stMat;
	float St;/*�L�����N�^�[���Ƃ̃X�^�~�i*/

	//ST�p
	LPDIRECT3DTEXTURE9 st_NotStateTex;

	//COVER�p
	LPDIRECT3DTEXTURE9 coverTex;
	D3DXMATRIX coverMat;

	/*C_HitEffect* eff;*/

	bool effActivateFlg;
	bool endActionSetFlg;

	int duelPosition;

	int nowMove;
};