#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Map.h"
#include "Character.h"
#include "mesageBox.h"
#include "Elementalattack.h"


namespace game_framework {

	enum AUDIO_ID {				// 定義各種音效的編號
		AUDIO_BGM,
		AUDIO_X,				//X登場音效
		AUDIO_BOSS,				//BOSS登場音效
		AUDIO_BOSS_ATK5,
		AUDIO_CHOOSE,
		AUDIO_X_ATK0_HIGHLEVEL,
		AUDIO_X_ATK1_HIGHLEVEL,
		AUDIO_X_ATK0_NORMALHLEVEL,
		AUDIO_X_ATK1_NORMALHLEVEL,
		AUDIO_X_DASH,
		AUDIO_X_JUMP,
		AUDIO_X_ATK_HITTED,
		AUDIO_X_StartCharge,
		AUDIO_X_Charge,
		AUDIO_DAMAGED,
		AUDIO_X_DEATH,
		AUDIO_BOSS_ATK4,
		AUDIO_CLOSE_HITTED,
		AUDIO_CLOSE_MISSED,
		AUDIO_MESG_NEXT,
		AUDIO_ARTHUR_SHOOTATK,
		AUDIO_GAMEOVER,
		AUDIO_MENU,
		AUDIO_IAMGUNDAM,
		AUDIO_CHORD,
		AUDIO_CATVOICE1,
		AUDIO_CATVOICE2,
		AUDIO_CLEAR,
		AUDIO_CLEAR_BGM
	};

	Map::Map() 
	{
		x = 248; y = -192;//-408
		this->distanceBox[0] = 999;
		this->distanceBox[1] = 999;
		this->distanceBox[2] = 999;
		this->distanceBox[3] = 999;
		isMovingUp = false;
		isMovingDown = false;
		isMovingLeft = false;
		isMovingRight = false;
		isDash = false;
		isCharging = false;
		moveUnit = 8;
		downSpeed = 5;
		accelerateTime = 1;
		chLR = 0; chNum = 0;
		xmode = 0; macroWorking = 0;
		dash_d = 60;
		chargingTime = 90;
		clear_counter = 1800;
		clear_page = 0;
		mapNum = 0;
		mapDataInit();
		monster_counter = 0;
		for (int i = 0; i < 30; i++)monster[i] = NULL;
		isGameOver = false;
		p1 = new Character;
		boss = new Character;
		facai = new mesageBox;
		energyAndBullet = new Elementalattack;

		

	}
	Map::~Map() {
		delete p1;
		for (int i = 0; i < monster_counter; i++)delete monster[i];
		delete boss;
		delete facai;
		delete energyAndBullet;
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


		UI_Boss[0][1].LoadBitmap(hp2_button, RGB(255, 255, 255));
		UI_Boss[0][0].LoadBitmap(hp2_button, RGB(255, 255, 255));
		UI_Boss[1][1].LoadBitmap(hp_1, RGB(255, 255, 255));
		UI_Boss[2][1].LoadBitmap(hp_1, RGB(255, 255, 255));
		UI_Boss[3][1].LoadBitmap(hp_1, RGB(255, 255, 255));
		UI_Boss[4][1].LoadBitmap(hp_1, RGB(255, 255, 255));
		UI_Boss[5][1].LoadBitmap(hp_1, RGB(255, 255, 255));
		UI_Boss[1][0].LoadBitmap(hp_0, RGB(255, 255, 255));
		UI_Boss[2][0].LoadBitmap(hp_0, RGB(255, 255, 255));
		UI_Boss[3][0].LoadBitmap(hp_0, RGB(255, 255, 255));
		UI_Boss[4][0].LoadBitmap(hp_0, RGB(255, 255, 255));
		UI_Boss[5][0].LoadBitmap(hp_0, RGB(255, 255, 255));
		UI_Boss[6][1].LoadBitmap(hp_top, RGB(255, 255, 255));
		UI_Boss[6][0].LoadBitmap(hp_top, RGB(255, 255, 255));
		

		ground.AddBitmap(ground1, RGB(255, 255, 255));
		ground.AddBitmap(ground2, RGB(255, 255, 255));
		ground.AddBitmap(ground3, RGB(255, 255, 255));
		ground.AddBitmap(ground4, RGB(255, 255, 255));
		ground.AddBitmap(ground5, RGB(255, 255, 255));
		ground.AddBitmap(ground6, RGB(255, 255, 255));
		ground.AddBitmap(ground7, RGB(255, 255, 255));
		ground.SetDelayCount(10);

		map[0].LoadBitmap(m1, RGB(255, 255, 255));
		map[1].LoadBitmap(m2, RGB(255, 255, 255));

		finalList[0].LoadBitmap(clear0, RGB(0, 255, 0));
		finalList[1].LoadBitmap(clear1, RGB(0, 255, 0));
		finalList[2].LoadBitmap(clear2, RGB(0, 255, 0));
		finalList[3].LoadBitmap(clear4, RGB(0, 255, 0));

		this->generateMonster();
		p1->LoadBitmap();
		facai->LoadBitmap();
		energyAndBullet->LoadBitmap();
		energyAndBullet->AddMonster(monster[0]);
		energyAndBullet->AddMonster(monster[1]);
		boss->MonsterInit(2, 472, 2886);
		
		energyAndBullet->SetPlayerBoss(p1, boss);
		
	}


	////////////////////////////////////////

	void Map::SrollingUp(bool flag)
	{
		isMovingUp = flag;
		if(flag==true)CAudio::Instance()->Play(AUDIO_X_JUMP, false);
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

	void Map::Dash(bool flag)
	{
		if (xmode == 1) 
		{
			isDash = flag; 
			if (flag == true && dash_d == 200)CAudio::Instance()->Play(AUDIO_X_DASH, false);
		}
	}
		void Map::SetXY(int nx, int ny)
	{
		x = nx; y = ny;
	}

//////////////////////////////////////////////////
	void Map::playerAtk(bool flag)//遠
	{
		this->isCharging = flag;
		if (p1->getAttack() == true) {return; }

		if (flag == true || (flag == false && this->chargingTime <= 60)) { energyAndBullet->ShootingAtk(p1->getX() - this->x, p1->getY() - this->y,this->xmode);}
		if (flag == true) { p1->testAtk(true); }
		else if (flag == false && this->chargingTime <= 60) {  p1->testAtk(true); }
	}

	void Map::playerAtk2(bool flag) //近
	{
		if(p1->getAttack2()==false)p1->testAtk2(flag);
	}

	void Map::mesgNext() 
	{
		if (boss->isDead() == true&&clear_counter<1500) 
		{
			if (clear_page < 5)clear_page++;
		}


		if (facai->getOpen() == false)
		{
			p1->SetMapXY(this->x, this->y);
			if (mapNum == 0 && p1->Mbox(1185, 609) == true)facai->openMesgBox(true);
			if (mapNum == 0 && p1->Mbox(1900, 50) == true && monster[0]->isDead() == true && monster[1]->isDead() == true)SwitchMap();
			if (mapNum == 1 && p1->Mbox(263, 263) == true)facai->openMesgBox(true);

		}
		else 
		{
			facai->nextPage();
			CAudio::Instance()->Play(AUDIO_MESG_NEXT, false);
		}
	}

	void Map::ChargeAll() {
		energyAndBullet->Charge(1, 100);
		p1->setHP(100);
	}
	void Map::SwitchElem() 
	{
		energyAndBullet->switchElm();
	}

	void Map::SwitchMap(){
		if (mapNum == 0) 
		{
			mapNum = 1;
			this->x = 0;
			this->y = 0;
			monster[0]->setHP(0);
			monster[1]->setHP(0);
			energyAndBullet->AddMonster(boss);
			for (int i = 2; i < monster_counter; i++)energyAndBullet->AddMonster(monster[i]);
			TRACE("%d\n", monster_counter);
			
		}
	}

	bool Map::getDeadState()
	{
		if (p1->isDead() == true) 
		{
			if (xmode == 0 && p1->getAtkIsLast(6) == true) {
				p1->setHP(100);
				p1->resetAnimation(0, 6);
				p1->resetAnimation(1, 6);
				x = 248; y = -192;
				for (int i = 0; i < monster_counter; i++)monster[i]->MonsterStatusReset(0, 0);
				energyAndBullet->DelleteMonster(0);
				energyAndBullet->AddMonster(monster[0]);
				energyAndBullet->AddMonster(monster[1]);
				boss->MonsterStatusReset(0,0);
				ground.Reset();
				fillGround(2);
				mapNum = 0;
				CAudio::Instance()->Stop(AUDIO_BGM);
				CAudio::Instance()->Play(AUDIO_GAMEOVER,false);
				return true; 
			}
			if (xmode == 1 && p1->getAtkIsLast(30) == true) {
				p1->setHP(100);
				p1->resetAnimation(0, 30);
				p1->resetAnimation(1, 30);
				x = 248; y = -192;
				for (int i = 0; i < monster_counter; i++)monster[i]->MonsterStatusReset(0, 0);
				energyAndBullet->DelleteMonster(0);
				energyAndBullet->AddMonster(monster[0]);
				energyAndBullet->AddMonster(monster[1]);
				boss->MonsterStatusReset(0, 0);
				ground.Reset();
				fillGround(2);
				mapNum = 0;
				CAudio::Instance()->Stop(AUDIO_X_DEATH);
				CAudio::Instance()->Stop(AUDIO_BGM);
				CAudio::Instance()->Play(AUDIO_GAMEOVER, false);
				return true;
			}
		}
		return false;
	}

	bool Map::getClearState()
	{
		if (boss->isDead() == true && (clear_counter == 0 || clear_page >= 4)) {
			clear_counter = 1800;
			
			if (xmode == 0) {
				p1->setHP(100);
				p1->resetAnimation(0, 6);
				p1->resetAnimation(1, 6);
				x = 248; y = -192;
				for (int i = 0; i < monster_counter; i++)monster[i]->MonsterStatusReset(0, 0);
				energyAndBullet->DelleteMonster(0);
				energyAndBullet->AddMonster(monster[0]);
				energyAndBullet->AddMonster(monster[1]);
				boss->MonsterStatusReset(0, 0);
				ground.Reset();
				fillGround(2);
				CAudio::Instance()->Play(AUDIO_MENU, true);
				CAudio::Instance()->Stop(AUDIO_BGM);
				mapNum = 0;
			}
			if (xmode == 1) {
				p1->setHP(100);
				p1->resetAnimation(0, 30);
				p1->resetAnimation(1, 30);
				x = 248; y = -192;
				for (int i = 0; i < monster_counter; i++)monster[i]->MonsterStatusReset(0, 0);
				energyAndBullet->DelleteMonster(0);
				energyAndBullet->AddMonster(monster[0]);
				energyAndBullet->AddMonster(monster[1]);
				boss->MonsterStatusReset(0, 0);
				ground.Reset();
				fillGround(2);
				CAudio::Instance()->Play(AUDIO_MENU, true);
				CAudio::Instance()->Stop(AUDIO_BGM);
				mapNum = 0;
			}
			CAudio::Instance()->Stop(AUDIO_CLEAR_BGM);
			clear_page = 0;
			return true; 
		
		}
		return false;
	}
	void Map::setXmodel(int m)
	{
		p1->setXmodel(m);
		this->xmode = m;
		if (m == 1)CAudio::Instance()->Play(AUDIO_X, false);
	}

	int Map::getXmodel() 
	{
		return p1->getXmodel();
	}

	void Map::setMacro(int n)
	{
		if (n == 0) {
			macroWorking = 0;
		}
		if (n == 1) 
		{
			if (macroWorking == 0) {
				macroWorking = 1;
				p1->SetY(0);
			}
		}
	}

	////////////////////////////////////////
	void Map::ResetGravity() 
	{
		if (downSpeed > 6) {
			downSpeed = 5; 
			accelerateTime = 1;
		}
	}

	void Map::mesg(int phase)
	{
		if(phase==0)TRACE("x:%d y:%d\n",this->x,this->y);
		if (phase == 3)TRACE("x:%d y:%d    %d  %d ||  %d %d\n", p1->getX(), p1->getY(), this->x, this->y, p1->getX() - this->x, p1->getY() - this->y);
		if (phase == 4)TRACE("monster:%d %d  map:%d %d     ->%d %d\n", monster[0]->getX(), monster[0]->getY(),this->x,this->y, monster[0]->getX()- this->x, monster[0]->getY() - this->y);
		if (phase == 5)TRACE("m:%d %d   p:%d %d\n", monster[0]->getX() - this->x, monster[0]->getY() - this->y, p1->getX() - this->x, p1->getY() - this->y);
		if (phase == 6)TRACE("p=%d,%d   m=%d,%d", p1->getX(), p1->getY(), monster[0]->getX(), monster[0]->getY());
	}

	bool Map::block(Character *p,int UDRL)//U:0 D:1 R:3 L:2
	{
		int cw = p->getWidth(), ch = p->getHeight();
		int cx = p->getX(), cy = p->getY();
		int transX=this->CxToMapCoordinate(cx), transY=this->CyToMapCoordinate(cy);//轉換地圖座標
		int cx0 = transX, cy0 = transY;//左上
		int cx1 = cx0 + cw, cy1 = cy0;//右上
		int cx2 = cx0, cy2 = cy0 + ch;//左下
		int cx3 = cx0 + cw, cy3 = cy0 + ch;//右下
		CountDistance(p, UDRL);

		switch (UDRL)
		{
		case 0:
			for (int i = 0; i <= cw; i++)
			{
				if ((1 + cy0 - 1) >= 0 && mapData[mapNum][1 + cy0 - 1][1 + cx0 + i] == 1) {
					if (distanceBox[0] <= moveUnit)moveUnit = distanceBox[0]; return true; 
				}
				if ((1 + cy0 - 1) >= 0 && mapData[mapNum][1 + cy0 - 1][1 + cx0 + i] == 2) {
					p1->setHP(0);
				}
			}
			break;
		case 1:
			for (int i = 1; i <= cw-2; i++) 
			{
				if ((1 + cy2 + 1)>=0 && mapData[mapNum][1 + cy2+1][1 + cx2 + i] == 1){
					if (distanceBox[1] <= moveUnit)moveUnit = distanceBox[1];return true;
				}
				if ((1 + cy2 + 1)>=0&&mapData[mapNum][1 + cy2 + 1][1 + cx2 + i] == 2) {
					p1->setHP(0);
				}
			}
			break;
		case 2:
			for (int i = 1; i <= ch; i++)
			{
				if ((1 + cy0 + i)>=0&&mapData[mapNum][1 + cy0 + i][1 + cx0 - 1] == 1) {
					if (distanceBox[2] <= moveUnit)moveUnit = distanceBox[2]; return true; 
				}
				if ((1 + cy0 + i)>=0&&mapData[mapNum][1 + cy0 + i][1 + cx0 - 1] == 2) {
					p1->setHP(0);
				}
			}
			break;
		case 3:
			for (int i = 1; i <= ch; i++)
			{
				if ((1 + cy1 + i)>1&&mapData[mapNum][1 + cy1 + i][1 + cx1 + 1] == 1) {
					if (distanceBox[3] <= moveUnit)moveUnit = distanceBox[3]; return true; 
				}
				if ((1 + cy1 + i)>1&&mapData[mapNum][1 + cy1 + i][1 + cx1 + 1] == 2) {
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
		int transX = this->CxToMapCoordinate(cx), transY = this->CyToMapCoordinate(cy);//轉換地圖座標
		int cx0 = transX, cy0 = transY;//左上
		int cx1 = cx0 + cw, cy1 = cy0;//右上
		int cx2 = cx0, cy2 = cy0 + ch;//左下
		int cx3 = cx0 + cw, cy3 = cy0 + ch;//右下
		for (int i = -10; i <=64; i++) {

			if ((1 + cy0 - i - 1 )>=0&&i>=0&&UDRL == 0)for (int j = 0; j <= cw; j++)if (mapData[mapNum][1 + cy0 - i-1][1 + cx0 + j] == 1 &&distanceBox[0]>i)distanceBox[0] = i;
			if (UDRL == 1)for (int j = 0; j <= cw; j++)if ((1 + cy2 + i + 1)>=0&&mapData[mapNum][1 + cy2 + i+1][1 + cx2 + j] == 1 && distanceBox[1]>i)distanceBox[1] = i;
			if ((1 + cy0 ) >= 0 && i >= 0 && UDRL == 2)for (int j = 1; j <= ch-1; j++)if (mapData[mapNum][1 + cy0 + j][1 + cx0 - i-1] == 1 && distanceBox[2]>i)distanceBox[2] = i;
			if ((1 + cy1 ) >= 0 && i >= 0 && UDRL == 3)for (int j = 1; j <= ch-1; j++)if (mapData[mapNum][1 + cy1 + j][1 + cx1 + i+1] == 1 && distanceBox[3]>i)distanceBox[3] = i;

		}
	}

	void Map::fillGround(int n)
	{

		if (n == 0) 
		{
			for (int ay = 161; ay <= 192; ay++) {//填補熔岩
				for (int ax = 609; ax <= 832; ax++) mapData[0][ay][ax] = 1;
			}
		}

		if (n == 1) 
		{
			for (int ay = 2753; ay <= 2976; ay++) {// boss門
				for (int ax = 1377; ax <= 1440; ax++) mapData[1][ay][ax] = 1;
			}
		}
		if (n == 2) 
		{
			for (int ay = 2753; ay <= 2976; ay++) {// boss門
				for (int ax = 1377; ax <= 1440; ax++) mapData[1][ay][ax] = 0;
			}
			for (int ay = 161; ay <= 192; ay++) {//填補熔岩
				for (int ax = 609; ax <= 832; ax++) mapData[0][ay][ax] = 2;
			}
		}

	}
	int Map::CxToMapCoordinate(int cx) { return (cx - this->x); }
	int Map::CyToMapCoordinate(int cy) { return (cy - this->y); }

	void Map::OnMove()//出場動畫 死亡動畫 地圖動畫 受傷動畫最優先處理
	{

		if (boss->isDead() == true && clear_counter > 0)
		{
			clear_counter--;
			if (clear_counter == 1750) 
			{
				for (int i = 0; i <= AUDIO_CLEAR_BGM; i++)
				{
					CAudio::Instance()->Stop(i);
				}
			}
			if (clear_counter == 1700)CAudio::Instance()->Play(AUDIO_CLEAR, false);
			if (clear_counter == 1500)CAudio::Instance()->Play(AUDIO_CLEAR_BGM, false);
			if (clear_counter < 1702 && clear_counter>0)return;
		}

		if (macroWorking == 1) {//出場
			if (p1->animationOnMove() == true) { macroWorking = 999; chNum = 10; }
			return;
		}

		if (mapData[1][2753][1377] != 1 && mapNum == 1 && boss->getHP() != 999999) { fillGround(1);}
		if (p1->isDead() == true)//死亡
		{
			if (xmode == 0) 
			{
				if (chNum != 6) {  }
				chNum = 6; chLR = 0;
			}
			if (xmode == 1) 
			{
				if (chNum != 30) { CAudio::Instance()->Play(AUDIO_X_DEATH,true); }
				chNum = 30; 
			}
			p1->OnMove(chLR, chNum);
			return;
		}

		if (mapNum == 0 && monster[0]->isDead() == true)//怪物死亡與地圖互動動畫
		{
			if (ground.IsFinalBitmap() == false)
			{
				this->fillGround(0);
				ground.OnMove();
				return;
			}
		}
		if (chNum == 29 && xmode == 1)//受傷動畫
		{
			if (p1->getAtkIsLast(29) == true) {
				p1->resetAnimation(0, 29);
				p1->resetAnimation(1, 29);
				chNum = 10;
			}
			else 
			{
				if (chLR == 0) { this->x += 1; }
				if (chLR == 1) { this->x -= 1; }
				p1->OnMove(chLR, chNum);
			}

			if (mapNum == 0)
			{
				for (int i = 0; i < 2; i++) //處理怪物移動+攻擊
				{
					if (monster[i] != NULL)
					{
						monster[i]->AutoMove(this->y, this->x, p1);
						if (monster[i]->getHP() > 0 && monster[i]->MonsterAttack(this->x, this->y, p1) == true)chNum = 29;
					}
				}
			}
			else
			{
				for (int i = 2; i < monster_counter; i++) //處理怪物移動+攻擊
				{
					if (monster[i] != NULL)
					{
						monster[i]->AutoMove(this->y, this->x, p1);
						if (monster[i]->getHP() > 0 && monster[i]->MonsterAttack(this->x, this->y, p1) == true)chNum = 29;
					}
				}

				if (boss->getHP() > 0)
				{
					boss->AutoMove(this->y, this->x, p1);
					if (boss->MonsterAttack(this->x, this->y, p1) == true)chNum = 29;
					if (boss->getAttack() == true)
					{
						energyAndBullet->BossShootingAtk(boss->getX() - this->x, boss->getY() - this->y);
						boss->testAtk(false);
					}
				}
			}
			return;
		}

		if (p1->getAttack2() == true && isMovingUp == false) 
		{
			isMovingLeft = false;
			isMovingRight = false;
		}

		if (block(p1, 1) == false)
		{
			moveUnit = downSpeed;
			block(p1, 1);
			this->distanceBox[1] = 999;
			if (distanceBox[1] < downSpeed)downSpeed = distanceBox[1];
			moveUnit = downSpeed;
			this->y -= moveUnit;
			this->distanceBox[1] -= moveUnit;
			///////////////////////////////////////////////////////////控制貼圖
			if (xmode == 0)
			{
				if (isMovingUp == false && chNum != 5)
				{
					chNum = 3;
				}
			}
			else if (xmode == 1)
			{
				if (isMovingUp == false && chNum != 15)
				{
					chNum = 13;
				}
			}

			///////////////////////////////////////////////////////////
			if (accelerateTime == 0) { downSpeed++; accelerateTime = 1; }
			else { accelerateTime--; }
			///////////////////////////////////////////////////////////控制貼圖
			if (downSpeed >= 9 && isMovingUp == true)
			{
				if (xmode == 0) { chNum = 3; }
				else { if(p1->getAttack2() == false)chNum = 13; }

				isMovingUp = false; downSpeed = 7;
			}
			///////////////////////////////////////////////////////////
			p1->SetMapXY(this->x, this->y);
		}
		else if (block(p1, 1) == true)
		{
			downSpeed = 5;
			if (this->distanceBox[1] == -1)this->distanceBox[1] = 0;
			if (this->distanceBox[1] < 0)
			{
				this->y += this->distanceBox[1] * (-1);
				this->distanceBox[1] = this->distanceBox[1] * (-1);
			}
			///////////////////////////////////////////////////////////控制貼圖
			if (xmode == 0) { chNum = 0; }
			else { chNum = 10; }
			///////////////////////////////////////////////////////////
			p1->SetMapXY(this->x, this->y);
		}


		if (isMovingUp == true) {
			moveUnit = 25;
			if (xmode == 1)moveUnit = 30;
			this->distanceBox[0] = 999;
			if (block(p1, 0) == true)return;
			///////////////////////////////////////////////////////////控制貼圖
			if (xmode == 0) { chNum = 2; }
			else { chNum = 12; }
			///////////////////////////////////////////////////////////
			this->y += moveUnit;
			this->distanceBox[0] -= moveUnit;
			p1->SetMapXY(this->x, this->y);
		}



		if (isMovingLeft == false && isMovingRight == true) {
			moveUnit = 8;
			if (xmode == 1)moveUnit = 10;
			if (isDash == true && dash_d > 0)moveUnit = 16;
			this->distanceBox[3] = 999;
			if (block(p1, 3) == true && p1->getAttack2() == true)return;
			///////////////////////////////////////////////////////////控制貼圖
			if (this->distanceBox[1] == 0) {
				if (xmode == 0) 
				{ 
					chNum = 1; 
				}else if(isDash==false)
				{ 
					chNum = 11;
					p1->resetAnimation(0, 19);
					p1->resetAnimation(1, 19);
					dash_d = 200;
				}
				else if (isDash == true)
				{
					if (dash_d > 0) { chNum = 19;dash_d -= moveUnit;}
					else { chNum = 11; }
				}
			}
			///////////////////////////////////////////////////////////
				chLR = 0;
				this->x -= moveUnit;
				this->distanceBox[3] -= moveUnit;
				p1->SetMapXY(this->x, this->y);
		}

		if (isMovingRight == false && isMovingLeft == true) {
			moveUnit = 8;
			if (xmode == 1)moveUnit = 10;
			if (isDash == true && dash_d > 0)moveUnit = 16;
			this->distanceBox[2] = 999;
			if (block(p1, 2) == true && p1->getAttack2() == true)return;
			///////////////////////////////////////////////////////////控制貼圖
			if (this->distanceBox[1] == 0) {
				if (xmode == 0) 
				{ 
					chNum = 1; 
				}else if(isDash==false)
				{ 
					chNum = 11; 
					p1->resetAnimation(0, 19);
					p1->resetAnimation(1, 19);
					dash_d = 200;
				}else if (isDash == true)
				{
					if (dash_d > 0) { chNum = 19; dash_d -= moveUnit;}
					else { chNum = 11; }
				}
			}
			///////////////////////////////////////////////////////////
				chLR = 1;
				this->x += moveUnit;
				this->distanceBox[2] -= moveUnit;
				p1->SetMapXY(this->x, this->y);
		}

		///////////////////////////////////////////////////////////控制貼圖
		if (isMovingRight == false && isMovingLeft == false && isMovingUp == false && this->distanceBox[1] == 0) {
			if (xmode == 0) { chNum = 0; }
			else { chNum = 10; }
		}

		//遠攻
		if (isMovingUp == false && isMovingRight == false && isMovingLeft == false && this->distanceBox[1] == 0 && p1->getAttack() == true) {//在地板不移動
			if (xmode == 0) { chNum = 4; }
			else { chNum = 14; }
		}
		else if (isMovingUp == false && (isMovingRight == true || isMovingLeft == true) && this->distanceBox[1] == 0 && p1->getAttack() == true) {//再地板左右移動
			if (xmode == 0) { chNum = 4; }
			else 
			{
				if (isDash == true && dash_d > 0) { chNum = 20; }
				else { chNum = 18; }

			}
		}
		else if (this->distanceBox[1] != 0 && p1->getAttack() == true) {//跳躍時
			if (xmode == 0) { chNum = 4; }
			else { chNum = 16; }
		}

		//近攻
		if (isMovingUp == false && isMovingLeft == false && isMovingRight == false && this->distanceBox[1] == 0 && p1->getAttack2() == true) {//地板
			if (xmode == 0) { chNum = 5; }
			else { chNum = 15; }
		}
		else if (this->distanceBox[1] != 0 && p1->getAttack2() == true){//跳躍時
			if (xmode == 0) { chNum = 5; }
			else { chNum = 17; }
		}
		///////////////////////////////////////////////////////////


		if (xmode == 0 && chNum == 5 && p1->getAtkIsLast(5) == true)
		{
			energyAndBullet->CloseRangeAtk();
			this->chNum = 0;
		}

		if (isMovingUp == false && this->distanceBox[1] == 0 && xmode == 1 && chNum == 15 && p1->getAtkIsLast(15) == true)//地板
		{
			energyAndBullet->CloseRangeAtk();
			this->chNum = 10;
		}
		else if (this->distanceBox[1] == 0 && xmode == 1 && chNum == 17 && p1->getAtkIsLast(17) == true) {//跳躍+近攻
			energyAndBullet->CloseRangeAtk();
			this->chNum = 10;
		}

		
		p1->OnMove(chLR,chNum);//角色與怪物移動
		if (isCharging == true&&xmode==1)
		{
			if (chargingTime == 78) { CAudio::Instance()->Play(AUDIO_X_StartCharge, false); }
			
			if(chargingTime>-1)chargingTime--;
			if (chargingTime == 72) { energyAndBullet->SetChargingLevel(0); 
			}
			if (chargingTime == 60) {
				CAudio::Instance()->Stop(AUDIO_X_StartCharge);
				CAudio::Instance()->Play(AUDIO_X_Charge, true);
				if (energyAndBullet->getUIAtktype() == 0)energyAndBullet->Charge(0, 1);
			}
			if (chargingTime == 30)
			{
				energyAndBullet->SetChargingLevel(1);
				if(energyAndBullet->getUIAtktype()==0)energyAndBullet->Charge(0, 2);
			}
			if (chargingTime == 0)
			{
				energyAndBullet->SetChargingLevel(2);
			}
		}
		else
		{
			CAudio::Instance()->Stop(AUDIO_X_Charge);
			CAudio::Instance()->Stop(AUDIO_X_StartCharge);
			energyAndBullet->SetChargingLevel(-1);
			if (chargingTime == -1) 
			{
				if (energyAndBullet->getUIAtktype() == 0)energyAndBullet->Charge(0, 1); 
			}
			else if(chargingTime!=90)
			{ 
				if (energyAndBullet->getUIAtktype() == 0)energyAndBullet->Charge(0, 0);
			}
			this->chargingTime = 90;
		}




		if (mapNum == 0)
		{
			for (int i = 0; i < 2; i++) //處理怪物移動+攻擊
			{
				if (monster[i] != NULL) 
				{
					monster[i]->AutoMove(this->y, this->x,p1);
					if (monster[i]->getHP() > 0 && monster[i]->MonsterAttack(this->x, this->y, p1) == true) 
					{
						chNum = 29; 
						CAudio::Instance()->Play(AUDIO_DAMAGED, false);
					}
				}
			}
		}
		else 
		{

			for (int i = 2; i < monster_counter; i++) //處理怪物移動+攻擊
			{
				if (monster[i] != NULL)
				{
					monster[i]->AutoMove(this->y, this->x, p1);
					if (monster[i]->getHP() > 0 && monster[i]->MonsterAttack(this->x, this->y, p1) == true)
					{
						chNum = 29;
						CAudio::Instance()->Play(AUDIO_DAMAGED, false);
					}
				}
			}

			if (boss->getHP() > 0)
			{
				boss->AutoMove(this->y, this->x, p1);
				if (boss->MonsterAttack(this->x, this->y, p1) == true) 
				{
					chNum = 29;
					CAudio::Instance()->Play(AUDIO_DAMAGED, false);
				}
				if (boss->getAttack() == true)
				{
					energyAndBullet->BossShootingAtk(boss->getX() - this->x, boss->getY() - this->y);
					boss->testAtk(false);
				}
				if (boss->getAttack2() == true)
				{
					monster[13]->MonsterStatusReset(boss->getX() - this->x+60, boss->getY() - this->y+60);
					monster[14]->MonsterStatusReset(boss->getX() - this->x-60, boss->getY() - this->y-60);
					monster[15]->MonsterStatusReset(boss->getX() - this->x-60, boss->getY() - this->y+60);
					monster[16]->MonsterStatusReset(boss->getX() - this->x+60, boss->getY() - this->y-60);
					boss->testAtk2(false);
				}
			}
		}
	
		energyAndBullet->OnMove(this->y, this->x);//處理子彈碰撞
		facai->OnMove(mapNum);//對話框框
	}

	void Map::OnShow() 
	{
		map[mapNum].SetTopLeft(x, y);
		map[mapNum].ShowBitmap();
		//TRACE("PLAYER  %d,%d    %d,%d   %d,%d",  p1->getX(), p1->getY() ,this->x,this->y, p1->getX()- this->x, p1->getY()- this->y);
		//TRACE("MONSTER %d,%d    %d,%d   %d,%d", monster[0]->getX(), monster[0]->getY(), -this->x, -this->y, monster[0]->getX() - this->x, monster[0]->getY() - this->y);
		if (mapNum == 0 && monster[0] != NULL&& monster[0]->isDead() == true)
		{
			ground.SetTopLeft(608+x,160+y);
			ground.OnShow();
		}


		if (mapNum == 0) 
		{
			for (int i = 0; i < 2; i++)
			{
				if (monster[i] != NULL&&monster[i]->getHP() > 0)monster[i]->OnShow();
			}
		}
		else 
		{
			for (int i = 2; i < monster_counter; i++)
			{
				if (monster[i] != NULL&&monster[i]->getHP() > 0)monster[i]->OnShow();
			}
			if (boss->getHP() > 0) {
				boss->OnShow();
			}
		}


		

		if (macroWorking == 1) {p1->animationOnShow(); } else {p1->OnShow();}

		if (xmode == 0)
		{
			UI[p1->getHP() / 6].SetTopLeft(20, 20);
			UI[p1->getHP() / 6].ShowBitmap();
			energyAndBullet->OnShow();
		}

		printMegaManUI(40, 160,p1);
		energyAndBullet->OnShow();
		printBossUI(760, 160,boss);

		if (mapNum == 0 && p1->Mbox(1185, 609) == true && facai->getOpen() == false)
		{
			facai->setHint(true);
		}
		else 
		{
			facai->setHint(false);
		}

		if (mapNum == 0 && p1->Mbox(1900, 50) == true && monster[0]->isDead() == true && monster[1]->isDead() == true)
		{
			facai->setHint(true);
		}
		else if (mapNum == 0 && (monster[0]->isDead() == true || monster[1]->isDead() == true))
		{
			facai->setHint(false);
		}

		if (mapNum == 1 && p1->Mbox(263, 263) == true && facai->getOpen() == false)
		{
			facai->setHint(true);
		}
		else if(mapNum == 1)
		{
			facai->setHint(false);
		}

		facai->OnShow();
		if (clear_counter > -1 && clear_counter < 1500 && clear_page < 4)
		{
			finalList[clear_page].SetTopLeft(0, 0);
			finalList[clear_page].ShowBitmap();
		}
	}
	////////////////////////////////////////

	void Map::printMegaManUI(int ux,int uy, Character *p) //40.160
	{
		if (p->getXmodel() != 1)return;
		int hp = p->getHP();

		UI_megaman[6][1].SetTopLeft(ux, uy); UI_megaman[6][1].ShowBitmap();

		if (hp >= 80) { UI_megaman[5][1].SetTopLeft(ux, uy + 6); UI_megaman[5][1].ShowBitmap();}
		else { UI_megaman[5][0].SetTopLeft(ux, uy + 6); UI_megaman[5][0].ShowBitmap(); }

		if (hp >= 60) { UI_megaman[4][1].SetTopLeft(ux, uy + 30); UI_megaman[4][1].ShowBitmap();}
		else { UI_megaman[4][0].SetTopLeft(ux, uy + 30); UI_megaman[4][0].ShowBitmap();}

		if (hp >= 40) { UI_megaman[3][1].SetTopLeft(ux, uy + 54); UI_megaman[3][1].ShowBitmap();}
		else { UI_megaman[3][0].SetTopLeft(ux, uy + 54); UI_megaman[3][0].ShowBitmap();}

		if (hp >= 20) { UI_megaman[2][1].SetTopLeft(ux, uy + 78); UI_megaman[2][1].ShowBitmap(); }
		else { UI_megaman[2][0].SetTopLeft(ux, uy + 78); UI_megaman[2][0].ShowBitmap(); }

		if (hp > 0) { UI_megaman[1][1].SetTopLeft(ux, uy + 102); UI_megaman[1][1].ShowBitmap();}
		else { UI_megaman[1][0].SetTopLeft(ux, uy + 102); UI_megaman[1][0].ShowBitmap();}

		UI_megaman[0][1].SetTopLeft(ux, uy+126); UI_megaman[0][1].ShowBitmap();
	}

	void Map::printBossUI(int ux, int uy,Character *mboss) //40.160
	{
		if (mboss==NULL||mboss->isBossLevel() == false) return;

		int hp = mboss->getHP();

		UI_Boss[6][1].SetTopLeft(ux, uy); UI_Boss[6][1].ShowBitmap();

		if (hp >= 800) { UI_Boss[5][1].SetTopLeft(ux, uy + 6); UI_Boss[5][1].ShowBitmap(); }
		else { UI_Boss[5][0].SetTopLeft(ux, uy + 6); UI_Boss[5][0].ShowBitmap(); }

		if (hp >= 600) { UI_Boss[4][1].SetTopLeft(ux, uy + 30); UI_Boss[4][1].ShowBitmap(); }
		else { UI_Boss[4][0].SetTopLeft(ux, uy + 30); UI_Boss[4][0].ShowBitmap(); }

		if (hp >= 400) { UI_Boss[3][1].SetTopLeft(ux, uy + 54); UI_Boss[3][1].ShowBitmap(); }
		else { UI_Boss[3][0].SetTopLeft(ux, uy + 54); UI_Boss[3][0].ShowBitmap(); }

		if (hp >= 200) { UI_Boss[2][1].SetTopLeft(ux, uy + 78); UI_Boss[2][1].ShowBitmap(); }
		else { UI_Boss[2][0].SetTopLeft(ux, uy + 78); UI_Boss[2][0].ShowBitmap(); }

		if (hp > 0) { UI_Boss[1][1].SetTopLeft(ux, uy + 102); UI_Boss[1][1].ShowBitmap(); }
		else { UI_Boss[1][0].SetTopLeft(ux, uy + 102); UI_Boss[1][0].ShowBitmap(); }

		UI_Boss[0][1].SetTopLeft(ux, uy + 126); UI_Boss[0][1].ShowBitmap();
	}

	void Map::mapDataInit() 
	{
		for (int ay = 0; ay < 6000; ay++) {
			for (int ax = 0; ax < 6000; ax++) mapData[0][ay][ax] = 0;
		}
		for (int ay = 0; ay < 6000; ay++) {
			for (int ax = 0; ax < 6000; ax++) mapData[1][ay][ax] = 1;
		}
		//地圖物件

		for (int ay = 641; ay <= 672; ay++) {//磚1
			for (int ax = 385; ax <= 448; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 609; ay <= 640; ay++) {//磚2
			for (int ax = 513; ax <= 576; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 577; ay <= 608; ay++) {//磚3
			for (int ax = 641; ax <= 704; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 545; ay <= 576; ay++) {//磚4
			for (int ax = 737; ax <= 800; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 545; ay <= 576; ay++) {//磚5
			for (int ax = 833; ax <= 896; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 481; ay <= 512; ay++) {//磚6
			for (int ax = 897; ax <= 960; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 417; ay <= 448; ay++) {//磚7
			for (int ax = 801; ax <= 832; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 385; ay <= 416; ay++) {//磚8
			for (int ax = 705; ax <= 768; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 385; ay <= 416; ay++) {//磚9
			for (int ax = 609; ax <= 672; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 417; ay <= 448; ay++) {//磚10
			for (int ax = 513; ax <= 608; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 449; ay <= 480; ay++) {//磚11
			for (int ax = 385; ax <= 448; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 417; ay <= 448; ay++) {//磚12
			for (int ax = 289; ax <= 352; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 385; ay <= 416; ay++) {//磚13
			for (int ax = 193; ax <= 256; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 321; ay <= 352; ay++) {//磚14
			for (int ax = 129; ax <= 192; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 289; ay <= 320; ay++) {//磚15
			for (int ax = 33; ax <= 96; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 225; ay <= 256; ay++) {//磚16
			for (int ax = 257; ax <= 320; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 193; ay <= 224; ay++) {//磚17
			for (int ax = 321; ax <= 352; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 161; ay <= 192; ay++) {//磚18
			for (int ax = 353; ax <= 608; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 193; ay <= 224; ay++) {//磚19
			for (int ax = 577; ax <= 864; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 161; ay <= 192; ay++) {//磚20
			for (int ax = 833; ax <= 1088; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 513; ay <= 832; ay++) {//磚21
			for (int ax = 1089; ax <= 1120; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 641; ay <= 672; ay++) {//磚22
			for (int ax = 1569; ax <= 2080; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 609; ay <= 640; ay++) {//磚23
			for (int ax = 1921; ax <= 2080; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 577; ay <= 608; ay++) {//磚24
			for (int ax = 1985; ax <= 2080; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 545; ay <= 576; ay++) {//磚25
			for (int ax = 2017; ax <= 2080; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 513; ay <= 544; ay++) {//磚26
			for (int ax = 2049; ax <= 2080; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 449; ay <= 480; ay++) {//磚27
			for (int ax = 1921; ax <= 1952; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 417; ay <= 448; ay++) {//磚28
			for (int ax = 1825; ax <= 1856; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 417; ay <= 448; ay++) {//磚29
			for (int ax = 1473; ax <= 1760; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 353; ay <= 448; ay++) {//磚30
			for (int ax = 1377; ax <= 1472; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 321; ay <= 352; ay++) {//磚31
			for (int ax = 1377; ax <= 1440; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 289; ay <= 320; ay++) {//磚32
			for (int ax = 1121; ax <= 1408; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 257; ay <= 288; ay++) {//磚33
			for (int ax = 1217; ax <= 1344; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 225; ay <= 256; ay++) {//磚34
			for (int ax = 1217; ax <= 1280; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 193; ay <= 224; ay++) {//磚35
			for (int ax = 1217; ax <= 1248; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 193; ay <= 224; ay++) {//磚36
			for (int ax = 1441; ax <= 1504; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 161; ay <= 192; ay++) {//磚37
			for (int ax = 1505; ax <= 1536; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 129; ay <= 160; ay++) {//磚38
			for (int ax = 1537; ax <= 2080; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 770; ay <= 832; ay++) {//磚39
			for (int ax = 801; ax <= 1088; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 795; ay <= 832; ay++) {//磚40
			for (int ax = 1505; ax <= 2080; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 673; ay <= 832; ay++) {//地板1
			for (int ax = 1; ax <= 800; ax++) mapData[0][ay][ax] = 1;
		}
		for (int ay = 705; ay <= 832; ay++) {//地板2
			for (int ax = 1121; ax <= 1504; ax++) mapData[0][ay][ax] = 1;
		}

		for (int ay = 161; ay <= 192; ay++) {//熔岩1
			for (int ax = 609; ax <= 832; ax++) mapData[0][ay][ax] = 2;
		}
		for (int ay = 611; ay <= 769; ay++) {//熔岩2
			for (int ax = 801; ax <= 1088; ax++) mapData[0][ay][ax] = 2;
		}

		//最外圈邊界;
		for (int ay = 0; ay < 1; ay++) {//上
			for (int ax = 0; ax < 2082; ax++) mapData[0][ay][ax] = 1;
		}
		for (int ay = 833; ay < 834; ay++) {//下
			for (int ax = 0; ax < 2082; ax++) mapData[0][ay][ax] = 1;
		}
		for (int ay = 0; ay < 834; ay++) {//左
			for (int ax = 0; ax < 1; ax++) mapData[0][ay][ax] = 1;
		}
		for (int ay = 0; ay < 834; ay++) {//右
			for (int ax = 2081; ax < 2082; ax++) mapData[0][ay][ax] = 1;
		}
		// 
		/////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////
		//map2
		for (int ay = 33; ay <= 384; ay++) {// 1
			for (int ax = 33; ax <= 4896; ax++) mapData[1][ay][ax] = 0;
		}

		for (int ay = 385; ay <= 1216; ay++) {// 2
			for (int ax = 3425; ax <= 3616; ax++) mapData[1][ay][ax] = 0;
		}

		for (int ay = 737; ay <= 1216; ay++) {// 3
			for (int ax = 3617; ax <= 4896; ax++) mapData[1][ay][ax] = 0;
		}

		for (int ay = 385; ay <= 736; ay++) {// 4
			for (int ax = 2049; ax <= 2304; ax++) mapData[1][ay][ax] = 0;
		}

		for (int ay = 737; ay <= 1248; ay++) {// 5
			for (int ax = 33; ax <= 2528; ax++) mapData[1][ay][ax] = 0;
		}

		for (int ay = 1249; ay <= 1568; ay++) {// 6
			for (int ax = 737; ax <= 2528; ax++) mapData[1][ay][ax] = 0;
		}

		for (int ay = 737; ay <= 1024; ay++) {// 7
			for (int ax = 2529; ax <= 3008; ax++) mapData[1][ay][ax] = 0;
		}

		for (int ay = 737; ay <= 1632; ay++) {// 8
			for (int ax = 3009; ax <= 3328; ax++) mapData[1][ay][ax] = 0;
		}

		for (int ay = 1313; ay <= 1632; ay++) {// 9
			for (int ax = 3329; ax <= 4896; ax++) mapData[1][ay][ax] = 0;
		}

		for (int ay = 1217; ay <= 1312; ay++) {// 10
			for (int ax = 4481; ax <= 4896; ax++) mapData[1][ay][ax] = 0;
		}

		for (int ay = 1089; ay <= 1664; ay++) {// 11
			for (int ax = 2689; ax <= 2944; ax++) mapData[1][ay][ax] = 0;
		}

		for (int ay = 1665; ay <= 2976; ay++) {// 12
			for (int ax = 33; ax <= 1376; ax++) mapData[1][ay][ax] = 0;
		}

		for (int ay = 1665; ay <= 2976; ay++) {// 13
			for (int ax = 1441; ax <= 1728; ax++) mapData[1][ay][ax] = 0;
		}

		for (int ay = 2753; ay <= 2976; ay++) {// 14
			for (int ax = 1440; ax <= 1728; ax++) mapData[1][ay][ax] = 0;
		}

		for (int ay = 1665; ay <= 1824; ay++) {// 15
			for (int ax = 1729; ax <= 3136; ax++) mapData[1][ay][ax] = 0;
		}

		for (int ay = 1665; ay <= 2240; ay++) {// 16
			for (int ax = 3137; ax <= 3392; ax++) mapData[1][ay][ax] = 0;
		}

		for (int ay = 2241; ay <= 2976; ay++) {// 17
			for (int ax = 3201; ax <= 3392; ax++) mapData[1][ay][ax] = 0;
		}

		for (int ay = 2625; ay <= 2976; ay++) {// 18
			for (int ax = 3393; ax <= 4896; ax++) mapData[1][ay][ax] = 0;
		}

		for (int ay = 2369; ay <= 2528; ay++) {// 19
			for (int ax = 3649; ax <= 4896; ax++) mapData[1][ay][ax] = 0;
		}

		for (int ay = 1665; ay <= 2528; ay++) {// 20
			for (int ax = 3457; ax <= 3648; ax++) mapData[1][ay][ax] = 0;
		}

		for (int ay = 2529; ay <= 2624; ay++) {// 21
			for (int ax = 4481; ax <= 4896; ax++) mapData[1][ay][ax] = 0;
		}

		for (int ay = 1825; ay <= 1984; ay++) {// 22
			for (int ax = 3649; ax <= 3776; ax++) mapData[1][ay][ax] = 0;
		}

		for (int ay = 1729; ay <= 2016; ay++) {// 23
			for (int ax = 3777; ax <= 4640; ax++) mapData[1][ay][ax] = 0;
		}

		for (int ay = 2017; ay <= 2304; ay++) {// 24
			for (int ax = 3841; ax <= 4000; ax++) mapData[1][ay][ax] = 0;
		}

		for (int ay = 2081; ay <= 2304; ay++) {// 25	
			for (int ax = 4001; ax <= 4896; ax++) mapData[1][ay][ax] = 0;
		}

		for (int ay = 1633; ay <= 2080; ay++) {// 26
			for (int ax = 4705; ax <= 4896; ax++) mapData[1][ay][ax] = 0;
		}

		for (int ay = 2337; ay <= 2656; ay++) {// 27
			for (int ax = 1729; ax <= 2272; ax++) mapData[1][ay][ax] = 0;
		}

		for (int ay = 2337; ay <= 2624; ay++) {// 28
			for (int ax = 2273; ax <= 2368; ax++) mapData[1][ay][ax] = 0;
		}

		for (int ay = 2337; ay <= 2752; ay++) {// 29
			for (int ax = 2369; ax <= 2848; ax++) mapData[1][ay][ax] = 0;
		}

		for (int ay = 2753; ay <= 2848; ay++) {// 30
			for (int ax = 2625; ax <= 2848; ax++) mapData[1][ay][ax] = 0;
		}

		for (int ay = 2849; ay <= 2976; ay++) {// 31
			for (int ax = 2721; ax <= 2848; ax++) mapData[1][ay][ax] = 0;
		}

		for (int ay = 2785; ay <= 2976; ay++) {// 32
			for (int ax = 2849; ax <= 3200; ax++) mapData[1][ay][ax] = 0;
		}

		for (int ay = 2657; ay <= 2664; ay++) {// 溶岩上
			for (int ax = 2177; ax <= 2272; ax++) mapData[1][ay][ax] = 0;
		}

		for (int ay = 2665; ay <= 2848; ay++) {// 溶岩
			for (int ax = 2177; ax <= 2272; ax++) mapData[1][ay][ax] = 2;
		}

		for (int ay = 2753; ay <= 2976; ay++) {// boss門
			for (int ax = 1377; ax <= 1440; ax++) mapData[1][ay][ax] = 0;
		}

	}

	void Map::generateMonster() 
	{

			monster[0] = new Character; monster_counter++;
			monster[1] = new Character; monster_counter++;
			monster[0]->MonsterInit(0, 370, 95);
			monster[1]->MonsterInit(1, 850, 95);
			monster[2] = new Character; monster_counter++;
			monster[2]->MonsterInit(4, 1312, 294);
			monster[3] = new Character; monster_counter++;
			monster[3]->MonsterInit(3, 2368, 294);
			monster[4] = new Character; monster_counter++;
			monster[4]->MonsterInit(3, 3056, 294);
			monster[5] = new Character; monster_counter++;
			monster[5]->MonsterInit(3, 1100, 1477);
			monster[6] = new Character; monster_counter++;
			monster[6]->MonsterInit(3, 1270, 1477);
			monster[7] = new Character; monster_counter++;
			monster[7]->MonsterInit(3, 2064, 1477);
			monster[8] = new Character; monster_counter++;
			monster[8]->MonsterInit(3, 3700, 1543);
			monster[9] = new Character; monster_counter++;
			monster[9]->MonsterInit(3, 4290, 1926);
			monster[10] = new Character; monster_counter++;
			monster[10]->MonsterInit(3, 3932, 2886);
			monster[11] = new Character; monster_counter++;
			monster[11]->MonsterInit(1, 1882, 2591);
			monster[12] = new Character; monster_counter++;
			monster[12]->MonsterInit(1, 2664, 306);
			
			monster[13] = new Character; monster_counter++;
			monster[13]->MonsterInit(5, 874, 2886);
			monster[14] = new Character; monster_counter++;
			monster[14]->MonsterInit(5, 774, 2886);
			monster[15] = new Character; monster_counter++;
			monster[15]->MonsterInit(5, 674, 2886);
			monster[16] = new Character; monster_counter++;
			monster[16]->MonsterInit(5, 574, 2886);

			
	}
}