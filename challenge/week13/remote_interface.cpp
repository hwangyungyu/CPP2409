#include <iostream>
using namespace std;

class RemoteControl{
public:
    virtual void TurnON() = 0;
    virtual void TurnOFF() = 0;
};

class Television : public RemoteControl{
    void TurnON() override{
        cout << "TV를 켭니다." << endl;
    }
    void TurnOFF() override{
        cout << "TV를 끕니다." << endl;
    }
};

class Refrigerator : public RemoteControl{
    void TurnON() override{
        cout << "냉장고를 켭니다." << endl;
    }
    void TurnOFF() override{
        cout << "냉장고를 끕니다." << endl;
    }
};

int main(){
    RemoteControl* remoteTV = new Television();
    remoteTV->TurnON();
    remoteTV->TurnOFF();
    
    RemoteControl* remoteRerigerator = new Refrigerator();
    remoteRerigerator->TurnON();
    remoteRerigerator->TurnOFF();

    delete remoteTV, remoteRerigerator;
    return 0;
}