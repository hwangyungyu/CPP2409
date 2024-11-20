#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name; // 기본적으로private이나 자식 클래스가 사용 가능하도록 protected로 전환
    string address;
};
class Student : Person {
public:
    void SetAddress(string add) {
        address = add;
    }
    string GetAddress() {
        return address;
    }
    void SetName(string name){ this->name = name; } // name변수를 protected로 수정하여 사용가능
    //이름을 리턴
    string GetName() {
        return name;
    }
};

int main() {
    Student obj;
    obj.SetName("미수") ; // 에러
    obj.SetAddress("서울시 종로구 1번지");
    cout << obj.GetAddress() << endl;
    // 이름을 출력
    cout << obj.GetName() << endl;
    return 0;
}