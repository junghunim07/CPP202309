#include <iostream>

using namespace std;

int main() {
	double H, C;				// H(화씨온도), C(섭씨온도) double 형 변수 생성

	// "섭씨온도:"출력
	cout << "섭씨온도:";
	cin >> C;					// 입력받은 값 C(섭씨온도)에 저장

	// 화씨온도를 계산하는 식 계산한 값 H에 저장
	H = C * (9.0 / 5.0) + 32;

	// H 출력
	cout << H;

	return 0;
}