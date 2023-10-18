#include <iostream>
#include <string>

using namespace std;

// 대문자를 소문자로 변환해줄 함수
string toLowerStr(string str) {
	for (char& c : str) {
		c = tolower(c);
	}

	return str;
}

// 소문자를 대문자로 변환해줄 함수
string toUpperStr(string str) {
	for (char& c : str) {
		c = toupper(c);
	}

	return str;
}

// 해밍거리를 계산해줄 함수
int calcHammingDist(string s1, string s2) {
	string s1LowerStr, s2LowerStr;
	int cnt = 0;

	// 프로그램 언어는 대소문자 구별을 하므로,
	// 매개변수로 받은 문자열을 모두 소문자로 변환.
	s1LowerStr = toLowerStr(s1);
	s2LowerStr = toLowerStr(s2);

	// 거리를 계산해줄 for문
	for (int i = 0; i < s1.length(); i++) {
		if (s1LowerStr[i] != s2LowerStr[i])
			cnt++;
	}

	return cnt;
}

int main() {
	string s1, s2;

	// s1을 입력 받는다.
	cout << "DNA1: ";
	cin >> s1;

	// s1과 s2의 길이가 다를 경우 s2의 입력값을 다시 받을 for문
	for (int i = 0; i < 2; i++) {
		cout << "DNA2: ";
		cin >> s2;

		if (s1.length() != s2.length()) {
			cout << "길이가 다릅니다. 다시 입력해주세요." << endl;
			i--;
		}
		else {
			break;
		}
	}

	// 해밍거리를 구한다.
	int result = calcHammingDist(s1, s2);

	cout << "해밍 거리는 " << result << endl;

	return 0;
}