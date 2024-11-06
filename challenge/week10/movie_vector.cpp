#include <iostream>
#include <vector>
using namespace std;

class Movie{
public:
    string name;
    float price;
    Movie(){name = ""; price = 0; }
    Movie(string name, float price){this -> name = name; this->price = price;}
    void Print(){
        cout  << name << " " << price << endl;
    }
};

int main(void){
    // Movie vector를 생성합니다.
    vector<Movie> objArray;
    
    // 각 객체에 값을 입력받습니다.
    objArray.push_back(Movie("titinic", 9.9));
    objArray.push_back(Movie("gone with the wind", 9.6));
    objArray.push_back(Movie("terminator", 9.7));

    // 끝까지 출력합니다.
    for(auto&e : objArray){
        e.Print();
    }

    return 0;
}