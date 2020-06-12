#include"attack.h"
#include"../../../Sound/SE/SE_TopAttack/SE_topAttack.h"
#include"../../../Sound/SE/SE_NormalAttack/SE_normalAttack.h"
#include"../../../Sound/SE/SE_UnderAttack/SE_underAttack.h"
#include"../Stay/stay.h"




C_Attack::C_Attack()
{
	NowPoint = mouse.Update();
	animeFrame  = 0;
	animeSetFlg = false;
	motionNumber = 0;
	switch (NowPoint)
	{
	case TOP:
		se = new C_SE_TopAttack();
		break;
	case NORMAL:
		se = new C_SE_NormalAttack();
		break;
	case UNDER:
		se = new C_SE_UnderAttack();
		break;
	}
	se->PlaySwitch(true);

	StackUpdateFlg = false;
}

C_Attack::~C_Attack()
{
	delete se;
}

HitElement C_Attack::GetCharaState()
{
	HitElement returnElement;
	SetHitElement(&returnElement, NowPoint, ATTACK, motionNumber, animeFrame);
	return returnElement;
}


C_State* C_Attack::Action(PlayerActionElement *actionElement)
{
	
	if (StackUpdateFlg == false)
	{
		AttackStackUpdate(actionElement->playerStack);
		StackUpdateFlg = true;
	}

	if (SetStDecrease(*actionElement->St, StDecreaseSetFlg, *actionElement->stMat) == false)
	return new C_Stay();

	switch (NowPoint)
	{
	case TOP:
		if (animeSetFlg == false)//アニメの行列は作成されていない
		{
			switch (motionNumber)
			{
			case 0:
				startMat = *actionElement->katanaElementMat;
				endMat = MakeTopAttackHalfwayMat();
				animeSetFlg = true;
				*actionElement->attackTapFlg = true;
				break;
			case 1:
				startMat = *actionElement->katanaElementMat;
				endMat = MakeTopAttackEndMat();
				animeSetFlg = true;
				break;
			}
		}

		//アニメを進める
		if (animeFrame < 1.0f)
		{
			animeFrame += 0.2f;
		}

		*actionElement->katanaElementMat = anime.animePric(&startMat, &endMat, animeFrame);

		//アニメが終了した
		//次の状態に移行
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
				return new C_Stay();
			}
		}
		break;
	case NORMAL:
		if (animeSetFlg == false)//アニメの行列は作成されていない
		{
			startMat = *actionElement->katanaElementMat;
			endMat = MakeNormalAttackEndMat();
			animeSetFlg = true;
			*actionElement->attackTapFlg = true;
		}
		*actionElement->katanaElementMat = anime.animePric(&startMat, &endMat, animeFrame);
		//アニメを進める
		if (animeFrame < 1.0f)
		{
			animeFrame += 0.1f;
		}
		//アニメが終了した
		if (animeFrame > 1.0f)
		{
			animeFrame = 1.0f;
		}
		//次の状態に移行
		if (animeFrame >= 1.0f)
		{
			return new C_Stay();
		}
		break;
	case UNDER:
		if (animeSetFlg == false)//アニメの行列は作成されていない
		{
			startMat = *actionElement->katanaElementMat;
			endMat = MakeUnderAttackEndMat();
			animeSetFlg = true;
			*actionElement->attackTapFlg = true;
		}

		//アニメを進める
		if (animeFrame < 1.0f)
		{
			animeFrame += 0.1f;
		}

		*actionElement->katanaElementMat = anime.animePric(&startMat, &endMat, animeFrame);

		//アニメが終了した
		if (animeFrame > 1.0f)
		{
			animeFrame = 1.0f;
		}
		//次の状態に移行
		if (animeFrame >= 1.0f)
		{
			return new C_Stay();
		}
		break;
	}
	return nullptr;
}