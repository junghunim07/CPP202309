#include <iostream>

using namespace std;

int main() {
	int a, b, c, shortest;

	cout << "3개의 정수를 입력하시오 : ";
	cin >> a >> b >> c;

	// 만약 a가 b보다 작고 a가 c보다 작으면
	if (a < b && a < c)
		shortest = a;			// shortest에 a를 저장.
	// 만약 b가 a보다 작고 b가 c보다 작으면
	else if (b < a && b < c)
		shortest = b;			// shortest에 b를 저장.
	// c가 a보다 작고 c가 b보다 작으면
	else
		shortest = c;			// shortest에 c를 저장.

	// "가장 작은 정수는"을 출력하고 shortest를 출력.
	cout << "가장 작은 정수는 " << shortest << endl;

	return 0;
}