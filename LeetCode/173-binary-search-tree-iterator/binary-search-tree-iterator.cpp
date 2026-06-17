/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
private:
    priority_queue<int, vector<int>, greater<int>> pq; // 오름차순

    void Traversal(TreeNode* root){
        if(root == nullptr) return;

        pq.push(root->val);

        Traversal(root->left);
        Traversal(root->right);
    }

public:
    BSTIterator(TreeNode* root) {
        Traversal(root);
    }
    
    int next() {
        int curr = pq.top();
        pq.pop();
        return curr; // 가장 작은 수를 반환
    }
    
    bool hasNext() {
        return pq.empty() ? false : true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */