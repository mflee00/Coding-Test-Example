// 8.counting_sort.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <stdio.h>

int main()
{
	int temp;
	int count[5];
	int array[30] = { 
		1,3,2,4,3,2,5,3,1,2,
		3,4,4,3,5,1,2,3,5,2,
		3,1,4,3,5,1,2,1,1,1 };
	for (int i = 0; i < 5; i++)	{
		count[i] = 0;
	}

	for (int i = 0; i < 30; i++)	{
		count[array[i] - 1]++;
	}

	for (int i = 0; i < 5; i++) {
		if (count[i] != 0)
		{
			for (int j = 0; j < count[i]; j++) {
				printf("%d ", i+1 );
			}
		}
		
	}
}