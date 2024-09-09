#include <iostream>
//PI 가 기호 상수
#define PI 3.14159265359
using namespace std;

int main(){
    //1000이 리터럴 상수
    int income = 1000;
    //TAX_RATE가 상수 변수
    const double TAX_RATE = 0.25;
    income = income -TAX_RATE * income;

    double x = 100;
    x = x * PI;

    cout << x << endl;
    return 0;
}