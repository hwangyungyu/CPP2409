#include <iostream>
using namespace std;

int main(){
    int number;

    cout << "숫자를 입력하시오: ";

    cin >> number;

    switch(number){
        //if 문의 조건을 case 문으로 바꾸었습니다.
        case 0:
            cout << "zero" << endl;
            break;
        case 1:
            cout << "one" << endl;
            break;
        default:
            cout << "many" << endl;
            break;
    }
    return 0;
}