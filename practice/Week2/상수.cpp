#include <iostream>
#include <string>
#define PI 3.14159265359		// PI���� ����.

using namespace std;

int main() {
	int income = 1000;						// income�� 1000�� ����.
	const double TAX_RATE = 0.25;			// TAX_RATE�� 0.25 ����.
	income = income - TAX_RATE * income;	// income�� income���� TAX_RATE * income�� �� ���� ����.

	double x = 100;							// x�� 100�� ����.
	x *= PI;								// x�� x * PI���� ����.

	cout << x << endl;						// x ���.

	return 0;
}