#include <iostream>
using namespace std;

//board를 전하고 싶었지만 전하지 못해서 전역변수로 선언하여 해결함. 
//함수로 2차원 배열을 전하는 법을 알아야 할 듯함

const int numCell = 5; // 보드판의 가로 세로 길이
char board[numCell][numCell]{}; // 보드판을 나타내는 2차원 배열

// is vaild 함수는 전역변수가 아니여도 해결이 가능하도록 해결함
bool isValid(int x, int y, int numCell, char board){
   if (x >= numCell || y >= numCell) {// 좌표 범위를 벗어날때
      cout << x << "," << y << ": x와 y둘중 하나가 칸을 벗어납니다. " << endl;
      return false;
   }
   if (board != ' ') {// 좌표범위의 입력값이 중복될때
      cout << x << "," << y << ": 이미 돌이 차있습니다. " << endl;
      return false;
   }
   return true;
}

bool checkWin(char currentUser){
   // 6.1. 가로/세로 돌 체크하기

   //가로 세로를 고려하지 않고 제출하였음으로 수정
      for (int i = 0; i < numCell; i++) {
         bool rowWin = true;
         bool colWin = true;
         for (int j = 0; j < numCell; j++) {
            if (board[i][j] != currentUser) rowWin = false;
            if (board[j][i] != currentUser) colWin = false;
         }
         if (rowWin || colWin) {
            cout << (rowWin ? "가로" : "세로") << "에 모두 돌이 놓였습니다!" << endl;
            return true;
         }
      }


      // 6.2. 대각선을 체크하기
      // TODO 1.3: numCell에 맞춘 대각선 빙고 체크 코드로 확장
      // HINT: for 문
      // 대각선을 체크하는 과정에서 check_side1,2 변수와 numCell과 비교하였어야 하는데 
      // 그 자리에 숫자 5를 대입하였음으로 수정
      int check_side1 = 0;
      int check_side2 = 0;

      for(int i = 0; i < numCell; i++){
         if (board[i][i] == currentUser) {
            check_side1 += 1;   
         }

         if (board[i][numCell-(i+1)] == currentUser) {
            check_side2 += 1;   
         }
      }
      
      if(check_side1 == numCell){
         cout << "왼쪽 위에서 오른쪽 아래 대각선으로 모두 돌이 놓였습니다!" << endl;
         return true;
      }

      if(check_side2 == numCell){
         cout << "오른쪽 위에서 왼쪽 아래 대각선으로 모두 돌이 놓였습니다!" << endl;
         return true;
      }
   return false;
}

int main() {
   // 게임을 진행하는 데 필요한 변수 선언

   int k = 0; // 누구 차례인지 체크하기 위한 변수
   char currentUser = 'X'; // 현재 유저의 돌을 저장하기 위한 변수

   int x, y = 0; // 사용자에게 xy좌표값을 입력받기 위한 변수

   // 보드판 초기화
   for (int i = 0; i < numCell; i++) {
      for (int j = 0; j < numCell; j++) {
         board[i][j] = ' ';
      }
   }

   // 게임을 무한 반복
   while (true) {
      // 1. 누구 차례인지 출력
      // TODO 1.1: 3인용 게임으로 변경
      switch (k % 3) {
      case 0:
         currentUser = 'X';
         break;
      case 1:         
         currentUser = 'O';
         break;
        // 3의 플레이어
        case 2:         
         currentUser = 'H';
         break;
      }
      cout << k % 3 + 1 << "번 유저("<< currentUser <<")의 차례입니다. -> ";

      // 2. 좌표 입력 받기
      cout << "(x, y) 좌표를 입력하세요: ";
      int x, y;
      cin >> x >> y;

      // 3. 입력받은 좌표의 유효성 체크
      // TODO FUNC 1: isValid 함수 생성 후 호출
      
      bool check = isValid(x, y, numCell, board[x][y]);
      //만약 false가 온다면 유효성 체크 실패임으로 continue를 실행
      if(!check){
         continue;
      }
      
      // 4. 입력받은 좌표에 현재 유저의 돌 놓기
      board[x][y] = currentUser;

      // 5. 현재 보드 판 출력
      // TODO 1.2: numCell 숫자에 맞춘 보드판 출력
       for (int i = 0; i < numCell; i++) {
         if(i == numCell - 1){
            cout << "---";
         }
         else{
            cout << "---|";
         }
      }
      cout << endl;

      for (int i = 0; i < numCell; i++) {
         for (int j = 0; j < numCell; j++)
         {
            cout << board[i][j];
            if (j == numCell - 1) {
               break;
            }
            cout << "  |";
         }
         cout << endl;

         for (int k = 0; k < numCell; k++) {
            if(k == numCell - 1){
               cout << "---"<< endl;
            }
            else{
               cout << "---|" ;
            }
         }
      }


      bool isWin = false; // 승리 여부
      // TODO FUNC2: 6.1부터 6.2까지 checkWin 함수 생성 후 호출

      isWin = checkWin(currentUser);

      // 승리자가 결정되었으면 해당 플레이어를 출력하고 게임을 종료한다.
      if (isWin == true) {
         // 승자에서 숫자를 바꾸지 않았음으로 수정
         cout << k % 3 + 1<< "번 유저(" << currentUser << ")의 승리입니다!" << endl;
         break;
      }

      // 7. 모든 칸 다 찼는지 체크하기
      int checked = 0;
      for (int i = 0; i < numCell; i++) {
         for (int j = 0; j < numCell; j++) {
            if (board[i][j] == ' ') {
               checked++;
            }
         }
      }
      if (checked == 0) {
         cout << "모든 칸이 다 찼습니다.  종료합니다. " << endl;
         break;
      }

      k++;
   }

   return 0;
}