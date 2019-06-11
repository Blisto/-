#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "mesageBox.h"

namespace game_framework
{
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


	mesageBox::mesageBox() {
		x = 0; y = 0;
		time = 0;
		page = 0;
		open = false;
		isHint = false;
		this->mapNum = 0;
	}
	mesageBox::~mesageBox() {
		
	}

	void mesageBox::LoadBitmap() 
	{
		x = 0; y = 0;
		time = 0;
		page = 0;
		open = false;
		mesg[0].AddBitmap(mb0, RGB(255, 255, 255));
		mesg[0].AddBitmap(mb1, RGB(255, 255, 255));
		mesg[0].SetDelayCount(5);
		mesg[1].AddBitmap(mb2, RGB(255, 255, 255));
		mesg[1].AddBitmap(mb3, RGB(255, 255, 255));
		mesg[1].SetDelayCount(5);
		mesg[2].AddBitmap(mb4, RGB(255, 255, 255));
		mesg[2].AddBitmap(mb5, RGB(255, 255, 255));
		mesg[2].SetDelayCount(5);
		mesg[3].AddBitmap(mb6, RGB(255, 255, 255));
		mesg[3].AddBitmap(mb7, RGB(255, 255, 255));
		mesg[3].SetDelayCount(5);
		mesg[4].AddBitmap(mb8, RGB(255, 255, 255));
		mesg[4].AddBitmap(mb9, RGB(255, 255, 255));
		mesg[4].SetDelayCount(5);
		mesg[5].AddBitmap(mb10, RGB(255, 255, 255));
		mesg[5].AddBitmap(mb11, RGB(255, 255, 255));
		mesg[5].SetDelayCount(5);



		mesg_map2[0].LoadBitmap(Mesg01, RGB(255, 242, 0));
		mesg_map2[1].LoadBitmap(Mesg02, RGB(255, 242, 0));
		mesg_map2[2].LoadBitmap(Mesg03, RGB(255, 242, 0));
		mesg_map2[3].LoadBitmap(Mesg04, RGB(0, 255, 0));
		mesg_map2[4].LoadBitmap(Mesg05, RGB(0, 255, 0));
		mesg_map2[5].LoadBitmap(Mesg06, RGB(0, 255, 0));
		mesg_map2[6].LoadBitmap(Mesg07, RGB(0, 255, 0));
		mesg_map2[7].LoadBitmap(Mesg08, RGB(0, 255, 0));
		mesg_map2[8].LoadBitmap(Mesg09, RGB(0, 255, 0));
		mesg_map2[9].LoadBitmap(Mesg10, RGB(0, 255, 0));
		mesg_map2[10].LoadBitmap(Mesg11, RGB(0, 255, 0));
		mesg_map2[11].LoadBitmap(Mesg12, RGB(0, 255, 0));
		mesg_map2[12].LoadBitmap(Mesg13, RGB(0, 255, 0));
		mesg_map2[13].LoadBitmap(Mesg14, RGB(0, 255, 0));
		mesg_map2[14].LoadBitmap(Mesg15, RGB(0, 255, 0));
		mesg_map2[15].LoadBitmap(Mesg16, RGB(0, 255, 0));
		mesg_map2[16].LoadBitmap(Mesg17, RGB(0, 255, 0));
		mesg_map2[17].LoadBitmap(Mesg18, RGB(0, 255, 0));
		mesg_map2[18].LoadBitmap(Mesg19, RGB(0, 255, 0));
		mesg_map2[19].LoadBitmap(Mesg20, RGB(0, 255, 0));
		mesg_map2[20].LoadBitmap(Mesg21, RGB(0, 255, 0));
		mesg_map2[21].LoadBitmap(Mesg22, RGB(0, 255, 0));
		mesg_map2[22].LoadBitmap(Mesg23, RGB(0, 255, 0));
		mesg_map2[23].LoadBitmap(Mesg24, RGB(0, 255, 0));
		mesg_map2[24].LoadBitmap(Mesg25, RGB(0, 255, 0));
		spaceBar.AddBitmap(spacebar0, RGB(255, 255, 255));
		spaceBar.AddBitmap(spacebar1, RGB(255, 255, 255));
		spaceBar.SetDelayCount(10);

	}
	void mesageBox::nextPage() 
	{
		if (this->mapNum == 0) 
		{
			if (this->isFinal() == false)
			{
				this->page++;
			}
			else
			{
				this->open = false;
				this->page = 0;
			}
		}
		if (this->mapNum == 1) 
		{
			if (this->isFinal() == false)
			{
				page++;
				if (page == 1)CAudio::Instance()->Play(AUDIO_CATVOICE1, false);
				if (page == 7)CAudio::Instance()->Play(AUDIO_BGM, true);
				if (page == 10)CAudio::Instance()->Play(AUDIO_CHORD, false);
				if (page == 18)CAudio::Instance()->Play(AUDIO_CATVOICE2, false);
				if (page == 24)CAudio::Instance()->Play(AUDIO_IAMGUNDAM, false);

			}
			else
			{
				this->open = false;
				this->page = 0;
			}
		}

	}

	void mesageBox::setHint(bool flag)
	{
		isHint = flag;
	}

	bool mesageBox::isFinal() 
	{
		if (mapNum == 0 && page == 5) { return true; }
		if (mapNum == 1) { return page == 24; }
		return false;
	}

	void mesageBox::openMesgBox(bool flag)
	{
		this->open = flag;
		if (flag == true) 
		{
			page = 0;
		}
		isHint = false;
	}

	bool mesageBox::getOpen() 
	{
		return this->open;
	}

	void mesageBox::OnMove(int mapN)
	{
		this->mapNum = mapN;
		if (mapNum == 0)mesg[page].OnMove();
		spaceBar.OnMove();
	}

	void mesageBox::OnShow()
	{

		if (this->open == true)
		{
			if (mapNum == 0) 
			{
				mesg[page].SetTopLeft(x, y);
				mesg[page].OnShow();
			}
			if (mapNum == 1) 
			{
				mesg_map2[page].SetTopLeft(x, y);
				mesg_map2[page].ShowBitmap();
			}
		}


		if (this->isHint == true) 
		{
			spaceBar.SetTopLeft(152, 500);
			spaceBar.OnShow();
		}

	}
}