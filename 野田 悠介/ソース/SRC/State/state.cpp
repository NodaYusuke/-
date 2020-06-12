#include"state.h"
#include"PlayerState/Attack/attack.h"
#include"PlayerState/Stay/stay.h"

C_State::C_State()
{
	StDecreaseSetFlg = false;
	ZeroMemory(&se, sizeof(&se));
}

C_State* C_State::Action(EnemyActionElement *enemyActionElement)
{
	return nullptr;
}

C_State* C_State::Action(PlayerActionElement* playerActionElement)
{
	return nullptr;
}

HitElement C_State ::GetCharaState()
{
	HitElement TmpElement;
	ZeroMemory(&TmpElement, sizeof(TmpElement));
	TmpElement.Position = mouse.Update();
	return TmpElement;
}

void C_State::Render2D(void)
{
}

//////ƒ‚[ƒVƒ‡ƒ“‚Ìì¬ŠÖ”
D3DXMATRIX C_State::MakeMotionMat(MakeMotionElement makeMotionElement)
{
	D3DXVECTOR3 tmpPos;
	tmpPos = makeMotionElement.WeaponPos;

	D3DXMATRIX transMat, rotMat, returnMat;
	D3DXMatrixTranslation(&transMat, tmpPos.x, tmpPos.y, tmpPos.z);

	D3DXMatrixRotationYawPitchRoll(&rotMat, D3DXToRadian(makeMotionElement.angY), D3DXToRadian(makeMotionElement.angX), D3DXToRadian(makeMotionElement.angZ));

	returnMat = rotMat * transMat;

	return returnMat;
}
////’†’i
//‘Ò‹@
D3DXMATRIX C_State::MakeNormalStayEndMat()
{
	D3DXMATRIX returnMat;
	MakeMotionElement tmpMotionElement;
	tmpMotionElement = { 45, 0, 0,D3DXVECTOR3(0.0f, 0.5f, 1.2f) };
	returnMat = MakeMotionMat(tmpMotionElement);
	return returnMat;
}
//UŒ‚
D3DXMATRIX C_State::MakeNormalAttackEndMat()
{
	D3DXMATRIX returnMat;
	MakeMotionElement tmpMotionElement;
	tmpMotionElement = { 60, 0, 0,D3DXVECTOR3(0.0f, 0.5f, 3.0f) };
	returnMat = MakeMotionMat(tmpMotionElement);
	return returnMat;
}
////ã’i
//‘Ò‹@
D3DXMATRIX C_State::MakeTopStayEndMat()
{
	D3DXMATRIX returnMat;
	MakeMotionElement tmpMotionElement;
	tmpMotionElement = { -70, 0, 0,D3DXVECTOR3(0.0f, 3.5f, 0.0f) };
	returnMat = MakeMotionMat(tmpMotionElement);
	return returnMat;
}
//UŒ‚€”õ
D3DXMATRIX C_State::MakeTopAttackPraparationMat()
{
	D3DXMATRIX returnMat;
	MakeMotionElement tmpMotionElement;
	tmpMotionElement = { -100, 0, 0,D3DXVECTOR3(0.0f, 3.7f, -0.6f) };
	returnMat = MakeMotionMat(tmpMotionElement);
	return returnMat;
}
//UŒ‚“r’†
D3DXMATRIX C_State::MakeTopAttackHalfwayMat()
{
	D3DXMATRIX returnMat;
	MakeMotionElement tmpMotionElement;
	tmpMotionElement = { 0, 0, 0,D3DXVECTOR3(0.0f, 2.6f, 0.95f) };
	returnMat = MakeMotionMat(tmpMotionElement);
	return returnMat;
}
//UŒ‚I—¹
D3DXMATRIX C_State::MakeTopAttackEndMat()
{
	D3DXMATRIX returnMat;
	MakeMotionElement tmpMotionElement;
	tmpMotionElement = { 100, 0, 0,D3DXVECTOR3(0.0f, 1.5f, 2.5f) };
	returnMat = MakeMotionMat(tmpMotionElement);
	return returnMat;
}
//UŒ‚‚ð‚Í‚¶‚©‚ê‚½‚ ‚Æ
D3DXMATRIX C_State::MakeT_PreventsAttackEndMat()
{
	D3DXMATRIX returnMat;
	MakeMotionElement tmpMotionElement;
	tmpMotionElement = { -70, 0, 0,D3DXVECTOR3(0.0f, 3.7f, -3.0f) };
	returnMat = MakeMotionMat(tmpMotionElement);
	return returnMat;
}
////‰º’i
//‘Ò‹@
D3DXMATRIX C_State::MakeUnderStayEndMat()
{
	D3DXMATRIX returnMat;
	MakeMotionElement tmpMotionElement;
	tmpMotionElement = { 110, -180, 20,D3DXVECTOR3(1.2f, -0.3f, 0.0f) };
	returnMat = MakeMotionMat(tmpMotionElement);
	return returnMat;
}
//UŒ‚€”õ
D3DXMATRIX C_State::MakeUnderAttackPraparationMat()
{
	D3DXMATRIX returnMat;
	MakeMotionElement tmpMotionElement;
	tmpMotionElement = { 120, -180, 90,D3DXVECTOR3(1.5f, 0.5f, -1.0f) };
	returnMat = MakeMotionMat(tmpMotionElement);
	return returnMat;
}
//UŒ‚“r’†
D3DXMATRIX C_State::MakeUnderAttackHalfwayMat()
{
	D3DXMATRIX returnMat;
	MakeMotionElement tmpMotionElement;
	tmpMotionElement = { 200, -180, 0,D3DXVECTOR3(1.5f, 0.5f, -1.0f) };
	returnMat = MakeMotionMat(tmpMotionElement);
	return returnMat;
}
//UŒ‚I—¹
D3DXMATRIX C_State::MakeUnderAttackEndMat()
{
	D3DXMATRIX returnMat;
	MakeMotionElement tmpMotionElement;
	tmpMotionElement = { 0, -90, -60,D3DXVECTOR3(0.0f, -0.3f, 2.0f) };
	returnMat = MakeMotionMat(tmpMotionElement);
	return returnMat;
}

void C_State::PositionStackDownUpdate(int* Stack)
{
	if (*Stack > 0)
	{
		*Stack -= POSITIONSTACKDOWNSPEED;

		if (*Stack < 0)
		{
			*Stack = 0;
		}
	}
	return;
}

void C_State::PositionStackUpUpdate(int* Stack)
{
	if (*Stack < STACKMAXRIMIT)
	{
		*Stack += POSITIONSTACKUPSPEED;

		if (*Stack > STACKMAXRIMIT)
		{
			*Stack = STACKMAXRIMIT;
		}
	}
	return;
}

void C_State::PositionStackUpdate(StateStack* playerStack, int nowPoint)
{
	PositionStackDownUpdate(&playerStack->topStack);
	PositionStackDownUpdate(&playerStack->underStack);
	PositionStackDownUpdate(&playerStack->normalStack);
	if (nowPoint == TOP)
	{
		PositionStackUpUpdate(&playerStack->topStack);
		return;
	}
	if (nowPoint == NORMAL)
	{
		PositionStackUpUpdate(&playerStack->normalStack);
		return;
	}
	if (nowPoint == UNDER)
	{
		PositionStackUpUpdate(&playerStack->underStack);
		return;
	}
	return;
}

void C_State::AttackStackUpdate(StateStack* playerStack)
{
	if (playerStack->attackStack < STACKMAXRIMIT)
	{
		playerStack->attackStack += OTHERSTACKUPSPEED;
	}
	if (playerStack->guardStack > 0)
	{
		playerStack->guardStack -= OTHERSTACKDOWNSPEED;
	}
	if (playerStack->stepStack > 0)
	{
		playerStack->stepStack -= OTHERSTACKDOWNSPEED;
	}
}

void C_State::GuardStackUpdate(StateStack* playerStack)
{
	if (playerStack->guardStack < STACKMAXRIMIT)
	{
		playerStack->guardStack += OTHERSTACKUPSPEED;
	}
	if (playerStack->attackStack > 0)
	{
		playerStack->attackStack -= OTHERSTACKDOWNSPEED;
	}
	if (playerStack->stepStack > 0)
	{
		playerStack->stepStack -= OTHERSTACKDOWNSPEED;
	}
}

void C_State::StepStackUpdate(StateStack* playerStack)
{
	if (playerStack->stepStack < STACKMAXRIMIT)
	{
		playerStack->stepStack += OTHERSTACKUPSPEED;
	}
	if (playerStack->attackStack > 0)
	{
		playerStack->attackStack -= OTHERSTACKDOWNSPEED;
	}
	if (playerStack->guardStack > 0)
	{
		playerStack->guardStack -= OTHERSTACKDOWNSPEED;
	}
}

bool C_State::SetStDecrease(float &St, bool &StDecreaseSetFlg, D3DXMATRIX& stMat)
{
	if (StDecreaseSetFlg == true)return true;
	if (St < 25)return false;
	St -= 25;
	stMat._41 += (25 / MAXST) * STGAUGEWIDTH;
	StDecreaseSetFlg = true;
	return true;
}

bool C_State::SetStDecrease(float& St, bool& StDecreaseSetFlg)
{
	if (StDecreaseSetFlg == true)return true;
	if (St < 25)return false;
	St -= 25;
	StDecreaseSetFlg = true;
	return true;
}

void C_State::StHeel(float& St, D3DXMATRIX& stMat)
{
	if (St >= 100)return;
	stMat._41 -= (STHEELNUM / MAXST) * STGAUGEWIDTH;
	St += STHEELNUM;
	return;
}

void C_State::StHeel(float * St)
{
	if (*St >= 100)return;
	
	*St += STHEELNUM;
	return;
}

void C_State::SetHitElement(HitElement *hitElement, int nowPoint, int nowState, int motionNumber, float frame)
{
	hitElement->Position = nowPoint;
	hitElement->NowState = nowState;
	hitElement->nowMotion = motionNumber;
	hitElement->animeFrame = frame;
	return;
}

bool C_State::MovePushKeyFlg()
{
	if (GetAsyncKeyState('W') & 0x8000 ||
		GetAsyncKeyState('A') & 0x8000 ||
		GetAsyncKeyState('S') & 0x8000 ||
		GetAsyncKeyState('D') & 0x8000)
		return true;
	return false;
}
bool C_State::PushKeyFlg(bool *tapFlg, int  *tapCnt,bool *timeSetFlg)
{
	if (GetAsyncKeyState('W') & 0x8000)
	{
		return true;
	}
	for (int i = 0; i < 3; i++)
	{
		if (*tapFlg == true)
		{
			if (*timeSetFlg == false)
			{
				*tapCnt = STEPKEYTIME;
				*timeSetFlg = true;
			}
			return true;
		}
		tapFlg++;
	}
	return false;
}

int C_State::ChangStay(const StateStack* playerStack)
{
	if (playerStack->normalStack > playerStack->topStack
		&& playerStack->normalStack > playerStack->underStack)
	{
		return NORMAL;
	}
	else
	{
		if (playerStack->topStack > playerStack->underStack)
		{
			return TOP;
		}
	}
	return UNDER;

}

int C_State::MostBigStack(const StateStack* playerStack)
{
	if (playerStack->attackStack > playerStack->stepStack
		&& playerStack->attackStack > playerStack->guardStack)
	{
		return ATTACK;
	}
	else
	{
		if (playerStack->stepStack > playerStack->guardStack)
		{
			return STEP;
		}
	}
	return GUARD;
}