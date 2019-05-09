namespace game_framework {
	class mesageBox
	{
	public:
		mesageBox();
		~mesageBox();
		void LoadBitmap();
		void nextPage();
		bool isFinal();
		void openMesgBox(bool flag);
		bool getOpen();
		void OnMove();
		void OnShow();
	private:
		CAnimation mesg[10];
		int x, y;
		int page,time;
		bool open;
	};

}