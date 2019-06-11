namespace game_framework
{
class Character;
class Bullet  //��±���l�u����
{


    public:
        Bullet();
        void LoadBitmap();
        void LoadHitEffectBitmap();
        void setDD(int dis, int dir, int xmode, int atktype, int energ[], int charglevel); //D�Z�� D��V atk���� ��e�෽ �R�൥��
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
        Character* monsters[30], *player, *boss; //�s��Ǫ��P���a���//���ѧ����ϥ�
        CAnimation effect[3];//charging level
        int monster_counter, activate_Count, bossactivate_Count;
        Bullet* bullets[10];
        Bullet* bossbullets[2];
        int chargeLevel;
        int bulletActivate[10];//-1���Ұ� 0���hit�ʵe 1�l�u�ʵe
        int bossbulletActivate[2];//-1���Ұ� 0���hit�ʵe 1�l�u�ʵe
        int atk_type, closeAtkCDR, CloseAtkPoint;
        int energy[3];//0:��� �L�x�q �R��K�[�l�uMAX=2   1:�s���� ���� MAX=100 �榸1
};
}