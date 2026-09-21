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

    bool same(TreeNode* p, TreeNode* q){
        if(!p && !q) return true;
        if(!p || !q) return false;
        if(p->val != q->val) return false;

        bool a1 = same(p->left,q->left);
        bool a2 = same(p->right,q->right);

        return a1 && a2;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==nullptr) return false;
        
        if(root->val==subRoot->val){
            if(same(root,subRoot))
                return true;
        }

        bool r1 = isSubtree(root->left,subRoot);
        bool r2 = isSubtree(root->right,subRoot);

        return r1 || r2;
    }
};