namespace game_framework
{
	class Character
	{
	public:
		Character();
		void LoadBitmap();

		void setMovingRight(bool flag);
		void setMovingLeft(bool flag);
		void setMovingUp(bool flag);
		void setMovingDown(bool flag);

		void setHP(int newHP);
		void SetXY(int nx, int ny);
		void SetMapXY(int nx, int ny);
		void SetnewMapXY(int nx, int ny);
		void AddXY(int nx, int ny);
		void setAnimation(int lr, int num);
		bool isDead();

		int getHP();
		int getX();
		int getY();
		int getHeight();
		int getWidth();
		bool getAtkIsLast(int Anum);
		bool getAttack();
		bool getAttack2();
		int getshootDistance();


		void testAtk(bool flag);
		void testAtk2(bool flag);
		bool ImpactCheck(Character *monster);

		void Attack(Character *monster);
		void MonsterInit(int select);
		void mesg();
		bool Mbox(int box_x, int box_y);

		void playerInit();
		void AutoMove(int my, int mx, int select, int px, int py);
		void OnMove(int lr, int num);
		void bulletMove();
		void OnShow();

	private:
		CAnimation animation[2][2][10], bullet[2][5];//[MegaMan][LR][num] X模式 選擇左右  選擇模型
		CAnimation animationX[2][10];
		int healthPoints;
		int LR, moveCount, moveDistence,shootDistance;

		int x, y,bx,by,moveUnit,  regenerateTime,tx,ty;
		int MapX, MapY,newMapX,newMapY;
		bool isMovingRight;
		bool isMovingLeft;
		bool isMovingUp;
		bool isMovingDown;
		bool isAttack,isAttack2;
		bool isHit;
		int chLR, chNum;
	};
}