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
    void DFS(TreeNode* root, int max, int& ans){
        if(root->val >= max){
            max = root->val;
            ans++;
        }
        
        if(root->left != nullptr) DFS(root->left, max, ans);
        if(root->right != nullptr) DFS(root->right, max, ans);

        return;
    }

    int goodNodes(TreeNode* root) {
        int ans = 0;
        DFS(root, root->val, ans);
        return ans;
    }
};