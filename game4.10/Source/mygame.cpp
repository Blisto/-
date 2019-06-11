/*
 * mygame.cpp: ���ɮ��x�C��������class��implementation
 * Copyright (C) 2002-2008 Woei-Kae Chen <wkc@csie.ntut.edu.tw>
 *
 * This file is part of game, a free game development framework for windows.
 *
 * game is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * game is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * History:
 *   2002-03-04 V3.1
 *          Add codes to demostrate the use of CMovingBitmap::ShowBitmap(CMovingBitmap &).
 *	 2004-03-02 V4.0
 *      1. Add CGameStateInit, CGameStateRun, and CGameStateOver to
 *         demonstrate the use of states.
 *      2. Demo the use of CInteger in CGameStateRun.
 *   2005-09-13
 *      Rewrite the codes for CBall and CEraser.
 *   2005-09-20 V4.2Beta1.
 *   2005-09-29 V4.2Beta2.
 *      1. Add codes to display IDC_GAMECURSOR in GameStateRun.
 *   2006-02-08 V4.2
 *      1. Revise sample screens to display in English only.
 *      2. Add code in CGameStateInit to demo the use of PostQuitMessage().
 *      3. Rename OnInitialUpdate() -> OnInit().
 *      4. Fix the bug that OnBeginState() of GameStateInit is not called.
 *      5. Replace AUDIO_CANYON as AUDIO_NTUT.
 *      6. Add help bitmap to CGameStateRun.
 *   2006-09-09 V4.3
 *      1. Rename Move() and Show() as OnMove and OnShow() to emphasize that they are
 *         event driven.
 *   2006-12-30
 *      1. Bug fix: fix a memory leak problem by replacing PostQuitMessage(0) as
 *         PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE,0,0).
 *   2008-02-15 V4.4
 *      1. Add namespace game_framework.
 *      2. Replace the demonstration of animation as a new bouncing ball.
 *      3. Use ShowInitProgress(percent) to display loading progress. 
 *   2010-03-23 V4.6
 *      1. Demo MP3 support: use lake.mp3 to replace lake.wav.
*/

#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "mygame.h"

namespace game_framework {
/////////////////////////////////////////////////////////////////////////////
// �o��class���C�����C���}�Y�e������
/////////////////////////////////////////////////////////////////////////////

CGameStateInit::CGameStateInit(CGame *g)
: CGameState(g)
{

}

void CGameStateInit::OnInit()
{
	ShowInitProgress(0);	// �@�}�l��loading�i�׬�0%
	Sleep(300);

	option = 0;
	helpOpen = false;
	helpBitmap.LoadBitmap(help00, RGB(255, 255, 255));
	menu[0].AddBitmap(menu0,RGB(255, 255, 255));
	menu[0].AddBitmap(menu1, RGB(255, 255, 255));
	menu[0].SetDelayCount(6);
	menu[1].AddBitmap(menu0, RGB(255, 255, 255));
	menu[1].AddBitmap(menu2, RGB(255, 255, 255));
	menu[1].SetDelayCount(6);
	menu[2].AddBitmap(menu0, RGB(255, 255, 255));
	menu[2].AddBitmap(menu3, RGB(255, 255, 255));
	menu[2].SetDelayCount(6);

	CAudio::Instance()->Load(AUDIO_BGM, "sounds\\OSTVOICEDOWN.mp3");
	CAudio::Instance()->Load(AUDIO_X, "sounds\\MMX1_SE_00023.wav");
	CAudio::Instance()->Load(AUDIO_BOSS, "sounds\\MMX1_SE_00134.wav");
	CAudio::Instance()->Load(AUDIO_BOSS_ATK5, "sounds\\0460.wav");
	CAudio::Instance()->Load(AUDIO_CHOOSE, "sounds\\MMX1_SE_00019.wav");
	CAudio::Instance()->Load(AUDIO_MENU, "sounds\\0051.mp3");
	CAudio::Instance()->Load(AUDIO_X_ATK0_HIGHLEVEL, "sounds\\MMX1_SE_00039.wav");
	CAudio::Instance()->Load(AUDIO_X_ATK1_HIGHLEVEL, "sounds\\MMX1_SE_00110.wav");

	CAudio::Instance()->Play(AUDIO_MENU, true);


}

void CGameStateInit::OnBeginState()
{
	option = 0;
	
}

void CGameStateInit::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	const char KEY_ESC = 27;
	const char KEY_LEFT = 0x25; // keyboard���b�Y
	const char KEY_UP = 0x26; // keyboard�W�b�Y
	const char KEY_RIGHT = 0x27; // keyboard�k�b�Y
	const char KEY_DOWN = 0x28; // keyboard�U�b�Y
	const char KEY_SPACE = 0x20;
	const char KEY_A = 0x41;

	if (nChar == KEY_UP)
	{
		if (helpOpen == false && option > 0) { option--; }
	}
	if (nChar == KEY_DOWN)
	{
		if (helpOpen == false && option < 2) { option++; }
	}

	if (nChar == KEY_A)
	{
		CAudio::Instance()->Play(AUDIO_CHOOSE, false);
		if (helpOpen == false) 
		{
			if (option == 0) 
			{
				CAudio::Instance()->Stop(AUDIO_MENU);
				GotoGameState(GAME_STATE_RUN); 
			}// ������GAME_STATE_RUN 
			if (option == 1) { helpOpen = true; }// ���}Help
			if (option == 2)PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE, 0, 0);	// �����C��
		}
		else 
		{
			helpOpen = false;
		}
	}

}

void CGameStateInit::OnLButtonDown(UINT nFlags, CPoint point)
{
	//GotoGameState(GAME_STATE_RUN);		// ������GAME_STATE_RUN
}

void CGameStateInit::OnShow()
{
	menu[option].SetTopLeft(0, 0);
	menu[option].OnShow();
	menu[option].OnMove();
	if (helpOpen == true) 
	{
		helpBitmap.SetTopLeft(0, 0);
		helpBitmap.ShowBitmap();
	}
}								

/////////////////////////////////////////////////////////////////////////////
// �o��class���C�����������A(Game Over)
/////////////////////////////////////////////////////////////////////////////

CGameStateOver::CGameStateOver(CGame *g)
: CGameState(g)
{
}

void CGameStateOver::OnMove()
{	
	counter--;
	if (counter <= 150 && counter > 90)animNext = 0;
	if(counter <= 90 && counter > 30)animNext = 1;
	if (counter <= 30 && counter > 0)animNext = 2;
	if (counter < 0)GotoGameState(GAME_STATE_INIT);

	if (animNext != 2) { gameover[animNext].OnMove(); }
	else { if (gameover[2].IsFinalBitmap() != true)gameover[animNext].OnMove(); }
}

void CGameStateOver::OnBeginState()
{
	counter = 30 * 11; // 5 seconds
	animNext = 0;
	gameover[0].AddBitmap(gameover0, RGB(255, 255, 255));
	gameover[1].AddBitmap(gameover2, RGB(255, 255, 255));
	gameover[1].AddBitmap(gameover3, RGB(255, 255, 255));
	gameover[1].SetDelayCount(3);
	gameover[2].AddBitmap(gameover4, RGB(255, 255, 255));
	gameover[2].AddBitmap(gameover5, RGB(255, 255, 255));
	gameover[2].AddBitmap(gameover6, RGB(255, 255, 255));
	gameover[2].AddBitmap(gameover7, RGB(255, 255, 255));
	gameover[2].AddBitmap(gameover8, RGB(255, 255, 255));
	gameover[2].SetDelayCount(5);
}

void CGameStateOver::OnInit()
{
	ShowInitProgress(66);
	Sleep(200);
	ShowInitProgress(100);
	CAudio::Instance()->Load(AUDIO_DAMAGED, "sounds\\MMX1_SE_00138.wav");
	CAudio::Instance()->Load(AUDIO_X_DEATH, "sounds\\0439.WAV");
	CAudio::Instance()->Load(AUDIO_BOSS_ATK4, "sounds\\yisell_sound.mp3");
	CAudio::Instance()->Load(AUDIO_CLOSE_HITTED, "sounds\\0017.WAV");
	CAudio::Instance()->Load(AUDIO_CLOSE_MISSED, "sounds\\0005.WAV");
	CAudio::Instance()->Load(AUDIO_MESG_NEXT, "sounds\\0077.WAV");
	CAudio::Instance()->Load(AUDIO_ARTHUR_SHOOTATK, "sounds\\0131.WAV");
	CAudio::Instance()->Load(AUDIO_GAMEOVER, "sounds\\0020.MP3");
	CAudio::Instance()->Load(AUDIO_IAMGUNDAM, "sounds\\iamGundam.mp3");
	CAudio::Instance()->Load(AUDIO_CHORD, "sounds\\chordsound.mp3");
	CAudio::Instance()->Load(AUDIO_CATVOICE1, "sounds\\0409.WAV");
	CAudio::Instance()->Load(AUDIO_CATVOICE2, "sounds\\0410.WAV");
	CAudio::Instance()->Load(AUDIO_CLEAR, "sounds\\clearState.mp3");
	CAudio::Instance()->Load(AUDIO_CLEAR_BGM, "sounds\\clearState_BGM.mp3");
}

void CGameStateOver::OnShow()
{
	gameover[animNext].SetTopLeft(0, 0);
	gameover[animNext].OnShow();
}

/////////////////////////////////////////////////////////////////////////////
// �o��class���C�����C�����檫��A�D�n���C���{�����b�o��
/////////////////////////////////////////////////////////////////////////////

CGameStateRun::CGameStateRun(CGame *g)
: CGameState(g), NUMBALLS(28)
{
	Newmap = new Map;
}

void CGameStateRun::OnInit()  								// �C������Ȥιϧγ]�w
{
	ShowInitProgress(33);	// ���ӫe�@�Ӫ��A���i�סA���B�i�׵���33%
							//
	CAudio::Instance()->Load(AUDIO_X_ATK0_NORMALHLEVEL, "sounds\\MMX1_SE_00012.wav");
	CAudio::Instance()->Load(AUDIO_X_ATK1_NORMALHLEVEL, "sounds\\MMX1_SE_00109.wav");
	CAudio::Instance()->Load(AUDIO_X_DASH, "sounds\\MMX1_SE_00016.wav");
	CAudio::Instance()->Load(AUDIO_X_JUMP, "sounds\\MMX1_SE_00121.wav");
	CAudio::Instance()->Load(AUDIO_X_ATK_HITTED, "sounds\\MMX1_SE_00026.wav");
	CAudio::Instance()->Load(AUDIO_X_StartCharge, "sounds\\MMX1_SE_00011.wav");
	CAudio::Instance()->Load(AUDIO_X_Charge, "sounds\\charging.wav");
							// �}�l���J���
							//
							// ��������Loading�ʧ@�A�����i��
							//
	ShowInitProgress(50);
	Sleep(500); // ��C�A�H�K�ݲM���i�סA��ڹC���ЧR����Sleep
				//
				// �~����J��L���
				//



	help.LoadBitmap(IDB_HELP, RGB(255, 255, 255));				// ���J�������ϧ�

																//
																// ��OnInit�ʧ@�|����CGameStaterOver::OnInit()�A�ҥH�i���٨S��100%

	Newmap->LoadBitmap();
}
CGameStateRun::~CGameStateRun()
{
	delete Newmap;
}

void CGameStateRun::OnBeginState()
{
	const int BACKGROUND_X = 60;
	counter = 30 * 5;
}

void CGameStateRun::OnMove()							// ���ʹC������
{
	Newmap->OnMove();
	if (Newmap->getDeadState() == true) 
	{ 
		CAudio::Instance()->Play(AUDIO_MENU, true); 
		GotoGameState(GAME_STATE_OVER); 
	}
	else if (Newmap->getClearState() == true) 
	{
		GotoGameState(GAME_STATE_INIT); 
	}
}


void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	const char KEY_LEFT  = 0x25; // keyboard���b�Y
	const char KEY_UP    = 0x26; // keyboard�W�b�Y
	const char KEY_RIGHT = 0x27; // keyboard�k�b�Y
	const char KEY_DOWN  = 0x28; // keyboard�U�b�Y
	const char KEY_SPACE = 0x20;
	const char KEY_Q=0x51;
	const char KEY_W=0x57;
	const char KEY_A=0x41;
	const char KEY_S=0x53;
	const char KEY_D=0x44;
	const char KEY_E=0x45;
	const char KEY_F1 = 0x70;
	const char KEY_F2 = 0x71;

	if (nChar == KEY_UP) 
	{
		Newmap->SrollingUp(true); Newmap->ResetGravity(); }//�H����
	if (nChar == KEY_LEFT) { Newmap->SrollingLeft(true); }//�H��������
	if (nChar == KEY_RIGHT) { Newmap->SrollingRight(true); }//�H�����k��

	if (nChar == KEY_A) { Newmap->playerAtk(true); }//�H������
	if (nChar == KEY_S) { Newmap->playerAtk2(true); }//�H�����
	if (nChar == KEY_D) { Newmap->Dash(true); }//�H���Ĩ�
	if (nChar == KEY_W) { Newmap->SwitchElem(); }//�ݩ�

	if (nChar == KEY_SPACE) { Newmap->mesgNext(); }//���
	if (nChar == KEY_F1) {//�K�޼Ҧ�
		if (Newmap->getXmodel() == 1) { Newmap->setXmodel(0); Newmap->setMacro(0); }
		else if (Newmap->getXmodel() == 0) { Newmap->setXmodel(1); Newmap->setMacro(1); }
	}
	if (nChar == KEY_F2) { Newmap->SwitchMap(); }//�����a��
	if (nChar == KEY_E) { Newmap->ChargeAll(); }//�R��
	//if(nChar==KEY_Q)
}

void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	const char KEY_LEFT = 0x25; // keyboard���b�Y
	const char KEY_UP = 0x26; // keyboard�W�b�Y
	const char KEY_RIGHT = 0x27; // keyboard�k�b�Y
	const char KEY_DOWN = 0x28; // keyboard�U�b�Y
	const char KEY_SPACE = 0x20;
	const char KEY_W = 0x57;
	const char KEY_A = 0x41;
	const char KEY_S = 0x53;
	const char KEY_D = 0x44;

	if (nChar == KEY_UP) { Newmap->SrollingUp(false); }
	if (nChar == KEY_LEFT) { Newmap->SrollingLeft(false); }
	if (nChar == KEY_RIGHT) { Newmap->SrollingRight(false); }
	if (nChar == KEY_D) { Newmap->Dash(false); }//�H���Ĩ�
	if (nChar == KEY_A) { Newmap->playerAtk(false); }
}

void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)  // �B�z�ƹ����ʧ@
{

}

void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point)	// �B�z�ƹ����ʧ@
{

}

void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point)	// �B�z�ƹ����ʧ@
{
	// �S�ơC�p�G�ݭn�B�z�ƹ����ʪ��ܡA�gcode�b�o��
}

void CGameStateRun::OnRButtonDown(UINT nFlags, CPoint point)  // �B�z�ƹ����ʧ@
{

}

void CGameStateRun::OnRButtonUp(UINT nFlags, CPoint point)	// �B�z�ƹ����ʧ@
{

}

void CGameStateRun::OnShow()
{
	//Newmap->mesg(3);
	Newmap->OnShow();
}
}