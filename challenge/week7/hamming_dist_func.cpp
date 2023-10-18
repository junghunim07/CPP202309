#include <iostream>
#include <string>

using namespace std;

// �빮�ڸ� �ҹ��ڷ� ��ȯ���� �Լ�
string toLowerStr(string str) {
	for (char& c : str) {
		c = tolower(c);
	}

	return str;
}

// �ҹ��ڸ� �빮�ڷ� ��ȯ���� �Լ�
string toUpperStr(string str) {
	for (char& c : str) {
		c = toupper(c);
	}

	return str;
}

// �عְŸ��� ������� �Լ�
int calcHammingDist(string s1, string s2) {
	string s1LowerStr, s2LowerStr;
	int cnt = 0;

	// ���α׷� ���� ��ҹ��� ������ �ϹǷ�,
	// �Ű������� ���� ���ڿ��� ��� �ҹ��ڷ� ��ȯ.
	s1LowerStr = toLowerStr(s1);
	s2LowerStr = toLowerStr(s2);

	// �Ÿ��� ������� for��
	for (int i = 0; i < s1.length(); i++) {
		if (s1LowerStr[i] != s2LowerStr[i])
			cnt++;
	}

	return cnt;
}

int main() {
	string s1, s2;

	// s1�� �Է� �޴´�.
	cout << "DNA1: ";
	cin >> s1;

	// s1�� s2�� ���̰� �ٸ� ��� s2�� �Է°��� �ٽ� ���� for��
	for (int i = 0; i < 2; i++) {
		cout << "DNA2: ";
		cin >> s2;

		if (s1.length() != s2.length()) {
			cout << "���̰� �ٸ��ϴ�. �ٽ� �Է����ּ���." << endl;
			i--;
		}
		else {
			break;
		}
	}

	// �عְŸ��� ���Ѵ�.
	int result = calcHammingDist(s1, s2);

	cout << "�ع� �Ÿ��� " << result << endl;

	return 0;
}