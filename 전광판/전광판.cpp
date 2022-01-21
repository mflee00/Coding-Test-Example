// 전광판.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>


using namespace std;

int n;
int rootup_table[12][7] =
{
	{1,2,3,5,6,7,-1},//0
	{3,6,-1,-1,-1,-1,-1},//1
	{1,3,4,5,7,-1,-1},//2
	{1,3,4,6,7,-1,-1},//3
	{2,3,4,6,-1,-1,-1},//4
	{1,2,4,6,7,-1,-1},//5
	{1,2,4,5,6,7,-1},//6
	{1,2,3,6,-1,-1,-1},//7
	{1,2,3,4,5,6,7},//8
	{1,2,3,4,6,7,-1},//9
	{1,2,3,4,5,6,-1},//A
	{1,2,3,4,5,6,7} //B
};
int cnt[5][10];
vector<int> toggle_number[2];
int toggle_number2[5][7];
vector<pair<string,string>> number;

void check_cnt_sort(int num, int index)
{
	int* _num = rootup_table[num];

	for (int i = 0; i < 7; i++)
	{
		if (_num[i] == -1) continue;

		if (cnt[index][_num[i]] > 0)
		{
			cnt[index][_num[i]]--;
		}
		else
		{
			cnt[index][_num[i]]++;
		}
	}
#if 0
	cout << num << " "<<index << " ";
	for (int i = 0; i < 10; i++)
	{
		cout << cnt[index][i];
	}
	cout << endl;
#endif
}
int counting_toggle()
{
	int re = 0;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (cnt[i][j] > 0) { re++; }
		}
	}
	return re;
}


int main(int argc, char** argv)
{
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		string num1, num2;
		string temp;

		cin >> num1 >> num2;

		if (stoi(num1) < stoi(num2) ) {
			swap(num1, num2);
		}
		number.push_back(make_pair(num1,num2));
	}
	
	

	for (int i = 0; i < n; i++)
	{	
		string num1 = number[i].first;
		string num2 = number[i].second;
		int size1 = num1.size();
		int size2 = num2.size();
		int diff = size1-size2;
		

		for (int j = 0; j < size1; j++)
		{
			toggle_number[0].push_back(num1[j] - '0');
			check_cnt_sort(toggle_number[0][j], j);
		}

		for (int j = 0; j < size2; j++)
		{
			toggle_number[1].push_back(num2[j] - '0');
			check_cnt_sort(toggle_number[1][j], diff+j);
		}

		
		
		
		cout << counting_toggle()<<endl;		
		//memset(cnt, 0x00, 5 * 10 * 4);
		fill(&cnt[0][0], &cnt[4][10], 0);
		toggle_number[0].clear();
		toggle_number[1].clear();
	}

	return 0;
}