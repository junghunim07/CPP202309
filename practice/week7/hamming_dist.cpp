#include <iostream>
#include <string>

using namespace std;

int main() {
	// �Է°��� ���� s1, s2
	string s1, s2;
	int cnt = 0;

	// DNA1�� ���� �Է¹޴´�.
	cout << "DNA1: ";
	cin >> s1;
	// DNA2�� ���� �Է¹޴´�.
	cout << "DNA2: ";
	cin >> s2;

	// ���̰� �ٸ���
	if (s1.length() != s2.length())
		// "����: ���̰� �ٸ�"�� ���
		cout << "����: ���̰� �ٸ�" << endl;
	// �׷��� �ʴٸ�
	else {
		// s1�� ���̸�ŭ for���� ���� Ʋ�� ���ڰ� �� �������� ����ϴ� for��
		for (int i = 0; i < s1.length(); i++) {
			if (s1[i] != s2[i])
				cnt += 1;
		}

		// ���� ���� ���.
		cout << "�ع� �Ÿ��� " << cnt << endl;
	}

	return 0;
}