#include <iostream>

using namespace std;

int main() {
	// ���� a, b, c, largest�� intŸ������ ����.
	int a, b, c, largest;

	// "3���� ������ �Է��Ͻÿ� : "�� ���.
	cout << "3���� ������ �Է��Ͻÿ� : ";
	// �Է� ���� ���� a, b, c�� ����.
	cin >> a >> b >> c;

	// ���� a�� b���� ũ�� a�� c���� ũ��
	if (a > b && a > c)
		largest = a;			// largest�� a�� ����.
	// ���� b�� a���� ũ�� b�� c���� ũ��
	else if (b > a && b > c)
		largest = b;			// largest�� b�� ����.
	// c�� a���� ũ�� c�� b���� ũ��
	else
		largest = c;			// largest�� c�� ����.

	// "���� ū ������"�� ����ϰ� largest�� ���.
	cout << "���� ū ������ " << largest << endl;

	return 0;
}