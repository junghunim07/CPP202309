#include "user.h"
#include "Magician.h"
#include "Warrior.h"
#include <iostream>
#include <string>
using namespace std;

const int mapX = 5;
const int mapY = 5;
Warrior warrior_user;
Magician magician_user;

// 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
int map[mapY][mapX] = { {0, 1, 2, 0, 4},
				{1, 0, 0, 2, 0},
				{0, 0, 0, 0, 0},
				{0, 2, 3, 0, 0},
				{3, 0, 0, 0, 2} };

// 사용자 정의 함수
void printWrongMsg();
bool checkXY(User* user);
void displayMap(Warrior* W, Magician* M);
bool CheckUser(User* user);
bool checkGoal(User* user);
void checkState(User* user);
void printEnemy(User* user);
bool checkEnemy(User* user);
void printItem();
bool checkItem(User* user);
void printPoshion();
bool checkPoshion(User* user);


// 메인  함수
int main() {
	warrior_user = Warrior();
	magician_user = Magician();

	warrior_user.setName("W");
	magician_user.setName("M");

	int k = 0;		// 누구 차례인지 체크하기 위한 변수
	User* current_user = &warrior_user;

	// 게임 시작 
	while (1) { // 사용자에게 계속 입력받기 위해 무한 루프

		// 누구 차례인지 확인
		switch (k % 2) {
		case 0:
			cout << "전사 유저의 차례입니다." << endl;
			current_user = &warrior_user;
			break;
		case 1:
			cout << "법사 유저의 차례입니다." << endl;
			current_user = &magician_user;
			break;
		}

		// 사용자의 입력을 저장할 변수
		string user_input = "";

		cout << "현재 HP : " << current_user->GetHP() << " 명령어를 입력하세요 (상,하,좌,우,지도,종료): ";
		cin >> user_input;

		if (user_input == "상") {
			// 위로 한 칸 올라가기
			current_user->moveUser(0, -1);
			bool inMap = checkXY(current_user);
			if (inMap == false) {
				printWrongMsg();
				current_user->moveUser(0, 1);
			}
			else {
				cout << "위로 한 칸 올라갑니다." << endl;
				displayMap(&warrior_user, &magician_user);
				current_user->MoveDecreaseHP(current_user->GetHP());			// 이동할 때 HP 1씩 감소
			}
		}
		else if (user_input == "하") {
			// TODO: 아래로 한 칸 내려가기
			current_user->moveUser(0, 1);
			bool inMap = checkXY(current_user);
			if (inMap == false) {
				printWrongMsg();
				current_user->moveUser(0, -1);
			}
			else {
				cout << "아래로 한 칸 내려갑니다." << endl;
				displayMap(&warrior_user, &magician_user);
				current_user->MoveDecreaseHP(current_user->GetHP());			// 이동할 때 HP 1씩 감소
			}
		}
		else if (user_input == "좌") {
			// TODO: 왼쪽으로 이동하기
			current_user->moveUser(-1, 0);
			bool inMap = checkXY(current_user);

			if (inMap == false) {
				printWrongMsg();
				current_user->moveUser(1, 0);
			}
			else {
				cout << "왼쪽으로 이동합니다." << endl;
				displayMap(&warrior_user, &magician_user);
				current_user->MoveDecreaseHP(current_user->GetHP());			// 이동할 때 HP 1씩 감소
			}
		}
		else if (user_input == "우") {
			// TODO: 오른쪽으로 이동하기
			current_user->moveUser(1, 0);
			bool inMap = checkXY(current_user);
			if (inMap == false) {
				printWrongMsg();
				current_user->moveUser(-1, 0);
			}
			else {
				cout << "오른쪽으로 이동합니다." << endl;
				displayMap(&warrior_user, &magician_user);
				current_user->MoveDecreaseHP(current_user->GetHP());			// 이동할 때 HP 1씩 감소
			}
		}
		else if (user_input == "지도") {
			// TODO: 지도 보여주기 함수 호출
			displayMap(&warrior_user, &magician_user);
			k--;
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
		checkState(current_user);

		// 목적지에 도달했는지 체크
		bool finish = checkGoal(current_user);
		if (finish == true) {
			cout << "목적지에 도착했습니다! 축하합니다!" << endl;
			cout << "게임을 종료합니다." << endl;
			break;
		}

		if (!CheckUser(current_user)) {
			cout << "HP가 0 이하가 되었습니다. 실패했습니다." << endl;
			cout << "게임을 종료합니다." << endl;
			break;
		}
		k++;
	}
	return 0;
}


// 지도와 사용자 위치 출력하는 함수
void displayMap(Warrior* W, Magician* M) {
	for (int i = 0; i < mapY; i++) {
		for (int j = 0; j < mapX; j++) {
			if (W->GetY() == M->GetY() && W->GetX() == M->GetX() 
				&& i == W->GetY() && j == W->GetX() 
				&& i == M->GetY() && j == M->GetX()) {
				cout << "  ";
				W->printName();
				M->printName();
				cout << "  |";
			}
			else if (i == W->GetY() && j == W->GetX()){
				cout << "   ";
				W->printName();
				cout << "  |";
			}
			else if (i == M->GetY() && j == M->GetX()) {
				cout << "   ";
				M->printName();
				cout << "  |";
			}
			/*if (i == W->GetY() && j == W->GetX() && i == M->GetY() && j == M->GetX()) {
				if (W->GetY() == M->GetY() && W->GetX() == M->GetX()) {
					cout << "  ";
					W->printName();
					M->printName();
					cout << "  |";
				}
				else if (i == W->GetY() && j == W->GetX()){
					cout << "   ";
					W->printName();
					cout << "  |";
				}
				else if (i == M->GetY() && j == M->GetX()) {
					cout << "   ";
					M->printName();
					cout << "  |";
				}
			}*/
			/*if (i == user->GetY() && j == user->GetX()) {
				user->printName();
				//cout << " USER |"; // 양 옆 1칸 공백
			}*/
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
		cout << "----------------------------------- " << endl;
	}
}

// 클린 코드를 위한 게임에 벗어났을 때 출력 함수
void printWrongMsg() {
	cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
}

// 이동하려는 곳이 유효한 좌표인지 체크하는 함수
bool checkXY(User* user) {
	bool checkFlag = false;
	if (user->GetX() >= 0 && user->GetX() < mapX && user->GetY() >= 0 && user->GetY() < mapY) {
		checkFlag = true;
	}
	return checkFlag;
}

bool CheckUser(User* user) {
	if (user->GetHP() <= 0) {
		return false;
	}
	return true;
}

// 유저의 위치가 목적지인지 체크하는 함수
bool checkGoal(User* user) {
	// 목적지 도착하면
	if (map[user->GetY()][user->GetX()] == 4) {
		return true;
	}
	return false;
}

// 상태 확인하는 함수
void checkState(User* user) {
	// 적을 만났는지 확인
	if (checkEnemy(user)) {
		user->DecreaseHP(user->GetHP());
		printEnemy(user);
	}
	// 아이템을 만났는지 확인
	if (checkItem(user)) {
		printItem();
	}
	// 포션을 만났는지 확인
	if (checkPoshion(user)) {
		user->IncreaseHP(user->GetHP());
		printPoshion();
	}
}

// 적을 만났을 경우 출력하는 함수
void printEnemy(User* user) {
	cout << "적을 만났습니다. HP 2 줄어듭니다. " << endl;
	if (user == &warrior_user) {
		warrior_user.doAttack();
	}
	if (user == &magician_user) {
		magician_user.doAttack();
	}
}

// 적을 만났는지 확인하는 함수
bool checkEnemy(User* user) {
	if (map[user->GetY()][user->GetX()] == 2) {
		return true;
	}
	return false;
}

// 아이템을 만났을 경우 출력하는 함수
void printItem() {
	cout << "아이템을 만났습니다." << endl;
}

// 아이템을 만났는지 확인하는 함수
bool checkItem(User* user) {
	if (map[user->GetY()][user->GetX()] == 1) {
		return true;
	}
	return false;
}

// 포션을 만났을 경우 출력하는 함수
void printPoshion() {
	cout << "포션을 만났습니다. HP 2 늘어났습니다. " << endl;
}

// 포션을 만났는지 확인하는 함수
bool checkPoshion(User* user) {
	if (map[user->GetY()][user->GetX()] == 3) {
		return true;
	}
	return false;
}