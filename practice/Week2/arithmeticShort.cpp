#include <iostream>

using namespace std;

int main() {
	// two, eight, sum1, sum2를 생성하고 2, 8, 2, 2를 각각 저장.
	int two = 2;
	int eight = 8;
	int sum1 = 2;
	int sum2 = 2;

	// sum1 에 sum1과 two를 합한 값을 저장
	sum1 = sum1 + two;
	// sum2에 sum2와 eight을 합한 값을 저장
	sum2 += eight;
	// "sum1 = 4"를 출력
	cout << "sum1 = " << sum1 << endl;
	// "sum2 = 10"을 출력
	cout << "sum2 = " << sum2 << endl;

	return 0;
}