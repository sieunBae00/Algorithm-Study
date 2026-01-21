#include <iostream>
using namespace std;
#include<stack>

int main() {
	stack<char> st;
	string s;
	char past;
	int ans = 0;

	cin >> s;

	for (char current : s) {

		if (current == ')') {
			if (past == '(') {
				st.pop();
				ans = ans + st.size();
			}
			else { // past == ')'
				st.pop();
				ans++;
			}
		}

		else { //current == '(' 
			st.push(current);
		}

		past = current;
	}

	cout << ans << endl;

	return 0;
}