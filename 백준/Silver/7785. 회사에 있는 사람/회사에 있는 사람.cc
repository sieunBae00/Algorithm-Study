#include <iostream>
using namespace std;
#include <set>
#include <algorithm>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    set<string, greater<string>> trace;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string name, log;
        cin >> name >> log;

        if (log == "enter") {
            trace.insert(name);
        }
        else if (log == "leave") {
            if (trace.find(name) != trace.end()) {
                trace.erase(name);
            }
        }
    }

    for (string s : trace) {
        cout << s << '\n';
    }

    return 0;
}