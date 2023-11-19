#include "user.h"
#include <iostream>
#include <string>
using namespace std;

const int mapX = 5;
const int mapY = 5;
User my_user;

// 사용자 정의 함수
void printWrongMsg();
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(int map[][mapX], int user_x, int user_y);
bool checkGoal(int map[][mapX], int user_x, int user_y);
void checkState(int map[][mapX], int user_x, int user_y, int userHP);
void printEnemy(int map[][mapX], int user_x, int user_y);
bool checkEnemy(int map[][mapX], int user_x, int user_y);
void printItem(int map[][mapX], int user_x, int user_y);
bool checkItem(int map[][mapX], int user_x, int user_y);
void printPoshion(int map[][mapX], int user_x, int user_y);
bool checkPoshion(int map[][mapX], int user_x, int user_y);


// 메인  함수
int main() {
	my_user = User();
	// 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
	int map[mapY][mapX] = { {0, 1, 2, 0, 4},
					{1, 0, 0, 2, 0},
					{0, 0, 0, 0, 0},
					{0, 2, 3, 0, 0},
					{3, 0, 0, 0, 2} };


	// 유저의 위치를 저장할 변수
	int user_x = 0; // 가로 번호
	int user_y = 0; // 세로 번호

	// 게임 시작 
	while (1) { // 사용자에게 계속 입력받기 위해 무한 루프

		// 사용자의 입력을 저장할 변수
		string user_input = "";

		cout << "현재 HP : " << my_user.GetHP() << " 명령어를 입력하세요 (상,하,좌,우,지도,종료): ";
		cin >> user_input;

		if (user_input == "상") {
			// 위로 한 칸 올라가기
			user_y -= 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			if (inMap == false) {
				printWrongMsg();
				user_y += 1;
			}
			else {
				cout << "위로 한 칸 올라갑니다." << endl;
				displayMap(map, user_x, user_y);
				my_user.MoveDecreaseHP(my_user.GetHP());			// 이동할 때 HP 1씩 감소
			}
		}
		else if (user_input == "하") {
			// TODO: 아래로 한 칸 내려가기
			user_y += 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			if (inMap == false) {
				printWrongMsg();
				user_y -= 1;
			}
			else {
				cout << "아래로 한 칸 내려갑니다." << endl;
				displayMap(map, user_x, user_y);
				my_user.MoveDecreaseHP(my_user.GetHP());			// 이동할 때 HP 1씩 감소
			}
		}
		else if (user_input == "좌") {
			// TODO: 왼쪽으로 이동하기
			user_x -= 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);

			if (inMap == false) {
				printWrongMsg();
				user_x += 1;
			}
			else {
				cout << "왼쪽으로 이동합니다." << endl;
				displayMap(map, user_x, user_y);
				my_user.MoveDecreaseHP(my_user.GetHP());			// 이동할 때 HP 1씩 감소
			}
		}
		else if (user_input == "우") {
			// TODO: 오른쪽으로 이동하기
			user_x += 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			if (inMap == false) {
				printWrongMsg();
				user_x -= 1;
			}
			else {
				cout << "오른쪽으로 이동합니다." << endl;
				displayMap(map, user_x, user_y);
				my_user.MoveDecreaseHP(my_user.GetHP());			// 이동할 때 HP 1씩 감소
			}
		}
		else if (user_input == "지도") {
			// TODO: 지도 보여주기 함수 호출
			displayMap(map, user_x, user_y);
		}
		else if (user_input == "종료") {
			cout << "종료합니다.";
			break;
		}
		else {
			cout << "잘못된 입력입니다." << endl;
			continue;
		}

		// 유저의 상태를 확인하기 위해 상태 체크 함수를 호출
		checkState(map, user_x, user_y, my_user.GetHP());

		// 목적지에 도달했는지 체크
		bool finish = checkGoal(map, user_x, user_y);
		if (finish == true) {
			cout << "목적지에 도착했습니다! 축하합니다!" << endl;
			cout << "게임을 종료합니다." << endl;
			break;
		}

		if (!my_user.CheckUser(my_user)) {
			cout << "HP가 0 이하가 되었습니다. 실패했습니다." << endl;
			cout << "게임을 종료합니다." << endl;
			break;
		}
	}
	return 0;
}


// 지도와 사용자 위치 출력하는 함수
void displayMap(int map[][mapX], int user_x, int user_y) {
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

// 클린 코드를 위한 게임에 벗어났을 때 출력 함수
void printWrongMsg() {
	cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
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
bool checkGoal(int map[][mapX], int user_x, int user_y) {
	// 목적지 도착하면
	if (map[user_y][user_x] == 4) {
		return true;
	}
	return false;
}

// 상태 확인하는 함수
void checkState(int map[][mapX], int user_x, int user_y, int userHP) {
	// 적을 만났는지 확인
	if (checkEnemy(map, user_x, user_y)) {
		my_user.DecreaseHP(userHP);
		printEnemy(map, user_x, user_y);
	}
	// 아이템을 만났는지 확인
	if (checkItem(map, user_x, user_y)) {
		printItem(map, user_x, user_y);
	}
	// 포션을 만났는지 확인
	if (checkPoshion(map, user_x, user_y)) {
		my_user.IncreaseHP(userHP);
		printPoshion(map, user_x, user_y);
	}
}

// 적을 만났을 경우 출력하는 함수
void printEnemy(int map[][mapX], int user_x, int user_y) {
	cout << "적을 만났습니다. HP 2 줄어듭니다. " << endl;
}

// 적을 만났는지 확인하는 함수
bool checkEnemy(int map[][mapX], int user_x, int user_y) {
	if (user_x == 2 && user_y == 0) {
		return true;
	}
	if (user_x == 0 && user_y == 1) {
		return true;
	}
	if (user_x == 3 && user_y == 1) {
		return true;
	}
	if (user_x == 4 && user_y == 4) {
		return true;
	}
	return false;
}

// 아이템을 만났을 경우 출력하는 함수
void printItem(int map[][mapX], int user_x, int user_y) {
	cout << "아이템을 만났습니다." << endl;
}

// 아이템을 만났는지 확인하는 함수
bool checkItem(int map[][mapX], int user_x, int user_y) {
	if (user_x == 1 && user_y == 0) {
		return true;
	}

	if (user_x == 0 && user_y == 1) {
		return true;
	}
	return false;
}

// 포션을 만났을 경우 출력하는 함수
void printPoshion(int map[][mapX], int user_x, int user_y) {
	cout << "포션을 만났습니다. HP 2 늘어났습니다. " << endl;
}

// 포션을 만났는지 확인하는 함수
bool checkPoshion(int map[][mapX], int user_x, int user_y) {
	if (user_x == 0 && user_y == 4) {
		return true;
	}

	if (user_x == 2 && user_y == 3) {
		return true;
	}

	return false;
}