// knuth-morris-pratt.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>

using namespace std;


int findString(string parent, string pattern)
{
	int parentSize  = parent.size();
	int patternSize = pattern.size();
	for (int i = 0; i <= parentSize - patternSize; i++)
	{
		bool finded = true;
		for (int j = 0; j < patternSize; j++)
		{
			if (parent[i + j] != pattern[j])
			{
				finded = false;
				break;
			}
		}
		if (finded)
		{
			return i;
		}
	}
	return -1;
}

int main()
{
	string parent = "Hello World";
	string pattern = "llo W";
	int result = findString(parent, pattern);
	if (result == -1)
	{
		printf("찾을수 없음\n");
	}
	else
	{
		printf("%d번째 찾음\n", result+1);
	}
}

