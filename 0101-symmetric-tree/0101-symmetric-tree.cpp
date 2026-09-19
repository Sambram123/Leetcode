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
    bool sym(TreeNode* t1,TreeNode* t2){
        if(t1==nullptr && t2==nullptr) return true;
        if(t1==nullptr || t2==nullptr) return false;
        if(t1->val != t2->val) return false;
        
        bool a1 = sym(t1->left,t2->right);
        bool a2 = sym(t1->right,t2->left);
        

        return a1 && a2;
    }
public:
    bool isSymmetric(TreeNode* root) {
        bool ans = sym(root->left,root->right);

        return ans;
    }
};