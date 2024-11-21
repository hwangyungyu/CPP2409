#include <iostream>
#include <string>
#include <vector>
using namespace std;

class User{
protected:
    int hp;
    int itemCnt;
public:
    User();
    void IncreaseHP(int inc_hp);
    void DecreaseHP(int dec_hp);
    void DoAttack();
    int GetHP();

    void IncreseItemCnt(int inc_item);
    friend ostream& operator<<(ostream& os, const User& v){
        os << "현재 HP는 " << v.hp << "이고, 먹은 아이템은 총 " << v.itemCnt << "개 입니다" << endl;
        return os;
    }
};

class Warrior:public User{
public:
    void DoAttack();
};

class Magician:public User{
public:
    void DoAttack();
};