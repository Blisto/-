namespace game_framework {
	class CGameCharacter;
	class CMap
	{
	public:
		CMap();
		void LoadBitmap();										// 載入圖形
		void setMapData(int mapNum);
		void OnMove();											// 移動
		void SrollingUp(bool flag);
		void SrollingDown(bool flag);
		void SrollingRight(bool flag);
		void SrollingLeft(bool flag);
		void playerUP(bool flag);
		bool getPlayerUP();
		void playerDown(bool flag);
		void playerRight(bool flag);
		void playerLeft(bool flag);
		void playerXY(int nx, int ny);
		void playerAttack();
		void OnShow();											// 將圖形貼到畫面
		int getX();
		int getY();
		bool isDead();
		int getMapData(int i, int j);
		void SetXY(int nx, int ny);								// 設定XY座標
	private:
		CMovingBitmap map;
		CGameCharacter *p1;
		CGameCharacter *testMon1;
		int moveCount;
		int mapData[3][100][100];
		int objType;
		int x, y;
		bool isMovingUp, isMovingDown,isMovingRight,isMovingLeft;

	};



}