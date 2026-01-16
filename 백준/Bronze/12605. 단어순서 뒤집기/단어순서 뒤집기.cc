#include <iostream>
using namespace std;
#include <stack>
#include <sstream>


int main() {
	int N;
	cin >> N;
	cin.ignore();


	for (int i = 0; i < N; i++) {

		string line;
		getline(cin, line);

		stringstream ss(line);
		string word;

		stack<string> st;
		while (ss >> word) {
			st.push(word);
		}

		cout << "Case #" << i + 1 << ": ";
		while (!st.empty()) {
			cout << st.top() << " ";
			st.pop();
		}
		cout << endl;
	}
}