#include <iostream>
#include <string>
using namespace std;

int main(){
    int C;
    float F, q;
    cout << "화씨온도를 입력해주세요: ";
    cin >> C;

    q = (5.0/9.0)*(C - 32);

    cout << "섭씨 온도: " << q << endl;

    return 0;
}