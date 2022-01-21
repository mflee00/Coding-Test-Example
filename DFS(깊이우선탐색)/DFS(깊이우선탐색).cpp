// DFS(깊이우선탐색).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stack>
#include <vector>

using namespace std;
//스택 사용

int number = 7;
int d[7];
int c[7];
vector<int> a[8];

#if 1
void dfs(int x)
{

	if(c[x])  return;
	c[x] = true;
	cout << x << ' ';
	for (int i = 0; i < a[x].size(); i++)
	{
		int y = a[x][i];
		dfs(y);
	}
}
#else
bool dfs(int x)
{
	// 연결된 모든 노드에 대해서 들어갈 수 있는지 시도 
	for (int i = 0; i < a[x].size(); i++) {
		int t = a[x][i];
		// 이미 처리한 노드는 더 이상 볼 필요가 없음 
		if (c[t]) continue;
		c[t] = true; // 방문 처리
		// 비어있거나 점유 노드에 더 들어갈 공간이 있는 경우 
		if (d[t] == 0 || dfs(d[t])) {
			d[t] = x;
			return true;
		}
	}
	return false;
}
#endif
int main()
{
	a[1].push_back(2);
	a[2].push_back(1);

	a[1].push_back(3);
	a[3].push_back(1);

	a[2].push_back(3);
	a[3].push_back(2);

	a[2].push_back(4);
	a[4].push_back(3);

	a[2].push_back(5);
	a[5].push_back(2);

	a[3].push_back(6);
	a[6].push_back(3);

	a[3].push_back(7);
	a[7].push_back(3);

	a[4].push_back(5);
	a[5].push_back(4);

	a[6].push_back(7);
	a[7].push_back(6);

	dfs(1);
}
