#include <iostream>
#include <string>

using namespace std;

int main() {
	const int STUDENT = 5;				// �л� ��
	const int SUBJECT = 3;				// ���� ��
	int scores[STUDENT][SUBJECT];		// �� �л��� �ش� ���� ������ ������ 2���� �迭.

	// �л� �迭
	string studentNames[STUDENT] = { "����", "����", "ö��", "�̹�", "����" };
	// ���� �迭
	string subjectNames[SUBJECT] = { "����", "����", "CPP" };

	// �� �л��� �� ���� ������ �Է¹ޱ� ���� 2�� for��
	for (int i = 0; i < STUDENT; i++) {
		cout << studentNames[i] << "�� ������ �ϳ��� �Է��ϼ���." << endl;

		// �� �л� �� ���� �� ������ �Է¹ޱ� ���� for��
		for (int j = 0; j < SUBJECT; j++) {
			cout << subjectNames[j] << " : ";
			cin >> scores[i][j];		// 2�����迭�� ���� ����.
		}
	}

	// �� �л� �� ���� ����� ���� ���� for��
	for (int i = 0; i < STUDENT; i++) {
		cout << studentNames[i] << "�� ��� ������ ";
		
		double sum = 0;				// �� �л��� 3���� ������ ���� ������ ����
		double average = 0;			// �� �л��� 3���� ����� ������ ����

		// ���� ����ŭ for���� ������ sum�� �ش� ���� ������ ���ϴ� for��
		for (int j = 0; j < SUBJECT; j++) {
			sum += scores[i][j];
		}

		// ���� ������ ���� �� ��ŭ ������ ����� ����.
		average = sum / SUBJECT;

		// ��� ���.
		cout << average << "�Դϴ�." << endl;
	}

	return 0;
}