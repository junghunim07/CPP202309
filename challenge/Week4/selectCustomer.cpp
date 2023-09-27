#include <iostream>
#include <string>

using namespace std;

int main() {
	// �ִ� �ο� ���� ������ ����.
	const int maxPeople = 3;
	// cout << "�� ���� ���� �Է��϶� : ";
	// cin >> maxPeople;

	string names[maxPeople];		// ������� �̸��� ������ �迭
	int ages[maxPeople];			// ������� ���̸� ������ �迭
	
	// ������� �̸��� ���̸� �Է¹��� �ݺ���
	for (int i = 0; i < maxPeople; i++) {
		cout << "��� " << i + 1 << "�� �̸� : ";
		cin >> names[i];
		cout << "��� " << i + 1 << "�� ���� : ";
		cin >> ages[i];
	}

	int ageThreshold;				// Ư�� ������ ���� ������ ����
	int tmp = 0;					// Ư�� ������ ����� ������ ���θ� �Ǵ��� ����
	
	// "Ư�� ���� �̻��� ����� ã������ ���̸� �Է��ϼ��� : "���
	cout << "Ư�� ���� �̻��� ����� ã������ ���̸� �Է��ϼ��� : ";
	cin >> ageThreshold;			// ageThreshold�� �Է¹��� �� ����.

	// "Ư�� ���� �̻��� ���� : "�� ���
	cout << ageThreshold << "�� �̻��� ���� : \n";

	// Ư�� ���� �̻��� ������ Ȯ���ϱ� ���� for��
	for (int i = 0; i < maxPeople; i++) {
		// Ư�� ���� �̻��̶��
		if (ages[i] > ageThreshold) {
			// ���� (�̸�) ���.
			cout << names[i] << " (" << ages[i] << ")";
			tmp = 1;			// �����Ѵٴ� �ǹ�.
		}
	}

	// Ư�� ���� �̻��� ����� ���ٸ�
	if (tmp == 0) {
		// "Ư�� ���� �̻��� ���̸� ���� ���� �����ϴ�."�� ���
		cout << ageThreshold << "�̻��� ���̸� ���� ���� �����ϴ�";
	}

	return 0;
}