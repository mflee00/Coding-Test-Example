// 6.cpp_STL_sort_2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


using namespace std;


bool compare(pair<string, pair<int, int>> a,
	pair<string, pair<int, int>> b)
{
	if (a.second.first == b.second.first)
	{
		return a.second.second > b.second.second;
	}
	else
	{
		return a.second.first > b.second.first;
	}
}


int main()
{
	vector<pair<string, pair<int, int>>> v;

	v.push_back(pair<string, pair<int, int>>("박한울",pair<int,int>(90,19961222)));
	v.push_back(pair<string, pair<int, int>>("이태일",pair<int,int>(80,19951222)));
	v.push_back(pair<string, pair<int, int>>("나동빈",pair<int,int>(50,19941222)));
	v.push_back(pair<string, pair<int, int>>("강종구",pair<int,int>(90,19931222)));
	v.push_back(pair<string, pair<int, int>>("이상욱",pair<int,int>(70,19921222)));

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i].first << " ";
	}

    
	
}
