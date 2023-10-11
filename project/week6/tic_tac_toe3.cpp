#include <iostream>

using namespace std;

int main() {
	const int numCell = 3;
	char board[numCell][numCell];
	int x, y;	// 사용자에게 입력받는 x, y 좌표를 저장할 변수

	// 보드판 초기화
	for (x = 0; x < numCell; x++) {
		for (y = 0; y < numCell; y++) {
			board[x][y] = ' ';
		}
	}

	int k = 0;					// 누구 차례인지 체크하기 위한 변수
	char currentUser = 'X';		// 현재 유저의 돌을 저장하기 위한 문자 변수

	// 유저 3번을 'A'로 생성.
	while (true) {
		int user = k % 3 + 1;	// 유저 번호를 표시할 변수.
		// 1. 누구 차례인지 출력
		switch (k % 3) {
		case 0:
			cout << user << "번 유저(X)의 차례입니다 -> ";
			currentUser = 'X';
			break;
		case 1:
			cout << user << "번 유저(O)의 차례입니다 -> ";
			currentUser = 'O';
			break;
		case 2:
			cout << user << "번 유저(A)의 차례입니다 -> ";
			currentUser = 'A';
			break;
		}

		// 2. 좌표 입력 받기
		cout << "(x, y) 좌표를 입력하세요: ";
		cin >> x >> y;

		// 3. 입력받은 좌표의 유효성 체크
		if (x >= numCell || y >= numCell) {
			cout << x << ", " << y << ": ";
			cout << " x 와 y 둘 중 하나가 칸을 벗어납니다." << endl;
			continue;
		}

		if (board[x][y] != ' ') {
			cout << x << ", " << y << ": 이미 돌이 차있습니다." << endl;
			continue;
		}

		// 4. 입력받은 좌표에 현재 유저의 돌 놓기
		board[x][y] = currentUser;

		// 5. 현재 보드 판 출력
		for (int i = 0; i < numCell; i++) {
			cout << "---|---|---" << endl;
			for (int j = 0; j < numCell; j++) {
				cout << board[i][j];
				if (j == numCell - 1) {
					break;
				}

				cout << "  |";
			}
			cout << endl;
		}

		cout << "---|---|---" << endl;

		// 게임이 끝났는지 판단하기 위한 tmp변수
		int tmp = 0;

		// 빙고가 됐는지 확인하기 위한 for문
		for (int i = 0; i < numCell; i++) {
			// 가로가 같은 돌이 한줄로 다 놓였을 경우
			if ((board[i][0] == board[i][1]) && (board[i][0] == board[i][2])) {
				if (board[i][0] != ' ') {
					cout << "가로에 모두 돌이 놓였습니다!: " << user << "번 유저(" << board[i][0] << ")의 승리입니다.";
					tmp = 1;		// 게임을 끝내기 위해서 tmp변수를 1로 초기화.
					break;
				}
			}
			// 세로가 같은 돌로 한줄로 다 놓였을 경우
			else if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && (board[0][i] == board[2][i])) {
				if (board[0][i] != ' ') {
					cout << "세로에 모두 돌이 놓였습니다!: " << user << "번 유저(" << board[0][i] << ")의 승리입니다.";
					tmp = 1;		// 게임을 끝내기 위해서 tmp변수를 1로 초기화.
					break;
				}
			}
			// 대각선을 확인하기 위한 if문
			// 배열의 범위를 벗어나지 않기 위해.
			// 오른쪽 대각선
			if (i == 0) {
				// 왼쪽 위에서 오른쪽 아래 대각선으로 모두 같은 돌로 한줄로 놓였을 경우
				if (board[i][0] == board[i + 1][1] && board[i][0] == board[i + 2][2]) {
					if (board[i][0] != ' ') {
						cout << "왼쪽 위에서 오른쪽 아래 대각선으로 모두 돌이 놓였습니다!: " << user << "번 유저(" << board[0][i] << ")의 승리입니다.";
						tmp = 1;	// 게임을 끝내기 위해서 tmp변수를 1로 초기화.
						break;
					}
				}
			}
			// 왼쪽 대각선
			else if (i == 2) {
				// 오른쪽 위에서 왼쪽 아래 대각선으로 모두 같은 돌로 한줄로 놓였을 경우
				if (board[0][i] == board[1][i - 1] && board[0][i] == board[2][i - 2]) {
					if (board[0][i] != ' ') {
						cout << "오른쪽 위에서 왼쪽 아래 대각선으로 모두 돌이 놓였습니다!: " << user << "번 유저(" << board[0][i] << ")의 승리입니다.";
						tmp = 1;	// 게임을 끝내기 위해서 tmp변수를 1로 초기화.
						break;
					}
				}
			}
		}

		k++;

		// tmp가 1이라면 게임이 끝났음을 알리기 위해
		if (tmp == 1)
			break;

		// 보드판에 모든 돌이 찼을 경우
		if (k == 9) {
			cout << "모든 칸이 다 찼습니다. 종료합니다.";
			break;
		}
	}

	return 0;
}