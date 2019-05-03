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
		x = 355;
		y = -225;
		isMovingUp = false;
		isMovingDown = false;
		isMovingRight = false;
		isMovingLeft = false;

		for (int k = 0; k < 3; k++) {
			for (int i = 0; i < 100; i++)
			{
				for (int j = 0; j < 100; j++)mapData[0][i][j] = 0;
			}
		}
	}

	void CMap::LoadBitmap()
	{
		map.LoadBitmap(MAP01, RGB(255, 255, 255));
	}

	void CMap::setMapData(int mapNum)
	{
		if (mapNum == 0) 
		{
			for (int i = 0; i <= map.Width() / 32; i++) 
			{
				for (int j = 0; j <= map.Height() / 32; j++) 
				{
					mapData[mapNum][i][j] = 0;
				}
			}
		}

		for (int i = 0; i < 4; i++) mapData[0][19][14+i] = 1;
		
		for (int i = 5; i <= 6; i++)mapData[0][12][i] = 1;
		for (int i = 8; i <= 10; i++)mapData[0][14][i] = 1;
		for (int i = 12; i <= 15; i++)mapData[0][15][i] = 1;
		for (int i = 18; i <= 23; i++)mapData[0][17][i] = 1;
		for (int i = 8; i <= 17; i++)mapData[0][10][i] = 1;
		for (int i = 10; i <= 12; i++)mapData[0][i][18] = 1;
		for (int i = 19; i <= 25; i++)mapData[0][12][i] = 1;
		for (int i = 10; i <= 12; i++)mapData[0][i][26] = 1;
		for (int i = 27; i <= 33; i++)mapData[0][10][i] = 1;
		for (int i = 21; i <= 25; i++) 
		{
			for(int j=0;j<=24;j++)mapData[0][i][j] = 1;

		}
		for(int i=15;i <= 25;i++)mapData[0][i][34] = 1;

		for (int i = 35; i <= 46; i++) 
		{
			for (int j = 22; j <= 25; j++)mapData[0][j][i]=1;
		}

		for (int i = 49; i <= 64; i++)mapData[0][20][i] = 1;
		for (int i = 60; i <= 64; i++)mapData[0][19][i] = 1;
		for (int i = 62; i <= 64; i++)mapData[0][18][i] = 1;
		for (int i = 63; i <= 64; i++)mapData[0][17][i] = 1;
		mapData[0][16][64] = 1;
		for (int i = 46; i <= 64; i++)mapData[0][4][i] = 1;
		for (int i = 43; i <= 51; i++)mapData[0][10][i] = 1;

		for (int i = 11; i <= 14; i++) 
		{
			for (int j = 51; j <= 52; j++)mapData[0][i][j] = 1;
		}
		for (int i = 53; i <= 62;i++)mapData[0][14][i] = 1;
		mapData[0][12][53] = 1;
		mapData[0][13][53] = 1;
		mapData[0][13][54] = 1;

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
	int CMap::getMapData(int i,int j) { return mapData[0][i][j]; }
	void CMap::OnShow() 
	{
		map.SetTopLeft(x, y);
		map.ShowBitmap();
		//TRACE("NOW map is in X=%d and Y=%d", this->x, this->y);
	}

	bool CMap::isBlock(int top_y, int left_x, int w, int h) 
	{
		// 1:左上角 2:右下角 3:右上角 4:左下角
		int x1 = left_x, y1 = top_y;        //左上角座標
		//int x2 = left_x + w, y2 = top_y + h;//右下角座標
		//int x3 = left_x + w, y3 = top_y;    //右上角座標
		//int x4 = left_x, y4 = top_y + h;    //左下角座標
	    //將人物轉換到地圖座標系統上
		int tx1 = left_x - this->getX(), ty1 = top_y - this->getY(); //左上角
		int tx2 = tx1 + w, ty2 = ty1 + h;						     //右下角
		int tx3 = tx1 + w, ty3 = ty1;								 //右上角
		int tx4 = tx1, ty4 = ty1 + h;								 //左下角

		for (int i = 0; i <= w; i++) 
		{
			for (int j = 0; j <= h; j++) 
			{
				if (mapData[0][(ty1 + j)/32][(tx1 + i)/32] == 1)return true;
			}
		}
		return false;//無阻擋 可通過
	}

	bool CMap::isBottom(int top_y, int left_x, int w, int h)
	{
		int x1 = left_x, y1 = top_y;
		//將人物轉換到地圖座標系統上
		int tx1 = left_x - this->getX(), ty1 = top_y - this->getY(); //左上角
		int tx4 = tx1, ty4 = ty1 + h;								 //左下角
		int tx2 = tx1 + w, ty2 = ty1 + h;						     //右下角
		
		for (int i = 0; i < h;i++)if (mapData[0][(ty4) / 32][(tx4+w) / 32] == 1)return true;
		return false;
	}
}