#include "user.h"
#include <iostream>
#include <string>
using namespace std;

const int mapX = 5;
const int mapY = 5;
User my_user;

// ����� ���� �Լ�
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


// ����  �Լ�
int main() {
	my_user = User();
	// 0�� �� ����, 1�� ������, 2�� ��, 3�� ����, 4�� ������
	int map[mapY][mapX] = { {0, 1, 2, 0, 4},
					{1, 0, 0, 2, 0},
					{0, 0, 0, 0, 0},
					{0, 2, 3, 0, 0},
					{3, 0, 0, 0, 2} };


	// ������ ��ġ�� ������ ����
	int user_x = 0; // ���� ��ȣ
	int user_y = 0; // ���� ��ȣ

	// ���� ���� 
	while (1) { // ����ڿ��� ��� �Է¹ޱ� ���� ���� ����

		// ������� �Է��� ������ ����
		string user_input = "";

		cout << "���� HP : " << my_user.GetHP() << " ��ɾ �Է��ϼ��� (��,��,��,��,����,����): ";
		cin >> user_input;

		if (user_input == "��") {
			// ���� �� ĭ �ö󰡱�
			user_y -= 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			if (inMap == false) {
				printWrongMsg();
				user_y += 1;
			}
			else {
				cout << "���� �� ĭ �ö󰩴ϴ�." << endl;
				displayMap(map, user_x, user_y);
				my_user.MoveDecreaseHP(my_user.GetHP());			// �̵��� �� HP 1�� ����
			}
		}
		else if (user_input == "��") {
			// TODO: �Ʒ��� �� ĭ ��������
			user_y += 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			if (inMap == false) {
				printWrongMsg();
				user_y -= 1;
			}
			else {
				cout << "�Ʒ��� �� ĭ �������ϴ�." << endl;
				displayMap(map, user_x, user_y);
				my_user.MoveDecreaseHP(my_user.GetHP());			// �̵��� �� HP 1�� ����
			}
		}
		else if (user_input == "��") {
			// TODO: �������� �̵��ϱ�
			user_x -= 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);

			if (inMap == false) {
				printWrongMsg();
				user_x += 1;
			}
			else {
				cout << "�������� �̵��մϴ�." << endl;
				displayMap(map, user_x, user_y);
				my_user.MoveDecreaseHP(my_user.GetHP());			// �̵��� �� HP 1�� ����
			}
		}
		else if (user_input == "��") {
			// TODO: ���������� �̵��ϱ�
			user_x += 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			if (inMap == false) {
				printWrongMsg();
				user_x -= 1;
			}
			else {
				cout << "���������� �̵��մϴ�." << endl;
				displayMap(map, user_x, user_y);
				my_user.MoveDecreaseHP(my_user.GetHP());			// �̵��� �� HP 1�� ����
			}
		}
		else if (user_input == "����") {
			// TODO: ���� �����ֱ� �Լ� ȣ��
			displayMap(map, user_x, user_y);
		}
		else if (user_input == "����") {
			cout << "�����մϴ�.";
			break;
		}
		else {
			cout << "�߸��� �Է��Դϴ�." << endl;
			continue;
		}

		// ������ ���¸� Ȯ���ϱ� ���� ���� üũ �Լ��� ȣ��
		checkState(map, user_x, user_y, my_user.GetHP());

		// �������� �����ߴ��� üũ
		bool finish = checkGoal(map, user_x, user_y);
		if (finish == true) {
			cout << "�������� �����߽��ϴ�! �����մϴ�!" << endl;
			cout << "������ �����մϴ�." << endl;
			break;
		}

		if (!my_user.CheckUser(my_user)) {
			cout << "HP�� 0 ���ϰ� �Ǿ����ϴ�. �����߽��ϴ�." << endl;
			cout << "������ �����մϴ�." << endl;
			break;
		}
	}
	return 0;
}


// ������ ����� ��ġ ����ϴ� �Լ�
void displayMap(int map[][mapX], int user_x, int user_y) {
	for (int i = 0; i < mapY; i++) {
		for (int j = 0; j < mapX; j++) {
			if (i == user_y && j == user_x) {
				cout << " USER |"; // �� �� 1ĭ ����
			}
			else {
				int posState = map[i][j];
				switch (posState) {
				case 0:
					cout << "      |"; // 6ĭ ����
					break;
				case 1:
					cout << "������|";
					break;
				case 2:
					cout << "  ��  |"; // �� �� 2ĭ ����
					break;
				case 3:
					cout << " ���� |"; // �� �� 1ĭ ����
					break;
				case 4:
					cout << "������|";
					break;
				}
			}
		}
		cout << endl;
		cout << " -------------------------------- " << endl;
	}
}

// Ŭ�� �ڵ带 ���� ���ӿ� ����� �� ��� �Լ�
void printWrongMsg() {
	cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
}

// �̵��Ϸ��� ���� ��ȿ�� ��ǥ���� üũ�ϴ� �Լ�
bool checkXY(int user_x, int mapX, int user_y, int mapY) {
	bool checkFlag = false;
	if (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY) {
		checkFlag = true;
	}
	return checkFlag;
}

// ������ ��ġ�� ���������� üũ�ϴ� �Լ�
bool checkGoal(int map[][mapX], int user_x, int user_y) {
	// ������ �����ϸ�
	if (map[user_y][user_x] == 4) {
		return true;
	}
	return false;
}

// ���� Ȯ���ϴ� �Լ�
void checkState(int map[][mapX], int user_x, int user_y, int userHP) {
	// ���� �������� Ȯ��
	if (checkEnemy(map, user_x, user_y)) {
		my_user.DecreaseHP(userHP);
		printEnemy(map, user_x, user_y);
	}
	// �������� �������� Ȯ��
	if (checkItem(map, user_x, user_y)) {
		printItem(map, user_x, user_y);
	}
	// ������ �������� Ȯ��
	if (checkPoshion(map, user_x, user_y)) {
		my_user.IncreaseHP(userHP);
		printPoshion(map, user_x, user_y);
	}
}

// ���� ������ ��� ����ϴ� �Լ�
void printEnemy(int map[][mapX], int user_x, int user_y) {
	cout << "���� �������ϴ�. HP 2 �پ��ϴ�. " << endl;
}

// ���� �������� Ȯ���ϴ� �Լ�
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

// �������� ������ ��� ����ϴ� �Լ�
void printItem(int map[][mapX], int user_x, int user_y) {
	cout << "�������� �������ϴ�." << endl;
}

// �������� �������� Ȯ���ϴ� �Լ�
bool checkItem(int map[][mapX], int user_x, int user_y) {
	if (user_x == 1 && user_y == 0) {
		return true;
	}

	if (user_x == 0 && user_y == 1) {
		return true;
	}
	return false;
}

// ������ ������ ��� ����ϴ� �Լ�
void printPoshion(int map[][mapX], int user_x, int user_y) {
	cout << "������ �������ϴ�. HP 2 �þ���ϴ�. " << endl;
}

// ������ �������� Ȯ���ϴ� �Լ�
bool checkPoshion(int map[][mapX], int user_x, int user_y) {
	if (user_x == 0 && user_y == 4) {
		return true;
	}

	if (user_x == 2 && user_y == 3) {
		return true;
	}

	return false;
}