#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "mesageBox.h"

namespace game_framework
{
	mesageBox::mesageBox() {
		x = 0; y = 0;
		time = 0;
		page = 0;
		open = false;
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

	}
	void mesageBox::nextPage() 
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
	bool mesageBox::isFinal() 
	{
		if (page == 5)return true;
		return false;
	}

	void mesageBox::openMesgBox(bool flag)
	{
		this->open = flag;
	}

	bool mesageBox::getOpen() 
	{
		return this->open;
	}

	void mesageBox::OnMove() 
	{
		mesg[page].OnMove();
	}

	void mesageBox::OnShow() 
	{
		if (this->open == false)return;
		mesg[page].SetTopLeft(x, y);
		mesg[page].OnShow();
	}
}