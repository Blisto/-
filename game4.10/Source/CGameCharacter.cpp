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
		x = 395;
		y = 380;
		moveUnit = 8;
		blockflag = false;
		isMovingRight = false;
		isMovingLeft = false;
		isMovingUp = false;
		isMovingDown = false;
		isMovingJump = false;
	}

	void CGameCharacter::LoadBitmap() 
	{
		character.LoadBitmap(TestDog, RGB(255, 255, 255));
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

	int CGameCharacter::getX()
	{
		return x;
	}

	int CGameCharacter::getY()
	{
		return y;
	}

	int CGameCharacter::getHeight()
	{
		return character.Height();
	}
	int CGameCharacter::getWidth()
	{
		return character.Width();
	}
	int CGameCharacter::getUnit() 
	{
		return moveUnit;
	}
	void CGameCharacter::setHP(int newHP) 
	{
		healthPoints = newHP;
	}
	void CGameCharacter::setBlockFlag(bool flag) 
	{
		blockflag = flag;
	}
	void CGameCharacter::SetXY(int nx, int ny) 
	{
		x = ny;
		y = ny;
	}

	void CGameCharacter::checkStep() 
	{
		
	}

	void CGameCharacter::OnMove() 
	{
		if (blockflag == false) {
			if (isMovingUp == true) { y -= moveUnit; }
			if (isMovingDown == true) { y += moveUnit; }
			if (isMovingRight == true) { x += moveUnit; }
			if (isMovingLeft == true) { x -= moveUnit; }
		}
		else 
		{
			if (isMovingUp == true) { y += moveUnit; }
			if (isMovingDown == true) { y -= moveUnit; }
			if (isMovingRight == true) { x -= moveUnit; }
			if (isMovingLeft == true) { x += moveUnit; }
			blockflag = false;
		}
	}

	void CGameCharacter::OnShow() 
	{
		character.SetTopLeft(x, y);
		character.ShowBitmap();
	}

}