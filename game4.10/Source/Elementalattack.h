namespace game_framework
{
class Character;
class Bullet  //單純控制子彈飛行
{


    public:
        Bullet();
        void LoadBitmap();
        void LoadHitEffectBitmap();
        void setDD(int dis, int dir, int xmode, int atktype, int energ[], int charglevel); //D距離 D方向 atk種類 當前能源 充能等級
        void SetXY(int nx, int ny);
        void SetTXY(int nx, int ny);
        int getX();
        int getY();
        int getHeight();
        int getWidth();
        int getD();
        int getAttackType();
        int getAtk();
        void isHitted();
        void OnMove(int my, int mx);
        void OnShow();
    private:
        CAnimation bullet[2][10];
        CAnimation hitEffect[2][10];
        int attackPoint;
        int distance, counting_distance;
        int direct, LR;
        int atk_type;
        int x, y, tx, ty;
        int getAtkPoint(int xmode, int energ[]);
};

class Elementalattack
{
    public:
        Elementalattack();
        ~Elementalattack();
        void LoadBitmap();
        void ShootingAtk(int nx, int ny, int xmode);
        void BossShootingAtk(int nx, int ny);
        void CloseRangeAtk();
        void SetChargingLevel(int chLevel);
        void Charge(int type, int e);
        void switchElm();
        void AddMonster(Character* m);
        bool DelleteMonster(int t);//0:delete all  1:delete 1 unit   return value= true:success false:fail
        void SetPlayerBoss(Character* p, Character* m);
        int getUIAtktype();
        void OnMove(int my, int mx);
        void OnShow();
    private:
        CMovingBitmap UI_Top;
        CMovingBitmap UI_mid[12][2];
        CMovingBitmap UI_button[3];
        Character* monsters[30], *player, *boss; //存放怪物與玩家資料//提供攻擊使用
        CAnimation effect[3];//charging level
        int monster_counter, activate_Count, bossactivate_Count;
        Bullet* bullets[10];
        Bullet* bossbullets[2];
        int chargeLevel;
        int bulletActivate[10];//-1不啟動 0顯示hit動畫 1子彈動畫
        int bossbulletActivate[2];//-1不啟動 0顯示hit動畫 1子彈動畫
        int atk_type, closeAtkCDR, CloseAtkPoint;
        int energy[3];//0:原形 無儲量 充能添加子彈MAX=2   1:龍捲風 測試 MAX=100 單次1
};
}