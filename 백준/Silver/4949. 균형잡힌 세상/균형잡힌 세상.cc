#include <iostream>
using namespace std;
#include <string>
#include <stack>

int main() {
	string str;

	while (true) {
		stack<char> st;
		bool balance = true;

		getline(cin, str, '.');
		if (str == "\n") return 0;


		for (char c : str) {
			if ((c == '(') || (c == '[')) {
				st.push(c);
			}
			else if (c == ')') {
				if (!st.empty()) {
					if (st.top() == '(') st.pop();
					else {
						balance = false;
						break;
					}
				}
				else {
					balance = false;
					break;
				}
			}
			else if (c == ']') {
				if (!st.empty()) {
					if (st.top() == '[') st.pop();
					else {
						balance = false;
						break;
					}
				}
				else {
					balance = false;
					break;
				}
			}
		}
		if ((balance == true) && st.empty()) cout << "yes" << '\n';
		else cout << "no" << '\n';
	}
}