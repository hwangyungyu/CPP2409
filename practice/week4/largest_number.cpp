#include <iostream>
using namespace std;

int main(){
    int a, b, c, largest;

    cout << "3개의 정수를 입력하시오: ";
    cin >> a >> b >> c;

    // 두가지 조건을 모두 만족해야만 largest에 들어가게 됩니다.
    // 따라서 (a > b && a > c)의 조건에서 5 5 3의 케이스의 경우에는 a > b조건이 불만족되어지니
    // (a >= b && a >= c) 으로 바꾸어 주었습니다.
    if(a >= b && a >= c){
        largest = a;
    }
    else if (b >= a && b >= c){
        largest = b;
    }
    else{
        largest = c;
    }

    //세 정수가 모두 같을때 출력
    if(a == b && b == c){
        cout << "세 정수가 " << largest << "로 같습니다." << endl;
    }
    else{
        cout << "가장 큰 정수는 " << largest << endl;
    }
    

    return 0;
}