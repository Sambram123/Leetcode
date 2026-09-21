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
    void search(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==nullptr) return;
        if(root==p || root==q){
            ans=root;
            return;
        } 

        if(p->val>root->val && q->val>root->val){
            search(root->right,p,q);
        }
        else if(p->val<root->val && q->val<root->val){
            search(root->left,p,q);
        }
        else{
            ans=root;
            return;
        }

        
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val<q->val)
            search(root,p,q);
        if(p->val>q->val)
            search(root,q,p);

        return ans;
    }
};