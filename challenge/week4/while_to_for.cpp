#include <iostream>
using namespace std;

int main(){
    int userInput;

    cout << "정수를 10번 입력하세요 (0을 입력하면 종료):";
    int i = 0;
    /*
    while(true){
        cin >> userInput;
        if(userInput == 0){
            break;
        }

        cout << "입력값: " << userInput << " 횟수 :"<< i++ << endl;

        if(i == 10){
            break;
        }
    }
    */
    i = 0;
    for(i = 0; i < 10; i++){
        cin >> userInput;

        if(userInput == 0){
            break;
        }

        cout << "입력값: " << userInput << " 횟수 :"<< i << endl;
    }

    cout << "종료 되었습니다.";
    return 0;
}