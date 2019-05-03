namespace game_framework {

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
		void OnShow();											// 將圖形貼到畫面
		int getX();
		int getY();
		bool isBottom(int top_y, int left_x, int w, int h);
		int getMapData(int i, int j);
		void SetXY(int nx, int ny);								// 設定XY座標
		bool isBlock(int top_y, int left_x, int w, int h);
	private:
		CMovingBitmap map;
		int mapData[3][100][100];
		int x, y;
		bool isMovingUp, isMovingDown,isMovingRight,isMovingLeft;

	};



}