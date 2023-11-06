#include <iostream>
using namespace std;

const int numCell = 3; // �������� ���� ���� ����
char board[numCell][numCell]{}; // �������� ��Ÿ���� 2���� �迭
bool isValid(int x, int y);
bool checkWin(char currentUser);
bool checkLeftUpToBottom(char currentUser);
bool checkRightBottomToUp(char currentUser);

int main() {
	// ������ �����ϴ� �� �ʿ��� ���� ����

	int k = 0; // ���� �������� üũ�ϱ� ���� ����
	char currentUser = 'X'; // ���� ������ ���� �����ϱ� ���� ����
	int x, y = 0; // ����ڿ��� xy��ǥ���� �Է¹ޱ� ���� ����

	// ������ �ʱ�ȭ
	for (int i = 0; i < numCell; i++) {
		for (int j = 0; j < numCell; j++) {
			board[i][j] = ' ';
		}
	}

	// ������ ���� �ݺ�
	while (true) {
		// 1. ���� �������� ���
		// TODO 1.1: 3�ο� �������� ����
		switch (k % 3) {
		case 0:
			currentUser = 'X';
			break;
		case 1:
			currentUser = 'O';
			break;
		case 2:
			currentUser = 'H';
			break;
		}
		cout << k % 3 + 1 << "�� ����(" << currentUser << ")�� �����Դϴ�. -> ";

		// 2. ��ǥ �Է� �ޱ�
		cout << "(x, y) ��ǥ�� �Է��ϼ���: ";
		int x, y;
		cin >> x >> y;

		// 3. �Է¹��� ��ǥ�� ��ȿ�� üũ
		// TODO FUNC 1: isValid �Լ� ���� �� ȣ��
		if (isValid(x, y)) {
			continue;
		}

		/*if (x >= numCell || y >= numCell) {// ��ǥ ������ �����
			cout << x << "," << y << ": x�� y���� �ϳ��� ĭ�� ����ϴ�. " << endl;
			continue;
		}
		if (board[x][y] != ' ') {// ��ǥ������ �Է°��� �ߺ��ɶ�
			cout << x << "," << y << ": �̹� ���� ���ֽ��ϴ�. " << endl;
			continue;
		}*/



		// 4. �Է¹��� ��ǥ�� ���� ������ �� ����
		board[x][y] = currentUser;

		// 5. ���� ���� �� ���
		// TODO 1.2: numCell ���ڿ� ���� ������ ���
		for (int i = 0; i < numCell; i++) {
			for (int j = 0; j < numCell; j++) {
				if (j == numCell - 1) {
					cout << "---" << endl;
				}
				else {
					cout << "---|";
				}
			}
			for (int j = 0; j < numCell; j++)
			{
				cout << board[i][j];
				if (j == numCell - 1) {
					break;
				}
				cout << "  |";
			}
			cout << endl;
		}
		for (int i = 0; i < numCell; i++) {
			if (i == numCell - 1) {
				cout << "---" << endl;
			}
			else {
				cout << "---|";
			}
		}



		bool isWin = false; // �¸� ����
		// TODO FUNC2: 6.1���� 6.2���� checkWin �Լ� ���� �� ȣ��
		// 6.1. ����/���� �� üũ�ϱ�
		/*for (int i = 0; i < numCell; i++) {
			if (board[i][0] == currentUser && board[i][1] == currentUser && board[i][2] == currentUser) {
				cout << "���ο� ��� ���� �������ϴ�!!";
				isWin = true;
				break;
			}
			if (board[0][i] == currentUser && board[1][i] == currentUser && board[2][i] == currentUser) {
				cout << "���ο� ��� ���� �������ϴ�!!";
				isWin = true;
				break;
			}
		}


		// 6.2. �밢���� üũ�ϱ�
		// TODO 1.3: numCell�� ���� �밢�� ���� üũ �ڵ�� Ȯ��
		// HINT: for ��
		if (board[0][0] == currentUser && board[1][1] == currentUser && board[2][2] == currentUser) {
			cout << "���� ������ ������ �Ʒ� �밢������ ��� ���� �������ϴ�!" << endl;
			isWin = true;
		}
		if (board[0][2] == currentUser && board[1][1] == currentUser && board[2][0] == currentUser) {
			cout << "������ ������ ���� �Ʒ� �밢������ ��� ���� �������ϴ�!" << endl;
			isWin = true;
		}*/

		isWin = checkWin(currentUser);

		// �¸��ڰ� �����Ǿ����� �ش� �÷��̾ ����ϰ� ������ �����Ѵ�.
		if (isWin == true) {
			cout << k % 2 + 1 << "�� ����(" << currentUser << ")�� �¸��Դϴ�!" << endl;
			break;
		}

		// 7. ��� ĭ �� á���� üũ�ϱ�
		int checked = 0;
		for (int i = 0; i < numCell; i++) {
			for (int j = 0; j < numCell; j++) {
				if (board[i][j] == ' ') {
					checked++;
				}
			}
		}
		if (checked == 0) {
			cout << "��� ĭ�� �� á���ϴ�.  �����մϴ�. " << endl;
			break;
		}

		k++;
	}

	return 0;
}

bool isValid(int x, int y) {
	if (x >= numCell || y >= numCell) {
		cout << x << "," << y << ": x�� y���� �ϳ��� ĭ�� ����ϴ�. " << endl;
		return true;
	}
	if (board[x][y] != ' ') {
		cout << x << "," << y << ": �̹� ���� ���ֽ��ϴ�. " << endl;
		return true;
	}

	return false;
}

bool checkWin(char currentUser) {
	for (int i = 0; i < numCell; i++) {
		if (board[i][0] == currentUser && board[i][1] == currentUser && board[i][2] == currentUser) {
			cout << "���ο� ��� ���� �������ϴ�!!";
			return true;
		}
		if (board[0][i] == currentUser && board[1][i] == currentUser && board[2][i] == currentUser) {
			cout << "���ο� ��� ���� �������ϴ�!!";
			return true;
		}
	}
	if (checkLeftUpToBottom(currentUser)) {
		cout << "���� ������ ������ �Ʒ� �밢������ ��� ���� �������ϴ�!" << endl;
		return true;
	}

	if (checkRightBottomToUp(currentUser)) {
		cout << "������ ������ ���� �Ʒ� �밢������ ��� ���� �������ϴ�!" << endl;
		return true;
	}
	/*if (board[0][0] == currentUser && board[1][1] == currentUser && board[2][2] == currentUser) {
		cout << "���� ������ ������ �Ʒ� �밢������ ��� ���� �������ϴ�!" << endl;
		return true;
	}*/
	/*if (board[0][2] == currentUser && board[1][1] == currentUser && board[2][0] == currentUser) {
		cout << "������ ������ ���� �Ʒ� �밢������ ��� ���� �������ϴ�!" << endl;
		return true;
	}*/

	return false;
}

// ���� ������ ������ �Ʒ� �밢��
bool checkLeftUpToBottom(char currentUser) {
	int cnt = 0;

	for (int i = 0; i < numCell; i++) {
		if (board[i][i] == currentUser) {
			cnt++;
		}
	}

	if (cnt == numCell) {
		return true;
	}
	else {
		return false;
	}
}

// ������ ������ ���� �Ʒ� �밢��
bool checkRightBottomToUp(char currentUser) {
	int cnt = 0;

	for (int i = 0; i < numCell; i++) {
		if (board[i][numCell - 1 - i] == currentUser) {
			cnt++;
		}
	}

	if (cnt == numCell) {;
		return true;
	}
	else {
		return false;
	}
}