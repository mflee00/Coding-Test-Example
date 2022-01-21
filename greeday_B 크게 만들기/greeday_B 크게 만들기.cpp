// greeday_B 크게 만들기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
/*
문제
N자리 숫자가 주어졌을 때, 여기서 숫자 K개를 지워서 얻을 수 있는 가장 큰 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N과 K가 주어진다. (1 ≤ K < N ≤ 500,000)

둘째 줄에 N자리 숫자가 주어진다. 이 수는 0으로 시작하지 않는다.

출력
입력으로 주어진 숫자에서 K개를 지웠을 때 얻을 수 있는 가장 큰 수를 출력한다.

예제 입력 1
4 2
1924
예제 출력 1
94

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, k;
string a;
vector<char> result;

int main(void) {
	cin >> n >> k >> a;
	int i = 0;
	while (i != a.size()) {
		while (k != 0 && !result.empty() && result.back() < a[i]) {
			result.pop_back();
			k--;
		}
		result.push_back(a[i]);
		i++;
	}
	while (k--) {
		result.pop_back();
	}
	for (int i = 0; i < result.size(); i++) {
		cout << result[i];
	}
}

