// 타일링 문제2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <stdio.h>


//2*n 직사각형을 2*1 2*2 타일로 채우는 방법의 수를 구하는 프로그램




int d[1001];

int dp(int x)
{
	if (x == 1)  return 1;
	if (x == 2)  return 3;
	if (d[x] != 0)  return d[x];

	return d[x] = (dp(x - 1) + (2 * dp(x - 2)) ) % 10007;
}

int main()
{
	int x;
	scanf("%d", &x);

	printf("%d\n", dp(x));
}

