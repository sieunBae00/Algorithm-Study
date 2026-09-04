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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr) return ans;

        queue<pair<TreeNode*, int>> q; // {노드, 레벨}

        q.push({root, 1});

        pair<int, int> curr = {1, root->val}; // {현재 레벨, 값}
        while(!q.empty()){
            TreeNode* node = q.front().first; // 현재 노드
            int level = q.front().second; // 노드의 레벨
            q.pop();

            // right side 검사
            if(curr.first == level) curr.second = node->val;
            else {
                ans.push_back(curr.second);
                curr = {level, node->val};
            }

            if(node->left != nullptr) q.push({node->left, level+1});
            if(node->right != nullptr) q.push({node->right, level+1});
        }
        ans.push_back(q.back().first->val);

        return ans;
    }
};