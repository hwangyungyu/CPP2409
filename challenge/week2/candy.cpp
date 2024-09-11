#include <iostream>
#include <string>
using namespace std;

int main(){
    int money, candy_price;
    
    cout << "현재 가지고 있는 돈: ";
    cin >> money;
    cout << "캔디의 가격: ";
    cin >> candy_price;

    int result_count, change_money;

    result_count = money / candy_price;
    change_money = money - (candy_price*result_count);

    cout << "최대로 살 수 있는 캔디: " << result_count << endl;
    cout << "캔디 구입 후 남은 돈: " << change_money << endl;

    return 0;
}