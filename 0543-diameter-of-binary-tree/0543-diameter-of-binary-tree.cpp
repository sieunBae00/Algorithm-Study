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
    int max_diameter = 0;
public:
    // 깊이를 구해주는 헬퍼 함수
    int getDepth(TreeNode* node) {
        if(node == nullptr) return 0; // 리프 노드인 경우: 깊이 0 반환

        int leftDepth = getDepth(node->left); // 왼쪽 깊이
        int rightDepth = getDepth(node->right); // 오른쪽 깊이

        if(leftDepth + rightDepth > max_diameter) max_diameter = leftDepth + rightDepth; // 최대 지름 갱신

        return max(leftDepth, rightDepth) + 1; // '깊이'를 반환 !!
    }

    int diameterOfBinaryTree(TreeNode* root) {
        getDepth(root);

        return max_diameter; // 갱신된 최대 지름 반환
    }
};