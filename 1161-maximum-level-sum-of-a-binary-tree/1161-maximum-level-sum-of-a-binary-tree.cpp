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
    int maxLevelSum(TreeNode* root) {
        int maxLevel = 1;
        queue<pair<TreeNode*, int>> q;
        int levelSum[10000] = {0,};    // frequency array

        q.push({root, 1});

        int level;
        while(!q.empty()){
            TreeNode* node = q.front().first;
            level = q.front().second;

            levelSum[level] += node->val;    // 해당 레벨에 노드의 값 더하기
            q.pop();

            if(node->left != nullptr) q.push({node->left, level+1});
            if(node->right != nullptr) q.push({node->right, level+1});
        }

        for(int i=1; i<=level; i++){
            if(levelSum[i] > levelSum[maxLevel]) maxLevel = i;
        }

        return maxLevel;
    }
};