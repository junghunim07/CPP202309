#include <iostream>
#include <string>

using namespace std;

int main() {
	string s1 = "���";		// s1�� '���'�� ����
	string s2;				// s2�� default������ ����.
	
	// s2 = s1 + " " + 10 + "��";
	s2 = s1 + " " + to_string(10) + "��";

	// s2�� ���.
	cout << s2 << endl;
}