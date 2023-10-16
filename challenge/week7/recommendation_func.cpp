#include <iostream>

using namespace std;

const int NUM_USERS = 3;
const int NUM_ITEMS = 3;
int userPreferences[NUM_USERS][NUM_ITEMS];	// ������ ��ȣ���� ������ �Է¹��� 2���� �迭

// ����ڿ��� ��ȣ���� �Է¹޴� �Լ�
void initializePreferences() {
	for (int i = 0; i < NUM_USERS; ++i) {
		cout << "����� " << (i + 1) << "�� ��ȣ���� �Է��ϼ��� (";
		cout << NUM_ITEMS << "���� �׸� ����): ";

		// �Ű����� preferences�� ���� -> userPreferences�� �����̶� ����
		for (int j = 0; j < NUM_ITEMS; ++j) {
			cin >> userPreferences[i][j];
		}
	}
}

// �Է¹��� ��ȣ�� �߿��� ���� ū ���� ����ϴ� �Լ�
void findRecommendedItems() {
	for (int i = 0; i < NUM_USERS; ++i) {
		int maxPreferenceIndex = 0;			// �ʱⰪ ����

		// �ʱⰪ�� �� ���� ������ ���ؼ� ���� ���� �� ũ�ٸ� 
		// maxPreferenceIndext�� ���� �ʱ�ȭ �ϴ� for��
		for (int j = 1; j < NUM_ITEMS; ++j) {
			if (userPreferences[i][j] > userPreferences[i][maxPreferenceIndex]) {
				maxPreferenceIndex = j;
			}
		}

		cout << "����� " << (i + 1) << "���� ��õ�ϴ� �׸�: ";
		cout << (maxPreferenceIndex + 1) << endl;
	}
}

int main() {
	// ����ڿ��� ��ȣ���� �Է¹޴� �Լ� ȣ��
	initializePreferences();
	// �Է¹��� ��ȣ�� �߿��� ���� ū ���� ����ϴ� �Լ� ȣ��
	findRecommendedItems();

	return 0;
}