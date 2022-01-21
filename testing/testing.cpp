// testing.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string a[20000];
int n;

//문자열 정렬 길이가 짧은것 우선 순위로 출력
//길이가 같으면 사전순으로 정렬함.

bool compare(string a, string b)
{
	//길이가 짧은 순서 우선
	if (a.length() < b.length())
	{
		return 1;
	}
	else if (a.length() > b.length())
	{
		return 0;
	}
	//길이가 같은 경우라면
	else
	{
		return a < b; // 사전순으로 정렬
	}
}


int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n, compare);
	for (int i = 0; i < n; i++)
	{
		if (i > 0 && a[i] == a[i + 1])
		{
			continue;
		}
		else
		{
			cout << a[i] << '\n';
		}
		
	}
    
}
