#include <iostream>

using namespace std;

int main() {
	// 변수 choice를 int타입으로 생성.
	int choice;

	cout << "1. 파일 저장" << endl;			// "1. 파일 저장"을 출력
	cout << "2. 저장 없이 닫기" << endl;	// "2. 저장 없이 닫기"을 출력
	cout << "3. 종료" << endl;				// "3. 종료"을 출력
	cin >> choice;							// 입력 받은 값을 choice에 저장,

	// 입력받은 값에 따른 해당 출력을 하기 위한 switch문
	switch (choice) {
	case 1:		// 1을 선택했을 경우 "파일 저장을 선택했습니다."를 출력하고 switch문을 빠져나옴.
		cout << "파일 저장을 선택했습니다." << endl;
		break;
	case 2 :	// 2을 선택했을 경우 "파일 닫기를 선택했습니다."를 출력하고 switch문을 빠져나옴.
		cout << "파일 닫기를 선택했습니다." << endl;
		break;
	case 3 :	// 3을 선택했을 경우 "프로그램을 종료합니다."를 출력하고 switch문을 빠져나옴.
		cout << "프로그램을 종료합니다." << endl;
		break;
	default :	// 그 외의 값들을 입력받았을 경우 "잘못된 선택입니다."를 출력하고 switch문을 빠져나옴.
		cout << "잘못된 선택입니다." << endl;
		break;
	}

	return 0;
}