#pragma once
#include"../function.h"
#include"../numDecision.h"
#include"../Anime/anime.h"
#include"../Mouse/mouse.h"
#include"../Mouse/mouse.h"
#include"../Sound/SoundBase/soundBase.h"
#include"EnemyState/EnemyStateManeger/enemyStateManeger.h"

//��Ԃ�\�����N���X

class C_State
{
public:
	C_State();
	//�L�����N�^�[�̃N���X�ŌĂяo�����ƂŁA    
	//���[�V�������s����A�N�V�����֐��̉��z�֐�
	virtual C_State* Action(EnemyActionElement *enemyActionElement);
	virtual C_State* Action(PlayerActionElement *playerActionElement);
	//�߂�l�Ƃ��ē����蔻��̍\���̂����֐�
	virtual HitElement GetCharaState();

	virtual void Render2D(void);
    //////�U�����[�V�������쐬����֐�----------
	D3DXMATRIX MakeMotionMat(MakeMotionElement makeMotionElement);
	////���i
	//�ҋ@	
	D3DXMATRIX MakeNormalStayEndMat();
	//�U���̏I���
	D3DXMATRIX MakeNormalAttackEndMat();

	////��i
	D3DXMATRIX MakeTopStayEndMat();
	//�U������
	D3DXMATRIX MakeTopAttackPraparationMat();
	//�U���r��
	D3DXMATRIX MakeTopAttackHalfwayMat();
	//�U���̏I���
	D3DXMATRIX MakeTopAttackEndMat();
	//�U�����͂����ꂽ���̏I���
	D3DXMATRIX MakeT_PreventsAttackEndMat();

	////���i
	//�ҋ@
	D3DXMATRIX MakeUnderStayEndMat();
	//�U������
	D3DXMATRIX MakeUnderAttackPraparationMat();
	//�U���r��
	D3DXMATRIX MakeUnderAttackHalfwayMat();
	//�U���̏I���
	D3DXMATRIX MakeUnderAttackEndMat();
	
	////stack�֘A�̏㉺�֐�
	void PositionStackUpUpdate(int* Stack);
	void PositionStackDownUpdate(int* Stack);
	void PositionStackUpdate(StateStack* playerStack, int nowPoint);
	void AttackStackUpdate(StateStack* playerStack);
	void GuardStackUpdate(StateStack* playerStack);
	void StepStackUpdate(StateStack* playerStack);

	////�ړ����ɒ��f���čU�����s���Ƃ��̊֐�

	//�ړ���̎��̍s�������߂�֐�
	/*�}�E�X�̈ʒu�ɉ����Ė߂�l���ς��*/
	//�G�l�~�[
	int ChangStay(const StateStack* playerStack);
	int MostBigStack(const StateStack* playerStack);

	////�ړ����ɕǂ���o�Ă��܂�Ȃ��悤�ɂ���֐�
	/*bool CanReverse(const D3DXMATRIX* charaMat);*/
	//�G�̃X�^�~�i�����炷�֐�
	bool SetStDecrease(float& St, bool& StDecreaseSetFlg,D3DXMATRIX &stMat);
	//���@�̃X�^�~�i�����炷�֐�
	bool SetStDecrease(float& St, bool& StDecreaseSetFlg);

	//�G�̃X�^�~�i���񕜂���֐�
	void StHeel(float& St, D3DXMATRIX& stMat);
	//���@�̃X�^�~�i���񕜂���֐�
	void StHeel(float * St);

	//�����蔻��̕ϐ����Z�b�g����֐�
	void SetHitElement(HitElement *hitElement,int nowPoint,int nowState,int motionNumber,float frame);
	
	//��x����
	bool PushKeyFlg(bool* tapFlg, int  *tapCnt, bool* timeSetFlg);
	//�{�^���������Ă��邩�ǂ���
	bool MovePushKeyFlg();

	
protected:
	//animation�̃N���X
	C_Anime anime;

	//�}�E�X�̈ʒu�̃N���X
	C_Mouse mouse;

	//�X�^�~�i���Z�b�g�������ǂ����̃t���O
	bool    StDecreaseSetFlg;
	
	//����炷�N���X
	C_SoundBase* se;

	//�G�̍s�������߂�N���X
	C_E_StateManeger e_StateManeger;
	
};