#include <iostream>

using namespace std;

int main() {
	int a, b, c, shortest;

	cout << "3���� ������ �Է��Ͻÿ� : ";
	cin >> a >> b >> c;

	// ���� a�� b���� �۰� a�� c���� ������
	if (a < b && a < c)
		shortest = a;			// shortest�� a�� ����.
	// ���� b�� a���� �۰� b�� c���� ������
	else if (b < a && b < c)
		shortest = b;			// shortest�� b�� ����.
	// c�� a���� �۰� c�� b���� ������
	else
		shortest = c;			// shortest�� c�� ����.

	// "���� ���� ������"�� ����ϰ� shortest�� ���.
	cout << "���� ���� ������ " << shortest << endl;

	return 0;
}