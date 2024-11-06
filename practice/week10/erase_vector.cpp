#include <iostream>
#include <vector>
using namespace std;

int main(void){
    vector<int> v;
    for(int i = 0; i< 10; ++i){
        v.push_back(i);
    }

    cout << "현재의 v=";
    for(auto& e:v)
        cout << e << " ";
    cout << endl;
    
    v.erase(v.begin()+5);

    cout << "5번 인덱스를 제거한 후 v= ";
    //벡터가 공백이 될 때까지 pop_back()호출
    for(auto& e: v){
        cout << e << " ";
    }
    cout << endl;
    return 0;
}