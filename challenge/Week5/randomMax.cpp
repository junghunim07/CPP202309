#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
	const int numCell = 10;				// ����
	int numList[numCell][numCell];		// ���� ������ 2���� �迭

	// ���� ���� �� 2���� �迭�� �����ϱ� ���� 2�� for��
	for (int i = 0; i < numCell; i++) {
		for (int j = 0; j < numCell; j++) {
			// ������ 0 ~ 999������ ������ �����ϱ� ���� % 1000�� ��.
			numList[i][j] = rand() % 1000 + 1;

			cout << i << ", " << j << " : " << numList[i][j] << endl;
		}
	}

	cout << endl;

	int max;				// ū �� ������ ���� ����
	int maxI;				// ū ���� �ִ� i�� �����ϱ� ���� ����
	int maxJ;				// ū ���� �ִ� j�� �����ϱ� ���� ����

	// max�� ���� List�� ù��° ������ ����.
	max = numList[0][0];

	// ū ���� ��ġ�� �� ���� ã�� ���� 2�� for��
	for (int i = 0; i < numCell; i++) {
		int j = 0;			// �ش� ��ġ�� ã�� ���ؼ� j������ ����.

		// �� �پ� Ž���ϱ� ���� numList[i]
		for (auto elem : numList[i]) {
			// elem�� max���� ũ��
			if (elem > max) {
				max = elem;		// max�� ���� ����
				maxI = i;		// maxI�� i�� �� ����.
				maxJ = j;		// maxJ�� j�� �� ����.
			}
			j++;				// �ѹ� ������ ������ j�� ����.
		}
	}

	// ��� ���ǿ� �°� ����ϱ� ���� cout��
	cout << "���� ū ���� " << max << "�̰�,";
	cout << "i�� j�� ���� " << maxI << ", " << maxJ << "�Դϴ�. " << endl;
	cout << "���� ��� : " << numList[maxI][maxJ] << endl;

	return 0;
}