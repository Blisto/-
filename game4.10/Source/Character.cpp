#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Character.h"

namespace game_framework
{
	Character::Character()
	{
		healthPoints = 100;
		x = 352; y = 200;//417

		moveUnit = 2;
		moveDistence = 160;
		isMovingRight = false;
		isMovingLeft = false;
		isMovingUp = false;
		isMovingDown = false;
		isAttack = false;
		isAttack2 = false;
		isHit = false;


		shootDistance = 0;
		bx = 0; by = 0;
		LR = 0;
		moveCount = 2 * 1;
		regenerateTime = 90;
		chLR =0; chNum = 0;

	}

	void Character::LoadBitmap()
	{	//using in test
		//character.LoadBitmap(TestDog, RGB(255, 255, 255));

		//[MegaMan][LR][num] LR=0:´Â¥k  LR=1:´Â¥ª        
		//num:0 ¯¸«º   :1 ¶]    :2 ¸õ[¤W¤É]   :3 ¸õ[¸¨¤U]     :4§ðÀ»[»·]   :5 ¦º¤`   :6§ðÀ»[ªñ]

		////////////////////////////////////////////////////////////////
		//X
		animationX[0][0].AddBitmap(R_X_s0, RGB(255, 255, 255));
		animationX[0][0].AddBitmap(R_X_s1, RGB(255, 255, 255));
		animationX[0][0].AddBitmap(R_X_s2, RGB(255, 255, 255));
		animationX[0][0].SetDelayCount(3);


		animationX[0][1].AddBitmap(R_X_r0, RGB(255, 255, 255));
		animationX[0][1].AddBitmap(R_X_r1, RGB(255, 255, 255));
		animationX[0][1].AddBitmap(R_X_r2, RGB(255, 255, 255));
		animationX[0][1].AddBitmap(R_X_r3, RGB(255, 255, 255));
		animationX[0][1].AddBitmap(R_X_r4, RGB(255, 255, 255));
		animationX[0][1].AddBitmap(R_X_r5, RGB(255, 255, 255));
		animationX[0][1].AddBitmap(R_X_r6, RGB(255, 255, 255));
		animationX[0][1].AddBitmap(R_X_r7, RGB(255, 255, 255));
		animationX[0][1].AddBitmap(R_X_r8, RGB(255, 255, 255));
		animationX[0][1].AddBitmap(R_X_r9, RGB(255, 255, 255));
		animationX[0][1].AddBitmap(R_X_r10, RGB(255, 255, 255));
		animationX[0][1].AddBitmap(R_X_r11, RGB(255, 255, 255));
		animationX[0][1].SetDelayCount(3);

		animationX[0][2].AddBitmap(R_X_j0, RGB(255, 255, 255));
		animationX[0][2].AddBitmap(R_X_j1, RGB(255, 255, 255));
		animationX[0][2].AddBitmap(R_X_j2, RGB(255, 255, 255));
		animationX[0][2].SetDelayCount(3);

		animationX[0][3].AddBitmap(R_X_j3, RGB(255, 255, 255));
		animationX[0][3].AddBitmap(R_X_j4, RGB(255, 255, 255));
		animationX[0][3].AddBitmap(R_X_j5, RGB(255, 255, 255));
		animationX[0][3].SetDelayCount(3);

		animationX[0][4].AddBitmap(R_X_a0f, RGB(255, 255, 255));
		animationX[0][4].AddBitmap(R_X_a1f, RGB(255, 255, 255));
		animationX[0][4].SetDelayCount(3);

		animationX[0][6].AddBitmap(R_X_a0c, RGB(255, 255, 255));
		animationX[0][6].AddBitmap(R_X_a1c, RGB(255, 255, 255));
		animationX[0][6].AddBitmap(R_X_a2c, RGB(255, 255, 255));
		animationX[0][6].AddBitmap(R_X_a3c, RGB(255, 255, 255));
		animationX[0][6].SetDelayCount(3);
		////////////////////////////////////////////////////////////////
		//Arthur
		//¥k
		animation[0][0][0].AddBitmap(R_P0, RGB(255, 255, 255));

		animation[0][0][1].AddBitmap(R_P1, RGB(255, 255, 255));
		animation[0][0][1].AddBitmap(R_P2, RGB(255, 255, 255));
		animation[0][0][1].AddBitmap(R_P3, RGB(255, 255, 255));
		animation[0][0][1].AddBitmap(R_P4, RGB(255, 255, 255));
		animation[0][0][1].AddBitmap(R_P5, RGB(255, 255, 255));
		animation[0][0][1].AddBitmap(R_P6, RGB(255, 255, 255));
		animation[0][0][1].SetDelayCount(3);
		
		animation[0][0][4].AddBitmap(atk1_R, RGB(255, 255, 255));
		animation[0][0][4].AddBitmap(atk2_R, RGB(255, 255, 255));
		animation[0][0][4].AddBitmap(atk2_R, RGB(255, 255, 255));
		animation[0][0][4].SetDelayCount(10);

		animation[0][0][2].AddBitmap(R_J1, RGB(255, 255, 255));
		animation[0][0][3].AddBitmap(R_J2, RGB(255, 255, 255));

		animation[0][0][6].AddBitmap(atk1_Rc, RGB(255, 255, 255));
		animation[0][0][6].AddBitmap(atk2_Rc, RGB(255, 255, 255));
		animation[0][0][6].AddBitmap(atk2_Rc, RGB(255, 255, 255));
		animation[0][0][6].SetDelayCount(10);
		//¥ª
		animation[0][1][0].AddBitmap(L_P0, RGB(255, 255, 255));

		animation[0][1][1].AddBitmap(L_P1, RGB(255, 255, 255));
		animation[0][1][1].AddBitmap(L_P2, RGB(255, 255, 255));
		animation[0][1][1].AddBitmap(L_P3, RGB(255, 255, 255));
		animation[0][1][1].AddBitmap(L_P4, RGB(255, 255, 255));
		animation[0][1][1].AddBitmap(L_P5, RGB(255, 255, 255));
		animation[0][1][1].AddBitmap(L_P6, RGB(255, 255, 255));
		animation[0][1][1].SetDelayCount(3);

		animation[0][1][4].AddBitmap(atk1_L, RGB(255, 255, 255));
		animation[0][1][4].AddBitmap(atk2_L, RGB(255, 255, 255));
		animation[0][1][4].AddBitmap(atk2_L, RGB(255, 255, 255));
		animation[0][1][4].SetDelayCount(10);

		animation[0][1][2].AddBitmap(L_J1, RGB(255, 255, 255));
		animation[0][1][3].AddBitmap(L_J2, RGB(255, 255, 255));

		animation[0][0][5].AddBitmap(dameage, RGB(255, 255, 255));
		animation[0][0][5].AddBitmap(death1, RGB(255, 255, 255));
		animation[0][0][5].AddBitmap(death2, RGB(255, 255, 255));
		animation[0][0][5].AddBitmap(death3, RGB(255, 255, 255));
		animation[0][0][5].AddBitmap(death4, RGB(255, 255, 255));
		animation[0][0][5].AddBitmap(death5, RGB(255, 255, 255));
		animation[0][0][5].AddBitmap(death5, RGB(255, 255, 255));
		animation[0][0][5].SetDelayCount(20);

		animation[0][1][6].AddBitmap(atk1_Lc, RGB(255, 255, 255));
		animation[0][1][6].AddBitmap(atk2_Lc, RGB(255, 255, 255));
		animation[0][1][6].AddBitmap(atk2_Lc, RGB(255, 255, 255));
		animation[0][1][6].SetDelayCount(10);

		bullet[0][0].AddBitmap(spear_r, RGB(255, 255, 255));
		bullet[1][0].AddBitmap(spear_L, RGB(255, 255, 255));
	}

	void Character::setMovingRight(bool flag)
	{
		isMovingRight = flag;
	}

	void Character::setMovingLeft(bool flag)
	{
		isMovingLeft = flag;
	}

	void Character::setMovingUp(bool flag)
	{
		isMovingUp = flag;
	}

	void Character::setMovingDown(bool flag)
	{
		isMovingDown = flag;
	}



	void Character::setHP(int newHP)
	{
		healthPoints = newHP;
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

	bool Character::isDead() 
	{
		if (this->healthPoints > 0)return false;
		return true;
	}
	////////////////////////////////////////////////


	int Character::getHP()
	{
		return healthPoints;
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
		return animation[0][chLR][chNum].Height();
	}

	int Character::getWidth()
	{
		return animation[0][chLR][chNum].Width();
	}

	bool Character::getAtkIsLast(int Anum) 
	{
		//if (animation[chLR][Anum].IsFinalBitmap() == true)animation[chLR][Anum].Reset();
		return animation[0][chLR][Anum].IsFinalBitmap();
	}

	bool Character::getAttack()
	{
		return isAttack;
	}

	bool Character::getAttack2()
	{
		return isAttack2;
	}

	int Character::getshootDistance()
	{
		return shootDistance;
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
	bool Character::ImpactCheck(Character *monster) 
	{
		int bullet_x1 = bx - MapX, bullet_y1 = by - MapY;
		int bullet_x2=bullet_x1+bullet[0][0].Width()-1, bullet_y2=bullet_y1+ bullet[0][0].Height() - 1;
		int mons_x1=monster->getX() - MapX, mons_y1= monster->getY() - MapY;
		int mons_x2= mons_x1+monster->getWidth()-1, mons_y2= mons_y1 + monster->getHeight() - 1;

		//TRACE("   %d,%d  %d,%d    %d,%d %d,%d\n", bullet_x1, bullet_y1, bullet_x2, bullet_y2, mons_x1, mons_y1, mons_x2, mons_y2);

		if (monster->isDead() == false && shootDistance > 0 && bullet_x2 >= mons_x1 && bullet_x1 <= mons_x2 && bullet_y2 >= mons_y1 && bullet_y1 <= mons_y2) {
			
			shootDistance = 0;
			monster->setHP(monster->getHP() - 50);
			isHit = true;
			return true;
		}

			isHit = false;
			return false;
	}


	void Character::Attack(Character *monster) {
		int monster_x1 = monster->getX() - MapX;
		int monster_y1 = monster->getY() - MapY;
		int monster_x2 = monster_x1 + monster->getWidth()-1;
		int monster_y2 = monster_y1 + monster->getHeight()-1;

		int attack_width = 64 * 1, attack_height = 32 * 1;

		int attack_x1 ;
		int attack_y1 ;
		int attack_x2 ;
		int attack_y2 ;


		if (this->chLR == 0)
		{
			attack_x1 = this->getX() - MapX + this->getWidth() - 1;
			attack_y1 = this->getY() - MapY;
			attack_x2 = attack_x1 + attack_width;
			attack_y2 = attack_y1 + attack_height;
		}
		else if(this->chLR==1){
			attack_x1 = this->getX() - MapX - attack_width;
			attack_y1 = this->getY() - MapY;
			attack_x2 = attack_x1 + attack_width;
			attack_y2 = attack_y1 + attack_height;
		}

		if (this->chLR == 0 && attack_x2 >= monster_x1 && attack_x1 <= monster_x2 && attack_y2 >= monster_y1 && attack_y1 <= monster_y2)monster->setHP(monster->getHP() - 10);
		if (this->chLR == 1 && attack_x2 >= monster_x1 && attack_x1 <= monster_x2 && attack_y2 >= monster_y1 && attack_y1 <= monster_y2)monster->setHP(monster->getHP() - 10);
	}

	//////////////////////////////////////////////////////

	void Character::MonsterInit(int select) {

		if (select == 0) 
		{
			tx = 370; ty = 95;
			moveDistence = 160;
			LR = 0;
			chLR = 0; chNum = 0;
		}
		if (select == 1)
		{
			tx = 850; ty = 95;
			moveDistence = 160;
			LR = 0;
			chLR = 0; chNum = 0;
		}

		animation[0][0][0].AddBitmap(M1_5, RGB(255, 255, 255));
		animation[0][0][1].AddBitmap(M1_5, RGB(255, 255, 255));
		animation[0][0][1].AddBitmap(M1_4, RGB(255, 255, 255));
		animation[0][0][1].AddBitmap(M1_3, RGB(255, 255, 255));

		animation[0][0][1].SetDelayCount(5);

		animation[0][1][0].AddBitmap(M1_0, RGB(255, 255, 255));
		animation[0][1][1].AddBitmap(M1_0, RGB(255, 255, 255));
		animation[0][1][1].AddBitmap(M1_1, RGB(255, 255, 255));
		animation[0][1][1].AddBitmap(M1_2, RGB(255, 255, 255));
		animation[0][1][1].SetDelayCount(5);


	}

	void Character::playerInit()
	{
		healthPoints = 100;
	}

	void Character::AutoMove(int my, int mx, int select,int px,int py)
	{
		int new_my = - my;
		int new_mx =  - mx;
		this->SetXY(tx - new_mx, ty - new_my);

		if (select == 0) 
		{
			moveCount--;
			if (moveCount == 0) {
				if (moveDistence == 0) { LR = 1; }
				if (moveDistence == 160) { LR = 0; }
				chLR = LR;
				chNum = 1;
				if (LR == 0)
				{
					this->tx += 4; moveDistence -= 4;
				}
				if (LR == 1) {
					this->tx -= 4; moveDistence += 4;
				}
				animation[chLR][chNum].OnMove();
				moveCount = 2;
			}
		}
		if (select == 1)
		{
			px += new_mx;
			py += new_my;
			TRACE("%d %d  %d %d\n", px, py, tx - new_mx, ty - new_my);
			moveCount--;
			if (moveCount == 0) {
				if (moveDistence == 0) { LR = 1; }
				if (moveDistence == 160) { LR = 0; }
				chLR = LR;
				chNum = 1;

				if (LR == 0)
				{
					if (py > 50 && py < 159 && px>710 && px < 1082) 
					{
						this->tx += 8; moveDistence -= 8;
					}
					else { this->tx += 4; moveDistence -= 4; }
				}
				if (LR == 1) {
					if (py > 50 && py < 159 && px>710 && px < 1082)
					{
						this->tx -= 8; moveDistence += 8;
					}
					else { this->tx -= 4; moveDistence += 4; }
				}

				animation[chLR][chNum].OnMove();
				moveCount = 2;
			}
<<<<<<< HEAD:æ–°å¢žè³‡æ–™å¤¾/Source/Character.cpp
=======
			animation[0][chLR][chNum].OnMove();
			moveCount = 2;
>>>>>>> 2c91df05c316aaac117f0b052367c85e4c511858:game4.10/Source/Character.cpp
		}
	}





	void Character::mesg()
	{
		TRACE("x:%d y:%d\n", this->x, this->y);
	}

	bool Character::Mbox(int box_x, int box_y)
	{
		int monster_x1 = box_x ;
		int monster_y1 = box_y ;
		int monster_x2 = monster_x1 + 31;
		int monster_y2 = monster_y1 + 31;

		int attack_width = 32 * 1, attack_height = 32 * 1;

		int attack_x1 = this->getX() - MapX + this->getWidth() - 1;
		int attack_y1 = this->getY() - MapY;
		int attack_x2 = attack_x1 + attack_width;
		int attack_y2 = attack_y1 + attack_height;
		if (attack_x2 >= monster_x1 && attack_x1 <= monster_x2 && attack_y2 >= monster_y1 && attack_y1 <= monster_y2)return true;
		return false;
	}

	////////////////////////////////////////////////////////
	void Character::OnMove(int lr, int num)
	{
		chLR = lr; chNum = num;
		

		if (isMovingUp == true) { this->y -= 1; }
		if (isMovingDown == true) { this->y += 1; }
		if (isMovingLeft == true) { this->x -= 1; }
		if (isMovingRight == true) { this->x += 1; }
		if (isAttack == true && this->getAtkIsLast(4) == true&& this->getshootDistance() == 0) {
			isAttack = false; 
			animation[0][0][4].Reset();
			animation[0][1][4].Reset();
			shootDistance = 400;
			bx = this->x + this->getWidth() -30;
			by = this->y + 15;
			isHit = false;
		}
		if (isAttack2 == true && this->getAtkIsLast(6) == true) {
			isAttack2 = false;
			animation[0][0][6].Reset();
			animation[0][1][6].Reset();
		}
		if (shootDistance != 0) { this->bulletMove(); }
		
		//animation[1][0][chNum].OnMove();
		

		animation[0][chLR][chNum].OnMove();


	}
	void  Character::bulletMove()
	{
		if(moveUnit==0){
		//int new_my = by+(MapY)-newMapY;
		//int new_mx = bx+(MapX)-newMapX;
		if (isHit == true)return;
		bx += 10;
		shootDistance -= 10;
		bullet[0][0].SetTopLeft(bx, by);
		moveUnit = 1;
		//TRACE("¤l¼uXY:%d %d    in map:   %d %d \n", bx, by, bx - MapX, by - MapY);
		}
		moveUnit--;
	}
	void Character::OnShow()
	{


			//animation[0][chLR][chNum].SetTopLeft(x, y);
			//animation[0][chLR][chNum].OnShow();

			animationX[0][0].SetTopLeft(100, 100);
			animationX[0][0].OnShow();


		if (isHit == false&&shootDistance > 0) //¤l¼u
		{
			bullet[0][0].OnShow();
		}
	}
}