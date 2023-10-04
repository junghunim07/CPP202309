#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
	const int numCell = 10;				// 갯수
	int numList[numCell][numCell];		// 난수 저장할 2차원 배열

	// 난수 생성 및 2차원 배열에 저장하기 위한 2중 for문
	for (int i = 0; i < numCell; i++) {
		for (int j = 0; j < numCell; j++) {
			// 난수가 0 ~ 999사이의 난수를 생성하기 위해 % 1000을 함.
			numList[i][j] = rand() % 1000 + 1;

			cout << i << ", " << j << " : " << numList[i][j] << endl;
		}
	}

	cout << endl;

	int max;				// 큰 값 저장을 위한 변수
	int maxI;				// 큰 값이 있는 i를 저장하기 위한 변수
	int maxJ;				// 큰 값이 있는 j를 저장하기 위한 변수

	// max의 값을 List의 첫번째 값으로 설정.
	max = numList[0][0];

	// 큰 값의 위치와 그 값을 찾기 위한 2중 for문
	for (int i = 0; i < numCell; i++) {
		int j = 0;			// 해당 위치를 찾기 위해서 j변수를 생성.

		// 한 줄씩 탐사하기 위해 numList[i]
		for (auto elem : numList[i]) {
			// elem이 max보다 크면
			if (elem > max) {
				max = elem;		// max의 값을 변경
				maxI = i;		// maxI에 i의 값 저장.
				maxJ = j;		// maxJ에 j의 값 저장.
			}
			j++;				// 한번 동작할 때마다 j값 증가.
		}
	}

	// 출력 조건에 맞게 출력하기 위한 cout문
	cout << "가장 큰 값은 " << max << "이고,";
	cout << "i와 j는 각각 " << maxI << ", " << maxJ << "입니다. " << endl;
	cout << "검증 결과 : " << numList[maxI][maxJ] << endl;

	return 0;
}