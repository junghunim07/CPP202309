#include <iostream>
#include <string>
using namespace std;

bool checkNumber(int first, int second, int third);
int checkStrike(int firstNum, int secondNum, int thirdNum, int guessFirst, int guessSecond, int guessThird);
int checkBall(int firstNum, int secondNum, int thirdNum, int guessFirst, int guessSecond, int guessThird);

int main() {
	int randomNum; // ����� �ϴ� 3�ڸ����� ���� ���� ����
	int firstNum; // ������ ù��° �ڸ���
	int secondNum; // ������ �ι�° �ڸ���
	int thirdNum; // ������ ����° �ڸ���

	while (1) {
		randomNum = rand() % 900 + 100; // ������ 3�ڸ��� ����

		bool same = false; // ��� ���� �ٸ� ��� true�� ���� ����

		// TODO 1: 3�ڸ� ������ �ڸ����� �����ϰ�, ��� ���� �ٸ��� üũ�ϴ� �ڵ��� �ۼ�
		firstNum = randomNum / 100;
		randomNum %= 100;
		secondNum = randomNum / 10;
		randomNum %= 10;
		thirdNum = randomNum;

		same = checkNumber(firstNum, secondNum, thirdNum);

		if (same == true) {
			break;
		}
	}

	int turn = 0;
	while (1) {
		cout << turn + 1 << "��° �õ��Դϴ�. " << endl;

		int userNumber; // ����ڰ� �Է��� ���ڸ��� ���� ����
		int guessFirst; // ������ ������ ù��° �ڸ���
		int guessSecond; // ������ ������ �ι�° �ڸ���
		int guessThird; // ������ ������ ����° �ڸ���


		// ����ڿ��� ���ڸ� ���� �Է¹޴� �ڵ� ���
		while (1) {
			cout << "���ڸ� ���� �Է����ּ���: ";
			cin >> userNumber;

			bool same = false; // ��� ���� �ٸ� ��� true�� ���� ����
			// TODO 1: 3�ڸ� ������ �ڸ����� �����ϰ�, ��� ���� �ٸ��� üũ�ϴ� �ڵ��� �ۼ�


			if (to_string(userNumber).length() != 3) {
				cout << "�Էµ� ���ڰ� 3�ڸ� ���� �ƴմϴ�. �ٽ� �Է��ϼ���." << endl;
				continue;
			}

			guessFirst = userNumber / 100;
			userNumber %= 100;
			guessSecond = userNumber / 10;
			userNumber %= 10;
			guessThird = userNumber;

			same = checkNumber(guessFirst, guessSecond, guessThird);

			if (same == true) {
				break;
			}
		}


		int strike = checkStrike(firstNum, secondNum, thirdNum, guessFirst, guessSecond, guessThird); // ��Ʈ����ũ ������ �����ϴ� ����
		int ball = checkBall(firstNum, secondNum, thirdNum, guessFirst, guessSecond, guessThird); // �� ������ �����ϴ� ����

		// TODO 2: ����� ������ ������ �ڸ����� ���ڸ� ���ϸ� ��Ʈ�� �ֱ� ���� �ڵ��� �ۼ�
		/*if (firstNum == guessFirst) {
			strike++;
		}
		else if ((firstNum != guessFirst) && ((guessFirst == secondNum) || (guessFirst == thirdNum))) {
			ball++;
		}

		if (secondNum == guessSecond) {
			strike++;
		}
		else if ((secondNum != guessSecond) && ((guessSecond == firstNum) || (guessSecond == thirdNum))) {
			ball++;
		}

		if (thirdNum == guessThird) {
			strike++;
		}
		else if ((thirdNum != guessThird) && ((guessThird == firstNum) || (guessThird == secondNum))) {
			ball++;
		}*/


		cout << userNumber << "�� ��� : " << strike << " ��Ʈ����ũ, " << ball << "�� �Դϴ�." << endl;

		if (strike == 3) {
			cout << "������ ������ϴ�. �����մϴ�.";
			break;
		}

		turn += 1;
	}

	return 0;
}

bool checkNumber(int first, int second, int third) {
	if ((first != second) && (first != third) && (second != third)) {
		return true;
	}

	return false;
}

int checkStrike(int firstNum, int secondNum, int thirdNum, int guessFirst, int guessSecond, int guessThird) {
	int strike = 0;

	if (firstNum == guessFirst) {
		strike++;
	}
	if (secondNum == guessSecond) {
		strike++;
	}
	if (thirdNum == guessThird) {
		strike++;
	}

	return strike;
}

int checkBall(int firstNum, int secondNum, int thirdNum, int guessFirst, int guessSecond, int guessThird) {
	int ball = 0;

	if ((firstNum != guessFirst) && ((guessFirst == secondNum) || (guessFirst == thirdNum))) {
		ball++;
	}
	if ((secondNum != guessSecond) && ((guessSecond == firstNum) || (guessSecond == thirdNum))) {
		ball++;
	}
	if ((thirdNum != guessThird) && ((guessThird == firstNum) || (guessThird == secondNum))) {
		ball++;
	}

	return ball;
}