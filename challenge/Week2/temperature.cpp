#include <iostream>

using namespace std;

int main() {
	// H�� int�� C�� double�� ����.
	int H;
	double C;

	// "ȭ���µ� : "�� ���
	cout << "ȭ���µ� : ";
	// �Է¹��� ���� H�� ����.
	cin >> H;
	
	// C�� �Է¹��� H���� �̿��Ͽ� (5.0 / 9.0) * (H - 32)�� ����.
	C = (5.0 / 9.0) * (H - 32);

	// "�����µ� = C��"�� ���.
	cout << "�����µ� = " << C << endl;
}