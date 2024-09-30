#include <iostream>
using namespace std;

int main(){
    int floor;
    cout << "몇 층을 쌓겠습니까? (5~100):";
    cin >> floor;

    for(int i = 0; i < floor; i++){
        // for문을 1개로 합쳐 계산하도록 바꾸었습니다.
        for(int j = 0; j < (floor - 1 - i) + (i*2+1); j++){
            if(j < floor - 1 - i){
                cout << "S";
            }
            else{
                cout << "*";
            }
        }

        cout << endl;
    }
    return 0;
}