#include <iostream>
#include <string>
using namespace std;

int main(){
    // char 타입의 경우에는 작은 따옴표로 작성
    // char ch = "1";
    char ch = '1';
    string s1 = "Good";
    string s2 = "Morning";
    string s3 = s1 + " " + s2 + "!";
    //다른 타입의 경우에는 에러가 발생
    //string s4 = s1 + 10 + s2 + "!";

    cout << s3 << endl;
    return 0;
}

