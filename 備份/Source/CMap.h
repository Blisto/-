namespace game_framework {

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
		void OnShow();											// �N�ϧζK��e��
		int getX();
		int getY();
		bool isBottom(int top_y, int left_x, int w, int h);
		int getMapData(int i, int j);
		void SetXY(int nx, int ny);								// �]�wXY�y��
		bool isBlock(int top_y, int left_x, int w, int h);
	private:
		CMovingBitmap map;
		int mapData[3][100][100];
		int x, y;
		bool isMovingUp, isMovingDown,isMovingRight,isMovingLeft;

	};



}