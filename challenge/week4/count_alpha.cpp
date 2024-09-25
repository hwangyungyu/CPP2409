#include <iostream>
using namespace std;

int main(){
    int vowel = 0;
    int consonant = 0;

    cout << "영문자를 입력하고 ctrl+z를 치세요" << endl;

    char ch;

    while(cin >> ch){
        // 소문자 a부터 z의 값이 들어올 때만 switch문이 작동
        if(ch >= 'a' && ch <= 'z'){
            //모음이 들어오면 vowel++
            switch(ch){
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    vowel++;
                    break;
                default:
                    consonant++;
                    break; 
            }
        }
        else{
            // 소문자 a부터 z의 값이 아닐 시 경고문
            cout << "영소문자만 작성해주세요." << endl;
        }
        
    }

    cout << "모음: " << vowel << endl;
    cout << "자음: " << consonant << endl;
    return 0;
}