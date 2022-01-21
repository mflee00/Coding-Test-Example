// 2.best ambum.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// https://programmers.co.kr/learn/courses/30/lessons/42579#
// 프로그래머스 해시 문제 - 베스트앨범

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

unordered_map<string, int> hsmap;

struct Song {
	string name;
	int plays;
	int index;
};

bool cmp(const Song &s1, const Song &s2) {
	if (hsmap[s1.name] < hsmap[s2.name])
		return false;
	else if (hsmap[s1.name] == hsmap[s2.name]) {
		if (s1.plays < s2.plays)
			return false;
		else if (s1.plays == s2.plays) {
			if (s1.index < s2.index)
				return true;
			else
				return false;
		}
		else
			return true;
	}
	else
		return true;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	vector<Song> song;

	for (int i = 0; i < genres.size(); ++i) {
		hsmap[genres[i]] += plays[i];
		song.push_back({ genres[i], plays[i], i });
	}

	sort(song.begin(), song.end(), cmp);

	int cnt = 0;
	string name = "";

	for (auto it : song) {
		if (name != it.name) {
			answer.push_back(it.index);
			name = it.name;
			cnt = 1;
		}
		else if (cnt < 2) {
			answer.push_back(it.index);
			cnt++;
		}
	}

	return answer;
}