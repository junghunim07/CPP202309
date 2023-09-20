#include <iostream>

using namespace std;

int main() {
	// 모음 자음 횟수를 저장할 변수 생성.
	int vowel = 0;
	int consonant = 0;

	// "영문자를 입력하고 0를 치세요"를 출력.
	// ctrl + z가 안돼서 0이라는 임의의 조건.
	cout << "영문자를 입력하고 0를 치세요" << endl;

	// 입력값을 저장할 변수 생성.
	char ch;

	// 반복문.
	do {
		// 입력값 저장,
		cin >> ch;
		
		// 'a'가 입력됐다면.
		if (ch == 'a')
			vowel++;	// 모음 증가.
		// 'e'가 입력됐다면.
		else if (ch == 'e')
			vowel++;	// 모음 증가.
		// 'i'가 입력됐다면.
		else if (ch == 'i')
			vowel++;	// 모음 증가.
		// 'o'가 입력됐다면.
		else if (ch == 'o')
			vowel++;	// 모음 증가.
		// 'u'가 입력됐다면.
		else if (ch == 'u')
			vowel++;	// 모음 증가.
		// 그 외에는
		else
			consonant++;// 자음 증가.

		// 0을 입력했다면
		if (ch == '0')
			break;		// 반복문을 빠져나감.
	} while (true);

	// "모음 : " 모음횟수 출력.
	cout << "모음 : " << vowel << endl;
	// "자음 : " 자음횟수 출력.
	cout << "자음 : " << consonant << endl;

	return 0;
}