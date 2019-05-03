#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CMap.h"
#include "CGameCharacter.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// CMap: Map class
	/////////////////////////////////////////////////////////////////////////////
	CMap::CMap() 
	{
		x = 352; y = -358;
		//x = 0; y = 0;
		p1 = new CGameCharacter();
		testMon1 = new CGameCharacter();
		moveCount = 2 * 1;
		isMovingUp = false;
		isMovingDown = false;
		isMovingRight = false;
		isMovingLeft = false;

		for (int k = 0; k < 3; k++) {
			for (int i = 0; i < 100; i++)
			{
				for (int j = 0; j < 100; j++)mapData[k][i][j] = 0;
			}
		}
		this->setMapData(0);
		
		for (int i = 0; i < 100; i++) 
		{
			for (int j = 0; j < 100; j++)p1->setMapData(i, j, mapData[0][i][j]);
		}
	}

	void CMap::LoadBitmap()
	{
		map.LoadBitmap(MAP01, RGB(255, 255, 255));
		p1->LoadBitmap();
		testMon1->MonsterInit(this->y,this->x);
	}
	bool CMap::getPlayerUP(){
		return p1->getUP();
	}
	void CMap::setMapData(int mapNum)
	{
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

		//for (int i = 21; i <=25 ; i++)
		//{
		//	for (int j = 0; j <= 24; j++)mapData[0][i][j] = 1;
		//}
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 5; j++) {
				mapData[0][21 + j][25 + i] = 2;
			}
		}

		for (int i = 0; i < 7; i++) {
			mapData[0][10][19 + i] = 2;
			mapData[0][11][19 + i] = 2;
		}

		for (int i = 0; i < 65; i++)mapData[0][i][26] = 1;
	}

	void CMap::SetXY(int nx, int ny)
	{
		x = nx;
		y = ny;
	}

	void CMap::OnMove()
	{
		if (isMovingUp == true) { y += 32; }
		if (isMovingDown == true) { y -= 32;}
		if (isMovingRight == true) { 
			if (p1->get_distence(3) <= 1 &&p1->isBlock(this->y / 32, this->x / 32, 16) == 1)return;
			x -= 16;
		}
		if (isMovingLeft == true) {
			if (p1->get_distence(2) <= 1 &&p1->isBlock(this->y / 32, this->x / 32, 16) == 1)return;
			x += 16; 
		}
		p1->OnMove(this->y/32, this->x/32);
		
		objType = p1->isBlock(this->y / 32, this->x / 32, 0);

		testMon1->AutoMove(this->y, this->x);
		
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

	bool CMap::isDead() {
		if (p1->getHP() == 0)return true;
		return false;
	}
	void CMap::playerUP(bool flag)
	{
		p1->setMovingUp(flag);
	}
	void CMap::playerDown(bool flag)
	{
		p1->setMovingDown(flag,10);
	}
	void CMap::playerRight(bool flag)
	{
		p1->setMovingRight(flag);
	}
	void CMap::playerLeft(bool flag)
	{
		p1->setMovingLeft(flag);
	}

	void CMap::playerXY(int nx,int ny){
		p1->SetXY(nx, ny);
	}
	void CMap::playerAttack() {
		p1->Attack(testMon1, this->x, this->y);
	}

	int CMap::getX() { return x; }
	int CMap::getY() { return y; }
	int CMap::getMapData(int i,int j) { return mapData[0][i][j]; }
	void CMap::OnShow() 
	{
		map.SetTopLeft(x, y);
		map.ShowBitmap();
		p1->OnShow();
		testMon1->OnShow();
		//TRACE("NOW map is in X=%d and Y=%d", this->x, this->y);
	}


}