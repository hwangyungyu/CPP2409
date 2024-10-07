#include <iostream>
using namespace std;

//전역변수로 설정
const int NUM_USERS = 3;
const int NUM_ITEMS = 3;
int userPreferences[NUM_USERS][NUM_ITEMS];

//함수 호출 시 필요한 함수명, 매개변수, 반환형을 포함한 표현식
void initializePreferences(int preferences[NUM_USERS][NUM_ITEMS]);
void findRecommendedItems(const int preferences[NUM_USERS][NUM_ITEMS]);

int main(){
    //initializePreferences함수를 userPreferences배열을 넣어 호출합니다.
    initializePreferences(userPreferences);
    //findRecommendedItems함수를 userPreferences배열을 넣어 호출합니다.
    findRecommendedItems(userPreferences);

    return 0;
}

//호출자를 밑에 있음
void initializePreferences(int preferences[NUM_USERS][NUM_ITEMS]){
    for(int i = 0; i < NUM_USERS; i++){
        cout << "사용자" << (i+1) << "의 선호도를 입력하세요 (";
        cout << NUM_ITEMS << "개의 항목에 대해): ";
        for(int j = 0; j < NUM_ITEMS; j++){
            cin >> userPreferences[i][j];
        }
    }
}

void findRecommendedItems(const int preferences[NUM_USERS][NUM_ITEMS]){
    for(int i = 0; i < NUM_USERS; ++i){
        int maxPreferenceindex = 0;
        for(int j = 1; j < NUM_ITEMS; ++j){
            if(userPreferences[i][j] > userPreferences[i][maxPreferenceindex]){
                maxPreferenceindex = j;
            }
        }

        cout << "사용자 " << (i+1) << "에게 추천하는 항목: ";
        cout << (maxPreferenceindex+1) << endl;
    }
}