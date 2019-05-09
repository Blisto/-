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
	//
	// ��ϫܦh�ɡAOnInit���J�Ҧ����ϭn��ܦh�ɶ��C���קK���C�����H
	//     �������@�СA�C���|�X�{�uLoading ...�v�A���Loading���i�סC
	//
	ShowInitProgress(0);	// �@�}�l��loading�i�׬�0%
	//
	// �}�l���J���
	//
	Sleep(300);				// ��C�A�H�K�ݲM���i�סA��ڹC���ЧR����Sleep
	//
	// ��OnInit�ʧ@�|����CGameStaterRun::OnInit()�A�ҥH�i���٨S��100%
	//
	option = 0;
	menu[0].AddBitmap(menu0,RGB(255, 255, 255));
	menu[0].AddBitmap(menu1, RGB(255, 255, 255));
	menu[0].SetDelayCount(6);
	menu[1].AddBitmap(menu0, RGB(255, 255, 255));
	menu[1].AddBitmap(menu2, RGB(255, 255, 255));
	menu[1].SetDelayCount(6);
	menu[2].AddBitmap(menu0, RGB(255, 255, 255));
	menu[2].AddBitmap(menu3, RGB(255, 255, 255));
	menu[2].SetDelayCount(6);
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
	
	if (nChar == KEY_UP)
	{
		if (option > 0) { option--; }
	}
	if (nChar == KEY_DOWN)
	{
		if (option <2) { option++; }
	}

	if (nChar == KEY_SPACE)
	{
		if(option==0)GotoGameState(GAME_STATE_RUN);// ������GAME_STATE_RUN
		if(option==2)PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE, 0, 0);	// �����C��
	}

		
}

void CGameStateInit::OnLButtonDown(UINT nFlags, CPoint point)
{
	//GotoGameState(GAME_STATE_RUN);		// ������GAME_STATE_RUN
}

void CGameStateInit::OnShow()
{
	////
	//// Demo�ù��r�����ϥΡA���L�}�o�ɽкɶq�קK�����ϥΦr���A���CMovingBitmap����n
	////
	//CDC *pDC = CDDraw::GetBackCDC();			// ���o Back Plain �� CDC 
	//CFont f,*fp;
	//f.CreatePointFont(160,"Times New Roman");	// ���� font f; 160���16 point���r
	//fp=pDC->SelectObject(&f);					// ��� font f
	//pDC->SetBkColor(RGB(0,0,0));
	//pDC->SetTextColor(RGB(255,255,0));
	//pDC->TextOut(120,220,"Please click mouse or press SPACE to begin.");
	//pDC->TextOut(5,395,"Press Ctrl-F to switch in between window mode and full screen mode.");
	//if (ENABLE_GAME_PAUSE)
	//	pDC->TextOut(5,425,"Press Ctrl-Q to pause the Game.");
	//pDC->TextOut(5,455,"Press Alt-F4 or ESC to Quit.");
	//pDC->SelectObject(fp);						// �� font f (�d�U���n�|�F��)
	//CDDraw::ReleaseBackCDC();					// �� Back Plain �� CDC
	menu[option].SetTopLeft(0, 0);
	menu[option].OnShow();
	menu[option].OnMove();
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
	counter = 30 * 5; // 5 seconds
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
	//
	// ��ϫܦh�ɡAOnInit���J�Ҧ����ϭn��ܦh�ɶ��C���קK���C�����H
	//     �������@�СA�C���|�X�{�uLoading ...�v�A���Loading���i�סC
	//
	ShowInitProgress(66);	// ���ӫe�@�Ӫ��A���i�סA���B�i�׵���66%
	//
	// �}�l���J���
	//
	Sleep(300);				// ��C�A�H�K�ݲM���i�סA��ڹC���ЧR����Sleep
	//
	// �̲׶i�׬�100%
	//
	ShowInitProgress(100);
}

void CGameStateOver::OnShow()
{
	//CDC *pDC = CDDraw::GetBackCDC();			// ���o Back Plain �� CDC 
	//CFont f,*fp;
	//f.CreatePointFont(160,"Times New Roman");	// ���� font f; 160���16 point���r
	//fp=pDC->SelectObject(&f);					// ��� font f
	//pDC->SetBkColor(RGB(0,0,0));
	//pDC->SetTextColor(RGB(255,255,0));
	//char str[80];								// Demo �Ʀr��r�ꪺ�ഫ
	//sprintf(str, "Game Over ! (%d)", counter / 30);
	//pDC->TextOut(240,210,str);
	//pDC->SelectObject(fp);						// �� font f (�d�U���n�|�F��)
	//CDDraw::ReleaseBackCDC();					// �� Back Plain �� CDC
	gameover[animNext].SetTopLeft(0, 0);
	gameover[animNext].OnShow();
}

/////////////////////////////////////////////////////////////////////////////
// �o��class���C�����C�����檫��A�D�n���C���{�����b�o��
/////////////////////////////////////////////////////////////////////////////

CGameStateRun::CGameStateRun(CGame *g)
: CGameState(g), NUMBALLS(28)
{
	//MAP = new CMap;
	Newmap = new Map;
}

void CGameStateRun::OnInit()  								// �C������Ȥιϧγ]�w
{

	//
	// ��ϫܦh�ɡAOnInit���J�Ҧ����ϭn��ܦh�ɶ��C���קK���C�����H
	//     �������@�СA�C���|�X�{�uLoading ...�v�A���Loading���i�סC
	//
	ShowInitProgress(33);	// ���ӫe�@�Ӫ��A���i�סA���B�i�׵���33%
							//
							// �}�l���J���
							//
							// ��������Loading�ʧ@�A�����i��
							//
	ShowInitProgress(50);
	Sleep(300); // ��C�A�H�K�ݲM���i�סA��ڹC���ЧR����Sleep
				//
				// �~����J��L���
				//
	help.LoadBitmap(IDB_HELP, RGB(255, 255, 255));				// ���J�������ϧ�
	CAudio::Instance()->Load(AUDIO_DING, "sounds\\ding.wav");	// ���J�s��0���n��ding.wav
	CAudio::Instance()->Load(AUDIO_LAKE, "sounds\\lake.mp3");	// ���J�s��1���n��lake.mp3
	CAudio::Instance()->Load(AUDIO_NTUT, "sounds\\ntut.mid");	// ���J�s��2���n��ntut.mid
																//
																// ��OnInit�ʧ@�|����CGameStaterOver::OnInit()�A�ҥH�i���٨S��100%
																//


	//jumpTime = 15;
	//MAP.LoadBitmap();
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
	CAudio::Instance()->Play(AUDIO_LAKE, true);			// ���� WAVE
	CAudio::Instance()->Play(AUDIO_DING, false);		// ���� WAVE
	CAudio::Instance()->Play(AUDIO_NTUT, true);			// ���� MIDI
}

void CGameStateRun::OnMove()							// ���ʹC������
{
	//int cy = testing_dog->getY(), cx = testing_dog->getX();
	//int cw = 50, ch = 70;
	//int c_unit = testing_dog->getUnit();
	
	// �p�G�Ʊ�ק�cursor���˦��A�h�N�U���{����commment�����Y�i
	//
	// SetCursor(AfxGetApp()->LoadCursor(IDC_GAMECURSOR));
	//


	//////////////////////////////////////////////////////////////////////////////////
	//MAP.OnMove(); 
	//if (MAP.isDead() == true) {

	//	CDC *pDC = CDDraw::GetBackCDC();			// ���o Back Plain �� CDC 
	//	CFont f, *fp;
	//	f.CreatePointFont(160, "Times New Roman");	// ���� font f; 160���16 point���r
	//	fp = pDC->SelectObject(&f);					// ��� font f
	//	pDC->SetBkColor(RGB(0, 0, 0));
	//	pDC->SetTextColor(RGB(255, 255, 0));
	//	pDC->TextOut(5, 425, "���⦺�`");
	//	pDC->SelectObject(fp);						// �� font f (�d�U���n�|�F��)
	//	CDDraw::ReleaseBackCDC();					// �� Back Plain �� CDC
	//	counter--;
	//	if (counter == 0) {
	//		GotoGameState(GAME_STATE_OVER);
	//		MAP.SetXY(0, 0);
	//		MAP.playerXY(0, 0);
	//	}
	//}
	//////////////////////////////////////////////////////////////////////////////////


	Newmap->OnMove();
	if (Newmap->getDeadState() == true)GotoGameState(GAME_STATE_OVER);
}


void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	const char KEY_LEFT  = 0x25; // keyboard���b�Y
	const char KEY_UP    = 0x26; // keyboard�W�b�Y
	const char KEY_RIGHT = 0x27; // keyboard�k�b�Y
	const char KEY_DOWN  = 0x28; // keyboard�U�b�Y
	const char KEY_SPACE = 0x20;
	const char KEY_W=0x57;
	const char KEY_A=0x41;
	const char KEY_S=0x53;
	const char KEY_D=0x44;

	//////////////////////////////////////////////////////////////////////////////////
	//if (nChar == KEY_UP)MAP.SrollingUp(true);
	//if (nChar == KEY_DOWN)MAP.SrollingDown(true);


	//if (nChar == KEY_W) {
	//	if(MAP.getPlayerUP()==false)MAP.playerUP(true);
	//}else if (nChar == KEY_S) {
	//	MAP.playerDown(true);
	//}else if (nChar == KEY_SPACE) {
	//	MAP.playerAttack();
	//}
	//if (nChar == KEY_A)MAP.SrollingLeft(true);
	//if (nChar == KEY_D)MAP.SrollingRight(true);
	//else if (nChar == KEY_A) {
	//	MAP.playerLeft(true);
	//}
	//else if (nChar == KEY_D) {
	//	MAP.playerRight(true);
	//}
	//////////////////////////////////////////////////////////////////////////////////


	//////////////////////////////////////////////////////////////////////////////////
	//���c
	if (nChar == KEY_UP) { Newmap->SrollingUp(true); }
	//if (nChar == KEY_DOWN) { Newmap->SrollingDown(true);}
	if (nChar == KEY_LEFT) { Newmap->SrollingLeft(true); }
	if (nChar == KEY_RIGHT) { Newmap->SrollingRight(true); }

	if (nChar == KEY_A) { Newmap->playerAtk(true); }
	if (nChar == KEY_S) { Newmap->playerAtk2(true); }
	if (nChar == KEY_SPACE) { Newmap->mesgNext(); }
	if (nChar == KEY_W) { GotoGameState(GAME_STATE_OVER); }

	//if (nChar == KEY_W) { Newmap->playerUP(true); }
	//if (nChar == KEY_S) { Newmap->testhp(); }
	//if (nChar == KEY_S) { Newmap->playerDown(true); }
	//if (nChar == KEY_A) { Newmap->playerLeft(true); }
	//if (nChar == KEY_D) { Newmap->playerRight(true); }
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


	//////////////////////////////////////////////////////////////////////////////////
	//if (nChar == KEY_A)MAP.SrollingLeft(false);
	//if (nChar == KEY_D)MAP.SrollingRight(false);
	//if (nChar == KEY_UP)MAP.SrollingUp(false);
	//if (nChar == KEY_DOWN)MAP.SrollingDown(false);

	//if (nChar == KEY_W) { 
	//	MAP.playerUP(false);
	//	//jumpTime = 15;
	//}
	//if (nChar == KEY_S) {
	//	MAP.playerDown(false);
	//}
	//if (nChar == KEY_A){
	//	MAP.playerLeft(false);
	//}
	//if (nChar == KEY_D) { 
	//	MAP.playerRight(false);
	//}
	//////////////////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////////////////
	//���c
	if (nChar == KEY_UP) { Newmap->SrollingUp(false); }
	//if (nChar == KEY_DOWN) { Newmap->SrollingDown(false); }
	if (nChar == KEY_LEFT) { Newmap->SrollingLeft(false); }
	if (nChar == KEY_RIGHT) { Newmap->SrollingRight(false); }

	//if (nChar == KEY_SPACE) { Newmap->playerAtk(false); }

	//if (nChar == KEY_W) { Newmap->playerUP(false); }
	//if (nChar == KEY_S) { Newmap->playerDown(false); }
	//if (nChar == KEY_A) { Newmap->playerLeft(false); }
	//if (nChar == KEY_D) { Newmap->playerRight(false); }
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
	//
	//  �`�N�GShow�̭��d�U���n���ʥ��󪫥󪺮y�СA���ʮy�Ъ��u�@����Move���~��A
	//        �_�h��������sø�Ϯ�(OnDraw)�A����N�|���ʡA�ݰ_�ӷ|�ܩǡC���ӳN�y
	//        ���AMove�t�dMVC����Model�AShow�t�dView�A��View�������Model�C
	//
	//
	//  �K�W�I���ϡB�����ơB�y�B���l�B�u�����y
	//
	
	//MAP.OnShow();

	//help.ShowBitmap();					// �K�W������
	
	//  �K�W���W�Υk�U��������
	//
	//Newmap->mesg(5);
	Newmap->OnShow();
}
}