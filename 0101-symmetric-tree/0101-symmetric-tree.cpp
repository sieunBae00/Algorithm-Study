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
    bool isMirror(TreeNode* t1, TreeNode* t2){
        if(t1 == nullptr && t2 == nullptr) return true; // 두 노드 모두 null
        else if(t1 == nullptr || t2 == nullptr) return false; // 두 노드 중 하나만 null
        else if(t1->val != t2->val) return false; // 두 노드의 값이 다름

        // 위 세 가지 경우에 해당하지 않을 때에만 다음 자식 노드를 검사
        return isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left); // 크로스로 검사
    }


    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true; // 루트 노드부터 null 일 경우

        return isMirror(root->left, root->right);
    }
};