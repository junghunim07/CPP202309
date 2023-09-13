#include <iostream>

using namespace std;

int main() {
	// "char 크기 : 1"를 출력.
	cout << "char 크기 : " << sizeof('p') << endl;
	// "int 크기 : 4"를 출력.
	cout << "int 크기 : " << sizeof(10) << endl;
	// "double 크기 : 8"를 출력.
	cout << "double 크기 : " << sizeof(10.0) << endl;

	return 0;
}