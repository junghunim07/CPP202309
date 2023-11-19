#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	// �ִ� �ο� ���� ������ ����.
	int maxPeople;
	cout << "�� ���� ���� �Է��϶� : ";
	cin >> maxPeople;

	vector<string> names;		// ������� �̸��� ������ �迭
	vector<int> ages;			// ������� ���̸� ������ �迭

	// ������� �̸��� ���̸� �Է¹��� �ݺ���
	for (int i = 0; i < maxPeople; i++) {
		string name;
		int age;
		cout << "��� " << i + 1 << "�� �̸� : ";
		cin >> name;
		names.push_back(name);
		cout << "��� " << i + 1 << "�� ���� : ";
		cin >> age;
		ages.push_back(age);
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
			cout << names[i] << " (" << ages[i] << "��)\n";
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