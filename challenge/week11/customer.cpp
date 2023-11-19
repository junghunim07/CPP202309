#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	// 최대 인원 수를 저장할 변수.
	int maxPeople;
	cout << "총 고객의 수를 입력하라 : ";
	cin >> maxPeople;

	vector<string> names;		// 사람들의 이름을 저장할 배열
	vector<int> ages;			// 사람들의 나이를 저장할 배열

	// 사람들의 이름과 나이를 입력받을 반복문
	for (int i = 0; i < maxPeople; i++) {
		string name;
		int age;
		cout << "사람 " << i + 1 << "의 이름 : ";
		cin >> name;
		names.push_back(name);
		cout << "사람 " << i + 1 << "의 나이 : ";
		cin >> age;
		ages.push_back(age);
	}

	int ageThreshold;				// 특정 나이의 값을 저장할 변수
	int tmp = 0;					// 특정 나이의 사람이 존재할 여부를 판단할 변수

	// "특정 나이 이상인 사람을 찾으려면 나이를 입력하세요 : "출력
	cout << "특정 나이 이상인 사람을 찾으려면 나이를 입력하세요 : ";
	cin >> ageThreshold;			// ageThreshold에 입력받은 값 저장.

	// "특정 나이 이상인 고객들 : "을 출력
	cout << ageThreshold << "세 이상인 고객들 : \n";

	// 특정 나이 이상인 고객들을 확인하기 위한 for문
	for (int i = 0; i < maxPeople; i++) {
		// 특정 나이 이상이라면
		if (ages[i] > ageThreshold) {
			// 나이 (이름) 출력.
			cout << names[i] << " (" << ages[i] << "세)\n";
			tmp = 1;			// 존재한다는 의미.
		}
	}

	// 특정 나이 이상인 사람이 없다면
	if (tmp == 0) {
		// "특정 나이 이상의 나이를 가진 고객이 없습니다."를 출력
		cout << ageThreshold << "이상의 나이를 가진 고객이 없습니다";
	}

	return 0;
}