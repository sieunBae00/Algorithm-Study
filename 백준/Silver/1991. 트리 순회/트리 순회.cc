// 백준 1991 트리순회하기

#include <iostream>
using namespace std;
#include <vector>

class BinaryNode
{
    char data;
	BinaryNode* left;
	BinaryNode* right;
public:
	BinaryNode(char val = 0, BinaryNode* l = NULL, BinaryNode* r = NULL)
		: data(val), left(l), right(r) { }
	~BinaryNode() { }
	void setData(char val) { data = val; }
	void setLeft(BinaryNode* l) { left = l; }
	void setRight(BinaryNode* r) { right = r; }
	char getData() { return data; }
	BinaryNode* getLeft() { return left; }
	BinaryNode* getRight() { return right; }
	bool isLeaf() { return left == NULL && right == NULL; }
};

class BinaryTree {
	BinaryNode* root;
public:
	BinaryTree() : root(NULL) { }
	~BinaryTree() { }

	void setRoot(BinaryNode* node) { root = node; }
	BinaryNode* getRoot() { return root; }
	bool isEmpty() { return root == NULL; }

	void inorder(BinaryNode* node);
	void preorder(BinaryNode* node);
	void postorder(BinaryNode* node);
};


void
BinaryTree::inorder(BinaryNode* node) {
	if (node != NULL) {
		if (node->getLeft() != NULL) inorder(node->getLeft());
		cout << static_cast<char>(node->getData());
		if (node->getRight() != NULL) inorder(node->getRight());
	}
}

void
BinaryTree::preorder(BinaryNode* node) {
	if (node != NULL) {
		cout << static_cast<char>(node->getData());
		if (node->getLeft() != NULL) preorder(node->getLeft());
		if (node->getRight() != NULL) preorder(node->getRight());
	}
}

void
BinaryTree::postorder(BinaryNode* node) {
	if (node != NULL) {
		if (node->getLeft() != NULL) postorder(node->getLeft());
		if (node->getRight() != NULL) postorder(node->getRight());
		cout << static_cast<char>(node->getData());
	}
}

int main() {

	int N;	 // 노드 개수
	char p, left, right;
	vector<BinaryNode*> node;
	BinaryTree* tree;

	cin >> N;       // N 입력
	node.resize(N); // node 벡터 크기

	// BinaryNode 생성
	for (int i = 0; i < N; i++)
		node[i] = new BinaryNode('A' + i);

	// 노드 간 링크 연결
	for (int i = 0; i < N; i++){
		cin >> p >> left >> right;
		if (left != '.') node[p - 'A']->setLeft(node[left - 'A']);
		if (right != '.') node[p - 'A']->setRight(node[right - 'A']);
	}

	// BinaryTree 생성
	tree = new BinaryTree();
	tree->setRoot(node[0]);

	// BinaryTree traversal
	BinaryNode* root = tree->getRoot();
	tree->preorder(root);  cout << endl;
	tree->inorder(root);   cout << endl;
	tree->postorder(root); cout << endl;

	return 0;
}