#include <iostream>

using namespace std;

int main() {
	// money와 candy를 int타입으로 생성.
	int money;
	int candy;

	// "현재 가지고 잇는 돈 : "을 출력
	cout << "현재 가지고 있는 돈 : ";
	// 입력받은 값을 money에 저장
	cin >> money;
	// "캔디의 가격 : "을 출력
	cout << "캔디의 가격 : ";
	// 입력받은 값을 candy에 저장
	cin >> candy;

	// "최대로 살 수 잇는 캔디 = 3"을 출력
	cout << "최대로 살 수 잇는 캔디 = " << money / candy << endl;
	// "캔디 구입 후 남은 돈 = 100"을 출력
	cout << "캔디 구입 후 남은 돈 = " << money % candy << endl;

	return 0;
}