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
    vector<int> tmp;
    void fun(TreeNode* root){
        if(root==nullptr) return;

        fun(root->left);
        tmp.push_back(root->val);
        fun(root->right);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        fun(root);

        int n=tmp.size();
        int i=0, j=n-1;
        while(i<j){
            if(tmp[i]+tmp[j]==k) return true;

            if(tmp[i]+tmp[j]<k) i++;
            else j--;
        }
        return false;
    }
};