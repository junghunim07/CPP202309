#include <iostream>

using namespace std;

int main() {
	// ���� one, two, three, four ������ �����ϰ� ���� 1, 2, 3, 4�� ����.
	int one = 1;
	int two = 2;
	int three = 3;
	int four = 4;

	// "1 + 3 = 4"�� ���
	cout << "1 + 3 = " << one + three << endl;
	// "4 - 2 = 2"�� ���
	cout << "4 - 2 = " << four - two << endl;
	// "2 * 3 = 6"�� ���
	cout << "2 * 3 = " << two * three << endl;
	// "4 / 2 = 2"�� ���
	cout << "4 / 2 = " << four / two << endl;

	// "2 + 3 * 4 = 14"�� ���
	cout << "2 + 3 * 4 = " << two + three * four << endl;
	// "2 + 3 * 4 = 14"�� ���
	cout << "2 + 3 * 4 = " << two + three * four << endl;
	// "1 + 4 / 2 = 3"�� ���
	cout << "1 + 4 / 2 = " << one + four / two << endl;

	return 0;
}