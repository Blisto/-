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
		x = 135;
		y = 455;
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
		if (isMovingUp == true) { y -= 5; }
		if (isMovingDown == true) { y += 5; }
		if (isMovingRight == true) { x += 5; }
		if (isMovingLeft == true) { x -= 5; }
	}

	void CGameCharacter::OnShow() 
	{
		character.SetTopLeft(x, y);
		character.ShowBitmap();
		//TRACE("NOW dog is in X=%d and Y=%d", this->x, this->y);

	}
}