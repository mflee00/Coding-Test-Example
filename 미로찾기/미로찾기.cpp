// 미로찾기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <stdio.h>
using namespace std;

/*

4 6
101111
101010
101111
111011

*/

int N, M;
char Map[101][101]; // 맵
int Visit[101][101]; // 방문 표시
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int Min = 10001;

void DFS(int x, int y, int depth)
{

	if (x < 0 || y < 0 || x >= N || y >= M) return;   //맵의 범위를 벗어 날때
	if (x == N - 1 && y == M - 1)    //도착할때
	{
		if (depth < Min)
			Min = depth;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int Next_x = x + dx[i];
		int Next_y = y + dy[i];
		if (Visit[Next_x][Next_y] == 0 && Map[Next_x][Next_y] == '1')
		{
			Visit[Next_x][Next_y] = 1;
			DFS(Next_x, Next_y, depth + 1);
			Visit[Next_x][Next_y] = 0;
		}
	}

}

int main(void)
{
	scanf("%d %d", &N, &M);    //N세로 M가로

	for (int i = 0; i < N; i++)
	{
		scanf("%s", Map[i]);
	}

	DFS(0, 0, 1);
	printf("%d\n", Min);
}
