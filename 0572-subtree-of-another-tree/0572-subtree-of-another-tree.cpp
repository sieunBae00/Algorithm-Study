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
    bool isSameTree(TreeNode* n1, TreeNode* n2){
        if(n1 == nullptr && n2 == nullptr) return true;
        else if(n1 == nullptr && n2 != nullptr) return false;
        else if(n1 != nullptr && n2 == nullptr) return false;
        else if(n1->val != n2->val) return false;
        else return isSameTree(n1->left, n2->left) && isSameTree(n1->right, n2->right);
    }
   
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr) return false; // 더 이상 검사할 노드가 없다면 false

        // subTree 인 부분을 찾으면 true
        if(isSameTree(root, subRoot)) return true;

        bool left = isSubtree(root->left, subRoot);
        bool right = isSubtree(root->right, subRoot);

        return left || right; // 왼/오 서브트리 중 하나라도 subtree 가 있다면 true
    }
};