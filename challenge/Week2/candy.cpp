#include <iostream>

using namespace std;

int main() {
	// money�� candy�� intŸ������ ����.
	int money;
	int candy;

	// "���� ������ �մ� �� : "�� ���
	cout << "���� ������ �ִ� �� : ";
	// �Է¹��� ���� money�� ����
	cin >> money;
	// "ĵ���� ���� : "�� ���
	cout << "ĵ���� ���� : ";
	// �Է¹��� ���� candy�� ����
	cin >> candy;

	// "�ִ�� �� �� �մ� ĵ�� = 3"�� ���
	cout << "�ִ�� �� �� �մ� ĵ�� = " << money / candy << endl;
	// "ĵ�� ���� �� ���� �� = 100"�� ���
	cout << "ĵ�� ���� �� ���� �� = " << money % candy << endl;

	return 0;
}