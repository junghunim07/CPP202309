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

// 0�� �� ����, 1�� ������, 2�� ��, 3�� ����, 4�� ������
int map[mapY][mapX] = { {0, 1, 2, 0, 4},
				{1, 0, 0, 2, 0},
				{0, 0, 0, 0, 0},
				{0, 2, 3, 0, 0},
				{3, 0, 0, 0, 2} };

// ����� ���� �Լ�
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


// ����  �Լ�
int main() {
	warrior_user = Warrior();
	magician_user = Magician();

	warrior_user.setName("W");
	magician_user.setName("M");

	int k = 0;		// ���� �������� üũ�ϱ� ���� ����
	User* current_user = &warrior_user;

	// ���� ���� 
	while (1) { // ����ڿ��� ��� �Է¹ޱ� ���� ���� ����

		// ���� �������� Ȯ��
		switch (k % 2) {
		case 0:
			cout << "���� ������ �����Դϴ�." << endl;
			current_user = &warrior_user;
			break;
		case 1:
			cout << "���� ������ �����Դϴ�." << endl;
			current_user = &magician_user;
			break;
		}

		// ������� �Է��� ������ ����
		string user_input = "";

		cout << "���� HP : " << current_user->GetHP() << " ��ɾ �Է��ϼ��� (��,��,��,��,����,����): ";
		cin >> user_input;

		if (user_input == "��") {
			// ���� �� ĭ �ö󰡱�
			current_user->moveUser(0, -1);
			bool inMap = checkXY(current_user);
			if (inMap == false) {
				printWrongMsg();
				current_user->moveUser(0, 1);
			}
			else {
				cout << "���� �� ĭ �ö󰩴ϴ�." << endl;
				displayMap(&warrior_user, &magician_user);
				current_user->MoveDecreaseHP(current_user->GetHP());			// �̵��� �� HP 1�� ����
			}
		}
		else if (user_input == "��") {
			// TODO: �Ʒ��� �� ĭ ��������
			current_user->moveUser(0, 1);
			bool inMap = checkXY(current_user);
			if (inMap == false) {
				printWrongMsg();
				current_user->moveUser(0, -1);
			}
			else {
				cout << "�Ʒ��� �� ĭ �������ϴ�." << endl;
				displayMap(&warrior_user, &magician_user);
				current_user->MoveDecreaseHP(current_user->GetHP());			// �̵��� �� HP 1�� ����
			}
		}
		else if (user_input == "��") {
			// TODO: �������� �̵��ϱ�
			current_user->moveUser(-1, 0);
			bool inMap = checkXY(current_user);

			if (inMap == false) {
				printWrongMsg();
				current_user->moveUser(1, 0);
			}
			else {
				cout << "�������� �̵��մϴ�." << endl;
				displayMap(&warrior_user, &magician_user);
				current_user->MoveDecreaseHP(current_user->GetHP());			// �̵��� �� HP 1�� ����
			}
		}
		else if (user_input == "��") {
			// TODO: ���������� �̵��ϱ�
			current_user->moveUser(1, 0);
			bool inMap = checkXY(current_user);
			if (inMap == false) {
				printWrongMsg();
				current_user->moveUser(-1, 0);
			}
			else {
				cout << "���������� �̵��մϴ�." << endl;
				displayMap(&warrior_user, &magician_user);
				current_user->MoveDecreaseHP(current_user->GetHP());			// �̵��� �� HP 1�� ����
			}
		}
		else if (user_input == "����") {
			// TODO: ���� �����ֱ� �Լ� ȣ��
			displayMap(&warrior_user, &magician_user);
			k--;
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
		checkState(current_user);

		// �������� �����ߴ��� üũ
		bool finish = checkGoal(current_user);
		if (finish == true) {
			cout << "�������� �����߽��ϴ�! �����մϴ�!" << endl;
			cout << "������ �����մϴ�." << endl;
			break;
		}

		if (!CheckUser(current_user)) {
			cout << "HP�� 0 ���ϰ� �Ǿ����ϴ�. �����߽��ϴ�." << endl;
			cout << "������ �����մϴ�." << endl;
			break;
		}
		k++;
	}
	return 0;
}


// ������ ����� ��ġ ����ϴ� �Լ�
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
				//cout << " USER |"; // �� �� 1ĭ ����
			}*/
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
		cout << "----------------------------------- " << endl;
	}
}

// Ŭ�� �ڵ带 ���� ���ӿ� ����� �� ��� �Լ�
void printWrongMsg() {
	cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
}

// �̵��Ϸ��� ���� ��ȿ�� ��ǥ���� üũ�ϴ� �Լ�
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

// ������ ��ġ�� ���������� üũ�ϴ� �Լ�
bool checkGoal(User* user) {
	// ������ �����ϸ�
	if (map[user->GetY()][user->GetX()] == 4) {
		return true;
	}
	return false;
}

// ���� Ȯ���ϴ� �Լ�
void checkState(User* user) {
	// ���� �������� Ȯ��
	if (checkEnemy(user)) {
		user->DecreaseHP(user->GetHP());
		printEnemy(user);
	}
	// �������� �������� Ȯ��
	if (checkItem(user)) {
		printItem();
	}
	// ������ �������� Ȯ��
	if (checkPoshion(user)) {
		user->IncreaseHP(user->GetHP());
		printPoshion();
	}
}

// ���� ������ ��� ����ϴ� �Լ�
void printEnemy(User* user) {
	cout << "���� �������ϴ�. HP 2 �پ��ϴ�. " << endl;
	if (user == &warrior_user) {
		warrior_user.doAttack();
	}
	if (user == &magician_user) {
		magician_user.doAttack();
	}
}

// ���� �������� Ȯ���ϴ� �Լ�
bool checkEnemy(User* user) {
	if (map[user->GetY()][user->GetX()] == 2) {
		return true;
	}
	return false;
}

// �������� ������ ��� ����ϴ� �Լ�
void printItem() {
	cout << "�������� �������ϴ�." << endl;
}

// �������� �������� Ȯ���ϴ� �Լ�
bool checkItem(User* user) {
	if (map[user->GetY()][user->GetX()] == 1) {
		return true;
	}
	return false;
}

// ������ ������ ��� ����ϴ� �Լ�
void printPoshion() {
	cout << "������ �������ϴ�. HP 2 �þ���ϴ�. " << endl;
}

// ������ �������� Ȯ���ϴ� �Լ�
bool checkPoshion(User* user) {
	if (map[user->GetY()][user->GetX()] == 3) {
		return true;
	}
	return false;
}