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
class Solution {
public:
    void findLeaf(TreeNode* root, vector<int>& leaves){ // 리프 노드를 배열에 저장하는 함수
        if(root->left == nullptr && root->right == nullptr) leaves.push_back(root->val);
        if(root->left != nullptr) findLeaf(root->left, leaves);
        if(root->right != nullptr) findLeaf(root->right, leaves);
        return;
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> t1;
        vector<int> t2;

        findLeaf(root1, t1);
        findLeaf(root2, t2);

        return (t1==t2); // 배열을 비교해서 true/false 반환
    }
};