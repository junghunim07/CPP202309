#include <iostream>
#include <string>

using namespace std;

int main() {
	// 입력값을 받을 s1, s2
	string s1, s2;
	int cnt = 0;

	// DNA1의 값을 입력받는다.
	cout << "DNA1: ";
	cin >> s1;
	// DNA2의 값을 입력받는다.
	cout << "DNA2: ";
	cin >> s2;

	// 길이가 다르면
	if (s1.length() != s2.length())
		// "오류: 길이가 다름"을 출력
		cout << "오류: 길이가 다름" << endl;
	// 그렇지 않다면
	else {
		// s1의 길이만큼 for문을 돌려 틀린 글자가 몇 개인지를 계산하는 for문
		for (int i = 0; i < s1.length(); i++) {
			if (s1[i] != s2[i])
				cnt += 1;
		}

		// 구한 값을 출력.
		cout << "해밍 거리는 " << cnt << endl;
	}

	return 0;
}