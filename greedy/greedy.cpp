// greedy.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

int main(void) {
	int n, result = 0;
	cin >> n;
	result += n / 500;
	n %= 500;
	result += n / 100;
	n %= 100;
	result += n / 50;
	n %= 50;
	result += n / 10;
	cout << result;
	return 0;
}