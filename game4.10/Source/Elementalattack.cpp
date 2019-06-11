#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Elementalattack.h"
#include "Character.h"
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
Bullet::Bullet()
{
    this->distance = 0;
    this->direct = -1;
    this->counting_distance = 0;
    this->x = 400;
    this->y = 300;
    this->atk_type = 0;
    attackPoint = 0;
}

void Bullet::LoadBitmap()
{
    //子彈
    bullet[0][5].AddBitmap(spear_r, RGB(255, 255, 255));
    bullet[1][5].AddBitmap(spear_L, RGB(255, 255, 255));
    //X 子彈1
    bullet[0][0].AddBitmap(X_Bullet00_0, RGB(255, 255, 255));
    bullet[1][0].AddBitmap(LX_bulley00_0, RGB(255, 255, 255));
    bullet[0][1].AddBitmap(X_Bullet0_0, RGB(255, 255, 255));
    bullet[0][1].AddBitmap(X_Bullet0_1, RGB(255, 255, 255));
    bullet[0][1].AddBitmap(X_Bullet0_2, RGB(255, 255, 255));
    bullet[0][1].SetDelayCount(3);
    bullet[1][1].AddBitmap(LX_bullet0_0, RGB(255, 255, 255));
    bullet[1][1].AddBitmap(LX_bullet0_1, RGB(255, 255, 255));
    bullet[1][1].AddBitmap(LX_bullet0_2, RGB(255, 255, 255));
    bullet[1][1].SetDelayCount(3);
    bullet[0][2].AddBitmap(X_Bullet1_0, RGB(88, 136, 120));
    bullet[0][2].AddBitmap(X_Bullet1_1, RGB(88, 136, 120));
    bullet[0][2].AddBitmap(X_Bullet1_2, RGB(88, 136, 120));
    bullet[0][2].AddBitmap(X_Bullet1_3, RGB(88, 136, 120));
    bullet[0][2].AddBitmap(X_Bullet1_4, RGB(88, 136, 120));
    bullet[0][2].AddBitmap(X_Bullet1_5, RGB(88, 136, 120));
    bullet[0][2].AddBitmap(X_Bullet1_6, RGB(88, 136, 120));
    bullet[0][2].AddBitmap(X_Bullet1_7, RGB(88, 136, 120));
    bullet[0][2].AddBitmap(X_Bullet1_8, RGB(88, 136, 120));
    bullet[0][2].AddBitmap(X_Bullet1_9, RGB(88, 136, 120));
    bullet[0][2].AddBitmap(X_Bullet1_10, RGB(88, 136, 120));
    bullet[0][2].AddBitmap(X_Bullet1_11, RGB(88, 136, 120));
    bullet[0][2].AddBitmap(X_Bullet1_12, RGB(88, 136, 120));
    bullet[0][2].AddBitmap(X_Bullet1_13, RGB(88, 136, 120));
    bullet[0][2].AddBitmap(X_Bullet1_14, RGB(88, 136, 120));
    bullet[0][2].AddBitmap(X_Bullet1_15, RGB(88, 136, 120));
    bullet[0][2].AddBitmap(X_Bullet1_16, RGB(88, 136, 120));
    bullet[0][2].AddBitmap(X_Bullet1_17, RGB(88, 136, 120));
    bullet[0][2].AddBitmap(X_Bullet1_18, RGB(88, 136, 120));
    bullet[0][2].AddBitmap(X_Bullet1_19, RGB(88, 136, 120));
    bullet[0][2].SetDelayCount(1);
    bullet[1][2].AddBitmap(X_Bullet1_0, RGB(88, 136, 120));
    bullet[1][2].AddBitmap(X_Bullet1_1, RGB(88, 136, 120));
    bullet[1][2].AddBitmap(X_Bullet1_2, RGB(88, 136, 120));
	bullet[1][2].AddBitmap(X_Bullet1_3, RGB(88, 136, 120));
    bullet[1][2].AddBitmap(X_Bullet1_4, RGB(88, 136, 120));
    bullet[1][2].AddBitmap(X_Bullet1_5, RGB(88, 136, 120));
    bullet[1][2].AddBitmap(X_Bullet1_6, RGB(88, 136, 120));
    bullet[1][2].AddBitmap(X_Bullet1_7, RGB(88, 136, 120));
    bullet[1][2].AddBitmap(X_Bullet1_8, RGB(88, 136, 120));
    bullet[1][2].AddBitmap(X_Bullet1_9, RGB(88, 136, 120));
    bullet[1][2].AddBitmap(X_Bullet1_10, RGB(88, 136, 120));
    bullet[1][2].AddBitmap(X_Bullet1_11, RGB(88, 136, 120));
    bullet[1][2].AddBitmap(X_Bullet1_12, RGB(88, 136, 120));
    bullet[1][2].AddBitmap(X_Bullet1_13, RGB(88, 136, 120));
    bullet[1][2].AddBitmap(X_Bullet1_14, RGB(88, 136, 120));
    bullet[1][2].AddBitmap(X_Bullet1_15, RGB(88, 136, 120));
    bullet[1][2].AddBitmap(X_Bullet1_16, RGB(88, 136, 120));
    bullet[1][2].AddBitmap(X_Bullet1_17, RGB(88, 136, 120));
    bullet[1][2].AddBitmap(X_Bullet1_18, RGB(88, 136, 120));
    bullet[1][2].AddBitmap(X_Bullet1_19, RGB(88, 136, 120));
    bullet[1][2].SetDelayCount(1);
    bullet[0][3].AddBitmap(X_Bullet1_16, RGB(88, 136, 120));
    bullet[0][3].AddBitmap(X_Bullet1_17, RGB(88, 136, 120));
    bullet[0][3].AddBitmap(X_Bullet1_18, RGB(88, 136, 120));
    bullet[0][3].AddBitmap(X_Bullet1_19, RGB(88, 136, 120));
    bullet[0][3].SetDelayCount(2);
    bullet[1][3].AddBitmap(X_Bullet1_16, RGB(88, 136, 120));
    bullet[1][3].AddBitmap(X_Bullet1_17, RGB(88, 136, 120));
    bullet[1][3].AddBitmap(X_Bullet1_18, RGB(88, 136, 120));
    bullet[1][3].AddBitmap(X_Bullet1_19, RGB(88, 136, 120));
    bullet[1][3].SetDelayCount(2);
    bullet[0][4].AddBitmap(X_Bullet1_20, RGB(88, 136, 120));
    bullet[0][4].AddBitmap(X_Bullet1_21, RGB(88, 136, 120));
    bullet[0][4].AddBitmap(X_Bullet1_N, RGB(88, 136, 120));
    bullet[0][4].AddBitmap(X_Bullet1_N, RGB(88, 136, 120));
    bullet[0][4].AddBitmap(X_Bullet1_22, RGB(88, 136, 120));
    bullet[0][4].AddBitmap(X_Bullet1_23, RGB(88, 136, 120));
    bullet[0][4].AddBitmap(X_Bullet1_N, RGB(88, 136, 120));
    bullet[0][4].AddBitmap(X_Bullet1_N, RGB(88, 136, 120));
    bullet[0][4].AddBitmap(X_Bullet1_24, RGB(88, 136, 120));
    bullet[0][4].AddBitmap(X_Bullet1_25, RGB(88, 136, 120));
    bullet[0][4].AddBitmap(X_Bullet1_N, RGB(88, 136, 120));
    bullet[0][4].AddBitmap(X_Bullet1_N, RGB(88, 136, 120));
    bullet[0][4].AddBitmap(X_Bullet1_26, RGB(88, 136, 120));
    bullet[0][4].AddBitmap(X_Bullet1_27, RGB(88, 136, 120));
    bullet[0][4].AddBitmap(X_Bullet1_N, RGB(88, 136, 120));
    bullet[0][4].AddBitmap(X_Bullet1_N, RGB(88, 136, 120));
    bullet[0][4].SetDelayCount(1);
    bullet[1][4].AddBitmap(X_Bullet1_20, RGB(88, 136, 120));
    bullet[1][4].AddBitmap(X_Bullet1_21, RGB(88, 136, 120));
    bullet[1][4].AddBitmap(X_Bullet1_N, RGB(88, 136, 120));
    bullet[1][4].AddBitmap(X_Bullet1_N, RGB(88, 136, 120));
    bullet[1][4].AddBitmap(X_Bullet1_22, RGB(88, 136, 120));
    bullet[1][4].AddBitmap(X_Bullet1_23, RGB(88, 136, 120));
    bullet[1][4].AddBitmap(X_Bullet1_N, RGB(88, 136, 120));
    bullet[1][4].AddBitmap(X_Bullet1_N, RGB(88, 136, 120));
    bullet[1][4].AddBitmap(X_Bullet1_24, RGB(88, 136, 120));
    bullet[1][4].AddBitmap(X_Bullet1_25, RGB(88, 136, 120));
    bullet[1][4].AddBitmap(X_Bullet1_N, RGB(88, 136, 120));
    bullet[1][4].AddBitmap(X_Bullet1_N, RGB(88, 136, 120));
    bullet[1][4].AddBitmap(X_Bullet1_26, RGB(88, 136, 120));
    bullet[1][4].AddBitmap(X_Bullet1_27, RGB(88, 136, 120));
    bullet[1][4].AddBitmap(X_Bullet1_N, RGB(88, 136, 120));
    bullet[1][4].AddBitmap(X_Bullet1_N, RGB(88, 136, 120));
    bullet[1][4].SetDelayCount(1);
    LoadHitEffectBitmap();
}

void Bullet::LoadHitEffectBitmap()
{
    hitEffect[0][5].AddBitmap(X_nchB0_hit0, RGB(255, 255, 255));
    hitEffect[0][5].AddBitmap(X_nchB0_hit1, RGB(255, 255, 255));
    hitEffect[0][5].AddBitmap(X_nchB0_hit2, RGB(255, 255, 255));
    hitEffect[0][5].SetDelayCount(1);
    hitEffect[1][5].AddBitmap(LX_nchb0_hit0, RGB(255, 255, 255));
    hitEffect[1][5].AddBitmap(LX_nchb0_hit1, RGB(255, 255, 255));
    hitEffect[1][5].AddBitmap(LX_nchb0_hit2, RGB(255, 255, 255));
    hitEffect[1][5].SetDelayCount(1);
    hitEffect[0][0].AddBitmap(X_nchB0_hit0, RGB(255, 255, 255));
    hitEffect[0][0].AddBitmap(X_nchB0_hit1, RGB(255, 255, 255));
    hitEffect[0][0].AddBitmap(X_nchB0_hit2, RGB(255, 255, 255));
    hitEffect[0][0].SetDelayCount(1);
    hitEffect[1][0].AddBitmap(LX_nchb0_hit0, RGB(255, 255, 255));
    hitEffect[1][0].AddBitmap(LX_nchb0_hit1, RGB(255, 255, 255));
    hitEffect[1][0].AddBitmap(LX_nchb0_hit2, RGB(255, 255, 255));
    hitEffect[1][0].SetDelayCount(1);
    hitEffect[0][1].AddBitmap(X_B0_hit0, RGB(255, 255, 255));
    hitEffect[0][1].AddBitmap(X_B0_hit1, RGB(255, 255, 255));
    hitEffect[0][1].AddBitmap(X_B0_hit2, RGB(255, 255, 255));
    hitEffect[0][1].AddBitmap(X_B0_hit3, RGB(255, 255, 255));
    hitEffect[0][1].AddBitmap(X_B0_hit4, RGB(255, 255, 255));
    hitEffect[0][1].AddBitmap(X_B0_hit5, RGB(255, 255, 255));
    hitEffect[0][1].AddBitmap(X_B0_hit6, RGB(255, 255, 255));
    hitEffect[0][1].AddBitmap(X_B0_hit7, RGB(255, 255, 255));
    hitEffect[0][1].SetDelayCount(1);
    hitEffect[1][1].AddBitmap(LX_b0_hit0, RGB(255, 255, 255));
    hitEffect[1][1].AddBitmap(LX_b0_hit1, RGB(255, 255, 255));
    hitEffect[1][1].AddBitmap(LX_b0_hit2, RGB(255, 255, 255));
    hitEffect[1][1].AddBitmap(LX_b0_hit3, RGB(255, 255, 255));
    hitEffect[1][1].AddBitmap(LX_b0_hit4, RGB(255, 255, 255));
    hitEffect[1][1].AddBitmap(LX_b0_hit5, RGB(255, 255, 255));
    hitEffect[1][1].AddBitmap(LX_B0_hit6, RGB(255, 255, 255));
    hitEffect[1][1].AddBitmap(LX_b0_hit7, RGB(255, 255, 255));
    hitEffect[1][1].SetDelayCount(1);
    hitEffect[0][2].AddBitmap(X_nchB0_hit0, RGB(255, 255, 255));
    hitEffect[0][2].AddBitmap(X_nchB0_hit1, RGB(255, 255, 255));
    hitEffect[0][2].AddBitmap(X_nchB0_hit2, RGB(255, 255, 255));
    hitEffect[0][2].SetDelayCount(1);
    hitEffect[1][2].AddBitmap(LX_nchb0_hit0, RGB(255, 255, 255));
    hitEffect[1][2].AddBitmap(LX_nchb0_hit1, RGB(255, 255, 255));
    hitEffect[1][2].AddBitmap(LX_nchb0_hit2, RGB(255, 255, 255));
    hitEffect[1][2].SetDelayCount(1);
    hitEffect[0][3].AddBitmap(X_nchB0_hit0, RGB(255, 255, 255));
    hitEffect[0][3].AddBitmap(X_nchB0_hit1, RGB(255, 255, 255));
    hitEffect[0][3].AddBitmap(X_nchB0_hit2, RGB(255, 255, 255));
    hitEffect[0][3].SetDelayCount(1);
    hitEffect[1][3].AddBitmap(LX_nchb0_hit0, RGB(255, 255, 255));
    hitEffect[1][3].AddBitmap(LX_nchb0_hit1, RGB(255, 255, 255));
    hitEffect[1][3].AddBitmap(LX_nchb0_hit2, RGB(255, 255, 255));
    hitEffect[1][3].SetDelayCount(1);
    hitEffect[0][4].AddBitmap(X_nchB0_hit0, RGB(255, 255, 255));
    hitEffect[0][4].AddBitmap(X_nchB0_hit1, RGB(255, 255, 255));
    hitEffect[0][4].AddBitmap(X_nchB0_hit2, RGB(255, 255, 255));
    hitEffect[0][4].SetDelayCount(1);
    hitEffect[1][4].AddBitmap(LX_nchb0_hit0, RGB(255, 255, 255));
    hitEffect[1][4].AddBitmap(LX_nchb0_hit1, RGB(255, 255, 255));
    hitEffect[1][4].AddBitmap(LX_nchb0_hit2, RGB(255, 255, 255));
    hitEffect[1][4].SetDelayCount(1);
}

void Bullet::setDD(int dis, int dir, int xmode, int atktype, int energ[], int charglevel)
{
    this->bullet[0][2].Reset();
    this->bullet[1][2].Reset();
    this->bullet[0][3].Reset();
    this->bullet[1][3].Reset();

    if (dir == 0)
    {
        this->direct = 4;
        this->LR = 0;
    }

    if (dir == 1)
    {
        this->direct = 3;
        this->LR = 1;
    }

    if (xmode == 0)
    {
        this->atk_type = 5;
		CAudio::Instance()->Play(AUDIO_ARTHUR_SHOOTATK, false);
    }

    if (xmode == 1)
    {
        if (atktype == 0)
        {
            if (energ[0] > 0)
            {
                this->atk_type = 1;
				CAudio::Instance()->Play(AUDIO_X_ATK0_HIGHLEVEL, false);
            }
            else
            {
                this->atk_type = 0;
				CAudio::Instance()->Play(AUDIO_X_ATK0_NORMALHLEVEL, false);
            }
        }

        if (atktype == 1)
        {
			if (charglevel < 2) 
			{
				this->atk_type = 2; 
				CAudio::Instance()->Play(AUDIO_X_ATK1_NORMALHLEVEL, false);
			}

            if (charglevel == 2)
            {
				CAudio::Instance()->Play(AUDIO_X_ATK1_HIGHLEVEL, true);
                this->atk_type = 4;
                this->direct = 1;
            }
        }
    }

    this->attackPoint = this->getAtkPoint(xmode, energ);
    this->distance = dis;
    this->counting_distance = 0;
    x = 0;
    y = 0;
}

void Bullet::SetXY(int nx, int ny)
{
    this->x = nx;
    this->y = ny;
}

void Bullet::SetTXY(int nx, int ny)
{
    this->tx = nx;
    this->ty = ny;
}

int Bullet::getX()
{
    return x;
}

int Bullet::getY()
{
    return y;
}
int Bullet::getHeight()
{
    return bullet[LR][atk_type].Height();
}

int Bullet::getWidth()
{
    return bullet[LR][atk_type].Width();
}

int Bullet::getD()
{
    return direct;
}

int Bullet::getAtk()
{
    return -attackPoint;
}

int Bullet::getAttackType()
{
    return this->atk_type;
}

void Bullet::isHitted()
{
    direct = -2;
}

void Bullet::OnMove(int my, int mx)
{
    int new_my = -my, new_mx = -mx;
    this->SetXY(tx - new_mx, ty - new_my);


	if (this->atk_type == 4 && this->counting_distance >1350 && this->counting_distance <1400)
	{
		CAudio::Instance()->Stop(AUDIO_X_ATK1_HIGHLEVEL);
	}
    if (direct != -1 && this->counting_distance >= this->distance)
    {
        direct = -1;
        this->counting_distance = 0;
        this->distance = 0;
    }

    if (direct == 1)
    {
        this->x = 331;
        this->y = 0;
        this->counting_distance += 15;
    }

    if (direct == 3)
    {
        if (atk_type == 2 && bullet[LR][atk_type].IsFinalBitmap() == true)
        {
            atk_type = 3;
        }

        if (atk_type != 2)
        {
            this->tx -= 20;
            this->counting_distance += 20;
        }
        else
        {
            if ((bullet[LR][atk_type].GetCurrentBitmapNumber() + 1) % 4 == 0) this->tx -= 15;
        }
    }

    if (direct == 4)
    {
        if (atk_type == 2 && bullet[LR][atk_type].IsFinalBitmap() == true)atk_type = 3;

        if (atk_type != 2)
        {
            this->tx += 20;
            this->counting_distance += 20;
        }
    }

    if (direct == -2)
    {
        if (hitEffect[LR][atk_type].IsFinalBitmap())
        {
            direct = -1;
        }

        hitEffect[LR][atk_type].OnMove();
        hitEffect[LR][atk_type].SetTopLeft(x + 10, y);
    }

    if (direct != -2)
    {
        bullet[LR][atk_type].OnMove();
        bullet[LR][atk_type].SetTopLeft(x, y);
    }
}

void  Bullet::OnShow()
{
    if (direct != -2)bullet[LR][atk_type].OnShow();

    if (direct == -2)hitEffect[LR][atk_type].OnShow();
}

int Bullet::getAtkPoint(int xmode, int energ[])
{
    if (xmode == 0)return 40;

    if (xmode == 1)
    {
        if (this->atk_type == 0)return 30;

        if (this->atk_type == 1)return 100;

        if (this->atk_type == 2)return 2;

        if (this->atk_type == 3)return 30;

        if (this->atk_type == 4)return 8;
    }

    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
Elementalattack::Elementalattack()
{
    atk_type = 0;
    energy[0] = 0;
    energy[1] = 100;
    energy[2] = 100;
    monster_counter = 0;
    bullets[0] = new Bullet;
    bullets[1] = new Bullet;
    bullets[2] = new Bullet;
    bullets[3] = new Bullet;
    bullets[4] = new Bullet;
    bullets[5] = new Bullet;
    bullets[6] = new Bullet;
    bullets[7] = new Bullet;
    bullets[8] = new Bullet;
    bullets[9] = new Bullet;
    bossbullets[0] = new Bullet;
    bossbullets[1] = new Bullet;

    for (int i = 0; i < 30; i++)monsters[i] = NULL;

    for (int i = 0; i < 10; i++)bulletActivate[i] = -1;

    chargeLevel = -1;
    activate_Count = 0;
    bossactivate_Count = 0;
    closeAtkCDR = 5;
    CloseAtkPoint = 0;
}

Elementalattack::~Elementalattack()
{
    delete bullets[0];
    delete bullets[1];
    delete bullets[2];
    delete bullets[3];
    delete bullets[4];
    delete bullets[5];
    delete bullets[6];
    delete bullets[7];
    delete bullets[8];
    delete bullets[9];
    delete bossbullets[0];
    delete bossbullets[1];
}

void Elementalattack::LoadBitmap()
{
    UI_Top.LoadBitmap(energy_top, RGB(255, 255, 255));
    UI_button[0].LoadBitmap(energy1_button, RGB(255, 255, 255));
    UI_button[1].LoadBitmap(energy2_button, RGB(255, 255, 255));
    UI_button[2].LoadBitmap(energy3_button, RGB(255, 255, 255));
    UI_mid[0][0].LoadBitmap(energy1_0, RGB(255, 255, 255));
    UI_mid[1][0].LoadBitmap(energy1_0, RGB(255, 255, 255));
    UI_mid[2][0].LoadBitmap(energy_0, RGB(255, 255, 255));
    UI_mid[3][0].LoadBitmap(energy_0, RGB(255, 255, 255));
    UI_mid[4][0].LoadBitmap(energy_0, RGB(255, 255, 255));
    UI_mid[5][0].LoadBitmap(energy_0, RGB(255, 255, 255));
    UI_mid[6][0].LoadBitmap(energy_0, RGB(255, 255, 255));
    UI_mid[7][0].LoadBitmap(energy_0, RGB(255, 255, 255));
    UI_mid[8][0].LoadBitmap(energy_0, RGB(255, 255, 255));
    UI_mid[9][0].LoadBitmap(energy_0, RGB(255, 255, 255));
    UI_mid[10][0].LoadBitmap(energy_0, RGB(255, 255, 255));
    UI_mid[11][0].LoadBitmap(energy_0, RGB(255, 255, 255));
    UI_mid[0][1].LoadBitmap(energy1_1, RGB(255, 255, 255));
    UI_mid[1][1].LoadBitmap(energy1_1, RGB(255, 255, 255));
    UI_mid[2][1].LoadBitmap(energy_1, RGB(255, 255, 255));
    UI_mid[3][1].LoadBitmap(energy_1, RGB(255, 255, 255));
    UI_mid[4][1].LoadBitmap(energy_1, RGB(255, 255, 255));
    UI_mid[5][1].LoadBitmap(energy_1, RGB(255, 255, 255));
    UI_mid[6][1].LoadBitmap(energy_1, RGB(255, 255, 255));
    UI_mid[7][1].LoadBitmap(energy_1, RGB(255, 255, 255));
    UI_mid[8][1].LoadBitmap(energy_1, RGB(255, 255, 255));
    UI_mid[9][1].LoadBitmap(energy_1, RGB(255, 255, 255));
    UI_mid[10][1].LoadBitmap(energy_1, RGB(255, 255, 255));
    UI_mid[11][1].LoadBitmap(energy_1, RGB(255, 255, 255));

    for (int i = 0; i < 10; i++)bullets[i]->LoadBitmap();

    for (int i = 0; i < 2; i++)bossbullets[i]->LoadBitmap();

    //集氣特效
    effect[0].AddBitmap(X_charging0, RGB(255, 255, 255));
    effect[0].AddBitmap(X_charging1, RGB(255, 255, 255));
    effect[0].AddBitmap(X_charging2, RGB(255, 255, 255));
    effect[0].AddBitmap(X_charging3, RGB(255, 255, 255));
    effect[0].AddBitmap(X_charging4, RGB(255, 255, 255));
    effect[0].SetDelayCount(2);
    effect[1].AddBitmap(X_charging5, RGB(255, 255, 255));
    effect[1].AddBitmap(X_charging6, RGB(255, 255, 255));
    effect[1].AddBitmap(X_charging7, RGB(255, 255, 255));
    effect[1].AddBitmap(X_charging8, RGB(255, 255, 255));
    effect[1].AddBitmap(X_charging9, RGB(255, 255, 255));
    effect[1].SetDelayCount(2);
    effect[2].AddBitmap(X_charging10, RGB(255, 255, 255));
    effect[2].AddBitmap(X_charging11, RGB(255, 255, 255));
    effect[2].AddBitmap(X_charging12, RGB(255, 255, 255));
    effect[2].AddBitmap(X_charging13, RGB(255, 255, 255));
    effect[2].AddBitmap(X_charging14, RGB(255, 255, 255));
    effect[2].SetDelayCount(2);
}

void Elementalattack::ShootingAtk(int nx, int ny, int xmode)
{
    int distance;

    if (xmode == 1)
    {
        distance = 1500;

        if (atk_type != 0 && energy[atk_type] <= 0)return;
    }

    if (xmode == 0) distance = 700;

    if (this->activate_Count == 10)this->activate_Count = 0;

    if (player->getLR() == 0)
    {
        bullets[activate_Count]->SetTXY(nx + 40, ny + 18);
    }
    else
    {
        bullets[activate_Count]->SetTXY(nx + 10, ny + 18);
    }

    bullets[activate_Count]->setDD(distance, player->getLR(), xmode, this->atk_type, energy, this->chargeLevel);
    bulletActivate[activate_Count] = 1;

    if (this->activate_Count < 10)this->activate_Count += 1;

    if (this->atk_type == 1)
    {
        if (chargeLevel <= 1)
        {
            energy[atk_type] -= 1;
        }
        else
        {
            energy[atk_type] -= 5;
        }
    }
}

void Elementalattack::BossShootingAtk(int nx, int ny)
{
    if (this->bossactivate_Count == 2)this->bossactivate_Count = 0;

    if (boss->getLR() == 0)
    {
        bossbullets[bossactivate_Count]->SetTXY(nx + 40, ny + 35);
    }
    else
    {
        bossbullets[bossactivate_Count]->SetTXY(nx + 10, ny + 35);
    }

    bossbullets[bossactivate_Count]->setDD(600, boss->getLR(), 1, 1, energy, 0);
    bossbulletActivate[bossactivate_Count] = 1;

    if (this->bossactivate_Count < 10)this->bossactivate_Count += 1;
}

void Elementalattack::CloseRangeAtk()
{
	bool hitted = false;
    if (player->getXmodel() == 1)
    {
        CloseAtkPoint = 150;
    }
    else
    {
        CloseAtkPoint = 90;
    }

    for (int i = 0; i < monster_counter; i++)
    {
        int atkx1, atky1;
        int atkx2, atky2;
        int mx1 = monsters[i]->getX(), my1 = monsters[i]->getY();
        int mx2 = mx1 + monsters[i]->getWidth(), my2 = my1 + monsters[i]->getHeight();

        if (player->getLR() == 0)
        {
            atkx1 = player->getX() + player->getWidth();
            atky1 = player->getY();
            atkx2 = atkx1 + 100;
            atky2 = atky1 + player->getHeight();
        }
        else
        {
            atkx1 = player->getX() - 100;
            atky1 = player->getY();
            atkx2 = atkx1 + 100;
            atky2 = atky1 + player->getHeight();
        }

        if (closeAtkCDR == 5 && atkx2 >= mx1 && atkx1 <= mx2 && atky2 >= my1 && atky1 <= my2)
        {
            monsters[i]->subHP(-CloseAtkPoint);
            this->closeAtkCDR = 0;
			CAudio::Instance()->Play(AUDIO_CLOSE_HITTED, false);
            return;
        }
    }
	CAudio::Instance()->Play(AUDIO_CLOSE_MISSED, false);
}

void Elementalattack::SetChargingLevel(int chLevel)
{
    this->chargeLevel = chLevel;
}

void Elementalattack::Charge(int type, int e)
{
    this->energy[type] = e;
}
void Elementalattack::switchElm()
{
    if (this->atk_type <= 1)
    {
        this->atk_type++;
    }

    if (this->atk_type > 1)this->atk_type = 0;
}
void Elementalattack::AddMonster(Character* m)
{
    if (monster_counter > 30)return;

    if (monsters[monster_counter] == NULL)monsters[monster_counter++] = m;
}

bool Elementalattack::DelleteMonster(int t)
{
    if (t == 0)
    {
        for (int i = 0; i < monster_counter; i++)
        {
            if (monsters[i] != NULL)monsters[i] = NULL;
        }

        monster_counter = 0;
        return true;
    }

    if (t == 1)
    {
        if (monster_counter > 0 && monsters[monster_counter - 1] != NULL)
        {
            monsters[monster_counter - 1] = NULL;
            monster_counter--;
            return true;
        }
    }

    return false;
}

void Elementalattack::SetPlayerBoss(Character* p, Character* m)
{
    this->player = p;
    this->boss = m;
}

int Elementalattack::getUIAtktype()
{
    return this->atk_type;
}

void Elementalattack::OnMove(int my, int mx)
{
    if (closeAtkCDR < 5)closeAtkCDR++;

    for (int j = 0; j < 10; j++)
    {
        if (bulletActivate[j] == 1)
        {
            for (int i = 0; i < monster_counter; i++)
            {
                if (monsters[i] != NULL && monsters[i]->getHP() > 0)
                {
                    int bx1 = bullets[j]->getX(), by1 = bullets[j]->getY();
                    int bx2 = bx1 + bullets[j]->getWidth(), by2 = by1 + bullets[j]->getHeight();
                    int mx1 = monsters[i]->getX(), my1 = monsters[i]->getY();
                    int mx2 = mx1 + monsters[i]->getWidth(), my2 = my1 + monsters[i]->getHeight();

                    if (bx2 >= mx1 && bx1 <= mx2 && by2 >= my1 && by1 <= my2)
                    {
                        monsters[i]->subHP(bullets[j]->getAtk());
                        TRACE("HITTED! HP=%d  %d  ATK=%d\n", monsters[i]->getHP(), i, bullets[j]->getAtk());
						CAudio::Instance()->Play(AUDIO_X_ATK_HITTED, false);
                        if (bullets[j]->getAttackType() != 2 && bullets[j]->getAttackType() != 3 && bullets[j]->getAttackType() != 4)
                        {
                            bulletActivate[j] = 0;
                            bullets[j]->isHitted();
                        }
                    }
                }
            }
        }

        if (bulletActivate[j] > -1)bullets[j]->OnMove(my, mx);

        if (bullets[j]->getD() == -1)bulletActivate[j] = -1;
    }

    for (int i = 0; i < 2; i++)
    {
        if (bossbulletActivate[i] == 1)
        {
            if (player->getHP() > 0)
            {
                int bx1 = bossbullets[i]->getX(), by1 = bossbullets[i]->getY();
                int bx2 = bx1 + bossbullets[i]->getWidth(), by2 = by1 + bossbullets[i]->getHeight();
                int mx1 = player->getX(), my1 = player->getY();
                int mx2 = mx1 + player->getWidth(), my2 = my1 + player->getHeight();

                if (bx2 >= mx1 && bx1 <= mx2 && by2 >= my1 && by1 <= my2)
                {
                    player->subHP(-10);
                    player->UISendHitted();
                    bossbulletActivate[i] = 0;
                }
            }
        }

        if (bossbulletActivate[i] > -1)bossbullets[i]->OnMove(my, mx);

        if (bossbullets[i]->getD() == -1)bossbulletActivate[i] = -1;
    }

    if (chargeLevel >= 0 && player->getXmodel() == 1)effect[chargeLevel].OnMove();
}

void Elementalattack::OnShow()
{
    int ux = 70, uy = 160;

    for (int j = 0; j < 10; j++)
    {
        if (bulletActivate[j] > -1 && bullets[j]->getD() != -1)
        {
            bullets[j]->OnShow();
        }
    }

    for (int j = 0; j < 2; j++)
    {
        if (bossbulletActivate[j] > -1 && bossbullets[j]->getD() != -1)
        {
            bossbullets[j]->OnShow();
        }
    }

    if (player->getXmodel() == 1 && atk_type == 0)
    {
        UI_Top.SetTopLeft(ux, uy);
        UI_Top.ShowBitmap();

        if (energy[0] == 0)
        {
            UI_mid[0][0].SetTopLeft(ux, uy + 6);
            UI_mid[0][0].ShowBitmap();
            UI_mid[1][0].SetTopLeft(ux, uy + 30);
            UI_mid[1][0].ShowBitmap();
        }

        if (energy[0] == 1)
        {
            UI_mid[0][0].SetTopLeft(ux, uy + 6);
            UI_mid[0][0].ShowBitmap();
            UI_mid[1][1].SetTopLeft(ux, uy + 30);
            UI_mid[1][1].ShowBitmap();
        }

        if (energy[0] == 2)
        {
            UI_mid[0][1].SetTopLeft(ux, uy + 6);
            UI_mid[0][1].ShowBitmap();
            UI_mid[1][1].SetTopLeft(ux, uy + 30);
            UI_mid[1][1].ShowBitmap();
        }

        UI_button[0].SetTopLeft(ux, uy + 54);
        UI_button[0].ShowBitmap();
    }
    else if (player->getXmodel() == 1)
    {
        UI_Top.SetTopLeft(ux, uy);
        UI_Top.ShowBitmap();

        if (energy[atk_type] == 100)
        {
            UI_mid[2][1].SetTopLeft(ux, uy + 6);
            UI_mid[2][1].ShowBitmap();
        }
        else
        {
            UI_mid[2][0].SetTopLeft(ux, uy + 6);
            UI_mid[2][0].ShowBitmap();
        }

        if (energy[atk_type] >= 90)
        {
            UI_mid[3][1].SetTopLeft(ux, uy + 18);
            UI_mid[3][1].ShowBitmap();
        }
        else
        {
            UI_mid[3][0].SetTopLeft(ux, uy + 18);
            UI_mid[3][0].ShowBitmap();
        }

        if (energy[atk_type] >= 80)
        {
            UI_mid[4][1].SetTopLeft(ux, uy + 30);
            UI_mid[4][1].ShowBitmap();
        }
        else
        {
            UI_mid[4][0].SetTopLeft(ux, uy + 30);
            UI_mid[4][0].ShowBitmap();
        }

        if (energy[atk_type] >= 70)
        {
            UI_mid[5][1].SetTopLeft(ux, uy + 42);
            UI_mid[5][1].ShowBitmap();
        }
        else
        {
            UI_mid[5][0].SetTopLeft(ux, uy + 42);
            UI_mid[5][0].ShowBitmap();
        }

        if (energy[atk_type] >= 60)
        {
            UI_mid[6][1].SetTopLeft(ux, uy + 54);
            UI_mid[6][1].ShowBitmap();
        }
        else
        {
            UI_mid[6][0].SetTopLeft(ux, uy + 54);
            UI_mid[6][0].ShowBitmap();
        }

        if (energy[atk_type] >= 50)
        {
            UI_mid[7][1].SetTopLeft(ux, uy + 66);
            UI_mid[7][1].ShowBitmap();
        }
        else
        {
            UI_mid[7][0].SetTopLeft(ux, uy + 66);
            UI_mid[7][0].ShowBitmap();
        }

        if (energy[atk_type] >= 40)
        {
            UI_mid[8][1].SetTopLeft(ux, uy + 78);
            UI_mid[8][1].ShowBitmap();
        }
        else
        {
            UI_mid[8][0].SetTopLeft(ux, uy + 78);
            UI_mid[8][0].ShowBitmap();
        }

        if (energy[atk_type] >= 30)
        {
            UI_mid[9][1].SetTopLeft(ux, uy + 90);
            UI_mid[9][1].ShowBitmap();
        }
        else
        {
            UI_mid[9][0].SetTopLeft(ux, uy + 90);
            UI_mid[9][0].ShowBitmap();
        }

        if (energy[atk_type] >= 20)
        {
            UI_mid[10][1].SetTopLeft(ux, uy + 102);
            UI_mid[10][1].ShowBitmap();
        }
        else
        {
            UI_mid[10][0].SetTopLeft(ux, uy + 102);
            UI_mid[10][0].ShowBitmap();
        }

        if (energy[atk_type] >= 10)
        {
            UI_mid[11][1].SetTopLeft(ux, uy + 114);
            UI_mid[11][1].ShowBitmap();
        }
        else
        {
            UI_mid[11][0].SetTopLeft(ux, uy + 114);
            UI_mid[11][0].ShowBitmap();
        }

        UI_button[atk_type].SetTopLeft(ux, uy + 126);
        UI_button[atk_type].ShowBitmap();
    }

    if (chargeLevel >= 0 && player->getXmodel() == 1)
    {
        effect[chargeLevel].SetTopLeft(player->getX() + 4, player->getY());
        effect[chargeLevel].OnShow();
    }
}



}