#include <iostream>

using namespace std;

int main() {
	// ���� ���� Ƚ���� ������ ���� ����.
	int vowel = 0;
	int consonant = 0;

	// "�����ڸ� �Է��ϰ� 0�� ġ����"�� ���.
	// ctrl + z�� �ȵż� 0�̶�� ������ ����.
	cout << "�����ڸ� �Է��ϰ� 0�� ġ����" << endl;

	// �Է°��� ������ ���� ����.
	char ch;

	// �ݺ���.
	do {
		// �Է°� ����,
		cin >> ch;
		
		// 'a'�� �Էµƴٸ�.
		if (ch == 'a')
			vowel++;	// ���� ����.
		// 'e'�� �Էµƴٸ�.
		else if (ch == 'e')
			vowel++;	// ���� ����.
		// 'i'�� �Էµƴٸ�.
		else if (ch == 'i')
			vowel++;	// ���� ����.
		// 'o'�� �Էµƴٸ�.
		else if (ch == 'o')
			vowel++;	// ���� ����.
		// 'u'�� �Էµƴٸ�.
		else if (ch == 'u')
			vowel++;	// ���� ����.
		// �� �ܿ���
		else
			consonant++;// ���� ����.

		// 0�� �Է��ߴٸ�
		if (ch == '0')
			break;		// �ݺ����� ��������.
	} while (true);

	// "���� : " ����Ƚ�� ���.
	cout << "���� : " << vowel << endl;
	// "���� : " ����Ƚ�� ���.
	cout << "���� : " << consonant << endl;

	return 0;
}