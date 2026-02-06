#include <iostream>
using namespace std;
#include<vector>

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> H; // 높이 h의 AVL 트리를 만들기 위해 필요한 최소 노드 수를 저장.
	H.resize(51);

	H[1] = 1;
	H[2] = 2;

	for (int i = 3; i <= 50; i++) {
		H[i] = H[i - 1] + H[i - 2] + 1;
	}

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int V;
		cin >> V;

		for (int j = 1; j < H.size(); j++) {
			if (H[j] > V) {
				cout << j-1 << '\n';
				break;
			}
		}
	}

	return 0;
}