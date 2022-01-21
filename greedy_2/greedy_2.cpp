// greedy_2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> a;

int main(void) {
	int n, k;
	cin >> n >> k;
	int result = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a.push_back(x);
	}
	for (int i = a.size() - 1; i >= 0; i--) {
		result += k / a[i];
		k %= a[i];
	}
	cout << result;
	return 0;
}