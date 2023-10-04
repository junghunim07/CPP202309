#include <iostream>
#include <string>

using namespace std;

int main() {
	const int STUDENT = 5;				// 학생 수
	const int SUBJECT = 3;				// 과목 수
	int scores[STUDENT][SUBJECT];		// 그 학생의 해당 과목 점수를 저장할 2차원 배열.

	// 학생 배열
	string studentNames[STUDENT] = { "영수", "영희", "철수", "미미", "쥬쥬" };
	// 과목 배열
	string subjectNames[SUBJECT] = { "수학", "영어", "CPP" };

	// 각 학생의 각 과목별 점수를 입력받기 위한 2중 for문
	for (int i = 0; i < STUDENT; i++) {
		cout << studentNames[i] << "의 성적을 하나씩 입력하세요." << endl;

		// 한 학생 당 과목 별 점수를 입력받기 위한 for문
		for (int j = 0; j < SUBJECT; j++) {
			cout << subjectNames[j] << " : ";
			cin >> scores[i][j];		// 2차원배열에 점수 저장.
		}
	}

	// 각 학생 별 과목 평균을 내기 위한 for문
	for (int i = 0; i < STUDENT; i++) {
		cout << studentNames[i] << "의 평균 점수는 ";
		
		double sum = 0;				// 각 학생별 3과목 점수의 합을 저장할 변수
		double average = 0;			// 각 학생별 3과목 평균을 저장할 변수

		// 과목 수만큼 for문을 돌려서 sum에 해당 과목 점수를 합하는 for문
		for (int j = 0; j < SUBJECT; j++) {
			sum += scores[i][j];
		}

		// 과목 총합을 과목 수 만큼 나눠서 평균을 구함.
		average = sum / SUBJECT;

		// 평균 출력.
		cout << average << "입니다." << endl;
	}

	return 0;
}