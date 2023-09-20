#include <iostream>

using namespace std;

int main() {
	// 입력값을 저장할 userInput으로 변수 생성.
	int userInput;

	// "정수를 10번 입력하세요 (0을 입력하면 종료) : "출력.
	cout << "정수를 10번 입력하세요 (0을 입력하면 종료) : ";

	// 10번 반복할 반복문
	for (int i = 0; i < 10; i++) {
		// userInput에 입력값을 저장.
		cin >> userInput;

		// 0을 입력하면 break;
		if (userInput == 0)
			break;

		// "입력 값 : " 입력값 " 횟수 : " 반복문 횟수를 출력.
		cout << "입력값 : " << userInput << " 횟수 : " << i << endl;
	}

	// "종료되었습니다."를 출력.
	cout << "종료되었습니다.";

	return 0;
}