#include <iostream>

using namespace std;

int main() {
	// 변수 number를 int타입으로 생성
	int number;
	// "숫자를 입력하시오 : "를 출력
	cout << "숫자를 입력하시오 : ";
	// 입력받은 값을 number에 저장.
	cin >> number;

	// 만약 number가 0 이라면
	if (number == 0)
		// "zero"를 출력.
		cout << "zero" << endl;
	// 만약 number가 1 이라면
	else if (number == 1)
		// "one"을 출력.
		cout << "one" << endl;
	// 그 외의 값이면
	else
		// "many"를 출력.
		cout << "many" << endl;

	return 0;
}