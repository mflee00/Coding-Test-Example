// 1.runners.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// https://programmers.co.kr/learn/courses/30/lessons/42576
// 프로그래머스 해시 문제 - 완주하지 못한 선수

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	unordered_map<string, int> htmap;

	for (auto it : participant) {
		if (htmap.count(it))
			htmap.find(it)->second++;
		else
			htmap.insert({ it,0 });
	}
	for (auto it : completion) {
		if (htmap.find(it)->second > 0)
			htmap.find(it)->second--;
		else
			htmap.erase(it);
	}

	return htmap.begin()->first;
}