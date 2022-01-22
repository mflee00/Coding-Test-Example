
// 다이나믹프로그램.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <stdio.h>

int d[100];

int dp(int x) {
	if (x == 1) return 1;
	if (x == 2) return 1;
	
	if (d[x] != 0)  return d[x];

	return d[x] = dp(x - 1) + dp(x - 2);
}

int main(void) {
	printf("%d", dp(30));
}