#include "E_Attack.h"
#include"../../../Sound/SE/SE_TopAttack/SE_topAttack.h"
#include"../../../Sound/SE/SE_NormalAttack/SE_normalAttack.h"
#include"../../../Sound/SE/SE_UnderAttack/SE_underAttack.h"
#include"../../EnemyState/Stay/E_Stay.h"
C_E_Attack::C_E_Attack()
{
	animeFrame = 0;
	animeSetFlg = false;
	motionNumber = 0;
	//switch ()
	//{
	//case TOP:
	//	se = new C_SE_TopAttack();
	//	break;
	//case NORMAL:
	//	se = new C_SE_NormalAttack();
	//	break;
	//case UNDER:
	//	se = new C_SE_UnderAttack();
	//	break;
	//}
	//se->PlaySwitch(true);

}

HitElement C_E_Attack::GetCharaState()
{
	HitElement returnElement;
	SetHitElement(&returnElement, OTHER, ATTACK, motionNumber, animeFrame);
	return returnElement;
}

C_E_Attack::~C_E_Attack()
{
	//delete se;
}

C_State* C_E_Attack::Action(EnemyActionElement* actionElement)
{
	if (SetStDecrease(*actionElement->St, StDecreaseSetFlg) == false)
	return new C_E_Stay();

	switch (*actionElement->NowPosition)
	{
	case TOP:
		if (animeSetFlg == false)//�A�j���̍s��͍쐬����Ă��Ȃ�
		{
			switch (motionNumber)
			{
			case 0:
				startMat = *actionElement->katanaElementMat;
				endMat = MakeTopAttackHalfwayMat();
				animeSetFlg = true;
				break;
			case 1:
				startMat = *actionElement->katanaElementMat;
				endMat = MakeTopAttackEndMat();
				animeSetFlg = true;
				break;
			}
		}

		//�A�j����i�߂�
		if (animeFrame < 1.0f)
		{
			animeFrame += 0.2f;
		}

		*actionElement->katanaElementMat = anime.animePric(&startMat, &endMat, animeFrame);

		//�A�j�����I������
		//���̏�ԂɈڍs
		if (animeFrame >= 1.0f)
		{
			if (motionNumber == 0)
			{
				animeSetFlg = false;
				animeFrame = 0;
				motionNumber++;
			}
			else
			{
				e_StateManeger.ResetCommand();
				return new C_E_Stay();
			}
		}
		break;
	case NORMAL:
		if (animeSetFlg == false)//�A�j���̍s��͍쐬����Ă��Ȃ�
		{
			startMat = *actionElement->katanaElementMat;
			endMat = MakeNormalAttackEndMat();
			animeSetFlg = true;
		}
		*actionElement->katanaElementMat = anime.animePric(&startMat, &endMat, animeFrame);
		//�A�j����i�߂�
		if (animeFrame < 1.0f)
		{
			animeFrame += 0.1f;
		}
		//�A�j�����I������
		if (animeFrame > 1.0f)
		{
			animeFrame = 1.0f;
		}
		//���̏�ԂɈڍs
		if (animeFrame >= 1.0f)
		{
			e_StateManeger.ResetCommand();
			return new C_E_Stay();
		}
		break;
	case UNDER:
		if (animeSetFlg == false)//�A�j���̍s��͍쐬����Ă��Ȃ�
		{
			startMat = *actionElement->katanaElementMat;
			endMat = MakeUnderAttackEndMat();
			animeSetFlg = true;
		}

		//�A�j����i�߂�
		if (animeFrame < 1.0f)
		{
			animeFrame += 0.1f;
		}

		*actionElement->katanaElementMat = anime.animePric(&startMat, &endMat, animeFrame);

		//�A�j�����I������
		if (animeFrame > 1.0f)
		{
			animeFrame = 1.0f;
		}
		//���̏�ԂɈڍs
		if (animeFrame >= 1.0f)
		{
			e_StateManeger.ResetCommand();
			return new C_E_Stay();
		}
		break;
	}
	return nullptr;
}


