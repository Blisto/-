#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CGameCharacter.h"


namespace game_framework 
{
	CGameCharacter::CGameCharacter() 
	{
		healthPoints = 100;
		x = 0; y = 0;
		trans_x = 384; trans_y = 384; speed = 10;
		moveUnit = 32;
		moveDistence = 160;
		isMovingRight = false;
		isMovingLeft = false;
		isMovingUp = false;
		isMovingDown = false;
		isMovingJump = false;
		LR = 0;
		moveCount = 2 * 1;
		jumpTime = 7;
		regenerateTime = 90;
		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				mapData[0][i][j] = 0;
			}
		}

	}

	void CGameCharacter::LoadBitmap() 
	{
		character.LoadBitmap(TestDog, RGB(255, 255, 255));
	}
	bool CGameCharacter::getUP() {
		return isMovingJump;
	}
	void CGameCharacter::setMovingRight(bool flag)
	{
		isMovingRight = flag;
	}
	
	void CGameCharacter::setMovingLeft(bool flag)
	{
		isMovingLeft = flag;
	}

	void CGameCharacter::setMovingUp(bool flag)
	{
		isMovingUp = flag;
	}

	void CGameCharacter::setMovingDown(bool flag,int speed)
	{
		this->speed = speed;
		isMovingDown = flag;
	}

	void CGameCharacter::setMovingJump(bool flag)
	{
		isMovingJump = flag;
	}

	int CGameCharacter::getHP() 
	{
		return healthPoints;
	}

	int CGameCharacter::getX()
	{
		return x;
	}

	int CGameCharacter::getY()
	{
		return y;
	}

	int CGameCharacter::getHeight()
	{
		return character.Height();
	}
	int CGameCharacter::getWidth()
	{
		return character.Width();
	}
	int CGameCharacter::getUnit() 
	{
		return moveUnit;
	}
	void CGameCharacter::setHP(int newHP) 
	{
		healthPoints = newHP;
	}


	void CGameCharacter::setMapData(int i, int j, int Data) 
	{
		mapData[0][i][j] = Data;
	}

	void CGameCharacter::counte_distence(int my, int mx) 
	{
		this->distenceBox[0] = 999;//上
		this->distenceBox[1] = 999;//下
		this->distenceBox[2] = 999;//左
		this->distenceBox[3] = 999;//右
		int cx1, cy1;
		cx1 = trans_x - mx * 32;
		cy1 = trans_y - my * 32;
		int next_x = cx1 / 32, next_y = cy1 / 32;

		for (int i = 0; i < 3; i++) {
			if (mapData[0][next_y - i][next_x] == 1)
			{
				if (cy1 - (next_y - i + 1) * 32 < distenceBox[0])distenceBox[0] = cy1 - (next_y - i + 1) * 32;
			}
			if (mapData[0][next_y + i][next_x] == 1)
			{
				if ((next_y + i) * 32 - (cy1 + this->getHeight()) < distenceBox[1])distenceBox[1] = (next_y + i) * 32 - (cy1 + this->getHeight());
			}

			if (mapData[0][next_y][next_x - i] == 1)
			{
				if (cx1 - (next_x - i + 1) * 32 < distenceBox[2])distenceBox[2] = cx1 - (next_x - i + 1) * 32;
			}

			if (mapData[0][next_y][next_x + i] == 1)
			{
				if ((next_x + i) * 32 - (cx1 + this->getWidth()) < distenceBox[3])distenceBox[3] = (next_x + i) * 32 - (cx1 + this->getWidth());
			}

		}
		
	}

	void CGameCharacter::test() {
		TRACE("上:%d 下:%d 左:%d 右:%d \n", distenceBox[0], distenceBox[1], distenceBox[2], distenceBox[3]);
	}

	void CGameCharacter::Attack(CGameCharacter *monster,int mx,int my) {
		int monster_x1 = monster->getX()-mx;
		int monster_y1 = monster->getY()-my;
		int monster_x2 = monster_x1+monster->getWidth();
		int monster_y2 = monster_y1+monster->getHeight();

		int attack_width = 32*3,attack_height=32*1;

		int attack_x1 = this->getX() - mx - attack_width;
		int attack_y1 = this->getY() - my;
		int attack_x2 = this->getX() - mx;
		int attack_y2 = this->getY() - my+attack_height;

		TRACE("1:%d - %d , %d - %d   2:%d - %d ,%d - %d\n", monster_x1, monster_y1, monster_x2, monster_y2, attack_x1, attack_y1, attack_x2, attack_y2);
		if(attack_x2 >= monster_x1 && attack_x1 <= monster_x2 && attack_y2 >= monster_y1 && attack_y1 <= monster_y2)monster->setHP(monster->getHP()-10);
	}

	int CGameCharacter::isBlock(int my, int mx,int moveDistence)
	{
		
		int cx1, cy1, cx2, cy2, cx3, cy3, cx4, cy4;//1:LeftTop 2:RightBottom 3:RightTop 4:LeftBottom
		int mx1, my1, mx2, my2, mx3, my3, mx4, my4;
		cx1 = trans_x - mx * 32;
		cy1 = trans_y - my * 32;
		int next_x = cx1 / 32, next_y = cy1 / 32;
		int x_matrix[8], y_matrix[8]; //移動的方向預測
		y_matrix[0] = (next_y - 1);//上
		x_matrix[0] = (next_x - mx);
		y_matrix[1] = (next_y + 1);//下
		x_matrix[1] = (next_x);
		y_matrix[2] = (next_y);//左
		x_matrix[2] = (next_x -1);
		y_matrix[3] = (next_y);//右
		x_matrix[3] = (next_x + 1);

		y_matrix[4] = (next_y - 1);
		x_matrix[4] = (next_x - 1);

		y_matrix[5] = (next_y - 1);//右
		x_matrix[5] = (next_x + 1);

		y_matrix[6] = (next_y + 1);//右
		x_matrix[6] = (trans_x - mx - 1);

		y_matrix[7] = (next_y + 1);//右
		x_matrix[7] = (next_x + 1);


		if (isMovingUp == true) 
		{
			cy1 -= moveDistence;
		}
		if (isMovingDown == true)
		{
			cy1 += moveDistence;
		}
		if (isMovingLeft == true)
		{
			cx1 -= moveDistence;
		}
		if (isMovingRight == true)
		{
			cx1 += moveDistence;
		}

		cx2 = cx1 + this->getWidth();
		cy2 = cy1 + this->getHeight();
		cx3 = cx1 + this->getWidth();
		cy3 = cy1;
		cx4 = cx1;
		cy4 = cy1 + this->getHeight();


		for (int i = 0; i < 8; i++) {
			if (mapData[0][y_matrix[i]][x_matrix[i]] == 1) {
				mx1 = x_matrix[i] * 32;
				my1 = y_matrix[i] * 32;
				mx2 = mx1 + 32;
				my2 = my1 + 32;
				mx3 = mx1 + 32;
				my3 = my1;
				mx4 = mx1;
				my4 = my1 + 32;
				if (cx2 >= mx1 && cx1 <= mx2 && cy2 >= my1 && cy1 <= my2) { return true; }
			}
			if (mapData[0][y_matrix[i]][x_matrix[i]] == 2) {
				mx1 = x_matrix[i] * 32;
				my1 = y_matrix[i] * 32;
				mx2 = mx1 + 32;
				my2 = my1 + 32;
				mx3 = mx1 + 32;
				my3 = my1;
				mx4 = mx1;
				my4 = my1 + 32;
				if (cx2 >= mx1 && cx1 <= mx2 && cy2 >= my1 && cy1 <= my2) { return 2; }
			}

		}

		return false;
	}

	void CGameCharacter::SetXY(int nx, int ny) 
	{
		x = nx; y = ny;
	}

	void CGameCharacter::checkStep() 
	{
		
	}

	void CGameCharacter::OnMove(int my,int mx) 
	{
		
		counte_distence(my, mx);
		if (isBlock(my, mx, 0) == 2) { 

			healthPoints = 0;
			return; 
		}
		if (isMovingUp == false && isMovingJump == false)jumpY = this->getY();
		if (isMovingUp == true) {
			newJumpY = this->getY();
			if (newJumpY - jumpY < -112) { isMovingJump = false; }
			else { isMovingJump = true; }


		}

		if (isMovingDown == true) {
			counte_distence(my, mx);
			if (distenceBox[3]!=0&&distenceBox[1] < 1)return;
			if (distenceBox[1] == 999 &&this->isBlock(my, mx,16) == 0)trans_y+=16;
		}
		if (isMovingRight == true) {
			counte_distence(my, mx);
			if (distenceBox[3] != 999 && distenceBox[3] <= 1)return;
			if (this->isBlock(my, mx,16) == 0)trans_x+=16;
		}
		if (isMovingLeft == true) {
			counte_distence(my, mx);
			if (distenceBox[2] != 999 && distenceBox[2] <= 1)return;
			if (this->isBlock(my, mx,16) == 0)trans_x-=16;
		}

		if (isMovingJump == true) {
			
			counte_distence(my, mx);
			if (distenceBox[0] < 1)return;
			if (jumpTime >= 0 && this->isBlock(my, mx, 16) == 0)trans_y -= 16;
		}
		if (isMovingUp==false&& isMovingJump == false &&distenceBox[1] != 0)
		{
			if (speed > distenceBox[1]) { speed = distenceBox[1]; }
			if (distenceBox[2] < 1) { trans_x -= distenceBox[2]; }
			if (distenceBox[3] < 1) { trans_x += distenceBox[3]; }
			trans_y += speed++;
		}
		else if(distenceBox[1] == 0){
			speed = 10;
			jumpTime = 7;
		}



		this->SetXY(trans_x, trans_y);
		//TRACE("map:%d %d chara:%d %d or:%d %d", mx*32, my*32, trans_x - (mx*32), trans_y - (my*32),trans_x,trans_y);
	}
	int CGameCharacter::get_distence(int UDLR){
		return distenceBox[UDLR];
	}
	void CGameCharacter::OnShow() 
	{
		if (this->healthPoints <= 0) {
			regenerateTime--;
			if (regenerateTime == 0)
			{
				regenerateTime = 90;
				healthPoints = 100;
			}
			return; 
		}
		if (this->isMovingJump == true)jumpTime--;
		if (jumpTime == 0)isMovingJump = false;
		TRACE("%d %d\n", isMovingJump,isMovingUp);
		character.SetTopLeft(x, y);
		character.ShowBitmap();
		
	}
	

	void CGameCharacter::MonsterInit(int my, int mx) {
		character.LoadBitmap(monsterTest, RGB(255, 255, 255));
		trans_x = 640; trans_y =32;
	}
	void CGameCharacter::AutoMove(int my, int mx) 
	{	
		int new_my = -224 - my;
		int new_mx = 352 - mx;
		this->SetXY(trans_x -new_mx, trans_y-new_my);
		
		moveCount--;
		if (moveCount == 0) {
			if (moveDistence == 0) { LR = 1; }
			if (moveDistence == 160) { LR = 0; }

			if (LR == 0) 
			{
				trans_x += 8; moveDistence -= 8;
			}
			if (LR == 1) {
				trans_x -= 8; moveDistence += 8;
			}
			moveCount = 1;
		}
		//TRACE("monster: %d %d projection: %d %d", trans_x, trans_y, trans_x - new_mx, trans_y - new_my);
	}
}