#include <iostream>

using namespace std;

// x�� y�� ���ϴ� �޼ҵ�
auto add(int x, int y) {
	return x * y;
}

int main() {
	// sum�� add�� ȣ���Ͽ� 5�� 6�� ���� ���� ����.
	auto sum = add(5, 6);

	// sum�� ���
	cout << sum;

	return 0;
}