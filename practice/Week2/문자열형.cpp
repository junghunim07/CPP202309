#include <iostream>
#include <string>

using namespace std;

int main() {
	string s1 = "Good";				// s1에 Good을 저장.
	string s2 = "Morning!";			// s2에 Morning!을 저장
	string s3 = s1 + " " + s2;		// s3 = s1과 s2 사이에 공백을 포함하여 저장.

	cout << s3 << endl;				// s3 출력.

	return 0;
}