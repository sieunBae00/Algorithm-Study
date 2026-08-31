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
    int findSub(TreeNode* root){
        while(root->left != nullptr){
            root = root->left;
        }
        return root->val;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return root; // 노드가 존재하지 않을 경우

        // 노드 탐색
        if(root->val < key) root->right = deleteNode(root->right, key);

        else if(root->val > key) root->left = deleteNode(root->left, key);

        else if(root->val == key){
            if(root->left == nullptr && root->right == nullptr) return nullptr; // 자식 0개
            //자식 1개
            else if(root->left == nullptr) return root->right;
            else if(root->right == nullptr) return root->left;
            else{ // 자식 2개
                root->val = findSub(root->right); // 대체할 노드의 값 복사
                root->right = deleteNode(root->right, root->val);
                return root;
            }
        }
        return root;
    }
};