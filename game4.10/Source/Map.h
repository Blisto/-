namespace game_framework {
	class Character;
	class mesageBox;
	class Map 
	{
	public:
		Map();
		~Map();
		void LoadBitmap();

		void SrollingUp(bool flag);
		void SrollingDown(bool flag);
		void SrollingRight(bool flag);
		void SrollingLeft(bool flag);

		void SetXY(int nx, int ny);


		//////
		//player 怪物 活動物件
		void playerUP(bool flag);
		void playerDown(bool flag);
		void playerRight(bool flag);
		void playerLeft(bool flag);
		void playerAtk(bool flag);
		void playerAtk2(bool flag);
		void mesgNext();
		bool getDeadState();
		//////
		void mesg(int phase);
		bool block_test(Character *p,  int UDRL);
		void CountDistance(Character *p, int UDRL);
		void fillGround();
		int CxToMapCoordinate(int cx);
		int CyToMapCoordinate(int cy);
		void OnMove();
		void OnShow();

		void testhp();
	private:
		int MegaManMode;
		CMovingBitmap map,UI[17],UI_megaman[7][2];
		CAnimation ground;
		int hpState;
		Character *p1;
		Character *monster[3];
		mesageBox *facai;
		int chLR, chNum;
		int mapData[3][834][2082];
		int x, y;
		int distanceBox[4];// U:0 D:1 R:3 L:2
		int moveUnit,downSpeed, accelerateTime;
		int jumpDistance,jumpSpeed,target;
		bool isMovingUp, isMovingDown, isMovingRight, isMovingLeft;
		void printMegaManUI(int ux, int uy);
	};
}