#pragma once
#include"include.h"
struct VERTEX
{
	D3DXVECTOR3 Pos;

	D3DCOLOR Color;

	D3DXVECTOR2 Tex;
};

struct XFILE
{
	LPD3DXMESH lpMesh;	//���b�V���̌`��̃f�[�^

	DWORD NumMaterial;	//�O���[�v�̌�

	D3DMATERIAL9 *Mat;	//�}�e���A���̓��e�@���@�O���[�v��

	LPDIRECT3DTEXTURE9 *Tex;	//�e�N�X�`���̓��e�@���@�O���[�v��
};

struct Color
{
	float r;
	float g;
	float b;
};
struct MakeMotionElement
{
	float angX;
	float angY;
	float angZ;
	D3DXVECTOR3 WeaponPos;
};

struct States
{
	const float* ST;
	const float* HP;
};

//�L�����N�^�[�̍s���ɂ���đ�������stack��
//�܂Ƃ߂�\����
struct StateStack
{
	int topStack;   //��i��stack//�؂�ւ��A���Ԍo�߂ő���
	int normalStack;//���i��stack//�؂�ւ��A���Ԍo�߂ő���
	int underStack; //���i��stack//�؂�ւ��A���Ԍo�߂ő���
	int attackStack;//�U����stack//�U���񐔂ő���
	int guardStack; //�h���stack//�h��񐔂ő���
	int stepStack;  //�����stack//����񐔂ő���
};

//�����蔻��̍\����
struct HitElement
{
	float animeFrame;//�A�j���̐i�s�x
	int   NowState;  //�U�����Ă��邩�ǂ���
	int   nowMotion;
	int   Position;  //�ǂ��̍s����
};

struct HitAttackElement
{
	const HitElement &myElement;
	const HitElement &duelElement;
	int* damageCnt;
	bool AttackHitFlg;
};
//chara�쐬���Ɏ󂯓n���\����
struct charaElement
{
	const D3DXMATRIX *duelMat;
	const HitElement *duelElement;
	bool AttackHitFlg;
	const float* Len;
	float* ToAng;//����܂ł̉�]�p�x
	bool* duelDamageFlg;
	D3DXVECTOR3 *camPos;          /*�J�����̍��W*/
};
//State�N���X��Action�֐��̈���
struct EnemyActionElement
{
	D3DXMATRIX* katanaElementMat;/*���̍s��*/
	D3DXMATRIX* katanaTransMat;  /*���̈ړ��s��*/
	D3DXMATRIX* katanaRotMat;    /*���̉�]�s��*/
	D3DXMATRIX* charaMat;        /*�L�����̍s��*/
	D3DXMATRIX* RotMat;          /*�L�����̉�]�s��*/
	D3DXMATRIX* TransMat;        /*�L�����̈ړ��s��*/
	D3DXMATRIX* stMat;           /*�X�^�~�i�\���p�̍s��*/
	float* St;                   /*�X�^�~�i*/
	charaElement* enemyElement;  /*�L�����쐬���ɓn���ϐ�*/
	int* nowMove;                /*���݂̈ړ�����*/
	const StateStack* playerStack;/*player��Stack*/
	int* NowPosition;
	int* MoveWay;/*��������*/
	States* playerStates;
	States* enemyStates;
};

struct PlayerActionElement
{
	D3DXMATRIX* katanaElementMat;/*���̍s��*/
	D3DXMATRIX* katanaTransMat;  /*���̈ړ��s��*/
	D3DXMATRIX* katanaRotMat;    /*���̉�]�s��*/
	D3DXMATRIX* charaMat;        /*�L�����̍s��*/
	D3DXMATRIX* RotMat;          /*�L�����̉�]�s��*/
	D3DXMATRIX* TransMat;        /*�L�����̈ړ��s��*/
	D3DXMATRIX* stMat;           /*�X�^�~�i�\���p�̍s��*/
	float* St;                   /*�X�^�~�i*/
	bool* attackTapFlg;	         /*�U���{�^���������Ă��邩�ǂ����̃t���O*/
	StateStack* playerStack;     /*�v���C���[��stack*/
	charaElement *playerElement; /*�L�����쐬���ɓn���ϐ�*/
	int* nowMove;                /*���݂̈ړ�����*/
	int* NowPoint;               /*�}�E�X�̈ʒu*/
};

