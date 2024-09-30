#include <iostream>
#include <string>
using namespace std;

int main(){
    const int maxPeople = 5;
    string names[maxPeople];
    int ages[maxPeople];
    int menu = 0;

    cout << maxPeople << "명의 회원 정보를 입력해주세요." << endl;

    for(int i = 0; i < maxPeople; i++){
        cout << "사람" << i+1 << "의 이름: ";
        cin >> names[i];
        cout << "사람" << i+1 << "의 나이: ";
        cin >> ages[i];
        cout << endl;
    }

    

    int max_num;
    int max = ages[0];

    int min_num;
    int min = ages[0];


    while(menu < 4){
        cout << "1. 나이가 가장 많은 사람, 2. 나이가 가장 적은 사람, 3. 모두 출력, 4. 종료" << endl;
        cin >> menu;
        
        bool min_check = true;
        bool max_check = true;

        switch(menu){
            case 1:
                cout << "나이가 가장 많은 사람" << endl;
                //max에 최대값을 담아놓습니다.
                for(int i = 0; i < maxPeople; i++){
                    if(ages[i] >= max){
                        max = ages[i];
                        max_num = i;
                    }
                }

                //max의 값과 같은 나이를 가진 모든 사람을 출력하여 중복된 값도 출력하게 만들었습니다.
                for(int i = 0; i < maxPeople; i++){
                    if(ages[i] == max){
                        cout << names[i] << "(" << ages[i] << ")" << endl;
                        max_check = false;
                    }
                }

                /*
                if(max_check){
                    cout << names[max_num] << "(" << ages[max_num] << ")" << endl;
                }
                */


                break;
            case 2:
                cout << "나이가 가장 적은 사람" << endl;
                
                //min에 최소값을 담아놓습니다.
                for(int i = 0; i < maxPeople; i++){
                    if(ages[i] <= min){
                        min = ages[i];
                        min_num = i;
                    }
                }

                //min의 값과 같은 나이를 가진 모든 사람을 출력하여 중복된 값도 출력하게 만들었습니다.
                for(int i = 0; i < maxPeople; i++){
                    if (ages[i] == min){
                        cout << names[i] << "(" << ages[i] << ")" << endl;
                        min_check = false;
                    }
                }

                /*
                if(min_check){
                    cout << names[min_num] << "(" << ages[min_num] << ")" << endl;
                }
                */
                break;
            case 3:
            //모든 사람들과 나이를 출력합니다.
                for(int i = 0; i < maxPeople; i++){
                    cout << names[i] << "(" << ages[i] << ")" << endl;
                }
                break;
            default:
                cout << "종료합니다" << endl;
                break;
        }
        cout << endl;
    }
    
    
    return 0;
}