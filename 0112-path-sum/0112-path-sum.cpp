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
    bool res=false;
    void pathSum(TreeNode* root,int sum,int tar){
        if(root==nullptr) return;

        sum+=root->val;
        if(root->left==nullptr && root->right==nullptr){
            if(sum==tar) res = true;
        }

        pathSum(root->left,sum,tar);
        pathSum(root->right,sum,tar);
        return;
    }
public:
    bool hasPathSum(TreeNode* root, int tar) {
        int sum = 0;
        pathSum(root,sum,tar);

        return res;
    }
};