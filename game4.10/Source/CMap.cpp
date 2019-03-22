#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CMap.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// CMap: Map class
	/////////////////////////////////////////////////////////////////////////////
	CMap::CMap() 
	{
		x = 0;
		y = -290;
		isMovingUp = false;
		isMovingDown = false;
		isMovingRight = false;
		isMovingLeft = false;
		
	}

	void CMap::LoadBitmap()
	{
		map.LoadBitmap(MAP01, RGB(255, 255, 255));
	}

	void CMap::SetXY(int nx, int ny)
	{
		x = nx;
		y = ny;
	}

	void CMap::OnMove()
	{
		if (isMovingUp == true) { y += 5; }
		if (isMovingDown == true) { y -= 5;}
		if (isMovingRight == true) { x -= 5; }
		if (isMovingLeft == true) { x += 5; }

	}
	
	void CMap::SrollingUp(bool flag)
	{
		isMovingUp = flag;
	}
	
	void CMap::SrollingDown(bool flag)
	{
		isMovingDown = flag;
	}
	
	void CMap::SrollingRight(bool flag) 
	{
		isMovingRight = flag;
	}

	void CMap::SrollingLeft(bool flag)
	{
		isMovingLeft = flag;
	}

	int CMap::getX() { return x; }
	int CMap::getY() { return y; }

	void CMap::OnShow() 
	{
		map.SetTopLeft(x, y);
		map.ShowBitmap();
		//TRACE("NOW map is in X=%d and Y=%d", this->x, this->y);
	}
}