#pragma once

#define	SCRW		    1280   // �E�B���h�E��  �iWidth
#define	SCRH		    720    // �E�B���h�E�����iHeight
#define	FVF_VERTEX (D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1)

const int MISS = -1;            /*�����Ă��Ȃ�*/
const float NOTGO = 4.0f;       /*����ȏ�ߊ��Ȃ�����*/
const float LIMITLENGH = 20.0f;       /*����ȏ�ߊ��Ȃ�����*/
const int LIMITLEN = 15;        /*�G������ȏ�͊���Ȃ�����*/
const int EFFECTNUM = 50;       /*�U���G�t�F�N�g�̃|���S������*/
const float POLYNUM = 5.0f;      /*�X�e�[�W�̃|���S���̖���*/
const float POLYSIZE = 10.0f;
const int   DAMEAGECNTNUM = 10;  /*�U�����ꂽ���̖��G����*/
const float MOVESPEED = 0.15f;   /*�ړ����x*/
const float SIDEMOVESPEED = 0.2f;/*�ړ����x*/
const float STEPSPEED = 0.4f;    /*�X�e�b�v���x*/
const float SIDESTEPSPEED = 0.6f;/*���X�e�b�v���x*/
const int STEPTIME = 10;         /*�X�e�b�v����*/
const int STEPKEYTIME = 30;      /*�X�e�b�v�̎�t����*/
const int ATTACKMOTIONEND = 2;   /*�U���̃��[�V�����̐�*/
const int GUARDMOTIONEND = 2;    /*�h��̃��[�V�����̐�*/
const float CHARAANGSPEED = 2.0f;/*�L�����N�^�[�̉�]���x*/
const int   TESTATTACKCNT = 120; /*�e�X�g�p�̂Ă��̍U���p�x*/

const int TEXTALPHASWICHCNT = 60;/*�^�C�g���̃e�L�X�g�̓_�ŕp�x*/
const int BATTLESTARTTEXCNTNUM = 120;/*�킢���J�n�������Ƀe�L�X�g��\�����鎞��*/

const int LIMITTIME = 10800;
const int TIMETEXSIZEX = 50;
const float SCALESIZE = 1.5f;

const float GAUGEPOSX = 10.0f;/*�o�[��X���W*/
const float MAXHP = 100.0f;/*�ő�̗�*/
const float HPGAUGEWIDTH = 550.0f;  /*HP�o�[�̉��̒���*/
const float HPGAUGEHEIGHT = 50.0f; /*HP�o�[�̏c�̒���*/

const float MAXST = 100.0f;/*�ő�X�^�~�i*/
const float STGAUGEWIDTH = 550.0f;  /*HP�o�[�̉��̒���*/
const float STGAUGEHEIGHT = 25.0f; /*HP�o�[�̏c�̒���*/
const float STHEELNUM = 0.2f;
const int   STCOLORCHAGECNT = 60;

const int EFFECTRENDERTIME=60;/*�G�t�F�N�g���\������鎞��*/

const int CHAGENEXTSTAYTIMEMIN = 100;
const int CHAGENEXTSTAYTIMEMAX = 10;

const int OTHER = -1;
const float OVERSTAGELENMARGIN = -5;

const int attackUpPoint = 5;


//stack�֘A
const int POSITIONSTACKDOWNSPEED = 1;//�������x
const int POSITIONSTACKUPSPEED = 5;//�������x

const int OTHERSTACKUPSPEED = 100;//�������x
const int OTHERSTACKDOWNSPEED = 50;//�������x

const int STACKMAXRIMIT = 1200;//�ő�l

const int MOVEWAYCHAGECNT = 30;

const int ATTACKRANDNUM = 10;

const int RANDOMSEED = 50;

const int UPATTACKRIMIT = 10;

const enum { TOP = 0, NORMAL, UNDER };
const enum { STAY = 0,STEP,MOVE, ATTACK,GUARD ,};
const enum { FORWARD = 0, REVERSE, LEFT, RIGHT };