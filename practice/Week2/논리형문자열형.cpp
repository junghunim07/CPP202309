#include <iostream>
#include <string>

using namespace std;

int main() {
	string s1 = "Good";		// s1�� Good�� ����.
	string s2 = "Bad";		// s2�� Bad ����.

	// b�� s1�� s2�� ���ٸ� True
	// �ٸ��ٸ� False�� ����.
	bool b = (s1 == s2);

	// b�� ����.
	cout << b << endl;

	// s2�� Good���� ���� ����.
	s2 = "Good";
	// b�� s1�� s2�� �ٽ� ���Ͽ� ����.
	b = (s1 == s2);
	
	// b ���
	cout << b << endl;
}