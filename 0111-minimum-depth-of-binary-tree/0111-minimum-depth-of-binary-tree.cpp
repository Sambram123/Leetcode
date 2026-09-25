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
    int height(TreeNode* root){
        if(root==nullptr) return 0;
        if(root->left==nullptr && root->right==nullptr) return 1;

        if(root->left==nullptr){
            return 1+height(root->right);
        }
        if(root->right==nullptr){
            return 1+height(root->left);
        }

        int left = height(root->left);
        int right = height(root->right);

        return 1+min(left,right);
    }
public:
    int minDepth(TreeNode* root) {
        
        int depth = height(root);

        return depth;
    }
};