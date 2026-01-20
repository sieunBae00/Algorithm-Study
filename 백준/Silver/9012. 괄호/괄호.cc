#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int ans = 0;
		bool success = true;

		string s;
		cin >> s;

		for (char c : s) {
			if (c == '(') ans++;
			else {
				ans--;
				if (ans < 0) {
					success = false;
					break;
				}
			}
		}
		if ((success == true) && ans == 0) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}