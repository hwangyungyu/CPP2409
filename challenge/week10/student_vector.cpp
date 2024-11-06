#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v;
    int grade;

    while(true){
        cout << "성적을 입력하시오(종료는 -1) : ";
        cin >> grade;
        // 음수 값이면 다시 입력받고 -1일시에 종료합니다.
        if(grade < -1){
            cout << "다시 입력해주세요." << endl;
            continue;
        }
        else if(grade == -1){
            break;
        }
        v.push_back(grade);
    }

    int sum = 0;
    int len = 0;
    // 값을 입력받고 전부 더해줍니다.
    while(v.empty()!=true){
        sum += v.back();
        v.pop_back();
        len++;
    }

    cout << "성적 평균" << sum/len << endl; 
}