#include <iostream>

using namespace std;

int main() {
	// two, eight, sum1, sum2 변수를 생성하고, 2, 8, 2, 8을 각각 저장.
	int two = 2;
	int eight = 8;
	int sum1 = 2;
	int sum2 = 8;

	//sum1 에 sum1 + two한 값을 저장.
	sum1 *= two;
	// sum2에 sum2 / eight한 값을 저장.
	sum2 /= eight;

	// "sum1 = 4"를 출력
	cout << "sum1 = " << sum1 << endl;
	// "sum2 = 1"를 출력
	cout << "sum2 = " << sum2 << endl;

	return 0;
}