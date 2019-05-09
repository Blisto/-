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
		void setMovingDown(bool flag,int speed);
		void setMovingJump(bool flag);
		bool getUP();
		int getHP();
		int getX();
		int getY();
		int getHeight();
		int getWidth();
		int getUnit();
		void setHP(int newHP);
		void setMapData(int i, int j,int Data);
		int isBlock(int my, int mx, int moveDistence);
		void counte_distence(int my,int mx);
		int get_distence(int UDLR);
		void test();
		void Attack(CGameCharacter *monster, int mx, int my);
		void SetXY(int nx, int ny);
		void OnShow();			// 將圖形貼到畫面
		void OnMove(int my, int mx);
		void MonsterInit(int my, int mx);
		void AutoMove(int my, int mx);
	private:
		CMovingBitmap character;
		CAnimation animation;
		int healthPoints;
		int LR, moveCount,moveDistence;
		int mapData[3][100][100];
		int distenceBox[4];
		int x, y,moveUnit,speed,trans_x,trans_y,regenerateTime;
		int jumpY, newJumpY,jumpTime;
		bool isMovingRight;
		bool isMovingLeft;
		bool isMovingUp;
		bool isMovingDown;
		bool isMovingJump;

	};

}