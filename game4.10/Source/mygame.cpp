/*
 * mygame.cpp: 本檔案儲遊戲本身的class的implementation
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
// 這個class為遊戲的遊戲開頭畫面物件
/////////////////////////////////////////////////////////////////////////////

CGameStateInit::CGameStateInit(CGame *g)
: CGameState(g)
{
}

void CGameStateInit::OnInit()
{
	//
	// 當圖很多時，OnInit載入所有的圖要花很多時間。為避免玩遊戲的人
	//     等的不耐煩，遊戲會出現「Loading ...」，顯示Loading的進度。
	//
	ShowInitProgress(0);	// 一開始的loading進度為0%
	//
	// 開始載入資料
	//
	Sleep(300);				// 放慢，以便看清楚進度，實際遊戲請刪除此Sleep
	//
	// 此OnInit動作會接到CGameStaterRun::OnInit()，所以進度還沒到100%
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
	const char KEY_LEFT = 0x25; // keyboard左箭頭
	const char KEY_UP = 0x26; // keyboard上箭頭
	const char KEY_RIGHT = 0x27; // keyboard右箭頭
	const char KEY_DOWN = 0x28; // keyboard下箭頭
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
		if(option==0)GotoGameState(GAME_STATE_RUN);// 切換至GAME_STATE_RUN
		if(option==2)PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE, 0, 0);	// 關閉遊戲
	}

		
}

void CGameStateInit::OnLButtonDown(UINT nFlags, CPoint point)
{
	//GotoGameState(GAME_STATE_RUN);		// 切換至GAME_STATE_RUN
}

void CGameStateInit::OnShow()
{
	////
	//// Demo螢幕字型的使用，不過開發時請盡量避免直接使用字型，改用CMovingBitmap比較好
	////
	//CDC *pDC = CDDraw::GetBackCDC();			// 取得 Back Plain 的 CDC 
	//CFont f,*fp;
	//f.CreatePointFont(160,"Times New Roman");	// 產生 font f; 160表示16 point的字
	//fp=pDC->SelectObject(&f);					// 選用 font f
	//pDC->SetBkColor(RGB(0,0,0));
	//pDC->SetTextColor(RGB(255,255,0));
	//pDC->TextOut(120,220,"Please click mouse or press SPACE to begin.");
	//pDC->TextOut(5,395,"Press Ctrl-F to switch in between window mode and full screen mode.");
	//if (ENABLE_GAME_PAUSE)
	//	pDC->TextOut(5,425,"Press Ctrl-Q to pause the Game.");
	//pDC->TextOut(5,455,"Press Alt-F4 or ESC to Quit.");
	//pDC->SelectObject(fp);						// 放掉 font f (千萬不要漏了放掉)
	//CDDraw::ReleaseBackCDC();					// 放掉 Back Plain 的 CDC
	menu[option].SetTopLeft(0, 0);
	menu[option].OnShow();
	menu[option].OnMove();
}								

/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的結束狀態(Game Over)
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
	// 當圖很多時，OnInit載入所有的圖要花很多時間。為避免玩遊戲的人
	//     等的不耐煩，遊戲會出現「Loading ...」，顯示Loading的進度。
	//
	ShowInitProgress(66);	// 接個前一個狀態的進度，此處進度視為66%
	//
	// 開始載入資料
	//
	Sleep(300);				// 放慢，以便看清楚進度，實際遊戲請刪除此Sleep
	//
	// 最終進度為100%
	//
	ShowInitProgress(100);
}

void CGameStateOver::OnShow()
{
	//CDC *pDC = CDDraw::GetBackCDC();			// 取得 Back Plain 的 CDC 
	//CFont f,*fp;
	//f.CreatePointFont(160,"Times New Roman");	// 產生 font f; 160表示16 point的字
	//fp=pDC->SelectObject(&f);					// 選用 font f
	//pDC->SetBkColor(RGB(0,0,0));
	//pDC->SetTextColor(RGB(255,255,0));
	//char str[80];								// Demo 數字對字串的轉換
	//sprintf(str, "Game Over ! (%d)", counter / 30);
	//pDC->TextOut(240,210,str);
	//pDC->SelectObject(fp);						// 放掉 font f (千萬不要漏了放掉)
	//CDDraw::ReleaseBackCDC();					// 放掉 Back Plain 的 CDC
	gameover[animNext].SetTopLeft(0, 0);
	gameover[animNext].OnShow();
}

/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的遊戲執行物件，主要的遊戲程式都在這裡
/////////////////////////////////////////////////////////////////////////////

CGameStateRun::CGameStateRun(CGame *g)
: CGameState(g), NUMBALLS(28)
{
	//MAP = new CMap;
	Newmap = new Map;
}

void CGameStateRun::OnInit()  								// 遊戲的初值及圖形設定
{

	//
	// 當圖很多時，OnInit載入所有的圖要花很多時間。為避免玩遊戲的人
	//     等的不耐煩，遊戲會出現「Loading ...」，顯示Loading的進度。
	//
	ShowInitProgress(33);	// 接個前一個狀態的進度，此處進度視為33%
							//
							// 開始載入資料
							//
							// 完成部分Loading動作，提高進度
							//
	ShowInitProgress(50);
	Sleep(300); // 放慢，以便看清楚進度，實際遊戲請刪除此Sleep
				//
				// 繼續載入其他資料
				//
	help.LoadBitmap(IDB_HELP, RGB(255, 255, 255));				// 載入說明的圖形
	CAudio::Instance()->Load(AUDIO_DING, "sounds\\ding.wav");	// 載入編號0的聲音ding.wav
	CAudio::Instance()->Load(AUDIO_LAKE, "sounds\\lake.mp3");	// 載入編號1的聲音lake.mp3
	CAudio::Instance()->Load(AUDIO_NTUT, "sounds\\ntut.mid");	// 載入編號2的聲音ntut.mid
																//
																// 此OnInit動作會接到CGameStaterOver::OnInit()，所以進度還沒到100%
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
	CAudio::Instance()->Play(AUDIO_LAKE, true);			// 撥放 WAVE
	CAudio::Instance()->Play(AUDIO_DING, false);		// 撥放 WAVE
	CAudio::Instance()->Play(AUDIO_NTUT, true);			// 撥放 MIDI
}

void CGameStateRun::OnMove()							// 移動遊戲元素
{
	//int cy = testing_dog->getY(), cx = testing_dog->getX();
	//int cw = 50, ch = 70;
	//int c_unit = testing_dog->getUnit();
	
	// 如果希望修改cursor的樣式，則將下面程式的commment取消即可
	//
	// SetCursor(AfxGetApp()->LoadCursor(IDC_GAMECURSOR));
	//


	//////////////////////////////////////////////////////////////////////////////////
	//MAP.OnMove(); 
	//if (MAP.isDead() == true) {

	//	CDC *pDC = CDDraw::GetBackCDC();			// 取得 Back Plain 的 CDC 
	//	CFont f, *fp;
	//	f.CreatePointFont(160, "Times New Roman");	// 產生 font f; 160表示16 point的字
	//	fp = pDC->SelectObject(&f);					// 選用 font f
	//	pDC->SetBkColor(RGB(0, 0, 0));
	//	pDC->SetTextColor(RGB(255, 255, 0));
	//	pDC->TextOut(5, 425, "角色死亡");
	//	pDC->SelectObject(fp);						// 放掉 font f (千萬不要漏了放掉)
	//	CDDraw::ReleaseBackCDC();					// 放掉 Back Plain 的 CDC
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
	const char KEY_LEFT  = 0x25; // keyboard左箭頭
	const char KEY_UP    = 0x26; // keyboard上箭頭
	const char KEY_RIGHT = 0x27; // keyboard右箭頭
	const char KEY_DOWN  = 0x28; // keyboard下箭頭
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
	//重構
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
	const char KEY_LEFT = 0x25; // keyboard左箭頭
	const char KEY_UP = 0x26; // keyboard上箭頭
	const char KEY_RIGHT = 0x27; // keyboard右箭頭
	const char KEY_DOWN = 0x28; // keyboard下箭頭
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
	//重構
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

void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{

}

void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{

}

void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
	// 沒事。如果需要處理滑鼠移動的話，寫code在這裡
}

void CGameStateRun::OnRButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{

}

void CGameStateRun::OnRButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{

}

void CGameStateRun::OnShow()
{
	//
	//  注意：Show裡面千萬不要移動任何物件的座標，移動座標的工作應由Move做才對，
	//        否則當視窗重新繪圖時(OnDraw)，物件就會移動，看起來會很怪。換個術語
	//        說，Move負責MVC中的Model，Show負責View，而View不應更動Model。
	//
	//
	//  貼上背景圖、撞擊數、球、擦子、彈跳的球
	//
	
	//MAP.OnShow();

	//help.ShowBitmap();					// 貼上說明圖
	
	//  貼上左上及右下角落的圖
	//
	//Newmap->mesg(5);
	Newmap->OnShow();
}
}