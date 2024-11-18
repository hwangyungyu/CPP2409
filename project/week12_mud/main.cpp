#include "user.h"

const int mapX = 5;
const int mapY = 5;

bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(vector<vector<int>> map, int user_x, int user_y);
bool checkGoal(vector<vector<int>> map, int user_x, int user_y);
void checkItem(vector<vector<int>> map, int user_x, int user_y, User &HP);
void movePlayer(vector<vector<int>> map, int &user_x, int &user_y, int dx, int dy, int mapX, int mapY, User &HP);
bool CheckUser(User &user);


// 메인  함수
int main() {
	// 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
	/*
		int map[mapY][mapX] = { {0, 1, 2, 0, 4},
					{1, 0, 0, 2, 0},
					{0, 0, 0, 0, 0},
					{0, 2, 3, 0, 0},
					{3, 0, 0, 0, 2}};
	*/
	vector<vector<int>> map;

	map.push_back({0, 1, 2, 0, 4}); 
	map.push_back({1, 0, 0, 2, 0}); 
	map.push_back({0, 0, 0, 0, 0}); 
	map.push_back({0, 2, 3, 0, 0}); 
	map.push_back({3, 0, 0, 0, 2}); 

	// 유저의 hp를 초기에 20으로 설정함			
	User user;


	// 유저의 위치를 저장할 변수
	int user_x = 0; // 가로 번호
	int user_y = 0; // 세로 번호

	// 게임 시작 
	while (1) { // 사용자에게 계속 입력받기 위해 무한 루프


		if(!CheckUser(user)){
			cout << "실패" << endl; 
			break;
		} 
		
		// 사용자의 입력을 저장할 변수
		string user_input = "";
		
		// 플레이어의 체력을 출력함 
		cout << "현재 HP: " << user.GetHP() << "  "; 
		cout << "명령어를 입력하세요 (up,down,left,right,map,info,exit): ";
		cin >> user_input;

		if (user_input == "up") {
		    movePlayer(map, user_x, user_y, 0, -1, mapX, mapY, user);  // 위로 이동
		}
		else if (user_input == "down") {
		    movePlayer(map, user_x, user_y, 0, 1, mapX, mapY, user);    // 아래로 이동
		}
		else if (user_input == "left") {
		    movePlayer(map, user_x, user_y, -1, 0, mapX, mapY, user);   // 왼쪽으로 이동
		}
		else if (user_input == "right") {
		    movePlayer(map, user_x, user_y, 1, 0, mapX, mapY, user);    // 오른쪽으로 이동
		}
		else if (user_input == "map") {
			// TODO: 지도 보여주기 함수 호출
			displayMap(map, user_x, user_y);
		}
		else if (user_input == "info") {
			// 정보 명령어 추가 및 출력
			cout << user << endl;
			continue;
		}
		else if (user_input == "exit") {
			cout << "종료합니다.";
			break;
		}
		else {
			cout << "잘못된 입력입니다." << endl;
			continue;
		}
		 
		//이벤트에 따른 hp증감을 checkItem함수를 통해 받습니다. 
		checkItem(map, user_x, user_y, user);

		// 목적지에 도달했는지 체크
		bool finish = checkGoal(map, user_x, user_y);
		if (finish == true) {
			cout << "목적지에 도착했습니다! 축하합니다!" << endl;
			cout << "게임을 종료합니다." << endl;
			break;
		}
	}
	return 0;
}


// 지도와 사용자 위치 출력하는 함수
void displayMap(vector<vector<int>> map, int user_x, int user_y) {
	for (int i = 0; i < mapY; i++) {
		for (int j = 0; j < mapX; j++) {
			if (i == user_y && j == user_x) {
				cout << " USER |"; // 양 옆 1칸 공백
			}
			else {
				int posState = map[i][j];
				switch (posState) {
				case 0:
					cout << "      |"; // 6칸 공백
					break;
				case 1:
					cout << "아이템|";
					break;
				case 2:
					cout << "  적  |"; // 양 옆 2칸 공백
					break;
				case 3:
					cout << " 포션 |"; // 양 옆 1칸 공백
					break;
				case 4:
					cout << "목적지|";
					break;
				}
			}
		}
		cout << endl;
		cout << " -------------------------------- " << endl;
	}
}

// 이동하려는 곳이 유효한 좌표인지 체크하는 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY) {
	bool checkFlag = false;
	if (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY) {
		checkFlag = true;
	}
	return checkFlag;
}

// 유저의 위치가 목적지인지 체크하는 함수
bool checkGoal(vector<vector<int>> map, int user_x, int user_y) {
	// 목적지 도착하면
	if (map[user_y][user_x] == 4) {
		return true;
	}
	return false;
}

// 유저의 위치에 각종 이벤트를 확인하는 함수 
void checkItem(vector<vector<int>> map, int user_x, int user_y, User &HP){
	// 이벤트를 담는 변수 
	int item = map[user_y][user_x];
	
	// 각종 이벤트에 따라 작동 
	if (item == 1) {
		cout << "아이템이 있습니다." << endl; 
		HP.IncreseItemCnt(1);
	}
	else if(item == 2){
		cout << "적이 있습니다." << endl; 
		cout << "HP가 2 줄어듭니다." << endl;
		//적을 만날 시에 -2를 리턴 시켜 hp를 감소시킵니다. 
		HP.DecreaseHP(2);
	}
	else if(item == 3){
		cout << "포션이 있습니다." << endl; 
		cout << "HP가 2 증가합니다" << endl;
		//포션을 만날 시에 2를 리턴 시켜 hp를 증가시킵니다. 
		HP.IncreaseHP(2);
	}
}

// 유저를 이동시키고, 그 결과를 출력하는 함수 
void movePlayer(vector<vector<int>> map, int &user_x, int &user_y, int dx, int dy, int mapX, int mapY, User &HP) {
    // 유저를gk 이동시킵니다. 

    user_x += dx;
    user_y += dy;
    
    bool inMap = checkXY(user_x, mapX, user_y, mapY);
    if (!inMap) {
        cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
        user_x -= dx;
        user_y -= dy;
    } else {
        // 방향에 따라 메시지를 출력합니다. 
        if (dx == -1) cout << "왼쪽으로 이동합니다." << endl;
        else if (dx == 1) cout << "오른쪽으로 이동합니다." << endl;
        else if (dy == -1) cout << "위로 한 칸 올라갑니다." << endl;
        else if (dy == 1) cout << "아래로 한 칸 내려갑니다." << endl;
		
        HP.DecreaseHP(1);
        // 맵을 보여줍니다. 
        displayMap(map, user_x, user_y);
    }
}

bool CheckUser(User &user){
    if(user.GetHP() <= 0){
        return false;
    }
    return true;
}