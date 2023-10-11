#include <iostream>

using namespace std;

int main() {
	const int numCell = 3;
	char board[numCell][numCell];
	int x, y;	// ����ڿ��� �Է¹޴� x, y ��ǥ�� ������ ����

	// ������ �ʱ�ȭ
	for (x = 0; x < numCell; x++) {
		for (y = 0; y < numCell; y++) {
			board[x][y] = ' ';
		}
	}

	int k = 0;					// ���� �������� üũ�ϱ� ���� ����
	char currentUser = 'X';		// ���� ������ ���� �����ϱ� ���� ���� ����

	// ���� 3���� 'A'�� ����.
	while (true) {
		int user = k % 3 + 1;	// ���� ��ȣ�� ǥ���� ����.
		// 1. ���� �������� ���
		switch (k % 3) {
		case 0:
			cout << user << "�� ����(X)�� �����Դϴ� -> ";
			currentUser = 'X';
			break;
		case 1:
			cout << user << "�� ����(O)�� �����Դϴ� -> ";
			currentUser = 'O';
			break;
		case 2:
			cout << user << "�� ����(A)�� �����Դϴ� -> ";
			currentUser = 'A';
			break;
		}

		// 2. ��ǥ �Է� �ޱ�
		cout << "(x, y) ��ǥ�� �Է��ϼ���: ";
		cin >> x >> y;

		// 3. �Է¹��� ��ǥ�� ��ȿ�� üũ
		if (x >= numCell || y >= numCell) {
			cout << x << ", " << y << ": ";
			cout << " x �� y �� �� �ϳ��� ĭ�� ����ϴ�." << endl;
			continue;
		}

		if (board[x][y] != ' ') {
			cout << x << ", " << y << ": �̹� ���� ���ֽ��ϴ�." << endl;
			continue;
		}

		// 4. �Է¹��� ��ǥ�� ���� ������ �� ����
		board[x][y] = currentUser;

		// 5. ���� ���� �� ���
		for (int i = 0; i < numCell; i++) {
			cout << "---|---|---" << endl;
			for (int j = 0; j < numCell; j++) {
				cout << board[i][j];
				if (j == numCell - 1) {
					break;
				}

				cout << "  |";
			}
			cout << endl;
		}

		cout << "---|---|---" << endl;

		// ������ �������� �Ǵ��ϱ� ���� tmp����
		int tmp = 0;

		// ���� �ƴ��� Ȯ���ϱ� ���� for��
		for (int i = 0; i < numCell; i++) {
			// ���ΰ� ���� ���� ���ٷ� �� ������ ���
			if ((board[i][0] == board[i][1]) && (board[i][0] == board[i][2])) {
				if (board[i][0] != ' ') {
					cout << "���ο� ��� ���� �������ϴ�!: " << user << "�� ����(" << board[i][0] << ")�� �¸��Դϴ�.";
					tmp = 1;		// ������ ������ ���ؼ� tmp������ 1�� �ʱ�ȭ.
					break;
				}
			}
			// ���ΰ� ���� ���� ���ٷ� �� ������ ���
			else if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && (board[0][i] == board[2][i])) {
				if (board[0][i] != ' ') {
					cout << "���ο� ��� ���� �������ϴ�!: " << user << "�� ����(" << board[0][i] << ")�� �¸��Դϴ�.";
					tmp = 1;		// ������ ������ ���ؼ� tmp������ 1�� �ʱ�ȭ.
					break;
				}
			}
			// �밢���� Ȯ���ϱ� ���� if��
			// �迭�� ������ ����� �ʱ� ����.
			// ������ �밢��
			if (i == 0) {
				// ���� ������ ������ �Ʒ� �밢������ ��� ���� ���� ���ٷ� ������ ���
				if (board[i][0] == board[i + 1][1] && board[i][0] == board[i + 2][2]) {
					if (board[i][0] != ' ') {
						cout << "���� ������ ������ �Ʒ� �밢������ ��� ���� �������ϴ�!: " << user << "�� ����(" << board[0][i] << ")�� �¸��Դϴ�.";
						tmp = 1;	// ������ ������ ���ؼ� tmp������ 1�� �ʱ�ȭ.
						break;
					}
				}
			}
			// ���� �밢��
			else if (i == 2) {
				// ������ ������ ���� �Ʒ� �밢������ ��� ���� ���� ���ٷ� ������ ���
				if (board[0][i] == board[1][i - 1] && board[0][i] == board[2][i - 2]) {
					if (board[0][i] != ' ') {
						cout << "������ ������ ���� �Ʒ� �밢������ ��� ���� �������ϴ�!: " << user << "�� ����(" << board[0][i] << ")�� �¸��Դϴ�.";
						tmp = 1;	// ������ ������ ���ؼ� tmp������ 1�� �ʱ�ȭ.
						break;
					}
				}
			}
		}

		k++;

		// tmp�� 1�̶�� ������ �������� �˸��� ����
		if (tmp == 1)
			break;

		// �����ǿ� ��� ���� á�� ���
		if (k == 9) {
			cout << "��� ĭ�� �� á���ϴ�. �����մϴ�.";
			break;
		}
	}

	return 0;
}