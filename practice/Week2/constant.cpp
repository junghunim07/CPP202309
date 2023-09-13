#include <iostream>

using namespace std;

int main() {
	// GREATE_VICTORY_SALSU을 생성하고 값이 변하지 않게 하기 위해 const로 생성.
	const int GREATE_VICTORY_SALSU = 612;
	// GREATE_VICTORY_GWIJU을 생성하고 값이 변하지 않게 하기 위해 const로 생성.
	const int GREATE_VICTORY_GWIJU = 1019;

	// "고구려 살수대첩 연도 : 612"를 출력
	cout << "고구려 살수대첩 연도 : " << GREATE_VICTORY_SALSU << "년" << endl;
	// "고려 귀주대첩 연도 : 1029"를 출력
	cout << "고려 귀주대첩 연도 : " << GREATE_VICTORY_GWIJU << "년" << endl;
}