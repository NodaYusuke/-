#include"E_Stay.h"
#include"../Move/E_Move.h"
#include"../Attack/E_Attack.h"

C_E_Stay::C_E_Stay()
{
	animeFrame = 0;
	animeSetFlg = false;
	motionNumber = 0;
	ChagePositionSetFlg = false;
	positionChangFlg = false;
}



C_State* C_E_Stay::Action(EnemyActionElement* actionElement)
{
	StHeel(actionElement->St);

	int nowCommand;
	nowCommand = e_StateManeger.SetNextState(actionElement->playerStack,actionElement->playerStates,actionElement->enemyStates);

	if (nowCommand == ATTACK)
	{
		if (*actionElement->enemyElement->Len < NOTGO + 0.5)
		{
			return new C_E_Attack;
		}
		return new C_E_Move;
	}

	if (ChagePositionSetFlg == false)
	{
		*actionElement->NowPosition=ChangStay(actionElement->playerStack);
		ChagePositionSetFlg = true;
	}
	switch (*actionElement->NowPosition)
	{
	case TOP:
		if (animeSetFlg == false)
		{
			switch (motionNumber)
			{
			case 0:
				endMat = MakeTopStayEndMat();
				startMat = *actionElement->katanaElementMat;
				animeSetFlg = true;
				break;
			case 1:
				endMat = MakeTopAttackPraparationMat();
				startMat = *actionElement->katanaElementMat;
				animeSetFlg = true;
				break;
			}
		}

		*actionElement->katanaElementMat = anime.animePric(&startMat, &endMat, animeFrame);
		//攻撃に移行
		if (motionNumber == 1)
		{
			if (animeFrame >= 1.0f)
			{
			}
		}
		if (animeFrame >= 1.0f)
		{

			//キャラクターを相手の角度に回転
			*actionElement->enemyElement->ToAng = TurnToAng(actionElement->RotMat, *actionElement->enemyElement->ToAng, CHARAANGSPEED);

			return new C_E_Move;

			if (animeFrame >= 1.0f
				&& motionNumber < 1)
			{
			}
			//アニメを進める
			if (animeFrame < 1.0f)
			{
				animeFrame += 0.1f;
			}
			return nullptr;
		}
		break;
	case NORMAL:
		if (animeSetFlg == false)
		{
			endMat = MakeNormalStayEndMat();
			startMat = *actionElement->katanaElementMat;
			animeSetFlg = true;
		}
		break;
	case UNDER:
		if (animeSetFlg == false)
		{
			endMat = MakeUnderStayEndMat();
			startMat = *actionElement->katanaElementMat;
			animeSetFlg = true;
		}
		break;
	}
	*actionElement->katanaElementMat = anime.animePric(&startMat, &endMat, animeFrame);
	//アニメを進める
	if (animeFrame >= 1.0f)
	{
		return new C_E_Move;
	}
	//アニメを進める
	if (animeFrame < 1.0f)
	{
		animeFrame += 0.1f;
	}
	return nullptr;
}
