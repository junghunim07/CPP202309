#include <iostream>

using namespace std;

int main() {
	// two, eight, sum1, sum2�� �����ϰ� 2, 8, 2, 2�� ���� ����.
	int two = 2;
	int eight = 8;
	int sum1 = 2;
	int sum2 = 2;

	// sum1 �� sum1�� two�� ���� ���� ����
	sum1 = sum1 + two;
	// sum2�� sum2�� eight�� ���� ���� ����
	sum2 += eight;
	// "sum1 = 4"�� ���
	cout << "sum1 = " << sum1 << endl;
	// "sum2 = 10"�� ���
	cout << "sum2 = " << sum2 << endl;

	return 0;
}