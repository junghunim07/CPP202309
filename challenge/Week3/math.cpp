#include <iostream>
#include <time.h>

using namespace std;

int main() {
	int i;				// 사용자 값을 저장할 변수
	int ans;			// 정답.
	int tries = 0;		// 횟수.

	// "산수 문제를 자동으로 출제합니다."를 출력
	cout << "산수 문제를 자동으로 출제합니다." << endl;

	// 반복문
	while (true) {
		// 랜덤 숫자 2개 생성.
		int firstNum = rand() % 100;
		int secondNum = rand() % 100;

		// 문제 출제,
		cout << firstNum << "+" << secondNum << "=";

		// 정답.
		ans = firstNum + secondNum;

		// 사용자 값 받기.
		cin >> i;

		// 맞았다면
		if (i == ans) {
			// "맞았습니다."를 출력,
			cout << "맞았습니다." << endl;
			tries++;	// 횟수 증가.
		}
		// 그렇지 않다면
		else
			// "틀렸습니다."를 출력,
			cout << "틀렸습니다." << endl;

		// 맞힌 횟수가 5회면
		if (tries == 5)
			break;		// 반복문 빠져나가기.
	} 

	return 0;
}