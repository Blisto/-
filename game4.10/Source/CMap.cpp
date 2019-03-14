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
	}

	void CMap::LoadBitmap()
	{
		map.LoadBitmap(SCROLLINGTEST);
	}

	void CMap::SetXY(int nx, int ny)
	{
		x = nx;
		y = ny;
	}

	void CMap::OnMove()
	{
		map.SetTopLeft(x,y);
		map.ShowBitmap();
	}

	void CMap::OnShow() 
	{
	
	}
}