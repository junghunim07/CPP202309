#include <iostream>
#include <time.h>

using namespace std;

int main() {
	int i;				// ����� ���� ������ ����
	int ans;			// ����.
	int tries = 0;		// Ƚ��.

	// "��� ������ �ڵ����� �����մϴ�."�� ���
	cout << "��� ������ �ڵ����� �����մϴ�." << endl;

	// �ݺ���
	while (true) {
		// ���� ���� 2�� ����.
		int firstNum = rand() % 100;
		int secondNum = rand() % 100;

		// ���� ����,
		cout << firstNum << "+" << secondNum << "=";

		// ����.
		ans = firstNum + secondNum;

		// ����� �� �ޱ�.
		cin >> i;

		// �¾Ҵٸ�
		if (i == ans) {
			// "�¾ҽ��ϴ�."�� ���,
			cout << "�¾ҽ��ϴ�." << endl;
			tries++;	// Ƚ�� ����.
		}
		// �׷��� �ʴٸ�
		else
			// "Ʋ�Ƚ��ϴ�."�� ���,
			cout << "Ʋ�Ƚ��ϴ�." << endl;

		// ���� Ƚ���� 5ȸ��
		if (tries == 5)
			break;		// �ݺ��� ����������.
	} 

	return 0;
}