#include <iostream>
#include <string>
using namespace std;

int main(){
    int C;
    float F;
    cout << "화씨온도를 입력해주세요: ";
    cin >> C;

    cout << "최대로 살 수 있는 캔디: " << (5.0/9.0)*(C - 32) << endl;

    return 0;
}