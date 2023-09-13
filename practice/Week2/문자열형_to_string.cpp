#include <iostream>
#include <string>

using namespace std;

int main() {
	string s1 = "사과";		// s1에 '사과'를 저장
	string s2;				// s2를 default값으로 생성.
	
	// s2 = s1 + " " + 10 + "개";
	s2 = s1 + " " + to_string(10) + "개";

	// s2를 출력.
	cout << s2 << endl;
}