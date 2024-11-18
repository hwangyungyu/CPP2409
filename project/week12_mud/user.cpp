#include "user.h"

User::User(){
    hp = 20;
    itemCnt = 0;
}

void User::IncreaseHP(int inc_hp){
    hp += inc_hp;
}

void User::DecreaseHP(int dec_hp){
    hp -= dec_hp;
}

int User::GetHP(){
    return hp;
}

void User::IncreseItemCnt(int inc_item){
    itemCnt += inc_item;
}

