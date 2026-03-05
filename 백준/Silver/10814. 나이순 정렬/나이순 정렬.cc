#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>

typedef pair<int, string> info;

vector<info> V;

bool sort_age(info a, info b) { // a가 b보다 앞에 와야 하면 True 를 반환
	if (a.first < b.first) return true; // 1. 나이 비교 -> 어린 쪽이 앞으로
	else return false; // 나이가 많다면 뒤로
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	V.resize(N);

	for (int i = 0; i < N; i++) {
		int age;
		cin >> age;
		string name;
		cin >> name;

		V[i] = { age, name };
	}

	// stable_sort(): 커스텀 비교 함수에서, 비교 값이 동일하다면 "원래의 순서를 유지한다." !!
	stable_sort(V.begin(), V.end(), sort_age); // 커스텀 함수(나이 기준)로 정렬하기

	for (int i = 0; i < V.size(); i++) {
		cout << V[i].first << " " << V[i].second << '\n';
	}

	return 0;
}