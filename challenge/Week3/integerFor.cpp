#include <iostream>

using namespace std;

int main() {
	// �Է°��� ������ userInput���� ���� ����.
	int userInput;

	// "������ 10�� �Է��ϼ��� (0�� �Է��ϸ� ����) : "���.
	cout << "������ 10�� �Է��ϼ��� (0�� �Է��ϸ� ����) : ";

	// 10�� �ݺ��� �ݺ���
	for (int i = 0; i < 10; i++) {
		// userInput�� �Է°��� ����.
		cin >> userInput;

		// 0�� �Է��ϸ� break;
		if (userInput == 0)
			break;

		// "�Է� �� : " �Է°� " Ƚ�� : " �ݺ��� Ƚ���� ���.
		cout << "�Է°� : " << userInput << " Ƚ�� : " << i << endl;
	}

	// "����Ǿ����ϴ�."�� ���.
	cout << "����Ǿ����ϴ�.";

	return 0;
}