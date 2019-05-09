#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Map.h"
#include "Character.h"
#include "mesageBox.h"

namespace game_framework {

	Map::Map() 
	{
		x = 248; y = -192;//-408
		this->distanceBox[0] = 999;
		this->distanceBox[1] = 999;
		this->distanceBox[2] = 999;
		this->distanceBox[3] = 999;
		moveUnit = 8;
		downSpeed = 5;
		jumpSpeed = 16;
		accelerateTime = 1;
		jumpDistance = 80;
		chLR = 0; chNum = 0;
		hpState = 16;
		MegaManMode = 0;
		target = 0;
		/////////////////////////////////////////////////////////
		//   map setting data
		for (int ay = 0; ay < 834; ay++) {
			for (int ax = 0; ax < 2082; ax++) mapData[0][ay][ax] = 0;
		}

		//¦a¹Ïª«¥ó

		for (int ay = 641; ay <= 672; ay++) {//¿j1
			for (int ax = 385; ax <= 448; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 609; ay <= 640; ay++) {//¿j2
			for (int ax = 513; ax <= 576; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 577; ay <= 608; ay++) {//¿j3
			for (int ax = 641; ax <= 704; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 545; ay <= 576; ay++) {//¿j4
			for (int ax = 737; ax <= 800; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 545; ay <= 576; ay++) {//¿j5
			for (int ax = 833; ax <= 896; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 481; ay <= 512; ay++) {//¿j6
			for (int ax = 897; ax <= 960; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 417; ay <= 448; ay++) {//¿j7
			for (int ax = 801; ax <= 832; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 385; ay <= 416; ay++) {//¿j8
			for (int ax = 705; ax <= 768; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 385; ay <= 416; ay++) {//¿j9
			for (int ax = 609; ax <= 672; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 417; ay <= 448; ay++) {//¿j10
			for (int ax = 513; ax <= 608; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 449; ay <= 480; ay++) {//¿j11
			for (int ax = 385; ax <= 448; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 417; ay <= 448; ay++) {//¿j12
			for (int ax = 289; ax <= 352; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 385; ay <= 416; ay++) {//¿j13
			for (int ax = 193; ax <= 256; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 321; ay <= 352; ay++) {//¿j14
			for (int ax = 129; ax <= 192; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 289; ay <= 320; ay++) {//¿j15
			for (int ax = 33; ax <= 96; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 225; ay <= 256; ay++) {//¿j16
			for (int ax = 257; ax <= 320; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 193; ay <= 224; ay++) {//¿j17
			for (int ax = 321; ax <= 352; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 161; ay <= 192; ay++) {//¿j18
			for (int ax = 353; ax <= 608; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 193; ay <= 224; ay++) {//¿j19
			for (int ax = 577; ax <= 864; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 161; ay <= 192; ay++) {//¿j20
			for (int ax = 833; ax <= 1088; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 513; ay <= 832; ay++) {//¿j21
			for (int ax = 1089; ax <= 1120; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 641; ay <= 672; ay++) {//¿j22
			for (int ax = 1569; ax <= 2080; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 609; ay <= 640; ay++) {//¿j23
			for (int ax = 1921; ax <= 2080; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 577; ay <= 608; ay++) {//¿j24
			for (int ax = 1985; ax <= 2080; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 545; ay <= 576; ay++) {//¿j25
			for (int ax = 2017; ax <= 2080; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 513; ay <= 544; ay++) {//¿j26
			for (int ax = 2049; ax <= 2080; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 449; ay <= 480; ay++) {//¿j27
			for (int ax = 1921; ax <= 1952; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 417; ay <= 448; ay++) {//¿j28
			for (int ax = 1825; ax <= 1856; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 417; ay <= 448; ay++) {//¿j29
			for (int ax = 1473; ax <= 1760; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 353; ay <= 448; ay++) {//¿j30
			for (int ax = 1377; ax <= 1472; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 321; ay <= 352; ay++) {//¿j31
			for (int ax = 1377; ax <= 1440; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 289; ay <= 320; ay++) {//¿j32
			for (int ax = 1121; ax <= 1408; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 257; ay <= 288; ay++) {//¿j33
			for (int ax = 1217; ax <= 1344; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 225; ay <= 256; ay++) {//¿j34
			for (int ax = 1217; ax <= 1280; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 193; ay <= 224; ay++) {//¿j35
			for (int ax = 1217; ax <= 1248; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 193; ay <= 224; ay++) {//¿j36
			for (int ax = 1441; ax <= 1504; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 161; ay <= 192; ay++) {//¿j37
			for (int ax = 1505; ax <= 1536; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 129; ay <= 160; ay++) {//¿j38
			for (int ax = 1537; ax <= 2080; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 770; ay <= 832; ay++) {//¿j39
			for (int ax = 801; ax <= 1088; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 795; ay <= 832; ay++) {//¿j40
			for (int ax = 1505; ax <= 2080; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 673; ay <= 832; ay++) {//¦aªO1
			for (int ax = 1; ax <= 800; ax++) mapData[0][ay][ax] = 1;
		}
		for (int ay = 705; ay <= 832; ay++) {//¦aªO2
			for (int ax = 1121; ax <= 1504; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 161; ay <= 192; ay++) {//º²©¥1
			for (int ax = 609; ax <= 832; ax++) mapData[0][ay][ax] = 2;
		}
		for (int ay = 611; ay <= 769; ay++) {//º²©¥2
			for (int ax = 801; ax <= 1088; ax++) mapData[0][ay][ax] = 2;
		}

		//³Ì¥~°éÃä¬É;
		for (int ay = 0; ay < 1; ay++) {//¤W
			for (int ax = 0; ax < 2082; ax++) mapData[0][ay][ax] = 1;
		}
		for (int ay = 833; ay < 834; ay++) {//¤U
			for (int ax = 0; ax < 2082; ax++) mapData[0][ay][ax] = 1;
		}
		for (int ay = 0; ay < 834; ay++) {//¥ª
			for (int ax = 0; ax < 1; ax++) mapData[0][ay][ax] = 1;
		}
		for (int ay = 0; ay < 834; ay++) {//¥k
			for (int ax = 2081; ax < 2082; ax++) mapData[0][ay][ax] = 1;
		}
		// 
		/////////////////////////////////////////////////////////
		


		p1 = new Character;
		monster[0] = new Character;
		monster[1] = new Character;
		facai = new mesageBox;
	}
	Map::~Map() {
		delete p1;
		delete monster[0];
		delete monster[1];
		delete facai;
	}

	void Map::LoadBitmap() 
	{
		UI[16].LoadBitmap(HP16, RGB(255, 255, 255));
		UI[15].LoadBitmap(HP15, RGB(255, 255, 255));
		UI[14].LoadBitmap(HP14, RGB(255, 255, 255));
		UI[13].LoadBitmap(HP13, RGB(255, 255, 255));
		UI[12].LoadBitmap(HP12, RGB(255, 255, 255));
		UI[11].LoadBitmap(HP11, RGB(255, 255, 255));
		UI[10].LoadBitmap(HP10, RGB(255, 255, 255));
		UI[9].LoadBitmap(HP9, RGB(255, 255, 255));
		UI[8].LoadBitmap(HP8, RGB(255, 255, 255));
		UI[7].LoadBitmap(HP7, RGB(255, 255, 255));
		UI[6].LoadBitmap(HP6, RGB(255, 255, 255));
		UI[5].LoadBitmap(HP5, RGB(255, 255, 255));
		UI[4].LoadBitmap(HP4, RGB(255, 255, 255));
		UI[3].LoadBitmap(HP3, RGB(255, 255, 255));
		UI[2].LoadBitmap(HP2, RGB(255, 255, 255));
		UI[1].LoadBitmap(HP1, RGB(255, 255, 255));
		UI[0].LoadBitmap(HP0, RGB(255, 255, 255));

		UI_megaman[0][1].LoadBitmap(hp_button, RGB(255, 255, 255));
		UI_megaman[0][0].LoadBitmap(hp_button, RGB(255, 255, 255));

		UI_megaman[1][1].LoadBitmap(hp_1, RGB(255, 255, 255));
		UI_megaman[2][1].LoadBitmap(hp_1, RGB(255, 255, 255));
		UI_megaman[3][1].LoadBitmap(hp_1, RGB(255, 255, 255));
		UI_megaman[4][1].LoadBitmap(hp_1, RGB(255, 255, 255));
		UI_megaman[5][1].LoadBitmap(hp_1, RGB(255, 255, 255));

		UI_megaman[1][0].LoadBitmap(hp_0, RGB(255, 255, 255));
		UI_megaman[2][0].LoadBitmap(hp_0, RGB(255, 255, 255));
		UI_megaman[3][0].LoadBitmap(hp_0, RGB(255, 255, 255));
		UI_megaman[4][0].LoadBitmap(hp_0, RGB(255, 255, 255));
		UI_megaman[5][0].LoadBitmap(hp_0, RGB(255, 255, 255));

		UI_megaman[6][1].LoadBitmap(hp_top, RGB(255, 255, 255));
		UI_megaman[6][0].LoadBitmap(hp_top, RGB(255, 255, 255));

		ground.AddBitmap(ground1, RGB(255, 255, 255));
		ground.AddBitmap(ground2, RGB(255, 255, 255));
		ground.AddBitmap(ground3, RGB(255, 255, 255));
		ground.AddBitmap(ground4, RGB(255, 255, 255));
		ground.AddBitmap(ground5, RGB(255, 255, 255));
		ground.AddBitmap(ground6, RGB(255, 255, 255));
		ground.AddBitmap(ground7, RGB(255, 255, 255));
		ground.SetDelayCount(10);

		map.LoadBitmap(m1, RGB(255, 255, 255));
		p1->LoadBitmap();

		monster[0]->MonsterInit(0);
		monster[1]->MonsterInit(1);
		facai->LoadBitmap();
	}


	////////////////////////////////////////

	void Map::SrollingUp(bool flag)
	{
		isMovingUp = flag;
	}

	void Map::SrollingDown(bool flag)
	{
		isMovingDown = flag;
	}

	void Map::SrollingRight(bool flag)
	{
		isMovingRight = flag;
	}
	void Map::SrollingLeft(bool flag)
	{
		isMovingLeft = flag;
	}


	void Map::SetXY(int nx, int ny)
	{
		x = nx; y = ny;
	}

	////////////////////////////////////////

	void Map::playerUP(bool flag)
	{
		monster[0]->setMovingUp(flag);
	}
	void Map::playerDown(bool flag)
	{
		monster[0]->setMovingDown(flag);
	}
	void Map::playerRight(bool flag)
	{
		monster[0]->setMovingRight(flag);
	}
	void Map::playerLeft(bool flag)
	{
		monster[0]->setMovingLeft(flag);
	}

	void Map::playerAtk(bool flag)//»·
	{
		p1->testAtk(flag);
	}

	void Map::playerAtk2(bool flag) //ªñ
	{
		p1->testAtk2(flag);
		//this->chNum = 6;
	}

	void Map::mesgNext() 
	{
		if (facai->getOpen() == false)
		{
			p1->SetMapXY(this->x, this->y);
			if(p1->Mbox(1185,609)==true)facai->openMesgBox(true);
		}
		else 
		{
			facai->nextPage();
		}
	}

	bool Map::getDeadState()
	{
		if (p1->isDead() == true) 
		{
			if (chLR == 0 && p1->getAtkIsLast(5) == true) {
				p1->setHP(100);
				x = 248; y = -192;
				return true; 
			}
		}
		return false;
	}

	////////////////////////////////////////
	void Map::mesg(int phase)
	{
		if(phase==0)TRACE("x:%d y:%d\n",this->x,this->y);
		if (phase == 1)p1->mesg();
		if(phase==3)TRACE("x:%d y:%d    %d  %d ||  %d %d\n", p1->getX(), p1->getY(), this->x, this->y, p1->getX()- this->x, p1->getY()- this->y);
		if (phase == 4)TRACE("monster:%d %d  map:%d %d     ->%d %d\n", monster[0]->getX(), monster[0]->getY(),this->x,this->y, monster[0]->getX()- this->x, monster[0]->getY() - this->y);
		if (phase == 5)TRACE("m:%d %d   p:%d %d\n", monster[0]->getX() - this->x, monster[0]->getY() - this->y, p1->getX() - this->x, p1->getY() - this->y);
	}

	bool Map::block_test(Character *p,int UDRL)//U:0 D:1 R:3 L:2
	{
		int cw = p->getWidth()-1, ch = p->getHeight()-1;
		int cx = p->getX(), cy = p->getY();
		int transX=this->CxToMapCoordinate(cx), transY=this->CyToMapCoordinate(cy);//Âà´«¦a¹Ï®y¼Ð
		int cx0 = transX, cy0 = transY;//¥ª¤W
		int cx1 = cx0 + cw, cy1 = cy0;//¥k¤W
		int cx2 = cx0, cy2 = cy0 + ch;//¥ª¤U
		int cx3 = cx0 + cw, cy3 = cy0 + ch;//¥k¤U
		CountDistance(p, UDRL);
		switch (UDRL)
		{
		case 0:
			for (int i = 0; i <= cw; i++)
			{
				if ((1 + cy0 - 1) >= 0 && mapData[0][1 + cy0 - 1][1 + cx0 + i] == 1) {
					if (distanceBox[0] <= moveUnit)moveUnit = distanceBox[0]; return true; 
				}
				if ((1 + cy0 - 1) >= 0 && mapData[0][1 + cy0 - 1][1 + cx0 + i] == 2) {
					p1->setHP(0);
				}
			}
			break;
		case 1:
			for (int i = 0; i <= cw; i++) 
			{
				if (mapData[0][1 + cy2+1][1 + cx2 + i] == 1){
					if (distanceBox[1] <= moveUnit)moveUnit = distanceBox[1];return true;
				}
				if (mapData[0][1 + cy2 + 1][1 + cx2 + i] == 2) {
					p1->setHP(0);
				}
			}
			break;
		case 2:
			for (int i = 1; i <= ch-1; i++)
			{
				if (mapData[0][1 + cy0 + i][1 + cx0 - 1] == 1) { 
					if (distanceBox[2] <= moveUnit)moveUnit = distanceBox[2]; return true; 
				}
				if (mapData[0][1 + cy0 + i][1 + cx0 - 1] == 2) {
					p1->setHP(0);
				}
			}
			break;
		case 3:
			for (int i = 1; i <= ch - 1; i++)
			{
				if (mapData[0][1 + cy1 + i][1 + cx1 + 1] == 1) {
					if (distanceBox[3] <= moveUnit)moveUnit = distanceBox[3]; return true; 
				}
				if (mapData[0][1 + cy1 + i][1 + cx1 + 1] == 2) {
					p1->setHP(0);
				}
			}
			break;
		default:
			break;
		}
		return false;
	}

	void Map::CountDistance(Character *p, int UDRL) {//U:0 D:1 R:3 L:2

		int cw = p->getWidth()-1, ch = p->getHeight()-1;
		int cx = p->getX(), cy = p->getY();
		int transX = this->CxToMapCoordinate(cx), transY = this->CyToMapCoordinate(cy);//Âà´«¦a¹Ï®y¼Ð
		int cx0 = transX, cy0 = transY;//¥ª¤W
		int cx1 = cx0 + cw, cy1 = cy0;//¥k¤W
		int cx2 = cx0, cy2 = cy0 + ch;//¥ª¤U
		int cx3 = cx0 + cw, cy3 = cy0 + ch;//¥k¤U
		for (int i = -10; i <=64; i++) {

			if ((1 + cy0 - i - 1 )>=0&&i>=0&&UDRL == 0)for (int j = 0; j <= cw; j++)if (mapData[0][1 + cy0 - i-1][1 + cx0 + j] == 1 &&distanceBox[0]>i)distanceBox[0] = i;
			if (UDRL == 1)for (int j = 0; j <= cw; j++)if (mapData[0][1 + cy2 + i+1][1 + cx2 + j] == 1 && distanceBox[1]>i)distanceBox[1] = i;
			if (i >= 0 && UDRL == 2)for (int j = 1; j <= ch-1; j++)if (mapData[0][1 + cy0 + j][1 + cx0 - i-1] == 1 && distanceBox[2]>i)distanceBox[2] = i;
			if (i >= 0 && UDRL == 3)for (int j = 1; j <= ch-1; j++)if (mapData[0][1 + cy1 + j][1 + cx1 + i+1] == 1 && distanceBox[3]>i)distanceBox[3] = i;

		}
	}

	void Map::fillGround()
	{
		for (int ay = 161; ay <= 192; ay++) {//¶ñ¸Éº²©¥
			for (int ax = 609; ax <= 832; ax++) mapData[0][ay][ax] = 1;
		}
	}
	int Map::CxToMapCoordinate(int cx) { return (cx - this->x); }
	int Map::CyToMapCoordinate(int cy) { return (cy - this->y); }

	void Map::OnMove() 
	{
		if (p1->isDead() == true) 
		{
			chLR = 0;
			chNum = 5;
			p1->OnMove(chLR, chNum);
			return;
		}

		if (monster[0]->isDead() == true) 
		{
			this->target = 1;
			if (ground.IsFinalBitmap() == false) 
			{ 
				this->fillGround();
				ground.OnMove();
				return; 
			}
		}


			if (block_test(p1, 1) == false)
			{
				moveUnit = downSpeed;
				
				block_test(p1, 1);
				this->distanceBox[1] = 999;
				if (distanceBox[1] < downSpeed)downSpeed = distanceBox[1];
				moveUnit = downSpeed;
				this->y -= moveUnit;
				this->distanceBox[1] -= moveUnit;
				
				if (isMovingUp == false && chNum != 6)chNum = 3;
				if (accelerateTime == 0) { downSpeed++; accelerateTime = 1; }
				else { accelerateTime--; }
				if (downSpeed >= 9&& isMovingUp ==true) { chNum = 3; isMovingUp = false; downSpeed = 7; }
				p1->SetMapXY(this->x, this->y);
			}
			else if (block_test(p1, 1) == true)
			{
				downSpeed = 5;
				if (this->distanceBox[1] == -1)this->distanceBox[1] = 0;
				if (this->distanceBox[1] <0)
				{ 
					this->y += this->distanceBox[1] * (-1);
					this->distanceBox[1] = this->distanceBox[1]*(-1);


				}
				chNum = 0;
				p1->SetMapXY(this->x, this->y);
			}


		if (isMovingUp == true) {
			moveUnit = 20;
			this->distanceBox[0] = 999;
			if (block_test(p1,0) == true)return;
			chNum = 2;
			this->y += moveUnit;
			this->distanceBox[0] -= moveUnit;
			p1->SetMapXY(this->x, this->y);
		}


		if (isMovingLeft == false && isMovingRight == true) {
			moveUnit = 8;
			this->distanceBox[3] = 999;
			if (block_test(p1, 3) == true)return;
			if (this->distanceBox[1] == 0) { chNum = 1; }
			chLR = 0;
			this->x -= moveUnit;
			this->distanceBox[3] -= moveUnit;
			p1->SetMapXY(this->x, this->y);
		}

		if (isMovingRight == false && isMovingLeft == true) {
			
			moveUnit = 8;
			this->distanceBox[2] = 999;
			if (block_test(p1, 2) == true)return;
			if(this->distanceBox[1] == 0){ chNum = 1; }
			chLR = 1;
			this->x += moveUnit;
			this->distanceBox[2]-= moveUnit;
			p1->SetMapXY(this->x, this->y);
		}
		
		if (isMovingRight == false && isMovingLeft == false && isMovingUp==false&& this->distanceBox[1] == 0) { chNum = 0; }



		if (p1->getAttack() == true)chNum = 4;

		if (p1->getAttack2() == true)chNum = 6;
	
		if (chNum == 6 && p1->getAtkIsLast(6) == true)
		{
			p1->SetMapXY(this->x, this->y);
			p1->Attack(monster[target]);
			this->chNum = 0;
		}
		TRACE("%d %d\n", target, monster[target]->getHP());
		p1->OnMove(chLR,chNum);
		monster[0]->AutoMove(this->y,this->x);
		monster[1]->AutoMove(this->y, this->x);
		p1->ImpactCheck(monster[target]);
		//p1->ImpactCheck(monster[1]);
		facai->OnMove();
		//TRACE("monsterHP:%d\n", monster[0]->getHP());
		//TRACE("d:%d %d %d %d\n", distanceBox[0], distanceBox[1], distanceBox[2], distanceBox[3]);

		
	}

	void Map::OnShow() 
	{
		map.SetTopLeft(x, y);
		map.ShowBitmap();
		if (monster[0]->isDead() == true) 
		{
			ground.SetTopLeft(608+x,160+y);
			ground.OnShow();
		}
		if (monster[0]->getHP() > 0) { monster[0]->OnShow(); }
		
		if (monster[1]->getHP()>0)monster[1]->OnShow();
		p1->OnShow();
		if (MegaManMode == 0) 
		{
			UI[p1->getHP() / 6].SetTopLeft(20, 20);
			UI[p1->getHP() / 6].ShowBitmap();
		}
		else 
		{
			printMegaManUI(40, 160);
		}
		facai->OnShow();
	}
	////////////////////////////////////////

	void Map::testhp() {
		if(hpState>0)hpState--;
	}


	void Map::printMegaManUI(int ux,int uy) //40.160
	{
		UI_megaman[6][1].SetTopLeft(ux, uy); UI_megaman[6][1].ShowBitmap();

		if (p1->getHP() >= 80) { UI_megaman[5][1].SetTopLeft(ux, uy + 6); UI_megaman[5][1].ShowBitmap();}
		else { UI_megaman[5][0].SetTopLeft(ux, uy + 6); UI_megaman[5][0].ShowBitmap(); }

		if (p1->getHP() >= 60) { UI_megaman[4][1].SetTopLeft(ux, uy + 30); UI_megaman[4][1].ShowBitmap();}
		else { UI_megaman[4][0].SetTopLeft(ux, uy + 30); UI_megaman[4][0].ShowBitmap();}

		if (p1->getHP() >= 40) { UI_megaman[3][1].SetTopLeft(ux, uy + 54); UI_megaman[3][1].ShowBitmap();}
		else { UI_megaman[3][0].SetTopLeft(ux, uy + 54); UI_megaman[3][0].ShowBitmap();}

		if (p1->getHP() >= 20) { UI_megaman[2][1].SetTopLeft(ux, uy + 78); UI_megaman[2][1].ShowBitmap(); }
		else { UI_megaman[2][0].SetTopLeft(ux, uy + 78); UI_megaman[2][0].ShowBitmap(); }

		if (p1->getHP() > 0) { UI_megaman[1][1].SetTopLeft(ux, uy + 102); UI_megaman[1][1].ShowBitmap();}
		else { UI_megaman[1][0].SetTopLeft(ux, uy + 102); UI_megaman[1][0].ShowBitmap();}

		UI_megaman[0][1].SetTopLeft(ux, uy+126); UI_megaman[0][1].ShowBitmap();
	}
}