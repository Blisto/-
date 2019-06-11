namespace game_framework {
	class mesageBox
	{
	public:
		mesageBox();
		~mesageBox();
		void LoadBitmap();
		void nextPage();
		void setHint(bool flag);
		bool isFinal();
		void openMesgBox(bool flag);
		bool getOpen();
		void OnMove(int mapN);
		void OnShow();
	private:
		CAnimation mesg[10],spaceBar;
		CMovingBitmap mesg_map2[25];
		int x, y,mapNum;
		int page,time;
		bool open,isHint;
	};

}