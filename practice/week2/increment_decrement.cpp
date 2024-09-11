#include <iostream>

using namespace std;

int main(){
    int x = 1;

    cout << "X = " << x++ << endl;
    cout << "X = " << x++ << endl;
    cout << "X = " << ++x << endl;
    cout << "X = " << x-- << endl;
    cout << "X = " << x-- << endl;
    cout << "X = " << --x << endl;
    
    return 0;
}