#include <iostream>

using namespace std;

// x와 y를 곱하는 메소드
auto add(int x, int y) {
	return x * y;
}

int main() {
	// sum에 add를 호출하여 5와 6을 곱한 값을 저장.
	auto sum = add(5, 6);

	// sum을 출력
	cout << sum;

	return 0;
}