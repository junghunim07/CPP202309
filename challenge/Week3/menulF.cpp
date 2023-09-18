#include <iostream>

using namespace std;

int main() {
	// 변수 choice를 int타입으로 생성.
	int choice;

	cout << "1. 파일 저장" << endl;			// "1. 파일 저장"을 출력
	cout << "2. 저장 없이 닫기" << endl;	// "2. 저장 없이 닫기"을 출력
	cout << "3. 종료" << endl;				// "3. 종료"을 출력
	cin >> choice;							// 입력 받은 값을 choice에 저장,

	// 만약 choice가 1이라면
	if (choice == 1)
		// "파일 저장을 선택했습니다."를 출력
		cout << "파일 저장을 선택했습니다." << endl;
	// choice가 2라면
	else if (choice == 2)
		// "파일 닫기를 선택했습니다."를 출력
		cout << "파일 닫기를 선택했습니다." << endl;
	// choice가 3이라면
	else if (choice == 3)
		// "프로그램을 종료합니다."를 출력
		cout << "프로그램을 종료합니다." << endl;
	// 그 외의 값이라면
	else
		// "잘못된 선택입니다."를 출력
		cout << "잘못된 선택입니다." << endl;

	return 0;
}