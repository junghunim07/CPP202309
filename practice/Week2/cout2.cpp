#include <iostream>
#include <string>

using namespace std;

int main() {
	// character������ char�� �����ϰ� C�� ����
	char character = 'C';
	// integer������ int�� �����ϰ� 100�� ����
	int integer = 100;
	// precision������ double�� �����ϰ� 3.14159�� ����
	double precision = 3.14159;
	// is_true������ bool�� �����ϰ� true�� ����
	bool is_true = true;
	// word������ string���� �����ϰ� Hello World�� ����
	string word = "Hello World";

	// "char : C"�� ���
	cout << "char : " << character << endl;
	// "int : 100"�� ���
	cout << "int : " << integer << endl;
	// "double : 3.14159"�� ���
	cout << "double : " << precision << endl;
	// "bool : 1"�� ���
	cout << "bool : " << is_true << endl;
	// "string : Hello World"�� ���
	cout << "string : " << word << endl;

	return 0;
}