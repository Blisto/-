namespace game_framework
{
class Character
{
    public:
        Character();
        void LoadBitmap();
        void setHP(int newHP);
        void SetY(int ny);
        void SetXY(int nx, int ny);
        void SetMapXY(int nx, int ny);
        void SetnewMapXY(int nx, int ny);
        void AddXY(int nx, int ny);
        void setAnimation(int lr, int num);
        void setXmodel(int m);
        bool isDead();
        void resetAnimation(int lr, int num);
        void UISendHitted();
        int getHP();
        int subHP(int n);
        int getX();
        int getY();
        int getHeight();
        int getWidth();
        bool getAtkIsLast(int Anum);
        bool getAttack();
        bool getAttack2();
        int getXmodel();
        int getLR();

        void testAtk(bool flag);
        void testAtk2(bool flag);

        bool Mbox(int box_x, int box_y);

        void MonsterInit(int select, int nx, int ny);
        void MonsterStatusReset(int xx, int yy);
        bool MonsterAttack(int nmapX, int nmapY, Character* player);
        void AutoMove(int my, int mx, Character* p);
        int getDistanceWith(Character* p);
        int getDirectWith(Character* p);
        bool isBossLevel();
        void OnMove(int lr, int num);
        void OnShow();

        bool animationOnMove();
        void animationOnShow();
    private://num 0~9:Arthur 10~30:MegaMan
        CAnimation animation[2][40];//[LR][num]選擇左右  選擇模型
        CAnimation appearance[3];
        int appearancePhase;
        int healthPoints;
        int x, y, tx, ty, megaManMode, saveX, saveY;
        int MapX, MapY, newMapX, newMapY;
        bool isAttack, isAttack2, isBoss;
        int chLR, chNum;
        int monsterAtkF, moveCount, moveDistence, m_atk, actionType, actionPtr, monsterSetting; //怪物的攻擊頻率 移動方向 移動距離 怪物攻擊力
        int dist(int x1, int y1, int x2, int y2);
};


}