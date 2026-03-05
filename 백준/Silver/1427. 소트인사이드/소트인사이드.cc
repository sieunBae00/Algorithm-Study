#include <iostream>
using namespace std;
#include <string>
#include <queue>

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<char, vector<char>, less<char>> pq;

	string N;
	cin >> N;

	for (char c : N) {
		pq.push(c);
	}

	while (!pq.empty()) {
		cout << pq.top();
		pq.pop();
	}

	return 0;
}