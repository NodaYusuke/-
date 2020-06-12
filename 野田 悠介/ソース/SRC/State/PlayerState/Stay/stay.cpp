#include "stay.h"
#include"../Attack/attack.h"
#include"../Guard/TopGuard/topGuard.h"
#include"../Move/move.h"

C_Stay::C_Stay()
{
	animeFrame = 0;
	animeSetFlg = false;
	startPoint = mouse.Update();
	motionNumber = 0;
}

HitElement C_Stay::GetCharaState()
{
	HitElement returnElement;
	SetHitElement(&returnElement, startPoint, STAY, motionNumber, animeFrame);
	return returnElement;
}

C_State* C_Stay::Action(PlayerActionElement* actionElement)
{
	StHeel(*actionElement->St, *actionElement->stMat);

	PositionStackUpdate(actionElement->playerStack, startPoint);
	
	switch (startPoint)
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
				return new C_Attack();
			}
		}
		if (animeFrame >= 1.0f)
		{
			//キャラクターを相手の角度に回転
			*actionElement->playerElement->ToAng = TurnToAng(actionElement->RotMat, *actionElement->playerElement->ToAng, CHARAANGSPEED);

			if (*actionElement->NowPoint== NORMAL)
			{
				return new C_Stay();
			}
			//攻撃準備
			if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
			{
				if (*actionElement->attackTapFlg == false)
				{
					*actionElement->attackTapFlg = true;
					animeSetFlg = false;
					animeFrame = 0;
					motionNumber++;
				}
			}
			else
			{
				*actionElement->attackTapFlg = false;
			}

			if (animeFrame >= 1.0f
				&& motionNumber < 1)
			{
				if (GetAsyncKeyState(VK_RBUTTON) & 0x8000)
				{
					return new C_TopGuard();
				}
				int NowPoint = mouse.Update();

				if (NowPoint != startPoint)
				{
					return new C_Stay();
				}

				//移動処理
				if (MovePushKeyFlg() == true)
				{
					return new C_Move;
				}
			}
			if (animeFrame >= 1.0f)
			{
			    //キャラクターを相手の角度に回転
				*actionElement->playerElement->ToAng = TurnToAng(actionElement->RotMat, *actionElement->playerElement->ToAng, CHARAANGSPEED);
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
			//キャラクターを相手の角度に回転
			*actionElement->playerElement->ToAng = TurnToAng(actionElement->RotMat, *actionElement->playerElement->ToAng, CHARAANGSPEED);

			//攻撃
			if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
			{
				if (*actionElement->attackTapFlg == false)
				{
					return new C_Attack();
				}
			}
			else
			{
				*actionElement->attackTapFlg = false;
			}
			int NowPoint = mouse.Update();

			if (NowPoint != startPoint)
			{
				return new C_Stay();
			}
			//移動処理
			if (MovePushKeyFlg() == true)
			{
				return new C_Move;
			}
		}
		//アニメを進める
		if (animeFrame < 1.0f)
		{
			animeFrame += 0.1f;
		}
		return nullptr;
}