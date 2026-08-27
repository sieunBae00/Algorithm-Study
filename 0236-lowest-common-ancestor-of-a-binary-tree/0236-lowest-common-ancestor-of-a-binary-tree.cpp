/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return nullptr; // 끝까지 내려옴: 못 찾음
        if(root == p || root == q) return root; // p, q 둘 중 하나를 찾음

        TreeNode* left = lowestCommonAncestor(root->left, p, q); // 왼쪽 재귀
        TreeNode* right = lowestCommonAncestor(root->right, p, q); // 오른쪽 재귀

        if(left != nullptr && right != nullptr) return root; // 둘 다 nullptr 가 아닌 경우: 최소공통조상을 찾음

        return (left != nullptr) ? left : right; // 둘 중 nullptr 가 아닌 것을 return
    }
};