#include <iostream>

using namespace std;

int main() {
	double H, C;				// H(ȭ���µ�), C(�����µ�) double �� ���� ����

	// "�����µ�:"���
	cout << "�����µ�:";
	cin >> C;					// �Է¹��� �� C(�����µ�)�� ����

	// ȭ���µ��� ����ϴ� �� ����� �� H�� ����
	H = C * (9.0 / 5.0) + 32;

	// H ���
	cout << H;

	return 0;
}