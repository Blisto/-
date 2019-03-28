#pragma once
namespace game_framework 
{
	class CGameCharacter 
	{
	public:
		CGameCharacter();
		void LoadBitmap();
		void setMovingRight(bool flag);
		void setMovingLeft(bool flag);
		void setMovingUp(bool flag);
		void setMovingDown(bool flag);
		void setMovingJump(bool flag);
		int getHP();
		int getX();
		int getY();
		int getHeight();
		int getWidth();
		int getUnit();
		void setHP(int newHP);
		void setBlockFlag(bool flag);
		//bool isHit(int x1, int y1, int x2, int y2);
		//void Attacking();
		//void Shooting();
		void SetXY(int nx, int ny);
		void checkStep();
		void OnShow();											// 將圖形貼到畫面
		void OnMove();
	private:
		CMovingBitmap character;
		CAnimation animation;
		int healthPoints;
		int x, y,moveUnit;
		int isMovingRight;
		int isMovingLeft;
		int isMovingUp;
		int isMovingDown;
		int isMovingJump;
		bool blockflag;
	};

}