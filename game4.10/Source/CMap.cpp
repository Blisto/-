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
		y = 0;
		isMovingRight = false;
		isMovingLeft = false;
	}

	void CMap::LoadBitmap()
	{
		map.LoadBitmap(SCROLLINGTEST, RGB(255, 255, 255));
	}

	void CMap::SetXY(int nx, int ny)
	{
		x = nx;
		y = ny;
	}

	void CMap::OnMove()
	{
		if (isMovingLeft == true) x -= 5;
		if (isMovingRight == true) x += 5;

	}

	void CMap::SrollingRight(bool flag) 
	{
		isMovingRight = flag;
	}

	void CMap::SrollingLeft(bool flag)
	{
		isMovingLeft = flag;
	}


	void CMap::OnShow() 
	{
		map.SetTopLeft(x, y);
		map.ShowBitmap();
	}
}