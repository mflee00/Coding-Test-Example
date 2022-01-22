// 바이러스 다이나믹.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>

using namespace std;

int d[100];
int k = 0;
int p = 0;
int n = 0;


int dp(int x) 
{
	if (x == 1) return k*p;

	if (d[x] != 0)  return d[x];

	return d[x] = p * dp(x-1) ;
}

int main(void) 
{
	cin >> k >> p >> n;

	printf("%d", dp(n) % 1000000007);
}