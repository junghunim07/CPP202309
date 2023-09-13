#include <iostream>
#include <string>
#define PI 3.14159265359		// PI값을 정의.

using namespace std;

int main() {
	int income = 1000;						// income에 1000을 저장.
	const double TAX_RATE = 0.25;			// TAX_RATE에 0.25 저장.
	income = income - TAX_RATE * income;	// income에 income에서 TAX_RATE * income을 뺀 값을 저장.

	double x = 100;							// x에 100을 저장.
	x *= PI;								// x에 x * PI값을 저장.

	cout << x << endl;						// x 출력.

	return 0;
}