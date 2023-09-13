#include <iostream>
#include <string>

using namespace std;

int main() {
	// name으로 string변수 생성.
	string name;

	// "이름을 입력하시오 : "를 출력.
	cout << "이름을 입력하시오 : ";

	// 입력받은 값을 name에 저장.
	cin >> name;

	// "'name값'을 환영합니다"를 출력
	cout << name << "을 환영합니다." << endl;

	return 0;
}