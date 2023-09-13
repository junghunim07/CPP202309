#include <iostream>

using namespace std;

int main() {
	// H는 int로 C는 double로 생성.
	int H;
	double C;

	// "화씨온도 : "를 출력
	cout << "화씨온도 : ";
	// 입력받은 값을 H에 저장.
	cin >> H;
	
	// C에 입력받은 H값을 이용하여 (5.0 / 9.0) * (H - 32)를 저장.
	C = (5.0 / 9.0) * (H - 32);

	// "섭씨온도 = C값"을 출력.
	cout << "섭씨온도 = " << C << endl;
}