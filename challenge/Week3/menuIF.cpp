#include <iostream>

using namespace std;

int main() {
	// ���� choice�� intŸ������ ����.
	int choice;

	cout << "1. ���� ����" << endl;			// "1. ���� ����"�� ���
	cout << "2. ���� ���� �ݱ�" << endl;	// "2. ���� ���� �ݱ�"�� ���
	cout << "3. ����" << endl;				// "3. ����"�� ���
	cin >> choice;							// �Է� ���� ���� choice�� ����,

	// ���� choice�� 1�̶��
	if (choice == 1)
		// "���� ������ �����߽��ϴ�."�� ���
		cout << "���� ������ �����߽��ϴ�." << endl;
	// choice�� 2���
	else if (choice == 2)
		// "���� �ݱ⸦ �����߽��ϴ�."�� ���
		cout << "���� �ݱ⸦ �����߽��ϴ�." << endl;
	// choice�� 3�̶��
	else if (choice == 3)
		// "���α׷��� �����մϴ�."�� ���
		cout << "���α׷��� �����մϴ�." << endl;
	// �� ���� ���̶��
	else
		// "�߸��� �����Դϴ�."�� ���
		cout << "�߸��� �����Դϴ�." << endl;

	return 0;
}