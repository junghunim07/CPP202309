#include <iostream>

using namespace std;

const int NUM_USERS = 3;
const int NUM_ITEMS = 3;
int userPreferences[NUM_USERS][NUM_ITEMS];	// 유저의 선호도를 저장할 입력받을 2차원 배열

// 사용자에게 선호도를 입력받는 함수
void initializePreferences() {
	for (int i = 0; i < NUM_USERS; ++i) {
		cout << "사용자 " << (i + 1) << "의 선호도를 입력하세요 (";
		cout << NUM_ITEMS << "개의 항목에 대해): ";

		// 매개변수 preferences에 저장 -> userPreferences에 저장이랑 같음
		for (int j = 0; j < NUM_ITEMS; ++j) {
			cin >> userPreferences[i][j];
		}
	}
}

// 입력받은 선호도 중에서 가장 큰 값을 출력하는 함수
void findRecommendedItems() {
	for (int i = 0; i < NUM_USERS; ++i) {
		int maxPreferenceIndex = 0;			// 초기값 설정

		// 초기값과 그 다음 값들을 비교해서 다음 값이 더 크다면 
		// maxPreferenceIndext의 값을 초기화 하는 for문
		for (int j = 1; j < NUM_ITEMS; ++j) {
			if (userPreferences[i][j] > userPreferences[i][maxPreferenceIndex]) {
				maxPreferenceIndex = j;
			}
		}

		cout << "사용자 " << (i + 1) << "에게 추천하는 항목: ";
		cout << (maxPreferenceIndex + 1) << endl;
	}
}

int main() {
	// 사용자에게 선호도를 입력받는 함수 호출
	initializePreferences();
	// 입력받은 선호도 중에서 가장 큰 값을 출력하는 함수 호출
	findRecommendedItems();

	return 0;
}