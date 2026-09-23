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
    vector<vector<int>> ans;

    void fun(TreeNode* root, int target,int sum,vector<int> tmp){
        if(root==nullptr) return;
        sum += root->val;
        tmp.push_back(root->val);
        if(root->left == nullptr && root->right==nullptr){
            if(sum==target) ans.push_back(tmp);
        }

        fun(root->left,target,sum,tmp);
        fun(root->right,target,sum,tmp);

        return;
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        int sum=0;
        vector<int> tmp;
        fun(root,target,sum,tmp);

        return ans;
    }
};