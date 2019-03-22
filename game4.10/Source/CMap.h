namespace game_framework {

	class CMap
	{
	public:
		CMap();
		void LoadBitmap();										// 載入圖形
		void OnMove();											// 移動
		void SrollingUp(bool flag);
		void SrollingDown(bool flag);
		void SrollingRight(bool flag);
		void SrollingLeft(bool flag);
		void OnShow();											// 將圖形貼到畫面
		int getX();
		int getY();
		void SetXY(int nx, int ny);								// 設定XY座標
	private:
		CMovingBitmap map;
		int x, y;
		bool isMovingUp, isMovingDown,isMovingRight,isMovingLeft;

	};



}