#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CGameCharacter.h"

namespace game_framework 
{
	CGameCharacter::CGameCharacter() 
	{
		healthPoints = 0;
		x = 0;
		y = 0;
		isMovingRight = false;
		isMovingLeft = false;
		isMovingUp = false;
		isMovingDown = false;
		isMovingJump = false;
	}

	void CGameCharacter::LoadBitmap() 
	{
	
	}

	void CGameCharacter::setMovingRight(bool flag)
	{
		isMovingRight = flag;
	}
	
	void CGameCharacter::setMovingLeft(bool flag)
	{
		isMovingLeft = flag;
	}

	void CGameCharacter::setMovingUp(bool flag)
	{
		isMovingUp = flag;
	}

	void CGameCharacter::setMovingDown(bool flag)
	{
		isMovingDown = flag;
	}

	void CGameCharacter::setMovingJump(bool flag)
	{
		isMovingJump = flag;
	}

	int CGameCharacter::getHP() 
	{
		return healthPoints;
	}

	void CGameCharacter::setHP(int newHP) 
	{
		healthPoints = newHP;
	}

	void CGameCharacter::SetXY(int nx, int ny) 
	{
		x = ny;
		y = ny;
	}

	void CGameCharacter::OnMove() 
	{
	
	}

	void CGameCharacter::OnShow() 
	{
		//////setTopLeft
		//////ShowBitmap
	}
}