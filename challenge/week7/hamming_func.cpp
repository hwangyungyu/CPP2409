#include <iostream>
#include <string>
using namespace std;

// 문자열을 소문자로 바꿈
string toLowerStr(string str){
    for(int i = 0; i < str.length(); i++){
        //대문자에 속하는지 체크
        if(str[i] >= 'A' && str[i] <= 'Z'){
            //대문자에 속한다면 32를 더하여 소문자 아스키 코드로 변환
            str[i] += 32;
        }
    }

    return str;
}

//문자열을 대문자로 변환
string toUpperStr(string str){
    //소문자에 속하는지 체크
    for(int i = 0; i < str.length(); i++){
         //소문자에 속한다면 32를 빼어 대문자 아스키 코드로 변환
        if(str[i] >= 'a' && str[i] <= 'z'){
            str[i] -= 32;
        }
    }

    return str;
}

// 해밍 거리 구하기
int calcHammingDist(string s1, string s2){
    // 문자를 둘다 소문자로 변환
    string a1 = toLowerStr(s1);
    string a2 = toLowerStr(s2);

    int cnt = 0;

    for(int i = 0; i < a1.length(); i++){
        //서로 문자가 다르다면 해밍거리를 더함
        if(a1[i] != a2[i]){
            cnt+=1;
        }
    }

    return cnt;
}

int main(){
    string s1, s2;
    // 해밍거리
    int count = 100;
    bool check = true;

    // 문자열의 길이가 같다면 반복문을 탈출
    // 문자열의 길이가 다르다면 입력할 때까지 반복
    while(check){
        // 두 문자열을 입력
        cout << "DNA1: ";
        cin >> s1;
        cout << "DNA2: ";
        cin >> s2;

        if (s1.length() != s2.length()){
            // 길이가 다르다면 다시한번 더 받도록 check를 false로 둔다.
            check = true;
            cout << "오류: 길이가 다름" << endl;
        }
        else{
            // 함수에 보내어 해밍거리를 받아옴
            count = calcHammingDist(s1, s2);
            cout << "해밍 거리는 " << count << endl;
            // 해밍거리를 출력했으면 탈출
            check = false;
        }
    }
    
    return 0;
}