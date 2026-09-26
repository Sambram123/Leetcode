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
    TreeNode* prev = nullptr; 
    bool res = true;
    void inorder(TreeNode* root){
        if(root==nullptr) return;

        inorder(root->left);
        if(prev==nullptr){
            prev = root;
        }
        else{
            if(root->val <= prev->val){
                res = false;
            }
            prev = root;
        }

        inorder(root->right);

        return;
    }
public:
    bool isValidBST(TreeNode* root) {
        inorder(root);

        return res;
    }
};