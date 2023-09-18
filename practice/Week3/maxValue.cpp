#include <iostream>

using namespace std;

int main() {
	// 변수 a, b, c, largest를 int타입으로 생성.
	int a, b, c, largest;

	// "3개의 정수를 입력하시오 : "를 출력.
	cout << "3개의 정수를 입력하시오 : ";
	// 입력 받은 값을 a, b, c에 저장.
	cin >> a >> b >> c;

	// 만약 a가 b보다 크고 a가 c보다 크면
	if (a > b && a > c)
		largest = a;			// largest에 a를 저장.
	// 만약 b가 a보다 크고 b가 c보다 크면
	else if (b > a && b > c)
		largest = b;			// largest에 b를 저장.
	// c가 a보다 크고 c가 b보다 크면
	else
		largest = c;			// largest에 c를 저장.

	// "가장 큰 정수는"을 출력하고 largest를 출력.
	cout << "가장 큰 정수는 " << largest << endl;

	return 0;
}