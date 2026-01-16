#include <iostream>
using namespace std;
#include <stack>

int main() {
	string S;
	cin >> S;

	stack<char> st;

	char ch;
	for (int i = 0; i < S.size(); i++) {
		char ch = S.at(i);

		if (st.empty()) {
			st.push(ch);
			continue;
		}

		if (ch == '(') {
			st.push(ch);
		}
		else if (ch == ')') {
			if (st.top() == '(') st.pop();
			else st.push(ch);
		}
	}
	cout << st.size();

}