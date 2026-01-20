#include <iostream>
using namespace std;
#include <queue>

int main() {
	queue<int> q;
	int N;
	int p;

	cin >> N;
	cin >> p;

	while (!(p == -1)) {
		if (p == 0) q.pop();
		else if (q.size() < N) {
			q.push(p);
		}
		cin >> p;
	}

	if (q.empty()) {
		cout << "empty";
	}

    while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
}