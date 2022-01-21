// testing_2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 모든 시리얼 번호는 알파벳 대문자 (a-z)와 숫자 (0-9)로 이루어짐
// 시리얼 번호 A가 시리얼번호 B의 앞에 오는 경우
// 1. A와 B의 길이가 다르면, 짧은 것이 먼저온다.
// 2. 만약 서로 길이가 같으면, A의 모든 자리수의 합과 B의 모든 자리수의 합을 비교해서 작은 합을 가지는 것이
//    먼저온다(숫자인 것만 더한다.)
// 3. 만약 1,2번 둘 조건으로도 비교할 수 없으면, 사전순으로 비교한다. 숫자가 알파벳보다 서전순으로 작다.
/*
5
ABCD
145C
A
A910
Z321
*/

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string a[20000];
int n;

int getSum(string a)
{
	int length = a.length(), sum = 0;
	for (int i = 0; i < length; i++)
	{
		//숫자인 경우에만 더함.
		if (a[i] - '0' <= 9 && a[i] - '0' >= 0)
		{
			sum += (a[i] - '0');
		}
	}
	return sum;
}

bool compare(string a, string b)
{
	//길이가 짧은 순서 우선
	//if (a.length() < b.length())
	//{
	//	return 1;
	//}
	//else if (a.length() > b.length())
	//{
	//	return 0;
	//}
	if (a.length() != b.length()) {
		return a.length() < b.length();
	}
	//길이가 같은 경우라면
	else
	{
		int aSum = getSum(a);
		int bSum = getSum(b);
		//글자에 포함된 숫자의 합이 다르다면
		if (aSum != bSum)
		{
			return aSum < bSum;
		}
		else
		{
			return a < b; // 사전순으로 정렬
		}

		
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
		cout << a[i] << endl;
	}

}
