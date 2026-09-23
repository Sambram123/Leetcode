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
    int ans=0;
    void fun(TreeNode* root,string num){
        if(root==nullptr) return;
        num += to_string(root->val);

        if(root->left==nullptr && root->right==nullptr){
            ans += stoi(num);
        }
        fun(root->left,num);
        fun(root->right,num);

        return;
    }
public:
    int sumNumbers(TreeNode* root) {
        string num="";

        fun(root,num);
        return ans;
    }
};