#include<iostream>
using namespace std;
#include<vector>
#include<cmath>

vector<int> weight;
int edgenum;

int DFS(int root) {
	if (root * 2 + 1 > edgenum) return 0;

	int leftchild = root * 2 + 1;
	int rightchild = root * 2 + 2;

	int left_W = DFS(leftchild);
	int right_W = DFS(rightchild);

	int leftside = left_W + weight[leftchild];
	int rightside = right_W + weight[rightchild];

	if (leftside > rightside) weight[rightchild] += (leftside - rightside);
	else if (leftside < rightside) weight[leftchild] += (rightside - leftside);

	return max(leftside, rightside);
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);

	int k;
	cin >> k;

	edgenum = pow(2, k + 1) - 2;

	weight.resize(edgenum+1);

	for (int i = 1; i <= edgenum; i++) {
		cin >> weight[i];
	}

	DFS(0);

	int ans = 0;
	for (int i = 1; i <= edgenum; i++) {
		ans += weight[i];
	}

	cout << ans << '\n';
    
    return 0;
}