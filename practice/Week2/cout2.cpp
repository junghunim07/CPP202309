#include <iostream>
#include <string>

using namespace std;

int main() {
	// character변수를 char로 생성하고 C를 저장
	char character = 'C';
	// integer변수를 int로 생성하고 100을 저장
	int integer = 100;
	// precision변수를 double로 생성하고 3.14159를 저장
	double precision = 3.14159;
	// is_true변수를 bool로 생성하고 true를 저장
	bool is_true = true;
	// word변수를 string으로 생성하고 Hello World를 저장
	string word = "Hello World";

	// "char : C"를 출력
	cout << "char : " << character << endl;
	// "int : 100"를 출력
	cout << "int : " << integer << endl;
	// "double : 3.14159"를 출력
	cout << "double : " << precision << endl;
	// "bool : 1"를 출력
	cout << "bool : " << is_true << endl;
	// "string : Hello World"를 출력
	cout << "string : " << word << endl;

	return 0;
}