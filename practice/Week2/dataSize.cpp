#include <iostream>

using namespace std;

int main() {
	// "char ũ�� : 1"�� ���.
	cout << "char ũ�� : " << sizeof('p') << endl;
	// "int ũ�� : 4"�� ���.
	cout << "int ũ�� : " << sizeof(10) << endl;
	// "double ũ�� : 8"�� ���.
	cout << "double ũ�� : " << sizeof(10.0) << endl;

	return 0;
}