#include <iostream>

using namespace std;

int main() {
	// 변수 one, two, three, four 각각을 생성하고 각각 1, 2, 3, 4를 저장.
	int one = 1;
	int two = 2;
	int three = 3;
	int four = 4;

	// "1 + 3 = 4"를 출력
	cout << "1 + 3 = " << one + three << endl;
	// "4 - 2 = 2"를 출력
	cout << "4 - 2 = " << four - two << endl;
	// "2 * 3 = 6"를 출력
	cout << "2 * 3 = " << two * three << endl;
	// "4 / 2 = 2"를 출력
	cout << "4 / 2 = " << four / two << endl;

	// "2 + 3 * 4 = 14"를 출력
	cout << "2 + 3 * 4 = " << two + three * four << endl;
	// "2 + 3 * 4 = 14"를 출력
	cout << "2 + 3 * 4 = " << two + three * four << endl;
	// "1 + 4 / 2 = 3"를 출력
	cout << "1 + 4 / 2 = " << one + four / two << endl;

	return 0;
}