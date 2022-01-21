// rabin-karp.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

void findString(string parent, string pattern) {
	int parentSize = parent.size();
	int patternSize = pattern.size();
	int parentHash = 0, patternHash = 0, power = 1;
	for (int i = 0; i <= parentSize - patternSize; i++) {
		if (i == 0) {
			for (int j = 0; j < patternSize; j++) {
				parentHash = parentHash +
					parent[patternSize - 1 - j] * power;
				patternHash = patternHash +
					pattern[patternSize - 1 - j] * power;
				if (j < patternSize - 1) power = power * 2;
			}
		}
		else {
			parentHash = 2 * (parentHash - parent[i - 1] * power) +
				parent[patternSize - 1 + i];
		}
		if (parentHash == patternHash) {
			bool finded = true;
			for (int j = 0; j < patternSize; j++) {
				if (parent[i + j] != pattern[j]) {
					finded = false;
					break;
				}
			}
			if (finded) {
				printf("%d번째에서 발견했습니다.\n", i + 1);
			}
		}
	}
}

int main(void) {
	string parent = "ababacabacaabacaaba";
	string pattern = "abacaaba";
	findString(parent, pattern);
	return 0;
}
