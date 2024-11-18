#include <iostream>
#include <string>
#include <vector>
using namespace std;

class User{
private:
    int hp;
    int itemCnt;
public:
    User();
    void IncreaseHP(int inc_hp);
    void DecreaseHP(int dec_hp);
    int GetHP();

};