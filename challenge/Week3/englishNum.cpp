#include <iostream>

using namespace std;

int main() {
	// ���� number�� intŸ������ ����
	int number;
	// "���ڸ� �Է��Ͻÿ� : "�� ���
	cout << "���ڸ� �Է��Ͻÿ� : ";
	// �Է¹��� ���� number�� ����.
	cin >> number;

	// ���� number�� 0 �̶��
	if (number == 0)
		// "zero"�� ���.
		cout << "zero" << endl;
	// ���� number�� 1 �̶��
	else if (number == 1)
		// "one"�� ���.
		cout << "one" << endl;
	// �� ���� ���̸�
	else
		// "many"�� ���.
		cout << "many" << endl;

	return 0;
}