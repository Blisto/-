namespace game_framework {
	class CGameCharacter;
	class CMap
	{
	public:
		CMap();
		void LoadBitmap();										// ���J�ϧ�
		void setMapData(int mapNum);
		void OnMove();											// ����
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
		void OnShow();											// �N�ϧζK��e��
		int getX();
		int getY();
		bool isDead();
		int getMapData(int i, int j);
		void SetXY(int nx, int ny);								// �]�wXY�y��
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