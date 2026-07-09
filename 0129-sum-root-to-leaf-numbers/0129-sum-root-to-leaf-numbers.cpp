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
private:
    int ans;

public:
    void DFS(TreeNode* node, int curr){
        if(node->left == nullptr && node->right == nullptr){ // 리프 노드라면
            ans += curr*10 + (node->val);

        }
        else{
            if(node->left != nullptr) DFS(node->left, curr*10 + (node->val));
            if(node->right != nullptr) DFS(node->right, curr*10 + (node->val));
        }
    }


    int sumNumbers(TreeNode* root) {
        ans = 0;
        DFS(root, 0);

        return ans;
    }
};