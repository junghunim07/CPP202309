#include <iostream>
#include <string>

using namespace std;

int main() {
	string s1 = "Good";		// s1에 Good을 저장.
	string s2 = "Bad";		// s2에 Bad 저장.

	// b에 s1과 s2가 같다면 True
	// 다르다면 False를 저장.
	bool b = (s1 == s2);

	// b를 저장.
	cout << b << endl;

	// s2에 Good으로 값을 변경.
	s2 = "Good";
	// b를 s1과 s2를 다시 비교하여 저장.
	b = (s1 == s2);
	
	// b 출력
	cout << b << endl;
}