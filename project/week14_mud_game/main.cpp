#include "user.h"

using namespace std;

const int mapX = 5;
const int mapY = 5;

int map[mapY][mapX];

bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap( int user_x, int user_y, int check_user);
bool checkGoal( int user_x, int user_y);
void checkItem( int user_x, int user_y, User *HP);
void movePlayer( int &user_x, int &user_y, int dx, int dy, int mapX, int mapY, User *HP, int check_user);
bool CheckUser(User *user);

User* user;

// 메인  함수
int main() {
	ifstream is{ "map.txt" };
	if(!is){
		cerr << "파일 오픈에 실패하였습니다." << endl;
		exit(1);
	}

	int map_input;
	int i = 0, j = 0;

	// while문을 통해 하나씩 받아옵니다.
	while(is >> map_input){
		map[i][j] = map_input;
		j++;
		// j가 mapY보다 커지면 다시 0으로 되돌립니다.
		if(j == mapY){
			j = 0;
			i++;
		}
	}

	// 유저의 hp를 초기에 20으로 설정함			
	Warrior warrior;
	Magician magician;

	// 유저의 위치를 저장할 변수
	int user_x = 0; // 가로 번호
	int user_y = 0; // 세로 번호

	int check_user = 0;
	//1202예외 추가
	while(true){
		// 예외 처리를 통해 직업의 선택의 예외를 고려합니다.
		try{
			cout << "직업을 선택해주세요. " << endl;
			cout << "1. warrior" << endl;
			cout << "2. magician" << endl;
			cout << ">> ";
			cin >> check_user;

			if(check_user < 0 || check_user > 2){
				throw check_user;
			}
		}
		catch(int e){
			cout << "올바르지 않은 선택입니다." << endl;
		}

		if(check_user == 1 || check_user == 2){
			break;
		}
	}
	
	// 게임 시작 
	while (1) { // 사용자에게 계속 입력받기 위해 무한 루프
		if (check_user == 1) {
			user = new Warrior();
		} else if(check_user == 2) {
			user = new Magician();
		}

		if(!CheckUser(user)){
			if(check_user == 1){
				cout << "warrior 실패" << endl; 
			}
			else{
				cout << "magician 실패" << endl; 
			} 
			break;
		} 
		
		// 사용자의 입력을 저장할 변수
		string user_input = "";
		
		
		// 플레이어의 체력을 출력함 
		cout << "현재 HP: " << user->GetHP() << "  "; 
		cout << "명령어를 입력하세요 (up,down,left,right,map,attack,info,exit): ";
		cin >> user_input;

		if (user_input == "up") {
		    movePlayer( user_x, user_y, 0, -1, mapX, mapY, user, check_user);  // 위로 이동
		}
		else if (user_input == "down") {
		    movePlayer( user_x, user_y, 0, 1,  mapX, mapY, user, check_user);    // 아래로 이동
		}
		else if (user_input == "left") {
		    movePlayer( user_x, user_y, -1, 0,  mapX, mapY, user, check_user);   // 왼쪽으로 이동
		}
		else if (user_input == "right") {
		    movePlayer( user_x, user_y, 1, 0,  mapX, mapY, user, check_user);    // 오른쪽으로 이동
		}
		else if (user_input == "map") {
			// TODO: 지도 보여주기 함수 호출
			displayMap( user_x, user_y, check_user);
		}
		else if (user_input == "attack") {
			user->DoAttack();
		}
		else if (user_input == "info") {
			// 정보 명령어 추가 및 출력
			cout << *user << endl;
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
		checkItem( user_x, user_y, user);
		
		// 목적지에 도달했는지 체크
		bool finish = checkGoal( user_x, user_y);
		if (finish == true) {
			if(check_user == 1){
				cout << "warrior가 목적지에 도착했습니다! 축하합니다!" << endl;
			}
			else{
				cout << "magician이 목적지에 도착했습니다! 축하합니다!" << endl;
			}
			
			cout << "게임을 종료합니다." << endl;
			break;
		}
	
	}
	return 0;
}


// 지도와 사용자 위치 출력하는 함수
void displayMap( int user_x, int user_y, int check_user) {
	for (int i = 0; i < mapY; i++) {
		for (int j = 0; j < mapX; j++) {
			if (i == user_y && j == user_x && check_user == 1) {
				cout << "  W   |"; // 양 옆 1칸 공백
			}
			else if (i == user_y && j == user_x && check_user == 2) {
				cout << "  M   |"; // 양 옆 1칸 공백
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
bool checkGoal( int user_x, int user_y) {
	// 목적지 도착하면
	if (map[user_y][user_x] == 4) {
		return true;
	}
	return false;
}

// 유저의 위치에 각종 이벤트를 확인하는 함수 
void checkItem( int user_x, int user_y, User *HP){
	// 이벤트를 담는 변수 
	int item = map[user_y][user_x];
	
	// 각종 이벤트에 따라 작동 
	if (item == 1) {
		cout << "아이템이 있습니다." << endl; 
		HP->IncreseItemCnt(1);
	}
	else if(item == 2){
		cout << "적이 있습니다." << endl; 
		cout << "HP가 2 줄어듭니다." << endl;
		//적을 만날 시에 -2를 리턴 시켜 hp를 감소시킵니다. 
		HP->DecreaseHP(2);
		HP->DoAttack();
	}
	else if(item == 3){
		cout << "포션이 있습니다." << endl; 
		cout << "HP가 2 증가합니다" << endl;
		//포션을 만날 시에 2를 리턴 시켜 hp를 증가시킵니다. 
		HP->IncreaseHP(2);
	}
}

// 유저를 이동시키고, 그 결과를 출력하는 함수 
void movePlayer( int &user_x, int &user_y, int dx, int dy, int mapX, int mapY, User *HP, int check_user) {
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
		
        HP->DecreaseHP(1);
        // 맵을 보여줍니다. 
        displayMap( user_x, user_y, check_user);
    }
}

bool CheckUser(User *user){
    if(user->GetHP() <= 0){
        return false;
    }
    return true;
}