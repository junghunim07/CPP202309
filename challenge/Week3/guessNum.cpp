#include <iostream>
#include <time.h>

using namespace std;

int main() {
	// random 함수 관련 설정
	srand(time(NULL));

	// 정답
	int answer = rand() % 100;
	// 시도 횟수 저장하는 변수
	int tries = 0;

	// 사용자 입력 저장하기 위한 변수
	int guess;

	// 맞춘 여부를 시도할 반복문
	do {
		// "정답을 추측하여 보시오 : "를 출력.
		cout << "정답을 추측하여 보시오 : ";
		cin >> guess;		// 사용자 입력값 저장.
		tries++;			// 횟수 증가.
		
		// 사용자 값이 답보다 작다면
		if (guess < answer)
			// "제시한 정수가 낮습니다."를 출력,
			cout << "제시한 정수가 낮습니다." << endl;
		// 그렇지 않다면
		else
			// "제시한 정수가 높습니다."를 출력,
			cout << "제시한 정수가 높습니다." << endl;

		// 답이 같다면
		if (guess == answer)
			break;		// 반복문을 빠져 나감.
	} 
	while (true);

	// "축하합니다. 시도횟수 = " 시도 횟수 출력.
	cout << "축하합니다. 시도 횟수 = " << tries << endl;
	
	return 0;
}