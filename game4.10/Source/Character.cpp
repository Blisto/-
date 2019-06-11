#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Character.h"
#include <stdio.h>
#include <stdlib.h> /* 亂數相關函數 */
#include <time.h>   /* 時間相關函數 */

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


	Character::Character()
	{
		healthPoints = 100;
		x = 352; y = 400;
		isAttack = false;
		isAttack2 = false;

		megaManMode = 0;
		appearancePhase = 0;
		moveCount = 2 * 1;
		chLR =0; chNum = 0;
	}

	void Character::LoadBitmap()
	{    	
		//Arthur          [LR][num] LR=0:朝右  LR=1:朝左
		//num  0:站姿,1:跑,2:跳[上升],3:跳[落下],:4攻擊[遠],5攻擊:[近],6:死亡
		//右
		animation[0][0].AddBitmap(R_P0, RGB(255, 255, 255));
		animation[0][1].AddBitmap(R_P1, RGB(255, 255, 255));
		animation[0][1].AddBitmap(R_P2, RGB(255, 255, 255));
		animation[0][1].AddBitmap(R_P3, RGB(255, 255, 255));
		animation[0][1].AddBitmap(R_P4, RGB(255, 255, 255));
		animation[0][1].AddBitmap(R_P5, RGB(255, 255, 255));
		animation[0][1].AddBitmap(R_P6, RGB(255, 255, 255));
		animation[0][1].SetDelayCount(3);
		animation[0][2].AddBitmap(R_J1, RGB(255, 255, 255));
		animation[0][3].AddBitmap(R_J2, RGB(255, 255, 255));
		animation[0][4].AddBitmap(atk1_R, RGB(255, 255, 255));
		animation[0][4].AddBitmap(atk2_R, RGB(255, 255, 255));
		animation[0][4].AddBitmap(atk2_R, RGB(255, 255, 255));
		animation[0][4].SetDelayCount(10);
		animation[0][5].AddBitmap(atk1_Rc, RGB(255, 255, 255));
		animation[0][5].AddBitmap(atk2_Rc, RGB(255, 255, 255));
		animation[0][5].AddBitmap(atk2_Rc, RGB(255, 255, 255));
		animation[0][5].SetDelayCount(10);
		//左
		animation[1][0].AddBitmap(L_P0, RGB(255, 255, 255));
		animation[1][1].AddBitmap(L_P1, RGB(255, 255, 255));
		animation[1][1].AddBitmap(L_P2, RGB(255, 255, 255));
		animation[1][1].AddBitmap(L_P3, RGB(255, 255, 255));
		animation[1][1].AddBitmap(L_P4, RGB(255, 255, 255));
		animation[1][1].AddBitmap(L_P5, RGB(255, 255, 255));
		animation[1][1].AddBitmap(L_P6, RGB(255, 255, 255));
		animation[1][1].SetDelayCount(3);
		animation[1][2].AddBitmap(L_J1, RGB(255, 255, 255));
		animation[1][3].AddBitmap(L_J2, RGB(255, 255, 255));
		animation[1][4].AddBitmap(atk1_L, RGB(255, 255, 255));
		animation[1][4].AddBitmap(atk2_L, RGB(255, 255, 255));
		animation[1][4].AddBitmap(atk2_L, RGB(255, 255, 255));
		animation[1][4].SetDelayCount(10);
		animation[1][5].AddBitmap(atk1_Lc, RGB(255, 255, 255));
		animation[1][5].AddBitmap(atk2_Lc, RGB(255, 255, 255));
		animation[1][5].AddBitmap(atk2_Lc, RGB(255, 255, 255));
		animation[1][5].SetDelayCount(10);
		animation[0][6].AddBitmap(dameage, RGB(255, 255, 255));
		animation[0][6].AddBitmap(death1, RGB(255, 255, 255));
		animation[0][6].AddBitmap(death2, RGB(255, 255, 255));
		animation[0][6].AddBitmap(death3, RGB(255, 255, 255));
		animation[0][6].AddBitmap(death4, RGB(255, 255, 255));
		animation[0][6].AddBitmap(death5, RGB(255, 255, 255));
		animation[0][6].AddBitmap(death5, RGB(255, 255, 255));
		animation[0][6].SetDelayCount(20);
		animation[1][6].AddBitmap(dameage, RGB(255, 255, 255));
		animation[1][6].AddBitmap(death1, RGB(255, 255, 255));
		animation[1][6].AddBitmap(death2, RGB(255, 255, 255));
		animation[1][6].AddBitmap(death3, RGB(255, 255, 255));
		animation[1][6].AddBitmap(death4, RGB(255, 255, 255));
		animation[1][6].AddBitmap(death5, RGB(255, 255, 255));
		animation[1][6].AddBitmap(death5, RGB(255, 255, 255));
		animation[1][6].SetDelayCount(20);
		/////MegaMan zone
		//num  10:站姿, 11: 跑,12 : 跳[上升],13 : 跳[落下], :14攻擊[遠],15攻擊 : [近],
		//16:跳遠攻,17:跳近攻,18:移動+攻擊,19:衝刺,20:衝刺+攻擊,29:受傷,30:死亡
		////右
		//站
		animation[0][10].AddBitmap(R_X_s0, RGB(255, 255, 255));
		animation[0][10].AddBitmap(R_X_s1, RGB(255, 255, 255));
		animation[0][10].AddBitmap(R_X_s2, RGB(255, 255, 255));
		animation[0][10].SetDelayCount(10);
		//跑
		animation[0][11].AddBitmap(R_X_r1, RGB(255, 255, 255));
		animation[0][11].AddBitmap(R_X_r2, RGB(255, 255, 255));
		animation[0][11].AddBitmap(R_X_r3, RGB(255, 255, 255));
		animation[0][11].AddBitmap(R_X_r4, RGB(255, 255, 255));
		animation[0][11].AddBitmap(R_X_r5, RGB(255, 255, 255));
		animation[0][11].AddBitmap(R_X_r6, RGB(255, 255, 255));
		animation[0][11].AddBitmap(R_X_r7, RGB(255, 255, 255));
		animation[0][11].AddBitmap(R_X_r8, RGB(255, 255, 255));
		animation[0][11].AddBitmap(R_X_r9, RGB(255, 255, 255));
		animation[0][11].AddBitmap(R_X_r10, RGB(255, 255, 255));
		animation[0][11].AddBitmap(R_X_r11, RGB(255, 255, 255));
		animation[0][11].SetDelayCount(2);
		//跳_上升
		animation[0][12].AddBitmap(R_X_j0, RGB(255, 255, 255));
		animation[0][12].AddBitmap(R_X_j1, RGB(255, 255, 255));
		animation[0][12].AddBitmap(R_X_j2, RGB(255, 255, 255));
		//跳_落下
		animation[0][13].AddBitmap(R_X_j3, RGB(255, 255, 255));
		//animation[0][13].AddBitmap(R_X_j4, RGB(255, 255, 255));
		//攻擊_遠
		//animation[0][14].AddBitmap(R_X_a0f, RGB(255, 255, 255));
		animation[0][14].AddBitmap(R_X_a1f, RGB(255, 255, 255));
		animation[0][14].AddBitmap(R_X_a1f, RGB(255, 255, 255));
		animation[0][14].AddBitmap(R_X_a1f, RGB(255, 255, 255));
		animation[0][14].SetDelayCount(2);
		//攻擊_近
		animation[0][15].AddBitmap(R_X_a0c, RGB(255, 255, 255));
		animation[0][15].AddBitmap(R_X_a1c, RGB(255, 255, 255));
		animation[0][15].AddBitmap(R_X_a2c, RGB(255, 255, 255));
		animation[0][15].AddBitmap(R_X_a3c, RGB(255, 255, 255));
		animation[0][15].AddBitmap(R_X_a4c, RGB(255, 255, 255));
		animation[0][15].AddBitmap(R_X_a5c, RGB(255, 255, 255));
		animation[0][15].AddBitmap(R_X_a6c, RGB(255, 255, 255));
		animation[0][15].AddBitmap(R_X_a7c, RGB(255, 255, 255));
		animation[0][15].AddBitmap(R_X_a8c, RGB(255, 255, 255));
		animation[0][15].AddBitmap(R_X_a9c, RGB(255, 255, 255));
		animation[0][15].SetDelayCount(1);
		//跳+遠攻
		animation[0][16].AddBitmap(R_X_ja2f, RGB(255, 255, 255));
		animation[0][16].AddBitmap(R_X_ja3f, RGB(255, 255, 255));
		animation[0][16].AddBitmap(R_X_ja4f, RGB(255, 255, 255));
		animation[0][16].SetDelayCount(5);
		//跳+近攻
		animation[0][17].AddBitmap(R_X_ja0c, RGB(255, 255, 255));
		animation[0][17].AddBitmap(R_X_ja1c, RGB(255, 255, 255));
		animation[0][17].AddBitmap(R_X_ja2c, RGB(255, 255, 255));
		animation[0][17].AddBitmap(R_X_ja3c, RGB(255, 255, 255));
		animation[0][17].AddBitmap(R_X_ja4c, RGB(255, 255, 255));
		animation[0][17].AddBitmap(R_X_ja5c, RGB(255, 255, 255));
		animation[0][17].AddBitmap(R_X_ja6c, RGB(255, 255, 255));
		animation[0][17].AddBitmap(R_X_ja7c, RGB(255, 255, 255));
		animation[0][17].AddBitmap(R_X_ja8c, RGB(255, 255, 255));
		animation[0][17].AddBitmap(R_X_ja9c, RGB(255, 255, 255));
		animation[0][17].SetDelayCount(1);
		//跑+遠攻
		animation[0][18].AddBitmap(R_X_ra0f, RGB(255, 255, 255));
		animation[0][18].AddBitmap(R_X_ra1f, RGB(255, 255, 255));
		animation[0][18].AddBitmap(R_X_ra2f, RGB(255, 255, 255));
		animation[0][18].AddBitmap(R_X_ra3f, RGB(255, 255, 255));
		animation[0][18].AddBitmap(R_X_ra4f, RGB(255, 255, 255));
		animation[0][18].AddBitmap(R_X_ra5f, RGB(255, 255, 255));
		//animation[0][18].AddBitmap(R_X_ra6f, RGB(255, 255, 255));
		//animation[0][18].AddBitmap(R_X_ra7f, RGB(255, 255, 255));
		//animation[0][18].AddBitmap(R_X_ra8f, RGB(255, 255, 255));
		//animation[0][18].AddBitmap(R_X_ra9f, RGB(255, 255, 255));
		animation[0][18].SetDelayCount(2);
		//衝刺
		animation[0][19].AddBitmap(R_X_dash0, RGB(255, 255, 255));
		animation[0][19].AddBitmap(R_X_dash1, RGB(255, 255, 255));
		animation[0][19].SetDelayCount(4);
		//衝刺+攻擊
		//animation[0][20].AddBitmap(R_X_dash_a0, RGB(255, 255, 255));
		animation[0][20].AddBitmap(R_X_dash_a1, RGB(255, 255, 255));
		animation[0][20].AddBitmap(R_X_dash_a1, RGB(255, 255, 255));
		animation[0][20].AddBitmap(R_X_dash_a1, RGB(255, 255, 255));
		animation[0][20].SetDelayCount(4);
		//受傷害
		animation[0][29].AddBitmap(R_X_beAtk0, RGB(255, 255, 255));
		animation[0][29].AddBitmap(R_X_beAtk1, RGB(255, 255, 255));
		animation[0][29].AddBitmap(R_X_beAtk2, RGB(255, 255, 255));
		animation[0][29].AddBitmap(R_X_beAtk1, RGB(255, 255, 255));
		animation[0][29].AddBitmap(R_X_beAtk2, RGB(255, 255, 255));
		animation[0][29].SetDelayCount(3);
		//死亡
		animation[0][30].AddBitmap(R_X_d0, RGB(255, 255, 255));
		animation[0][30].AddBitmap(R_X_d1, RGB(255, 255, 255));
		animation[0][30].AddBitmap(R_X_d2, RGB(255, 255, 255));
		animation[0][30].AddBitmap(R_X_d3, RGB(255, 255, 255));
		animation[0][30].AddBitmap(R_X_d4, RGB(255, 255, 255));
		animation[0][30].AddBitmap(R_X_d5, RGB(255, 255, 255));
		animation[0][30].AddBitmap(R_X_d6, RGB(255, 255, 255));
		animation[0][30].AddBitmap(R_X_d7, RGB(255, 255, 255));
		animation[0][30].AddBitmap(R_X_d1, RGB(255, 255, 255));
		animation[0][30].AddBitmap(R_X_d2, RGB(255, 255, 255));
		animation[0][30].AddBitmap(R_X_d3, RGB(255, 255, 255));
		animation[0][30].AddBitmap(R_X_d4, RGB(255, 255, 255));
		animation[0][30].AddBitmap(R_X_d5, RGB(255, 255, 255));
		animation[0][30].AddBitmap(R_X_d6, RGB(255, 255, 255));
		animation[0][30].AddBitmap(R_X_d7, RGB(255, 255, 255));
		animation[0][30].AddBitmap(R_X_d8, RGB(255, 255, 255));
		animation[0][30].AddBitmap(R_X_d8, RGB(255, 255, 255));
		animation[0][30].AddBitmap(R_X_d8, RGB(255, 255, 255));
		animation[0][30].AddBitmap(R_X_d8, RGB(255, 255, 255));
		animation[0][30].AddBitmap(R_X_d8, RGB(255, 255, 255));
		animation[0][30].AddBitmap(R_X_d8, RGB(255, 255, 255));
		animation[0][30].SetDelayCount(4);
		////左
		//站
		animation[1][10].AddBitmap(L_X_s0, RGB(255, 255, 255));
		animation[1][10].AddBitmap(L_X_s1, RGB(255, 255, 255));
		animation[1][10].AddBitmap(L_X_s2, RGB(255, 255, 255));
		animation[1][10].SetDelayCount(3);
		//跑
		animation[1][11].AddBitmap(L_X_r1, RGB(255, 255, 255));
		animation[1][11].AddBitmap(L_X_r2, RGB(255, 255, 255));
		animation[1][11].AddBitmap(L_X_r3, RGB(255, 255, 255));
		animation[1][11].AddBitmap(L_X_r4, RGB(255, 255, 255));
		animation[1][11].AddBitmap(L_X_r5, RGB(255, 255, 255));
		animation[1][11].AddBitmap(L_X_r6, RGB(255, 255, 255));
		animation[1][11].AddBitmap(L_X_r7, RGB(255, 255, 255));
		animation[1][11].AddBitmap(L_X_r8, RGB(255, 255, 255));
		animation[1][11].AddBitmap(L_X_r9, RGB(255, 255, 255));
		animation[1][11].AddBitmap(L_X_r10, RGB(255, 255, 255));
		animation[1][11].AddBitmap(L_X_r11, RGB(255, 255, 255));
		animation[1][11].SetDelayCount(2);
		//跳_上升
		animation[1][12].AddBitmap(L_X_j0, RGB(255, 255, 255));
		animation[1][12].AddBitmap(L_X_j1, RGB(255, 255, 255));
		animation[1][12].AddBitmap(L_X_j2, RGB(255, 255, 255));
		//跳_落下
		animation[1][13].AddBitmap(L_X_j3, RGB(255, 255, 255));
		//animation[1][13].AddBitmap(L_X_j4, RGB(255, 255, 255));
		//攻擊_遠
		//animation[1][14].AddBitmap(L_X_a0f, RGB(255, 255, 255));
		animation[1][14].AddBitmap(L_X_a1f, RGB(255, 255, 255));
		animation[1][14].AddBitmap(L_X_a1f, RGB(255, 255, 255));
		animation[1][14].AddBitmap(L_X_a1f, RGB(255, 255, 255));
		animation[1][14].SetDelayCount(2);
		//攻擊_近
		animation[1][15].AddBitmap(L_X_a0c, RGB(255, 255, 255));
		animation[1][15].AddBitmap(L_X_a1c, RGB(255, 255, 255));
		animation[1][15].AddBitmap(L_X_a2c, RGB(255, 255, 255));
		animation[1][15].AddBitmap(L_X_a3c, RGB(255, 255, 255));
		animation[1][15].AddBitmap(L_X_a4c, RGB(255, 255, 255));
		animation[1][15].AddBitmap(L_X_a5c, RGB(255, 255, 255));
		animation[1][15].AddBitmap(L_X_a6c, RGB(255, 255, 255));
		animation[1][15].AddBitmap(L_X_a7c, RGB(255, 255, 255));
		animation[1][15].AddBitmap(L_X_a8c, RGB(255, 255, 255));
		animation[1][15].AddBitmap(L_X_a9c, RGB(255, 255, 255));
		animation[1][15].SetDelayCount(1);
		//跳+遠攻
		animation[1][16].AddBitmap(L_X_ja2f, RGB(255, 255, 255));
		animation[1][16].AddBitmap(L_X_ja3f, RGB(255, 255, 255));
		animation[1][16].AddBitmap(L_X_ja4f, RGB(255, 255, 255));
		animation[1][16].SetDelayCount(5);
		//跳+近攻
		animation[1][17].AddBitmap(L_X_ja0c, RGB(255, 255, 255));
		animation[1][17].AddBitmap(L_X_ja1c, RGB(255, 255, 255));
		animation[1][17].AddBitmap(L_X_ja2c, RGB(255, 255, 255));
		animation[1][17].AddBitmap(L_X_ja3c, RGB(255, 255, 255));
		animation[1][17].AddBitmap(L_X_ja4c, RGB(255, 255, 255));
		animation[1][17].AddBitmap(L_X_ja5c, RGB(255, 255, 255));
		//animation[1][17].AddBitmap(L_X_ja6c, RGB(255, 255, 255));
		//animation[1][17].AddBitmap(L_X_ja7c, RGB(255, 255, 255));
		//animation[1][17].AddBitmap(L_X_ja8c, RGB(255, 255, 255));
		//animation[1][17].AddBitmap(L_X_ja9c, RGB(255, 255, 255));
		animation[1][17].SetDelayCount(1);
		//跑+遠攻
		animation[1][18].AddBitmap(L_X_ra0f, RGB(255, 255, 255));
		animation[1][18].AddBitmap(L_X_ra1f, RGB(255, 255, 255));
		animation[1][18].AddBitmap(L_X_ra2f, RGB(255, 255, 255));
		animation[1][18].AddBitmap(L_X_ra3f, RGB(255, 255, 255));
		animation[1][18].AddBitmap(L_X_ra4f, RGB(255, 255, 255));
		animation[1][18].AddBitmap(L_X_ra5f, RGB(255, 255, 255));
		animation[1][18].AddBitmap(L_X_ra6f, RGB(255, 255, 255));
		animation[1][18].AddBitmap(L_X_ra7f, RGB(255, 255, 255));
		animation[1][18].AddBitmap(L_X_ra8f, RGB(255, 255, 255));
		animation[1][18].AddBitmap(L_X_ra9f, RGB(255, 255, 255));
		animation[1][18].SetDelayCount(2);
		//衝刺
		animation[1][19].AddBitmap(L_X_dash0, RGB(255, 255, 255));
		animation[1][19].AddBitmap(L_X_dash1, RGB(255, 255, 255));
		animation[1][19].SetDelayCount(4);
		//衝刺+攻擊
		//animation[1][20].AddBitmap(L_X_dash_a0, RGB(255, 255, 255));
		animation[1][20].AddBitmap(L_X_dash_a1, RGB(255, 255, 255));
		animation[1][20].AddBitmap(L_X_dash_a1, RGB(255, 255, 255));
		animation[1][20].AddBitmap(L_X_dash_a1, RGB(255, 255, 255));
		animation[1][20].SetDelayCount(4);
		//受傷害
		animation[1][29].AddBitmap(L_X_beatk0, RGB(255, 255, 255));
		animation[1][29].AddBitmap(L_X_beatk1, RGB(255, 255, 255));
		animation[1][29].AddBitmap(L_X_beatk2, RGB(255, 255, 255));
		animation[1][29].AddBitmap(L_X_beatk1, RGB(255, 255, 255));
		animation[1][29].AddBitmap(L_X_beatk2, RGB(255, 255, 255));
		animation[1][29].SetDelayCount(3);
		//死亡
		animation[1][30].AddBitmap(L_X_d0, RGB(255, 255, 255));
		animation[1][30].AddBitmap(L_X_d1, RGB(255, 255, 255));
		animation[1][30].AddBitmap(L_X_d2, RGB(255, 255, 255));
		animation[1][30].AddBitmap(L_X_d3, RGB(255, 255, 255));
		animation[1][30].AddBitmap(L_X_d4, RGB(255, 255, 255));
		animation[1][30].AddBitmap(L_X_d5, RGB(255, 255, 255));
		animation[1][30].AddBitmap(L_X_d6, RGB(255, 255, 255));
		animation[1][30].AddBitmap(L_X_d7, RGB(255, 255, 255));
		animation[1][30].AddBitmap(L_X_d1, RGB(255, 255, 255));
		animation[1][30].AddBitmap(L_X_d2, RGB(255, 255, 255));
		animation[1][30].AddBitmap(L_X_d3, RGB(255, 255, 255));
		animation[1][30].AddBitmap(L_X_d4, RGB(255, 255, 255));
		animation[1][30].AddBitmap(L_X_d5, RGB(255, 255, 255));
		animation[1][30].AddBitmap(L_X_d6, RGB(255, 255, 255));
		animation[1][30].AddBitmap(L_X_d7, RGB(255, 255, 255));
		animation[1][30].AddBitmap(L_X_d8, RGB(255, 255, 255));
		animation[1][30].AddBitmap(L_X_d8, RGB(255, 255, 255));
		animation[1][30].AddBitmap(L_X_d8, RGB(255, 255, 255));
		animation[1][30].AddBitmap(L_X_d8, RGB(255, 255, 255));
		animation[1][30].SetDelayCount(4);

		//X登場
		appearance[0].AddBitmap(X_a0, RGB(255, 255, 255));
		appearance[1].AddBitmap(X_a1, RGB(255, 255, 255));
		appearance[1].AddBitmap(X_a2, RGB(255, 255, 255));
		appearance[1].AddBitmap(X_a3, RGB(255, 255, 255));
		appearance[1].AddBitmap(X_a4, RGB(255, 255, 255));
		appearance[1].AddBitmap(X_a5, RGB(255, 255, 255));
		appearance[1].AddBitmap(X_a6, RGB(255, 255, 255));
		appearance[1].AddBitmap(X_a7, RGB(255, 255, 255));
		appearance[1].SetDelayCount(3);

		appearance[2].AddBitmap(X_a7, RGB(255, 255, 255));
		appearance[2].AddBitmap(X_a6, RGB(255, 255, 255));
		appearance[2].AddBitmap(X_a5, RGB(255, 255, 255));
		appearance[2].AddBitmap(X_a4, RGB(255, 255, 255));
		appearance[2].AddBitmap(X_a3, RGB(255, 255, 255));
		appearance[2].AddBitmap(X_a2, RGB(255, 255, 255));
		appearance[2].AddBitmap(X_a1, RGB(255, 255, 255));
		appearance[2].SetDelayCount(6);
	}




	void Character::setHP(int newHP)
	{
		healthPoints = newHP;
	}


	void Character::SetY(int ny)
	{
		y = ny;
	}
	void Character::SetXY(int nx, int ny)
	{
		x = nx; y = ny;
	}

	void Character::SetMapXY(int nx, int ny)
	{
		MapX = nx; MapY = ny;
	}

	void Character::SetnewMapXY(int nx, int ny)
	{
		newMapX = nx; newMapY = ny;
	}

	void Character::AddXY(int nx, int ny)
	{
		x += nx;
		y += ny;
	}

	void Character::setAnimation(int lr, int num)
	{
		chLR = lr; chNum = num;
	}
	void Character::setXmodel(int m) 
	{
		this->megaManMode = m;
	}
	bool Character::isDead() 
	{
		if (this->healthPoints > 0)return false;
		return true;
	}

	void Character::resetAnimation(int lr, int num)
	{
		animation[lr][num].Reset();
	}

	void Character::UISendHitted() 
	{
		this->chNum = 29;
	}
	////////////////////////////////////////////////


	int Character::getHP()
	{
		if (isBoss == true && appearancePhase == -1&& animation[chLR][0].GetCurrentBitmapNumber()!=0)return animation[chLR][0].GetCurrentBitmapNumber() * 60;
		return healthPoints;
	}
	int Character::subHP(int n) 
	{
		this->healthPoints += n;
		return this->healthPoints;
	}
	int Character::getX()
	{
		return x;
	}

	int Character::getY()
	{
		return y;
	}

	int Character::getHeight()
	{
		return animation[chLR][chNum].Height();
	}

	int Character::getWidth()
	{
		return animation[chLR][chNum].Width();
	}

	bool Character::getAtkIsLast(int Anum) 
	{
		//if (Anum == 14 && megaManMode == 1)return true;
		//if (Anum == 16 && megaManMode == 1)return true;
		//if (Anum == 18 && megaManMode == 1)return true;
		return animation[chLR][Anum].IsFinalBitmap();
	}

	bool Character::getAttack()
	{
		return isAttack;
	}

	bool Character::getAttack2()
	{
		return isAttack2;
	}

	int Character::getXmodel() 
	{
		return megaManMode;
	}

	int Character::getLR()
	{
		return this->chLR;
	}
	///////////////////////////////////////////////////

	void Character::testAtk(bool flag) 
	{
		isAttack = flag;
	}
	void Character::testAtk2(bool flag)
	{
		isAttack2 = flag;
	}
	



	//////////////////////////////////////////////////////

	void Character::MonsterInit(int select,int nx,int ny) {

		if (select == 0) { this->m_atk = -10; this->healthPoints = 500; this->isBoss = false; }
		if (select == 1) { this->m_atk = -20; this->isBoss = false;}
		if (select == 0 || select == 1) 
		{
			animation[0][0].AddBitmap(M1_5, RGB(255, 255, 255));
			animation[0][1].AddBitmap(M1_5, RGB(255, 255, 255));
			animation[0][1].AddBitmap(M1_4, RGB(255, 255, 255));
			animation[0][1].AddBitmap(M1_3, RGB(255, 255, 255));
			animation[0][1].SetDelayCount(5);
			animation[1][0].AddBitmap(M1_0, RGB(255, 255, 255));
			animation[1][1].AddBitmap(M1_0, RGB(255, 255, 255));
			animation[1][1].AddBitmap(M1_1, RGB(255, 255, 255));
			animation[1][1].AddBitmap(M1_2, RGB(255, 255, 255));
			animation[1][1].SetDelayCount(5);
		}
		chLR = 0; chNum = 0;
		if (select == 2) 
		{//0 登場動畫  1閒置 2飛行 3地面攻擊 4俯衝攻擊 5追蹤攻擊
			srand(time(NULL));
			this->m_atk = 0; appearancePhase = -1; 
			if (appearance == 0)this->resetAnimation(0, 0);
			if(appearance==0)this->resetAnimation(1, 0);
			this->setHP(999999);
			this->isBoss = false;
			animation[0][0].AddBitmap(M2_0, RGB(255, 255, 255));
			animation[0][0].AddBitmap(M2_0, RGB(255, 255, 255));
			animation[0][0].AddBitmap(M2_0, RGB(255, 255, 255));
			animation[0][0].AddBitmap(M2_1, RGB(255, 255, 255));
			animation[0][0].AddBitmap(M2_1, RGB(255, 255, 255));
			animation[0][0].AddBitmap(M2_1, RGB(255, 255, 255));
			animation[0][0].AddBitmap(M2_2, RGB(255, 255, 255));
			animation[0][0].AddBitmap(M2_3, RGB(255, 255, 255));
			animation[0][0].AddBitmap(M2_3, RGB(255, 255, 255));
			animation[0][0].AddBitmap(M2_3, RGB(255, 255, 255));
			animation[0][0].AddBitmap(M2_3, RGB(255, 255, 255));
			animation[0][0].AddBitmap(M2_3, RGB(255, 255, 255));
			animation[0][0].AddBitmap(M2_4, RGB(255, 255, 255));
			animation[0][0].AddBitmap(M2_5, RGB(255, 255, 255));
			animation[0][0].AddBitmap(M2_6, RGB(255, 255, 255));
			animation[0][0].SetDelayCount(6);


			animation[0][1].AddBitmap(M2_0, RGB(255, 255, 255));

			animation[0][2].AddBitmap(M2_7, RGB(255, 255, 255));
			animation[0][2].AddBitmap(M2_8, RGB(255, 255, 255));
			animation[0][2].AddBitmap(M2_9, RGB(255, 255, 255));
			animation[0][2].AddBitmap(M2_10, RGB(255, 255, 255));
			animation[0][2].SetDelayCount(4);


			animation[0][3].AddBitmap(M2_11, RGB(255, 255, 255));
			animation[0][3].AddBitmap(M2_12, RGB(255, 255, 255));
			animation[0][3].AddBitmap(M2_11, RGB(255, 255, 255));
			animation[0][3].AddBitmap(M2_12, RGB(255, 255, 255));

			animation[0][4].AddBitmap(M2_13, RGB(255, 255, 255));
			animation[0][4].AddBitmap(M2_14, RGB(255, 255, 255));

			animation[0][5].AddBitmap(M2_15, RGB(255, 255, 255));
			animation[0][5].AddBitmap(M2_17, RGB(255, 255, 255));
			animation[0][5].AddBitmap(M2_15, RGB(255, 255, 255));
			animation[0][5].AddBitmap(M2_17, RGB(255, 255, 255));
			animation[0][5].AddBitmap(M2_16, RGB(255, 255, 255));
			animation[0][5].AddBitmap(M2_17, RGB(255, 255, 255));
			animation[0][5].AddBitmap(M2_16, RGB(255, 255, 255));
			animation[0][5].AddBitmap(M2_16, RGB(255, 255, 255));
			animation[0][5].SetDelayCount(4);

			animation[1][0].AddBitmap(LM2_0, RGB(255, 255, 255));
			animation[1][0].AddBitmap(LM2_0, RGB(255, 255, 255));
			animation[1][0].AddBitmap(LM2_1, RGB(255, 255, 255));
			animation[1][0].AddBitmap(LM2_1, RGB(255, 255, 255));
			animation[1][0].AddBitmap(LM2_1, RGB(255, 255, 255));
			animation[1][0].AddBitmap(LM2_2, RGB(255, 255, 255));
			animation[1][0].AddBitmap(LM2_3, RGB(255, 255, 255));
			animation[1][0].AddBitmap(LM2_3, RGB(255, 255, 255));
			animation[1][0].AddBitmap(LM2_3, RGB(255, 255, 255));
			animation[1][0].AddBitmap(LM2_3, RGB(255, 255, 255));
			animation[1][0].AddBitmap(LM2_3, RGB(255, 255, 255));
			animation[1][0].AddBitmap(LM2_4, RGB(255, 255, 255));
			animation[1][0].AddBitmap(LM2_5, RGB(255, 255, 255));
			animation[1][0].AddBitmap(LM2_6, RGB(255, 255, 255));
			animation[1][0].SetDelayCount(6);

			animation[1][1].AddBitmap(LM2_0, RGB(255, 255, 255));

			animation[1][2].AddBitmap(LM2_7, RGB(255, 255, 255));
			animation[1][2].AddBitmap(LM2_8, RGB(255, 255, 255));
			animation[1][2].AddBitmap(LM2_9, RGB(255, 255, 255));
			animation[1][2].AddBitmap(LM2_10, RGB(255, 255, 255));
			animation[1][2].SetDelayCount(7);
			animation[1][3].AddBitmap(LM2_11, RGB(255, 255, 255));
			animation[1][3].AddBitmap(LM2_12, RGB(255, 255, 255));
			animation[1][3].AddBitmap(LM2_11, RGB(255, 255, 255));
			animation[1][3].AddBitmap(LM2_12, RGB(255, 255, 255));

			animation[1][4].AddBitmap(LM2_13, RGB(255, 255, 255));
			animation[1][4].AddBitmap(LM2_14, RGB(255, 255, 255));

			animation[1][5].AddBitmap(LM2_15, RGB(255, 255, 255));
			animation[1][5].AddBitmap(LM2_17, RGB(255, 255, 255));
			animation[1][5].AddBitmap(LM2_15, RGB(255, 255, 255));
			animation[1][5].AddBitmap(LM2_17, RGB(255, 255, 255));
			animation[1][5].AddBitmap(LM2_15, RGB(255, 255, 255));
			animation[1][5].AddBitmap(LM2_17, RGB(255, 255, 255));
			animation[1][5].AddBitmap(LM2_16, RGB(255, 255, 255));
			animation[1][5].AddBitmap(LM2_16, RGB(255, 255, 255));
			animation[1][5].SetDelayCount(6);
			chLR = 0; chNum = 1;
			moveCount = 0;
		}
		
		if (select == 3)
		{//1閒置 2飛行
			srand(time(NULL));
			this->m_atk = -3; appearancePhase = -1;
			this->setHP(100);
			this->isBoss = false;
			animation[0][1].AddBitmap(M2_0, RGB(255, 255, 255));
			animation[0][2].AddBitmap(M2_7, RGB(255, 255, 255));
			animation[0][2].AddBitmap(M2_8, RGB(255, 255, 255));
			animation[0][2].AddBitmap(M2_9, RGB(255, 255, 255));
			animation[0][2].AddBitmap(M2_10, RGB(255, 255, 255));
			animation[0][2].SetDelayCount(7);
			animation[1][1].AddBitmap(LM2_0, RGB(255, 255, 255));
			animation[1][2].AddBitmap(LM2_7, RGB(255, 255, 255));
			animation[1][2].AddBitmap(LM2_8, RGB(255, 255, 255));
			animation[1][2].AddBitmap(LM2_9, RGB(255, 255, 255));
			animation[1][2].AddBitmap(LM2_10, RGB(255, 255, 255));
			animation[1][2].SetDelayCount(7);
			chLR = 0; chNum = 1;
			moveCount = 0;
		}

		if (select == 4)
		{//1閒置 2飛行
			srand(time(NULL));
			this->m_atk = -3; appearancePhase = -1;
			this->setHP(100);
			this->isBoss = false;
			animation[0][1].AddBitmap(M2_0, RGB(255, 255, 255));
			animation[0][2].AddBitmap(M2_7, RGB(255, 255, 255));
			animation[0][2].AddBitmap(M2_8, RGB(255, 255, 255));
			animation[0][2].AddBitmap(M2_9, RGB(255, 255, 255));
			animation[0][2].AddBitmap(M2_10, RGB(255, 255, 255));
			animation[0][2].SetDelayCount(7);
			animation[1][1].AddBitmap(LM2_0, RGB(255, 255, 255));
			animation[1][2].AddBitmap(LM2_7, RGB(255, 255, 255));
			animation[1][2].AddBitmap(LM2_8, RGB(255, 255, 255));
			animation[1][2].AddBitmap(LM2_9, RGB(255, 255, 255));
			animation[1][2].AddBitmap(LM2_10, RGB(255, 255, 255));
			animation[1][2].SetDelayCount(7);
			chLR = 0; chNum = 1;
			moveCount = 0;
		}
		if (select == 5)
		{//1閒置 2飛行
			srand(time(NULL));
			this->m_atk = -1;
			this->setHP(100);
			this->isBoss = false;
			animation[0][1].AddBitmap(M2_0, RGB(255, 255, 255));
			animation[0][2].AddBitmap(M2_7, RGB(255, 255, 255));
			animation[0][2].AddBitmap(M2_8, RGB(255, 255, 255));
			animation[0][2].AddBitmap(M2_9, RGB(255, 255, 255));
			animation[0][2].AddBitmap(M2_10, RGB(255, 255, 255));
			animation[0][2].SetDelayCount(7);
			animation[1][1].AddBitmap(LM2_0, RGB(255, 255, 255));
			animation[1][2].AddBitmap(LM2_7, RGB(255, 255, 255));
			animation[1][2].AddBitmap(LM2_8, RGB(255, 255, 255));
			animation[1][2].AddBitmap(LM2_9, RGB(255, 255, 255));
			animation[1][2].AddBitmap(LM2_10, RGB(255, 255, 255));
			animation[1][2].SetDelayCount(4);
			chLR = 0; chNum = 1;
			moveCount = 150;
		}
		if(select!=5)actionType = 0;
		monsterSetting = select;
		this->tx = nx; this->ty = ny;
		this->saveX = nx; this->saveY = ny;
		this->monsterAtkF = 35;
		moveDistence = 160;
	}

	void Character::MonsterStatusReset(int xx,int yy) 
	{
		if (monsterSetting == 0) 
		{
			this->m_atk = -10; this->setHP(500); this->isBoss = false;
			chLR = 0; chNum = 0;
		}
		if (monsterSetting == 1) 
		{
			this->setHP(100);
			this->m_atk = -20; this->isBoss = false;
			chLR = 0; chNum = 0;
		}
		if (monsterSetting == 2)
		{
			this->m_atk = 0; appearancePhase = -1;
			this->setHP(999999);
			this->resetAnimation(0, 0);
			this->resetAnimation(1, 0);

			this->isBoss = false;
			chLR = 0; chNum = 1;
			moveCount = 0;
		}
		if (monsterSetting == 3)
		{
			this->m_atk = -3;
			this->setHP(100);
			this->isBoss = false;
			chLR = 0; chNum = 1;
			moveCount = 0;
		}
		if (monsterSetting == 4)
		{
			this->m_atk = -3;
			this->setHP(100);
			this->isBoss = false;
			chLR = 0; chNum = 1;
			moveCount = 0;
		}
		if (monsterSetting == 5)
		{
			this->m_atk = -2;
			this->setHP(100);
			this->isBoss = false;
			chLR = 0; chNum = 1;
			moveCount = 180;
			actionType = 2;
		}
		if(monsterSetting != 5)actionType = 0;
		actionPtr = 0;
		if (xx != 0 && yy != 0) { this->tx = xx; this->ty = yy; }
		else { this->tx = saveX; this->ty = saveY; }
		this->monsterAtkF = 35;
		moveDistence = 160;
	}

	bool Character::MonsterAttack(int nmapX, int nmapY, Character*player)//T=擊中 F=未擊中
	{
		if(this->monsterAtkF==35){
			int px1=player->getX()-nmapX, py1= player->getY() - nmapY;
			int px2 = px1 + player->getWidth(), py2 = py1 + player->getHeight();;
			px1 += 15; px2 -= 20;
			int mx1=this->x-nmapX, my1=this->y-nmapY;
			int mx2=mx1+this->getWidth(), my2=my1+this->getHeight();

			if (px2 >= mx1 && px1 <= mx2 && py2 >= my1 && py1 <= my2) 
			{ 
				player->subHP(this->m_atk); 
				this->monsterAtkF = 0;
				return true; 
			}
		}
		else {
			this->monsterAtkF += 1;
		}
		return false;
	}

	void Character::AutoMove(int my, int mx,Character*p)
	{
		int min = 1;
		int max = 5;
		int action_arry[6][3];
		action_arry[1][0] = 1;
		action_arry[1][1] = 1;
		action_arry[1][2] = 1;
		action_arry[2][0] = 2;
		action_arry[2][1] = 2;
		action_arry[2][2] = 2;
		action_arry[3][0] = 1;
		action_arry[3][1] = 3;
		action_arry[3][2] = 1;
		action_arry[4][0] = 2;
		action_arry[4][1] = 4;
		action_arry[4][2] = 2;
		action_arry[5][0] = 2;
		action_arry[5][1] = 5;
		action_arry[5][2] = 2;

		int new_my = - my;
		int new_mx =  - mx;
		this->SetXY(tx - new_mx, ty - new_my);

		if (monsterSetting < 2)
		{
			moveCount--;
			if (moveCount == 0) {
				if (moveDistence == 0) { chLR = 1; }
				if (moveDistence == 160) { chLR = 0; }
				chNum = 1;
				if (chLR == 0)
				{
					this->tx += 4; moveDistence -= 4;
				}
				if (chLR == 1) {
					this->tx -= 4; moveDistence += 4;
				}
				animation[chLR][chNum].OnMove();
				moveCount = 2;
			}
		}
		else if(monsterSetting==2)
		{
			int dir = this->getDirectWith(p);
			int dis = this->getDistanceWith(p);
			if (chNum != 4 && chNum != 5)
			{
				if (dir == 4 || dir == 0 || dir == 1) { chLR = 0; }
				if (dir == 5 || dir == 2 || dir == 3) { chLR = 1; }
			}
			if (appearancePhase == -1) 
			{
				if (dis < 160 && dir == 4)
				{
					if (this->isBoss == false) { CAudio::Instance()->Play(AUDIO_BOSS, true); }
					this->isBoss = true;
					chNum = 0;
					if (animation[chLR][0].IsFinalBitmap() == true) 
					{
						CAudio::Instance()->Stop(AUDIO_BOSS);
						appearancePhase = 0;
						chNum = 1;
						this->m_atk = -5;
						this->setHP(1000);
						moveCount = 49;
						
					}
				}
			}
			else 
			{	
				if (moveCount <= 0) {
					int frontAction = actionType,random= rand() % (max - min + 1) + min;
					while (frontAction == random) 
					{
						random = rand() % (max - min + 1) + min;
						while (0)
						{
							random = rand() % (max - min + 1) + min;
						}
					}
					actionType = random;
					moveCount = 150;
					if (actionType == 4)moveCount = 290;
					actionPtr = 0;
				}

				if (dis > 370 && actionType == 1) { actionType = 2; actionPtr = 0; moveCount = 150; }//追擊

				if (actionType != 0)
				{
					chNum = action_arry[actionType][actionPtr];
					if (chNum == 1)
					{
						if (moveCount == 100) { actionPtr++; }
						if (moveCount == 50 ) { actionPtr++; }
						if (actionType == 1)moveCount -= 2;//縮短閒置時間
					}

					if (chNum == 2) 
					{
						if (moveCount == 100 && actionType != 4) { actionPtr++; }
						if (moveCount == 50 && actionType != 4 && actionType != 5) { actionPtr++; }

						if (moveCount == 205  && actionType == 4) 
						{
							actionPtr++; 
							if (dir == 1 && dis < 700)this->tx -= 700 - dis;
							if (dir == 2 && dis < 700)this->tx += 700 - dis;
							if (dir == 6) 
							{
								if (chLR == 1) { this->tx += 350; }
								else { this->tx -= 350; }
							}
							
						}

						if (actionPtr == 0)this->ty -= 6;
						if (actionPtr == 1) {}//停在空中
						if (actionPtr == 2)this->ty += 6;
						if (dis > 10 && actionType == 2)
						{
							if (chLR == 0)this->tx += 7;
							if (chLR == 1)this->tx -= 7;
						}
					}
					if (chNum == 3) 
					{
						if (moveCount == 100) { actionPtr++; }
						if (moveCount == 50) { actionPtr++; }
						if (actionPtr == 1) 
						{
							if (animation[chLR][chNum].IsFinalBitmap() == true)isAttack = true;
						}
					}
					if (chNum == 4)
					{
						int random_Atk_direct;
						if (moveCount == 86) {
							actionPtr++; 
							this->ty -= 1404;
							if (chLR == 0)this->tx -= 700;
							if (chLR == 1)this->tx += 700;

						}
						if (moveCount <= 203 && moveCount >= 87) 
						{
							if (moveCount == 200)CAudio::Instance()->Play(AUDIO_BOSS_ATK4, false);
							if (chLR == 0) { this->ty += 12; this->tx += 10; }
							if (chLR == 1) { this->ty += 12; this->tx -= 10; }
						}
					}
					if (chNum == 5)
					{
						if (animation[chLR][chNum].GetCurrentBitmapNumber() == 1) 
						{
							isAttack2 = true; 
							CAudio::Instance()->Play(AUDIO_BOSS_ATK5, false);
						}
						if (moveCount == 50) { 	
							actionPtr++; 
						}
					}
				}
				if (moveCount > 0)moveCount--;
			}
			animation[chLR][chNum].OnMove();
		}
		else if (monsterSetting == 3) 
		{
			int dir = this->getDirectWith(p);
			int dis = this->getDistanceWith(p);
			if (dir == 4 || dir == 0 || dir == 1) { chLR = 0; }
			if (dir == 5 || dir == 2 || dir == 3) { chLR = 1; }

			if (moveCount <= 0) {
				int frontAction = actionType, random = rand() % (2 - 1 + 1) + 1;
				while (frontAction == random) { random = rand() % (2 - 1 + 1) + 1; }
				actionType = random;
				moveCount = 150;
				actionPtr = 0;
			}

			if (dis < 700 && dis > 370 && actionType == 1) { actionType = 2; actionPtr = 0; moveCount = 150; }//追擊
			if (dis > 900) { actionType = 1; actionPtr = 0; moveCount = 150; this->tx = saveX; this->ty = saveY; }
			if (actionType != 0)
			{
				chNum = action_arry[actionType][actionPtr];

				if (chNum == 1)
				{
					if (moveCount == 100) { actionPtr++; }
					if (moveCount == 50) { actionPtr++; }
					if (actionType == 1)moveCount -= 1;//縮短閒置時間
				}

				if (chNum == 2)
				{
					if (moveCount == 100) { actionPtr++; }
					if (moveCount == 50) { actionPtr++; }
					if (actionPtr == 0)this->ty -= 6;
					if (actionPtr == 1) {}//停在空中
					if (actionPtr == 2)this->ty += 6;
					if (dis > 10 && actionType == 2)
					{
						if (chLR == 0)this->tx += 7;
						if (chLR == 1)this->tx -= 7;
					}
				}

			}
				if (moveCount > 0)moveCount--;
			animation[chLR][chNum].OnMove();

		}
		else if (monsterSetting == 4)
		{
			int dir = this->getDirectWith(p);
			int dis = this->getDistanceWith(p);
			if (dir == 4 || dir == 0 || dir == 1) { chLR = 0; }
			if (dir == 5 || dir == 2 || dir == 3) { chLR = 1; }

			if (moveCount <= 0) {
				int frontAction = actionType, random = rand() % (2 - 1 + 1) + 1;
				while (frontAction == random) { random = rand() % (2 - 1 + 1) + 1; }
				actionType = random;
				moveCount = 150;
				actionPtr = 0;
			}

			if (dis < 150 && dis > 100 && actionType == 1) { actionType = 2; actionPtr = 0; moveCount = 150; }//追擊
			if (dis > 400) { actionType = 1; actionPtr = 0; moveCount = 150; this->tx = saveX; this->ty = saveY; }
			if (actionType != 0)
			{
				chNum = action_arry[actionType][actionPtr];

				if (chNum == 1)
				{
					if (moveCount == 100) { actionPtr++; }
					if (moveCount == 50) { actionPtr++; }
					////if (actionType == 1)moveCount -= 1;//縮短閒置時間
				}

				if (chNum == 2)
				{
					if (moveCount == 120) { actionPtr++; }
					if (moveCount == 30) { actionPtr++; }
					if (actionPtr == 0)this->ty -= 6;
					if (actionPtr == 1) {}//停在空中
					if (actionPtr == 2)this->ty += 6;
					if (dis > 10 && actionType == 2)
					{
						if (chLR == 0)this->tx += 7;
						if (chLR == 1)this->tx -= 7;
					}
				}

			}
			if (moveCount > 0)moveCount--;
			animation[chLR][chNum].OnMove();

		}
		else if (monsterSetting == 5)
		{
			int dir = this->getDirectWith(p);
			int dis = this->getDistanceWith(p);
			if (dir == 4 || dir == 0 || dir == 1) { chLR = 0; }
			if (dir == 5 || dir == 2 || dir == 3) { chLR = 1; }

			if (moveCount <= 0) {
				actionType = 2;
				moveCount = 150;
				actionPtr = 0;
				this->setHP(0);
			}

			if(actionType==2)chNum = action_arry[actionType][actionPtr];

			if (chNum == 2)
			{
				if (moveCount == 120) { actionPtr++; }
				if (moveCount == 30) { actionPtr++; }
				if (this->getY()>p->getY() && actionPtr != 1)this->ty -= 3;
				if (actionPtr == 1) {}//停在空中
				if (this->getY()<p->getY()&& actionPtr != 1)this->ty += 3;
				if (dis > 10)
				{
					if (chLR == 0)this->tx += 7;
					if (chLR == 1)this->tx -= 7;
				}
			}

			if (moveCount > 0)moveCount--;
			animation[chLR][chNum].OnMove();

		}
	}

	int Character::getDistanceWith(Character*p)
	{
		int px1 = p->getX(), py1 = p->getY();
		int px2 = px1 + p->getWidth(), py2 = py1 + p->getHeight();

		int x1 = this->getX(), y1 = this->getY();
		int x2 = x1+this->getWidth(), y2 = y1+this->getHeight();
		bool left = x2<px1;
		bool right = px2<x1;
		bool bottom = y2<py1;
		bool top = py2<y1;

		if (top && left)return dist(px1, py2, x2, y1);
		if (left && bottom)return dist(px1, py1, x2, y2);
		if (bottom && right)return dist(py2, py1, x1, y2);
		if (right&&top)return dist(px2, py2, x1, x2);
		if (left)return px1 - x2;
		if (right)return x1 - px2;
		if (bottom)return py1 - y2;
	    if (top)return y1 - py2;

		


		return 0;
	}
	int Character::getDirectWith(Character*p)//0左上  1左下 2右下 3右上 4左 5右 6下 7上
	{
		int px1 = p->getX(), py1 = p->getY();
		int px2 = px1 + p->getWidth(), py2 = py1 + p->getHeight();

		int x1 = this->getX(), y1 = this->getY();
		int x2 = x1 + this->getWidth(), y2 = y1 + this->getHeight();
		bool left = x2<px1;
		bool right = px2<x1;
		bool bottom = y2<py1;
		bool top = py2<y1;

		if (top && left)return 0;
		if (left && bottom)return 1;
		if (bottom && right)return 2;
		if (right&&top)return 3;
		if (left)return 4;
		if (right)return 5;
		if (bottom)return 6;
		if (top)return 7;

		return -1;
	}

	bool Character::isBossLevel() { return isBoss; }

	bool Character::Mbox(int box_x, int box_y)//檢查人物是否在messageBox的觸發範圍
	{
		int monster_x1 = box_x-64 ;
		int monster_y1 = box_y-64 ;
		int monster_x2 = monster_x1 + 160;
		int monster_y2 = monster_y1 + 160;

		int attack_x1 = this->getX() - MapX;
		int attack_y1 = this->getY() - MapY;
		int attack_x2 = attack_x1 + this->getWidth();
		int attack_y2 = attack_y1 + this->getHeight();
		if (attack_x2 >= monster_x1 && attack_x1 <= monster_x2 && attack_y2 >= monster_y1 && attack_y1 <= monster_y2)return true;
		return false;
	}

	////////////////////////////////////////////////////////

	void Character::OnMove(int lr, int num)
	{
		chLR = lr; chNum = num;

		if (megaManMode == 0) {
			if (isAttack == true && this->getAtkIsLast(chNum) == true) {
				isAttack = false;
				animation[0][chNum].Reset();
				animation[1][chNum].Reset();
			}
			if (isAttack2 == true && this->getAtkIsLast(num) == true) {
				isAttack2 = false;
				animation[0][5].Reset();
				animation[1][5].Reset();
			}
		}
		else {
			if (isAttack == true && this->getAtkIsLast(chNum) == true) {
				isAttack = false;
				if (chNum == 14 && (animation[0][14].IsFinalBitmap() == true || animation[1][14].IsFinalBitmap() == true))
				{
					animation[0][14].Reset();
					animation[1][14].Reset();
				}
				if (chNum == 16 && (animation[0][16].IsFinalBitmap() == true || animation[1][16].IsFinalBitmap() == true))
				{
					animation[0][16].Reset();
					animation[1][16].Reset();
				}
				else if (chNum == 18 && (animation[0][18].IsFinalBitmap() == true || animation[1][18].IsFinalBitmap() == true))
				{
					animation[0][18].Reset();
					animation[1][18].Reset();
				}
				if (chNum != 14 || chNum != 16 || chNum != 18)animation[0][chNum].Reset();
				if (chNum != 14 || chNum != 16 || chNum != 18)animation[1][chNum].Reset();

			}
			if (isAttack2 == true && this->getAtkIsLast(chNum) == true) {
				isAttack2 = false;
				animation[0][15].Reset();
				animation[1][15].Reset();
				animation[0][17].Reset();
				animation[1][17].Reset();
			}
		}
		if (isAttack2 == false) {
			animation[0][5].Reset();
			animation[1][5].Reset();
			animation[0][15].Reset();
			animation[1][15].Reset();
			animation[0][17].Reset();
			animation[1][17].Reset();
		}

		if ((chNum == 19 && animation[chLR][19].IsFinalBitmap() == true) || (chNum == 20 && animation[chLR][20].IsFinalBitmap() == true))
		{
		}
		else {animation[chLR][chNum].OnMove();}
	}


	void Character::OnShow()
	{
			animation[chLR][chNum].SetTopLeft(x, y);
			animation[chLR][chNum].OnShow();
	}

	bool Character::animationOnMove() 
	{
		
		if (y == 400) { appearancePhase = 1; }
		else { y += 20; }
		if (appearance[1].IsFinalBitmap() == true) {
			appearancePhase = 0;
			this->OnMove(0, 10);
			appearance[1].Reset();
			return true; //return T/F is end
		}
		appearance[appearancePhase].OnMove();
		return false;
	}

	void Character::animationOnShow()
	{
		appearance[appearancePhase].SetTopLeft(x, y);
		appearance[appearancePhase].OnShow();
	}
	
	int Character::dist(int x1,int y1,int x2,int y2) 
	{
		int d = (int)sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
		return d;
	}
}