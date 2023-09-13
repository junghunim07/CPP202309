#include <iostream>

using namespace std;

int main() {
	// x를 int로 생성하고 1을 저장.
	int x = 1;

	// "x = 1"을 출력 출력하고 x는 1증가
	cout << "x = " << x++ << endl;
	// "x = 2"를 출력 위에서 x가 증가했고 그다음 x를 또 1증가
	cout << "x = " << x++ << endl;
	// "x = 4"를 출력 위에서 x가 2가 저장되어있고, 출력하기 전 1을 증가.
	cout << "x = " << ++x << endl;
	// "x = 4"를 출력 위에서 x에 4가 저장되어있고, 출력한 다음 1 감소.
	cout << "x = " << x-- << endl;
	// "x = 3"를 출력 위에서 x에 3이 저장되어있고, 출력한 다음 1 감소.
	cout << "x = " << x-- << endl;
	// "x = 1"를 출력 위에서 x에 2가 저장되어있고, 출력 전 1 감소.
	cout << "x = " << --x << endl;

	return 0;
}