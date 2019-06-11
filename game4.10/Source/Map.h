namespace game_framework {
	class Character;
	class mesageBox;
	class Elementalattack;



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
		void Dash(bool flag);
		void SetXY(int nx, int ny);


		//////
		//player 怪物 活動物件
		void playerAtk(bool flag);
		void playerAtk2(bool flag);
		void ChargeAll();
		void SwitchElem();
		void SwitchMap();
		void mesgNext();
		bool getDeadState();
		bool getClearState();
		void setXmodel(int m);
		int getXmodel();
		void setMacro(int n);
		//////
		void ResetGravity();
		void mesg(int phase);
		bool block(Character *p,  int UDRL);
		void CountDistance(Character *p, int UDRL);
		void fillGround(int n);
		void OnMove();
		void OnShow();

	private:
		CMovingBitmap map[2],UI[17],UI_megaman[7][2], UI_Boss[7][2],finalList[4];
		CAnimation ground;
		Character *p1;
		Character *monster[30],*boss;
		mesageBox *facai;
		Elementalattack *energyAndBullet;
		int chLR, chNum;
		int mapData[3][6000][6000],mapNum;//原834 2082
		int x, y,monster_counter,clear_page;
		int xmode, macroWorking;
		int distanceBox[4];// U:0 D:1 R:3 L:2
		int moveUnit,downSpeed, accelerateTime;
		int dash_d, chargingTime,clear_counter;
		bool isMovingUp, isMovingDown, isMovingRight, isMovingLeft, isDash,isCharging,isGameOver;
		void printMegaManUI(int ux, int uy, Character *p);
		void printBossUI(int ux, int uy, Character *boss);
		void mapDataInit();
		int CxToMapCoordinate(int cx);
		int CyToMapCoordinate(int cy);
		void generateMonster();
	};
}