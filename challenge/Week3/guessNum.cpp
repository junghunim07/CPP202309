#include <iostream>
#include <time.h>

using namespace std;

int main() {
	// random �Լ� ���� ����
	srand(time(NULL));

	// ����
	int answer = rand() % 100;
	// �õ� Ƚ�� �����ϴ� ����
	int tries = 0;

	// ����� �Է� �����ϱ� ���� ����
	int guess;

	// ���� ���θ� �õ��� �ݺ���
	do {
		// "������ �����Ͽ� ���ÿ� : "�� ���.
		cout << "������ �����Ͽ� ���ÿ� : ";
		cin >> guess;		// ����� �Է°� ����.
		tries++;			// Ƚ�� ����.
		
		// ����� ���� �亸�� �۴ٸ�
		if (guess < answer)
			// "������ ������ �����ϴ�."�� ���,
			cout << "������ ������ �����ϴ�." << endl;
		// �׷��� �ʴٸ�
		else
			// "������ ������ �����ϴ�."�� ���,
			cout << "������ ������ �����ϴ�." << endl;

		// ���� ���ٸ�
		if (guess == answer)
			break;		// �ݺ����� ���� ����.
	} 
	while (true);

	// "�����մϴ�. �õ�Ƚ�� = " �õ� Ƚ�� ���.
	cout << "�����մϴ�. �õ� Ƚ�� = " << tries << endl;
	
	return 0;
}