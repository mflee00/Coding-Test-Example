// testing_3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include "stdio.h"



//N개의 수가 주어졌을때, 오름차순 정렬
// 1 <= N <= 10,000,000
/*
10
5
2
3
1
4
2
3
5
1
7

*/


int n;
int a[100001];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		a[x]++;
	}
	for (int i = 0; i < 10001; i++)
	{
		while (a[i] != 0)
		{
			printf("%d\n", i);
			a[i]--;
		}
	}
}
