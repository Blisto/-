namespace game_framework {

	class CMap
	{
	public:
		CMap();
		void LoadBitmap();										// ���J�ϧ�
		void OnMove();											// ����
		void SrollingUp(bool flag);
		void SrollingDown(bool flag);
		void SrollingRight(bool flag);
		void SrollingLeft(bool flag);
		void OnShow();											// �N�ϧζK��e��
		int getX();
		int getY();
		void SetXY(int nx, int ny);								// �]�wXY�y��
	private:
		CMovingBitmap map;
		int x, y;
		bool isMovingUp, isMovingDown,isMovingRight,isMovingLeft;

	};



}