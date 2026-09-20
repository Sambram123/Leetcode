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
    TreeNode* ans=nullptr;
    int boss(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==nullptr) return 0;

        int left=boss(root->left,p,q);
        int right=boss(root->right,p,q);
        int self = (root==p || root==q) ? 1 : 0;

        int total = left+right+self;
        if(total==2 && ans==nullptr){
            ans=root;
        }
        return total;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        boss(root,p,q);

        return ans;
    }
};