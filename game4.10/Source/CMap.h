namespace game_framework {

	class CMap
	{
	public:
		CMap();
		void LoadBitmap();										// ���J�ϧ�
		void OnMove();											// ����
		void OnShow();											// �N�ϧζK��e��
		void SetXY(int nx, int ny);								// �]�wXY�y��
	private:
		CMovingBitmap map;
		int x, y;

	};



}