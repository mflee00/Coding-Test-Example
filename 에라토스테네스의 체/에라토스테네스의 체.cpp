// 에라토스테네스의 체.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "stdio.h"
#include "math.h"


bool isPrimeNumber(int x)
{
	for (int i = 2; i < x; i++)
	{
		if (x%i == 0) return false;
	}
	return true;
}

bool isPrimeNumber2(int x)
{
	int end = (int)sqrt(x);
	for (int i = 2; i < end; i++)
	{
		if (x%i == 0) return false;
	}
	return true;
}

int number = 10000;
int a[100001];

void primeNumverSieve()
{
	for (int i = 2; i <= number; i++)
	{
		a[i] = i;
	}
	for (int i = 2; i <= number; i++)
	{
		if (a[i] == 0) continue;
		for (int j = i + i; j <= number; j += i)
		{
			a[j] = 0;
		}
	}
	for (int i = 2; i <= number; i++)
	{
		if (a[i] != 0) printf("%d ", a[i]);
	}
}




int main()
{
	//printf("%d", isPrimeNumber2(97));
	primeNumverSieve();
	return 0;
}

